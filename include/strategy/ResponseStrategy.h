#ifndef RESPONSE_STRATEGY_H
#define RESPONSE_STRATEGY_H

class Incident;

class ResponseStrategy
{
public:
    virtual ~ResponseStrategy() = default;

    virtual void respond(Incident& incident) = 0;
    virtual const char* getName() const = 0;
};

#endif