#include "FacilitiesTeam.h"
#include "Incident.h"
#include "Mediator.h"

#include <iostream>

FacilitiesTeam::FacilitiesTeam(const std::string& name)
    : ResponseComponent(name)
{
}

void FacilitiesTeam::handleIncident(Incident& incident)
{
    std::cout << "[FACILITIES] " << name << " managing building systems for incident "
              << incident.getId() << " at " << incident.getLocation()
              << "." << std::endl;

    if (mediator)
    {
        mediator->notify(this, incident, "FACILITIES_READY");
    }
}

void FacilitiesTeam::coordinate(Incident& incident, const std::string& event)
{
    if (event == "SECURE_AREA_REQUESTED")
    {
        std::cout << "[FACILITIES] " << name
                  << " standing by to lock down the area for incident "
                  << incident.getId() << "." << std::endl;
    }
    else if (event == "SECURITY_ON_SCENE")
    {
        std::cout << "[FACILITIES] " << name
                  << " coordinating building access with security for incident "
                  << incident.getId() << "." << std::endl;
    }
    else if (event == "EMERGENCY_ALERT")
    {
        std::cout << "[FACILITIES] " << name
                  << " preparing building systems following the emergency broadcast for incident "
                  << incident.getId() << "." << std::endl;
    }
}
