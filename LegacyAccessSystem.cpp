#include "LegacyAccessSystem.h"
#include <iostream> 

LegacyAccessSystem::LegacyAccessSystem()
    :lastRestrictedZone(""){}

int LegacyAccessSystem::engageFullLockdown(const std::string& zoneCode){
    std::cout << "[LEGACY] Engaging full lockdown on zone " << zoneCode << "." << std::endl;

    lastRestrictedZone = "";
    return 0;
}

int LegacyAccessSystem::releaseLockdown(const std::string& zoneCode) {
    std::cout << "[LEGACY] Releasing lockdown on zone " << zoneCode << "." << std::endl;

    lastRestrictedZone = "";
    return 0;
}

int LegacyAccessSystem::SetPartialRestriction(const std::string& zoneCode, int level){
    if(zoneCode == lastRestrictedZone){
        std::cout <<"[LEGACY] Zone " << zoneCode << " is already restricted -- rejecting duplicate restriction request." << std::endl;

        return 1;
    }

    std::cout << "[LEGACY] setting partial restriction (level " << level << ") on zone " << zoneCode << "." << std::endl;

    lastRestrictedZone = zoneCode;
    return 0;
}