#include "SecurityTeam.h"
#include "Incident.h"
#include "Mediator.h"
#include <iostream>

SecurityTeam::SecurityTeam(const std::string& name)
    : ResponseComponent(name)
{
}

void SecurityTeam::handleIncident(Incident& incident)
{
    std::cout << "[SECURITY] " << name << " securing the scene at "
              << incident.getLocation() << " for incident "
              << incident.getId() << "." << std::endl;

    if (mediator)
    {
        mediator->notify(this, incident, "SECURITY_ON_SCENE");
    }
}

void SecurityTeam::coordinate(Incident& incident, const std::string& event)
{
    if (event == "MEDICAL_ON_SCENE")
    {
        std::cout << "[SECURITY] " << name
                  << " maintaining the perimeter while medical treats incident "
                  << incident.getId() << "." << std::endl;
    }
    else if (event == "SECURE_AREA_REQUESTED")
    {
        std::cout << "[SECURITY] " << name
                  << " assisting with the area restriction for incident "
                  << incident.getId() << "." << std::endl;
    }
    else if (event == "EMERGENCY_ALERT")
    {
        std::cout << "[SECURITY] " << name
                  << " moving to high alert following the emergency broadcast for incident "
                  << incident.getId() << "." << std::endl;
    }
}
