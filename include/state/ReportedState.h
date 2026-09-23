#ifndef REPORTED_STATE_H
#define REPORTED_STATE_H

#include "IncidentState.h"

class ReportedState : public IncidentState
{
public:
    void assess(Incident& incident) override;
    void dispatch(Incident& incident) override;
    void resolve(Incident& incident) override;
    void close(Incident& incident) override;

    const char* getName() const override;
};

#endif