#include "command/CommandInvoker.h"

CommandInvoker::CommandInvoker()
    : command(nullptr)
{
}

void CommandInvoker::setCommand(Command* newCommand)
{
    command = newCommand;
}

void CommandInvoker::executeCommand()
{
    if (command != nullptr)
    {
        command->execute();
    }
}