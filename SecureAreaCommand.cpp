#include "SecureAreaCommand.h"
#include "Incident.h"
#include "Mediator.h"

#include <iostream>

SecureAreaCommand::SecureAreaCommand(Incident& incident)
    : incident(incident)
{
}

void SecureAreaCommand::execute()
{
    std::cout << "Securing area at "
              << incident.getLocation()
              << " for incident "
              << incident.getId()
              << "." << std::endl;

    if(incident.getMediator()) incident.getMediator()->notify(nullptr, incident, "SECURE_AREA_REQUESTED");
}