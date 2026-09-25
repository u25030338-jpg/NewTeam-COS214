#include "MedicalResponseStrategy.h"
#include "Incident.h"
#include "DispatchUnitCommand.h"
#include "SecureAreaCommand.h"
#include "EmergencyAlertCommand.h"
 
#include <iostream>
 
bool MedicalResponseStrategy::execute(Incident& incident)
{
    std::cout << "[STRATEGY] " << getName() << " selected for incident " << incident.getId() << " (severity: " << incident.getSeverity() << ")." << std::endl;
 
    if (!prepareIncident(incident))
    {
        return false;
    }
 
    DispatchUnitCommand medical(incident, "Medical");
    run(medical);
 
    if (isHighSeverity(incident))
    {
        std::cout << "[STRATEGY] High severity medical incident: adding security to clear access." << std::endl;
        DispatchUnitCommand security(incident, "Security");
        run(security);
    }
 
    SecureAreaCommand secure(incident);
    run(secure);
 
    EmergencyAlertCommand alert(incident, "Medical emergency at " + incident.getLocation() + ". Keep corridors clear for responders.");
    run(alert);
 
    return true;
}
 
const char* MedicalResponseStrategy::getName() const
{
    return "MedicalResponseStrategy";
}