#ifndef EMERGENCY_RESPONSE_FACADE_H
#define EMERGENCY_RESPONSE_FACADE_H
 
#include "FireResponseStrategy.h"
#include "MedicalResponseStrategy.h"
 
#include <vector>
 
class Incident;
class Mediator;
class AccessControl;
class CommunicationService;
 
//Facade: one high-level entry point over incident handling, response strategies(commands -> mediator -> teams), access control (via adapter) and communications.
//The facade does not own the subsystems, so they all stay usable on their own.
class EmergencyResponseFacade
{
private:
    Mediator& mediator;
    AccessControl& accessControl;      //The adapter, seen through target interface
    CommunicationService& comms;
 
    FireResponseStrategy fireStrategy;
    MedicalResponseStrategy medicalStrategy;
 
    std::vector<Incident*> registered; //Reference, not ownership
 
    ResponseStrategy* selectStrategy(const Incident& incident);
    bool isRegistered(const Incident& incident) const;
 
public:
    EmergencyResponseFacade(Mediator& mediator, AccessControl& accessControl,  CommunicationService& comms);
 
    EmergencyResponseFacade(const EmergencyResponseFacade&) = delete;
    EmergencyResponseFacade& operator=(const EmergencyResponseFacade&) = delete;
 
    // Registers incident and sends it to the mediator (commands skip the mediator if it is null).
    void registerIncident(Incident& incident);
 
    // Register (if needed) -> pick strategy from incident type -> run it.
    bool respondToIncident(Incident& incident);
 
    // Stand-down workflow: resolve -> unlock area -> all-clear broadcast -> close.
    bool resolveIncident(Incident& incident);
};
 
#endif