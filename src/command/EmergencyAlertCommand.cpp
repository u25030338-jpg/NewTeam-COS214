#include "command/EmergencyAlertCommand.h"
#include "domain/Incident.h"

#include <iostream>

EmergencyAlertCommand::EmergencyAlertCommand(
    Incident& incident,
    const std::string& message)
    : incident(incident),
      message(message)
{
}

void EmergencyAlertCommand::execute()
{
    std::cout << "Emergency alert for incident "
              << incident.getId()
              << ": " << message
              << std::endl;
}