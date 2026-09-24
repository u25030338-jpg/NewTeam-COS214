#include "EmergencyAlertCommand.h"
#include "Incident.h"
#include "Mediator.h"

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

    if(incident.getMediator()) incident.getMediator()->notify(nullptr, incident, "EMERGENCY_ALERT");
}