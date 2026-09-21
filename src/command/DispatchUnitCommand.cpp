#include "command/DispatchUnitCommand.h"
#include "domain/Incident.h"

#include <iostream>

DispatchUnitCommand::DispatchUnitCommand(Incident& incident,
                                         const std::string& unitType)
    : incident(incident),
      unitType(unitType)
{
}

void DispatchUnitCommand::execute()
{
    std::cout << "Dispatching " << unitType
              << " unit to incident "
              << incident.getId() << "." << std::endl;

    incident.dispatch();
}