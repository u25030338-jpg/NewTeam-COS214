#include "FireResponseStrategy.h"
#include "Incident.h"
#include "DispatchUnitCommand.h"
#include "SecureAreaCommand.h"
#include "EmergencyAlertCommand.h"
 
#include <iostream>
 
bool FireResponseStrategy::execute(Incident& incident)
{
    std::cout << "[STRATEGY] " << getName() << " selected for incident " << incident.getId() << " (severity: " << incident.getSeverity() << ")." << std::endl;
 
    if (!prepareIncident(incident))
    {
        return false;
    }
 
    DispatchUnitCommand security(incident, "Security");
    run(security);
 
    DispatchUnitCommand facilities(incident, "Facilities");
    run(facilities);
 
    if (isHighSeverity(incident))
    {
        std::cout << "[STRATEGY] High severity fire: adding a medical unit." << std::endl;
        DispatchUnitCommand medical(incident, "Medical");
        run(medical);
    }
 
    SecureAreaCommand secure(incident);
    run(secure);
 
    EmergencyAlertCommand alert(incident, "EVACUATE: fire at " + incident.getLocation() + ". Leave the building immediately.");
    run(alert);
 
    return true;
}
 
const char* FireResponseStrategy::getName() const
{
    return "FireResponseStrategy";
}