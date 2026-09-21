#ifndef SECURE_AREA_COMMAND_H
#define SECURE_AREA_COMMAND_H

#include "command/Command.h"

class Incident;

class SecureAreaCommand : public Command
{
private:
    Incident& incident;

public:
    explicit SecureAreaCommand(Incident& incident);

    void execute() override;
};

#endif