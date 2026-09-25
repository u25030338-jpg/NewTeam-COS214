#ifndef ACCESS_CONTROL_H
#define ACCESS_CONTROL_H

#include <string>

class AccessControl
{
public:
    virtual ~AccessControl() = default;

    virtual bool lockArea(const std::string& area) = 0;
    virtual bool unlockArea(const std::string& area) = 0;
    virtual bool restrictArea(const std::string& area) = 0;
};

#endif