#ifndef SECURITY_TEAM_H
#define SECURITY_TEAM_H

#include "ResponseComponent.h"

class SecurityTeam : public ResponseComponent {
    public:
        explicit SecurityTeam(const std::string& name);

        void handleIncident(Incident& incident) override;
        void coordinate(Incident& incident, const std::string& event) override;
};

#endif