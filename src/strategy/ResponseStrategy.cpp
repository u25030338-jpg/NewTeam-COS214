#include "ResponseStrategy.h"
#include "Incident.h"
#include "IncidentState.h"
#include "Command.h"
#include "CommandInvoker.h"
 
#include <iostream>
#include <string>
 
bool ResponseStrategy::prepareIncident(Incident& incident)
{
    const std::string state = incident.getState()->getName();
 
    if (state == "Reported")
    {
        std::cout << "[STRATEGY] Incident " << incident.getId() << " is still Reported, assessing before responding." << std::endl;
        incident.assess();
        return true;
    }
 
    if ((state == "Assessing") || (state == "Responding"))
    {
        return true;
    }
 
    std::cout << "[STRATEGY] Cannot run " << getName() << " for incident " << incident.getId() << ": incident is " << state << "." << std::endl;
    return false;
}
 
void ResponseStrategy::run(Command& command)
{
    CommandInvoker invoker;
    invoker.setCommand(&command);
    invoker.executeCommand();
}
 
bool ResponseStrategy::isHighSeverity(const Incident& incident)
{
    // Manual lowercase so "High", "HIGH" and "high" all match
    std::string s = incident.getSeverity();
    for (std::string::size_type i = 0; i < s.size(); ++i)
    {
        if ((s[i] >= 'A') && (s[i] <= 'Z'))
        {
            s[i] = static_cast<char>(s[i] - 'A' + 'a');
        }
    }
    return s == "high" || s == "critical";
}