#include "CommunicationService.h"
#include "Incident.h"
#include <iostream>

void CommunicationService::broadcastAlert(const std::string& message){
    std::cout << "[COMMS] Broadcasting: " << message <<std::endl;
}

void CommunicationService::notifyAllComponents(Incident& incident, const std::string& event){
    
    std::cout << "[COMMS] Notifying all components of event \"" << event << "\" for incident" << incident.getId() << "." << std::endl;
}