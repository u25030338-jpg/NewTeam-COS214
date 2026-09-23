#ifndef EMERGENCY_ALERT_COMMAND_H
#define EMERGENCY_ALERT_COMMAND_H

#include "Command.h"
#include <string>

class Incident;

class EmergencyAlertCommand : public Command
{
private:
    Incident& incident;
    std::string message;

public:
    EmergencyAlertCommand(Incident& incident,
                          const std::string& message);

    void execute() override;
};

#endif