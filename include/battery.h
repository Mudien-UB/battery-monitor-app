#ifndef BATTERY_MONITOR_APP_BATTERY_H
#define BATTERY_MONITOR_APP_BATTERY_H

#include <windows.h>

class Battery {
private:
    bool getStatusInternal(SYSTEM_POWER_STATUS &sps) const {
        return GetSystemPowerStatus(&sps);
    }

public:
    bool getStatus(SYSTEM_POWER_STATUS &sps) const {
        return getStatusInternal(sps);
    }

    int getBatteryLifePercent() const {
        SYSTEM_POWER_STATUS sps{};
        if (!getStatus(sps)) return -1;
        return sps.BatteryLifePercent;
    }

    std::string getState() const {
        SYSTEM_POWER_STATUS sps{};
        if (!getStatus(sps)) return "Unknown";

        if (sps.BatteryFlag == 128) return "No Battery";
        if (sps.BatteryFlag == 8)   return "Charging";

        return (sps.ACLineStatus == 1) ? "Plugged" : "Discharging";
    }

    bool isNeedPlugIn(int threshold = 30) const {
        SYSTEM_POWER_STATUS sps{};
        if (!getStatus(sps)) return false;

        return (sps.BatteryLifePercent <= threshold) &&
               (sps.ACLineStatus == 0);
    }

    bool isNeedUnplugIn(int threshold = 50) const {
        SYSTEM_POWER_STATUS sps{};
        if (!getStatus(sps)) return false;

        return (sps.BatteryLifePercent >= threshold) &&
               (sps.ACLineStatus == 1);
    }
};

#endif //BATTERY_MONITOR_APP_BATTERY_H