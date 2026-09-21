#ifndef MEDIATOR_H
#define MEDIATOR_H

class ResponseComponent;
class Incident;

class Mediator
{
public:
    virtual ~Mediator() = default;

    virtual void notify(ResponseComponent* sender,
                        Incident& incident,
                        const char* event) = 0;
};

#endif