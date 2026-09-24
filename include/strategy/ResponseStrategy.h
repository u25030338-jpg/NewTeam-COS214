#ifndef RESPONSE_STRATEGY_H
#define RESPONSE_STRATEGY_H

class Incident;
class Command;

//Strategy: interchangeable response algorithms for different incident types.
class ResponseStrategy
{
    public:
        virtual ~ResponseStrategy() = default;
        virtual bool execute(Incident& incident) = 0;
        virtual const char* getName() const = 0;
    protected:
        bool prepareIncident(Incident& incident);
        void run(Command& command);
        static bool isHighSeverity(const Incident& incident);       //Static: same across all instances of class
};

#endif