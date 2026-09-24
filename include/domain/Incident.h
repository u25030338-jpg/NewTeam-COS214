#ifndef INCIDENT_H
#define INCIDENT_H

#include <string>

class IncidentState;
class Mediator;
class ResponseStrategy;

class Incident
{
private:
    std::string id;
    std::string type;
    std::string location;
    std::string severity;

    IncidentState* state;
    Mediator* mediator;
    ResponseStrategy* responseStrategy;

public:
    Incident(const std::string& id,
             const std::string& type,
             const std::string& location,
             const std::string& severity);

    ~Incident();

    const std::string& getId() const;
    const std::string& getType() const;
    const std::string& getLocation() const;
    const std::string& getSeverity() const;

    IncidentState* getState() const;
    void setState(IncidentState* newState);

    Mediator* getMediator() const;
    void setMediator(Mediator* newMediator);

    ResponseStrategy* getResponseStrategy() const;
    void setResponseStrategy(ResponseStrategy* newStrategy);

    void assess();
    bool dispatch();
    void resolve();
    void close();

    void printSummary() const;
};

#endif