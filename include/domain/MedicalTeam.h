#ifndef MEDICAL_TEAM_H
#define MEDICAL_TEAM_H

#include "ResponseComponent.h"

class MedicalTeam : public ResponseComponent {
    public:
        explicit MedicalTeam(const std::string& name);
        void handleIncident(Incident& incident) override;
        void coordinate(Incident& incident, const std::string& event) override;
};

#endif