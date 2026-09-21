#include "domain/Incident.h"
#include "command/CommandInvoker.h"
#include "command/DispatchUnitCommand.h"
#include "command/SecureAreaCommand.h"
#include "command/EmergencyAlertCommand.h"

#include <iostream>

int main()
{
    Incident incident(
        "INC-001",
        "Medical Emergency",
        "Student Centre",
        "High"
    );

    std::cout << "\nInitial incident:\n";
    incident.printSummary();

    CommandInvoker invoker;

    DispatchUnitCommand dispatchCommand(incident, "Medical");
    invoker.setCommand(&dispatchCommand);

    std::cout << "\nExecuting dispatch command:\n";
    invoker.executeCommand();

    std::cout << "\nIncident after dispatch attempt:\n";
    incident.printSummary();

    std::cout << "\nAssessing incident:\n";
    incident.assess();

    std::cout << "\nDispatching medical unit again:\n";
    invoker.executeCommand();

    std::cout << "\nIncident after dispatch:\n";
    incident.printSummary();

    SecureAreaCommand secureCommand(incident);
    invoker.setCommand(&secureCommand);

    std::cout << "\nExecuting secure area command:\n";
    invoker.executeCommand();

    EmergencyAlertCommand alertCommand(
        incident,
        "Medical emergency reported at the Student Centre."
    );

    invoker.setCommand(&alertCommand);

    std::cout << "\nExecuting emergency alert command:\n";
    invoker.executeCommand();

    return 0;
}