#include "Incident.h"
#include "IncidentState.h"
#include "ReportedState.h"

#include <iostream>

Incident::Incident(const std::string& id,
                   const std::string& type,
                   const std::string& location,
                   const std::string& severity)
    : id(id),
      type(type),
      location(location),
      severity(severity),
      state(new ReportedState()),
      mediator(nullptr),
      responseStrategy(nullptr)
{
}

Incident::~Incident()
{
    delete state;
}

const std::string& Incident::getId() const
{
    return id;
}

const std::string& Incident::getType() const
{
    return type;
}

const std::string& Incident::getLocation() const
{
    return location;
}

const std::string& Incident::getSeverity() const
{
    return severity;
}

IncidentState* Incident::getState() const
{
    return state;
}

void Incident::setState(IncidentState* newState)
{
    delete state;
    state = newState;
}

Mediator* Incident::getMediator() const
{
    return mediator;
}

void Incident::setMediator(Mediator* newMediator)
{
    mediator = newMediator;
}

ResponseStrategy* Incident::getResponseStrategy() const
{
    return responseStrategy;
}

void Incident::setResponseStrategy(ResponseStrategy* newStrategy)
{
    responseStrategy = newStrategy;
}

void Incident::assess()
{
    state->assess(*this);
}

void Incident::dispatch()
{
    state->dispatch(*this);
}

void Incident::resolve()
{
    state->resolve(*this);
}

void Incident::close()
{
    state->close(*this);
}

void Incident::printSummary() const
{
    std::cout << "Incident: " << id << std::endl;
    std::cout << "Type: " << type << std::endl;
    std::cout << "Location: " << location << std::endl;
    std::cout << "Severity: " << severity << std::endl;
    std::cout << "State: " << state->getName() << std::endl;
}