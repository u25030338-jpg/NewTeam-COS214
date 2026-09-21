#ifndef COMMAND_INVOKER_H
#define COMMAND_INVOKER_H

#include "command/Command.h"

class CommandInvoker
{
private:
    Command* command;

public:
    CommandInvoker();

    void setCommand(Command* newCommand);
    void executeCommand();
};

#endif