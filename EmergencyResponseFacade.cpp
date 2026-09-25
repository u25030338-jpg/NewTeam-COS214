#include "EmergencyResponseFacade.h"
#include "Incident.h"
#include "IncidentState.h"
#include "Mediator.h"
#include "AccessControl.h"
#include "CommunicationService.h"
 
#include <iostream>
#include <string>
 
//Used for handling capital and lowercase issues
namespace
{
    std::string toLower(std::string s)
    {
        for (std::string::size_type i = 0; i < s.size(); ++i)
        {
            if ((s[i] >= 'A') && (s[i] <= 'Z'))
            {
                s[i] = static_cast<char>(s[i] - 'A' + 'a');
            }
        }
        return s;
    }
 
    bool containsIgnoreCase(const std::string& text, const std::string& word)
    {
        return toLower(text).find(toLower(word)) != std::string::npos;
    }
}
 
EmergencyResponseFacade::EmergencyResponseFacade(Mediator& mediator, AccessControl& accessControl, CommunicationService& comms)
: mediator(mediator), accessControl(accessControl), comms(comms) {}


bool EmergencyResponseFacade::isRegistered(const Incident& incident) const
{
    for (std::vector<Incident*>::size_type i = 0; i < registered.size(); ++i)
    {
        if (registered[i] == &incident)
        {
            return true;
        }
    }
    return false;
}

 
void EmergencyResponseFacade::registerIncident(Incident& incident)
{
    if (isRegistered(incident))
    {
        std::cout << "[FACADE] Incident " << incident.getId() << " is already registered." << std::endl;
        return;
    }
 
    incident.setMediator(&mediator);
    registered.push_back(&incident);
 
    std::cout << "[FACADE] Registered incident " << incident.getId() << " (" << incident.getType() << ") at " << incident.getLocation() << ", severity " << incident.getSeverity() << "." << std::endl;
}

 
ResponseStrategy* EmergencyResponseFacade::selectStrategy(const Incident& incident)
{
    if (containsIgnoreCase(incident.getType(), "fire"))
    {
        return &fireStrategy;
    }
    if (containsIgnoreCase(incident.getType(), "medical"))
    {
        return &medicalStrategy;
    }
    return nullptr;
}

 
bool EmergencyResponseFacade::respondToIncident(Incident& incident)
{
    std::cout << "\n[FACADE] === Responding to incident " << incident.getId() << " ===" << std::endl;
 
    registerIncident(incident);
 
    const std::string state = incident.getState()->getName();
    if (state == "Responding")
    {
        std::cout << "[FACADE] Incident " << incident.getId() << " already has a response in progress; not dispatching again." << std::endl;
        return false;
    }
 
    ResponseStrategy* strategy = selectStrategy(incident);
    if (strategy == nullptr)
    {
        std::cout << "[FACADE] No response strategy for incident type \"" << incident.getType() << "\". Incident left unchanged." << std::endl;
        return false;
    }
 
    incident.setResponseStrategy(strategy);
 
    if (!incident.getResponseStrategy()->execute(incident))
    {
        std::cout << "[FACADE] Response for incident " << incident.getId() << " was not carried out." << std::endl;
        return false;
    }
 
    std::cout << "[FACADE] Response complete. Incident " << incident.getId() << " is now " << incident.getState()->getName() << "." << std::endl;
    return true;
}
 

bool EmergencyResponseFacade::resolveIncident(Incident& incident)
{
    std::cout << "\n[FACADE] === Standing down incident " << incident.getId() << " ===" << std::endl;
 
    const std::string state = incident.getState()->getName();
    if (state != "Responding")
    {
        std::cout << "[FACADE] Cannot stand down incident " << incident.getId() << ": it is " << state << ", not Responding." << std::endl;
        return false;
    }
 
    incident.resolve();
 
    if (!accessControl.unlockArea(incident.getLocation()))
    {
        std::cout << "[FACADE] FAILED to unlock " << incident.getLocation() << ". Incident " << incident.getId() << " left Resolved (not closed): manual access-control check needed." << std::endl;
        return false;
    }

    std::cout << "[FACADE] Area " << incident.getLocation() << " unlocked." << std::endl;
    comms.broadcastAlert("All clear for incident " + incident.getId() + " at " + incident.getLocation() + ".");
 
    incident.close();
    return true;
}