#ifndef DISPATCHUNITCOMMAND_H
#define DISPATCHUNITCOMMAND_H

#include "command/Command.h"
#include <string>

class Incident;

class DispatchUnitCommand : public Command
{
private:
    Incident& incident;
    std::string unitType;

public:
    DispatchUnitCommand(Incident& incident,
                        const std::string& unitType);

    void execute() override;
};

#endif