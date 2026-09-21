#include "state/AssessingState.h"
#include "domain/Incident.h"
#include "state/RespondingState.h"

#include <iostream>

void AssessingState::assess(Incident& incident)
{
    std::cout << "Incident " << incident.getId()
              << " is already being assessed." << std::endl;
}

void AssessingState::dispatch(Incident& incident)
{
    std::cout << "Incident " << incident.getId()
              << " is now being responded to." << std::endl;

    incident.setState(new RespondingState());
}

void AssessingState::resolve(Incident& incident)
{
    std::cout << "Cannot resolve incident "
              << incident.getId()
              << " before a response has been made." << std::endl;
}

void AssessingState::close(Incident& incident)
{
    std::cout << "Cannot close incident "
              << incident.getId()
              << " before it has been resolved." << std::endl;
}

const char* AssessingState::getName() const
{
    return "Assessing";
}