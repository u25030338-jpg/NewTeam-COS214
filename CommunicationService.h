#ifndef COMMUNICATION_SERVICE_H
#define COMMUNICATION_SERVICE_H

#include <string>

class Incident;

class CommunicationService {
    public:
        void broadcastAlert(const std::string& message);
        void notifyAllComponents(Incident & Incident, const std::string& event);

};

#endif

