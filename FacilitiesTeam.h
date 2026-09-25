#ifndef FACILITIES_TEAM_H
#define FACILITIES_TEAM_H

#include "ResponseComponent.h" 

class FacilitiesTeam : public ResponseComponent {
    public: 
        explicit FacilitiesTeam(const std::string& name);

        void handleIncident(Incident& incident) override;
        void coordinate(Incident& incident, const std::string& event) override;

};

#endif