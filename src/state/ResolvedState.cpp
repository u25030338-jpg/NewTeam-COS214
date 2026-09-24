#include "ResolvedState.h"
#include "Incident.h"
#include "ClosedState.h"

#include <iostream>

void ResolvedState::assess(Incident& incident)
{
    std::cout << "Incident " << incident.getId()
              << " has already been resolved." << std::endl;
}

void ResolvedState::dispatch(Incident& incident)
{
    std::cout << "Cannot dispatch incident "
              << incident.getId()
              << " because it has already been resolved." << std::endl;
}

void ResolvedState::resolve(Incident& incident)
{
    std::cout << "Incident " << incident.getId()
              << " is already resolved." << std::endl;
}

void ResolvedState::close(Incident& incident)
{
    std::cout << "Incident " << incident.getId()
              << " has been closed." << std::endl;

    incident.setState(new ClosedState());
}

const char* ResolvedState::getName() const
{
    return "Resolved";
}