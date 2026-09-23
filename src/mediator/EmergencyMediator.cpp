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

    if (evt == "UNIT_DISPATCHED")
    {
        // Route to the team matching the incident type. Falls back to facilities for anything that isn't clearly medical or security, matching the incident type strings used elsewhere in the project.
        const std::string& type = incident.getType();

        if (type.find("Medical") != std::string::npos)
        {
            medical->handleIncident(incident);
        }
        else if (type.find("Security") != std::string::npos)
        {
            security->handleIncident(incident);
        }
        else
        {
            facilities->handleIncident(incident);
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
