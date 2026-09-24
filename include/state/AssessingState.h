#ifndef ASSESSING_STATE_H
#define ASSESSING_STATE_H

#include "IncidentState.h"

class AssessingState : public IncidentState
{
public:
    void assess(Incident& incident) override;
    void dispatch(Incident& incident) override;
    void resolve(Incident& incident) override;
    void close(Incident& incident) override;

    const char* getName() const override;
};

#endif