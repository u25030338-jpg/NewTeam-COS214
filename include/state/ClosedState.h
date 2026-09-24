#ifndef CLOSED_STATE_H
#define CLOSED_STATE_H

#include "IncidentState.h"

class ClosedState : public IncidentState
{
public:
    void assess(Incident& incident) override;
    bool dispatch(Incident& incident) override;
    void resolve(Incident& incident) override;
    void close(Incident& incident) override;

    const char* getName() const override;
};

#endif