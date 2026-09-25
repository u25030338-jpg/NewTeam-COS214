#include "DispatchUnitCommand.h"
#include "Incident.h"
#include "Mediator.h"

#include <iostream>

DispatchUnitCommand::DispatchUnitCommand(
    Incident& incident,
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

    if (!incident.dispatch())
    {
        return;
    }

    if (incident.getMediator())
    {
        std::string event = "UNIT_DISPATCHED:" + unitType;

        incident.getMediator()->notify(
            nullptr,
            incident,
            event.c_str()
        );
    }
}