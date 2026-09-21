#ifndef EMERGENCY_RESPONSE_FACADE_H
#define EMERGENCY_RESPONSE_FACADE_H

#include <string>

class Incident;

class EmergencyResponseFacade
{
public:
    virtual ~EmergencyResponseFacade() = default;

    virtual bool startEmergencyResponse(Incident& incident) = 0;
    virtual bool resolveEmergency(Incident& incident) = 0;
};

#endif