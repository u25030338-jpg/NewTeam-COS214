#ifndef RESPONSE_COMPONENT_H
#define RESPONSE_COMPONENT_H

#include <string>
 class Mediator;
 class Incident;

 class ResponseComponent {
    protected:
        std::string name;
        Mediator* mediator;

    public:
        explicit ResponseComponent(const std::string& name);
        virtual ~ResponseComponent() = default;

        void setMediator(Mediator* m);
        const std::string& getName() const;

        //own domain behaviour, ends by calling mediator->notify(this, incodent, "<EVENT")
        virtual void handleIncident(Incident& incident) =0;
        
        //reaction when mediator calls it in response to some other colleague's event
        virtual void coordinate(Incident& incident, const std::string& event) = 0;
};

#endif