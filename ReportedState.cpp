#include "ReportedState.h"
#include "Incident.h"
#include "AssessingState.h"

#include <iostream>

void ReportedState::assess(Incident& incident)
{
    std::cout << "Incident " << incident.getId()
              << " is now being assessed." << std::endl;

    incident.setState(new AssessingState());
}

bool ReportedState::dispatch(Incident& incident)
{
    std::cout << "Cannot dispatch incident "
              << incident.getId()
              << " before it has been assessed." << std::endl;

    return false;          
}

void ReportedState::resolve(Incident& incident)
{
    std::cout << "Cannot resolve incident "
              << incident.getId()
              << " before a response has been made." << std::endl;
}

void ReportedState::close(Incident& incident)
{
    std::cout << "Cannot close incident "
              << incident.getId()
              << " before it has been resolved." << std::endl;
}

const char* ReportedState::getName() const
{
    return "Reported";
}