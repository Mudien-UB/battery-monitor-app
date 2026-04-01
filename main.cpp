#include <string>
#include <memory>

#include "include/notif.h"
#include "include/battery.h"

int main()
{
    try {
    std::shared_ptr<NotifHandler> handler = std::make_shared<NotifHandler>();
    std::shared_ptr<Battery> battery = std::make_shared<Battery>();

        while (true)
        {
            std::string title;
            std::string message;

            if (battery->isNeedPlugIn())
            {
                title = "Please plug charger";
                message = "Battery " + std::to_string(battery->getBatteryLifePercent()) +
                    "% | Status: " + battery->getState();
            }
            else if (battery->isNeedUnplugIn())
            {
                title = "Please unplug charger";
                message = "Battery " + std::to_string(battery->getBatteryLifePercent()) +
                    "% | Status: " + battery->getState();
            }

            if (!title.empty())
            {
                std::wstring wTitle(title.begin(), title.end());
                std::wstring wMessage(message.begin(), message.end());

                handler->showNotif(wTitle, wMessage);
            }

            std::this_thread::sleep_for(std::chrono::minutes(1));
        }
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
