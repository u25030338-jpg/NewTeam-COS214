#ifndef RESPONDING_STATE_H
#define RESPONDING_STATE_H

#include "state/IncidentState.h"

class RespondingState : public IncidentState
{
public:
    void assess(Incident& incident) override;
    void dispatch(Incident& incident) override;
    void resolve(Incident& incident) override;
    void close(Incident& incident) override;

    const char* getName() const override;
};

#endif