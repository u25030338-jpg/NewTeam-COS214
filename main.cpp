#include "domain/Incident.h"

#include "adapter/AccessControlAdapter.h"
#include "adapter/LegacyAccessSystem.h"

#include "domain/SecurityTeam.h"
#include "domain/MedicalTeam.h"
#include "domain/FacilitiesTeam.h"
#include "domain/CommunicationService.h"

#include "mediator/EmergencyMediator.h"

#include "facade/EmergencyResponseFacade.h"

#include <iostream>

int main()
{
    // The driver code owns all of the response components and subsystems.
    SecurityTeam security("Campus Security");
    MedicalTeam medical("Campus Medical Team");
    FacilitiesTeam facilities("Campus Facilities");
    CommunicationService comms;

    // Legacy access system is adapted to the AccessControl interface.
    LegacyAccessSystem legacyAccess;
    AccessControlAdapter accessControl(legacyAccess);

    // The mediator coordinates the response components.
    EmergencyMediator mediator(
        &security,
        &medical,
        &facilities,
        &comms,
        &accessControl
    );

    // Connect the response components to the mediator.
    security.setMediator(&mediator);
    medical.setMediator(&mediator);
    facilities.setMediator(&mediator);

    // Facade provides the high-level entry point for emergency response.
    EmergencyResponseFacade facade(
        mediator,
        accessControl,
        comms
    );

    // ------------------------------------------------------------
    // STORY 1: MEDICAL EMERGENCY
    // ------------------------------------------------------------

    std::cout << "\n========================================" << std::endl;
    std::cout << " STORY 1: MEDICAL EMERGENCY" << std::endl;
    std::cout << "========================================" << std::endl;

    Incident medicalIncident(
        "INC-001",
        "Medical Emergency",
        "Student Centre",
        "High"
    );

    medicalIncident.printSummary();

    std::cout << "\nStarting medical emergency response..." << std::endl;

    facade.respondToIncident(medicalIncident);

    std::cout << "\nMedical incident after response:" << std::endl;
    medicalIncident.printSummary();

    std::cout << "\nStanding down medical emergency..." << std::endl;

    facade.resolveIncident(medicalIncident);

    std::cout << "\nMedical incident after stand-down:" << std::endl;
    medicalIncident.printSummary();


    // ------------------------------------------------------------
    // STORY 2: FIRE / EVACUATION
    // ------------------------------------------------------------

    std::cout << "\n========================================" << std::endl;
    std::cout << " STORY 2: FIRE / EVACUATION" << std::endl;
    std::cout << "========================================" << std::endl;

    Incident fireIncident(
        "INC-002",
        "Fire",
        "Engineering Building",
        "Critical"
    );

    fireIncident.printSummary();

    std::cout << "\nStarting fire emergency response..." << std::endl;

    facade.respondToIncident(fireIncident);

    std::cout << "\nFire incident after response:" << std::endl;
    fireIncident.printSummary();

    std::cout << "\nStanding down fire emergency..." << std::endl;

    facade.resolveIncident(fireIncident);

    std::cout << "\nFire incident after stand-down:" << std::endl;
    fireIncident.printSummary();


    // ------------------------------------------------------------
    // FAILURE / INVALID OPERATION TEST
    // ------------------------------------------------------------

    std::cout << "\n========================================" << std::endl;
    std::cout << " INVALID OPERATION TEST" << std::endl;
    std::cout << "========================================" << std::endl;

    Incident unknownIncident(
        "INC-003",
        "Unknown Incident",
        "Library",
        "Medium"
    );

    std::cout << "\nAttempting response for unsupported incident type..." << std::endl;

    facade.respondToIncident(unknownIncident);

    return 0;
}