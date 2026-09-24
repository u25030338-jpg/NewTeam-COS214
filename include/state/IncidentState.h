#ifndef INCIDENT_STATE_H
#define INCIDENT_STATE_H

class Incident;

class IncidentState
{
public:
    virtual ~IncidentState() = default;

    virtual void assess(Incident& incident) = 0;
    virtual bool dispatch(Incident& incident) = 0;
    virtual void resolve(Incident& incident) = 0;
    virtual void close(Incident& incident) = 0;

    virtual const char* getName() const = 0;
};

#endif