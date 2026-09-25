#include "MedicalTeam.h"
#include "Incident.h"
#include "Mediator.h"

#include <iostream>

MedicalTeam::MedicalTeam(const std::string& name)
    : ResponseComponent(name)
{
}

void MedicalTeam::handleIncident(Incident& incident)
{
    std::cout << "[MEDICAL] " << name
              << " treating patients for incident "
              << incident.getId()
              << " at "
              << incident.getLocation()
              << "."
              << std::endl;

    if (mediator)
    {
        mediator->notify(this, incident, "MEDICAL_ON_SCENE");
    }
}

void MedicalTeam::coordinate(
    Incident& incident,
    const std::string& event)
{
    if (event == "SECURITY_ON_SCENE")
    {
        std::cout << "[MEDICAL] " << name
                  << " cleared to move in on incident "
                  << incident.getId()
                  << "."
                  << std::endl;
    }
    else if (event == "FACILITIES_READY")
    {
        std::cout << "[MEDICAL] " << name
                  << " using the cleared access route prepared by facilities for incident "
                  << incident.getId()
                  << "."
                  << std::endl;
    }
    else if (event == "EMERGENCY_ALERT")
    {
        std::cout << "[MEDICAL] " << name
                  << " standing by for casualties following the emergency broadcast for incident "
                  << incident.getId()
                  << "."
                  << std::endl;
    }
}