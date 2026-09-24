#include "ClosedState.h"
#include "Incident.h"

#include <iostream>

void ClosedState::assess(Incident& incident)
{
    std::cout << "Cannot assess incident "
              << incident.getId()
              << " because it is closed." << std::endl;
}

void ClosedState::dispatch(Incident& incident)
{
    std::cout << "Cannot dispatch incident "
              << incident.getId()
              << " because it is closed." << std::endl;
}

void ClosedState::resolve(Incident& incident)
{
    std::cout << "Cannot resolve incident "
              << incident.getId()
              << " because it is closed." << std::endl;
}

void ClosedState::close(Incident& incident)
{
    std::cout << "Incident "
              << incident.getId()
              << " is already closed." << std::endl;
}

const char* ClosedState::getName() const
{
    return "Closed";
}