#include "command/SecureAreaCommand.h"
#include "domain/Incident.h"

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
}