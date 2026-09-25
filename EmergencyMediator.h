#ifndef EMERGENCY_MEDIATOR_H
#define EMERGENCY_MEDIATOR_H

#include "Mediator.h"

class SecurityTeam;
class MedicalTeam;
class FacilitiesTeam;
class CommunicationService;
class AccessControl;

class EmergencyMediator : public Mediator {
    private:
        SecurityTeam* security; //driver code owns this
        MedicalTeam* medical;
        FacilitiesTeam* facilities;
        CommunicationService* comms;
        AccessControl* accessControl; // the adpater, referred to via the target interface

    public:
        EmergencyMediator(SecurityTeam* security, MedicalTeam* medical, FacilitiesTeam* facilities, CommunicationService* comms, AccessControl* accessControl);
    ~EmergencyMediator() override = default;
    void notify(ResponseComponent* sender, Incident& incident, const char* event) override;

};

#endif
