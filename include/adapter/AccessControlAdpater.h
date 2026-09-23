#ifndef ACCESS_CONTROL_ADAPTER_H
#define ACCESS_CONTROL_ADAPTER_H

#include "AccessControl.h"
class LegacyAccessSystem;

//this is the object adapter, it implements the AccessControl target interface by translating calls onto the incompatible LegacyAccessSystem setup.

class AccessControlAdapter : public AccessControl {
    private:
        LegacyAccessSystem& legacySystem;
        std::string toZoneCode(const std::string& area) const;
    
    public:
        explicit AccessControlAdapter(LegacyAccessSystem& legacy);
        bool lockArea(const std::string& area) override;
        bool unlockArea(const std::string& area) override;
        bool restrictArea(const std::string& area) override;
    
};

#endif