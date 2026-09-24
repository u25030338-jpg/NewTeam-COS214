#include "AccessControlAdapter.h"
#include "LegacyAccessSystem.h"

#include <algorithm>
#include <cctype>

AccessControlAdapter::AccessControlAdapter(LegacyAccessSystem& legacy) 
    : legacySystem(legacy){}


bool AccessControlAdapter::lockArea(const std::string& area){
    std::string zoneCode = toZoneCode(area);
    int status = legacySystem.engageFullLockdown(zoneCode);
    return status ==0;
}

bool AccessControlAdapter::unlockArea(const std::string& area){
    std::string zoneCode = toZoneCode(area);
    int status = legacySystem.releaseLockdown(zoneCode);
    return status ==0;
}

bool AccessControlAdapter::restrictArea(const std::string& area){
    std::string zoneCode = toZoneCode(area);
    int status = legacySystem.SetPartialRestriction(zoneCode, 1);
    return status ==0;
}

std::string AccessControlAdapter::toZoneCode(const std::string& area) const {
    std::string zoneCode = area;
    std::transform(zoneCode.begin(), zoneCode.end(), zoneCode.begin(), [] (unsigned char c) {return std::toupper(c); });

    zoneCode += "-ZONE";
    return zoneCode;
}