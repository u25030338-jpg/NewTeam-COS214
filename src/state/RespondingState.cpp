#include "RespondingState.h"
#include "Incident.h"
#include "ResolvedState.h"

#include <iostream>

void RespondingState::assess(Incident& incident)
{
    std::cout << "Incident " << incident.getId()
              << " is already being responded to." << std::endl;
}

bool RespondingState::dispatch(Incident& incident)
{
    std::cout << "Additional response unit dispatched for incident "
              << incident.getId() << "." << std::endl;

    return true;
}

void RespondingState::resolve(Incident& incident)
{
    std::cout << "Incident " << incident.getId()
              << " has been resolved." << std::endl;

    incident.setState(new ResolvedState());
}

void RespondingState::close(Incident& incident)
{
    std::cout << "Cannot close incident "
              << incident.getId()
              << " before it has been resolved." << std::endl;
}

const char* RespondingState::getName() const
{
    return "Responding";
}