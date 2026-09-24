#ifndef FIRE_RESPONSE_STRATEGY_H
#define FIRE_RESPONSE_STRATEGY_H
 
#include "ResponseStrategy.h"
 
// Fire: security + facilities first, medical too if severity is high, secure area, then broadcast evacuation instruction.
class FireResponseStrategy : public ResponseStrategy
{
    public:
        bool execute(Incident& incident) override;
        const char* getName() const override;
};
 
#endif