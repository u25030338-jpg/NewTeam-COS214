#include "DispatchUnitCommand.h"
#include "Incident.h"
#include "Mediator.h"

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

    if(incident.getMediator()) incident.getMediator()->notify(nullptr, incident, ("UNIT_DISPATCHED: " + unitType).c_str());
}