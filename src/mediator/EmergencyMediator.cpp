#include "EmergencyMediator.h"
#include "ResponseComponent.h"
#include "SecurityTeam.h"
#include "MedicalTeam.h"
#include "FacilitiesTeam.h"
#include "CommunicationService.h"
#include "Incident.h"
#include "AccessControl.h"
#include <iostream>


EmergencyMediator::EmergencyMediator(SecurityTeam* security, MedicalTeam* medical, FacilitiesTeam* facilities, CommunicationService* comms, AccessControl* accessControl)
    : security(security),
      medical(medical),
      facilities(facilities),
      comms(comms),
      accessControl(accessControl)
{
}

void EmergencyMediator::notify(ResponseComponent* sender, Incident& incident, const char* event)
{
    std::string evt(event);

    const std::string dispatchPrefix = "UNIT_DISPATCHED:";

if (evt.compare(0, dispatchPrefix.size(), dispatchPrefix) == 0)
{
    std::string unitType = evt.substr(dispatchPrefix.size());

    if (unitType == "Medical")
    {
        medical->handleIncident(incident);
    }
    else if (unitType == "Security")
    {
        security->handleIncident(incident);
    }
    else if (unitType == "Facilities")
    {
        facilities->handleIncident(incident);
    }
    else
    {
        std::cout << "[MEDIATOR] Unknown response unit: "
                  << unitType << "." << std::endl;
    }
}
    else if (evt == "SECURE_AREA_REQUESTED")
    {
        bool restricted = accessControl->restrictArea(incident.getLocation());

        if (restricted)
        {
            std::cout << "[MEDIATOR] Area " << incident.getLocation()
                      << " restricted for incident " << incident.getId()
                      << "." << std::endl;
        }
        else
        {
            std::cout << "[MEDIATOR] FAILED to restrict area " << incident.getLocation()
                      << " for incident " << incident.getId()
                      << " -- access control system rejected the request."
                      << std::endl;
        }

        facilities->coordinate(incident, "SECURE_AREA_REQUESTED");
        comms->broadcastAlert("Area restriction requested for incident "
                              + incident.getId() + " at " + incident.getLocation() + ".");
    }
    else if (evt == "EMERGENCY_ALERT")
    {
        comms->broadcastAlert("Emergency alert issued for incident "
                              + incident.getId() + " at " + incident.getLocation() + ".");
    }

    if (sender != nullptr)
    {
        // A colleague is reporting its own status change: fan it out to the
        // other colleagues (but not back to the sender) plus comms.
        if (sender != security)
        {
            security->coordinate(incident, evt);
        }

        if (sender != medical)
        {
            medical->coordinate(incident, evt);
        }

        if (sender != facilities)
        {
            facilities->coordinate(incident, evt);
        }

        comms->notifyAllComponents(incident, evt);
    }
}
