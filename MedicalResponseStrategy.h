#ifndef MEDICAL_RESPONSE_STRATEGY_H
#define MEDICAL_RESPONSE_STRATEGY_H
 
#include "ResponseStrategy.h"
 
// Medical: medical unit first, security added if severity is high, secure area, then send alert.
class MedicalResponseStrategy : public ResponseStrategy
{
    public:
        bool execute(Incident& incident) override;
        const char* getName() const override;
};
 
#endif