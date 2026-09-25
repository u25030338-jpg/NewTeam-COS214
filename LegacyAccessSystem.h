#ifndef LEGACY_ACCESS_SYSTEM_H
#define LEGACY_ACCESS_SYSTEM_H

#include <string>

class LegacyAccessSystem {
    private:
        std::string lastRestrictedZone;
    
    public:
        LegacyAccessSystem();
        int engageFullLockdown(const std::string& zoneCode);
        int releaseLockdown(const std::string& zoneCode);
        int SetPartialRestriction(const std::string& zoneCode, int level);
};

#endif