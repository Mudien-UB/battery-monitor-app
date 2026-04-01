#ifndef BATTERY_MONITOR_APP_NOTIF_H
#define BATTERY_MONITOR_APP_NOTIF_H

#include <iostream>
#include <memory>
#include <stdexcept>
#include <thread>

#include "WinToast/wintoastlib.h"

using namespace WinToastLib;

class ToastHandler : public IWinToastHandler {
public:
    ToastHandler() = default;

    void toastActivated() const override {
        std::wcout << L"Toast diklik!" << std::endl;
        delete this;
    }

    void toastActivated(int actionIndex) const override {
        std::wcout << L"Action " << actionIndex << L" diklik!" << std::endl;
        delete this;
    }

    void toastActivated(std::wstring response) const override {
        std::wcout << L"Input: " << response << std::endl;
        delete this;
    }

    void toastDismissed(WinToastDismissalReason) const override {
        std::wcout << L"Toast ditutup." << std::endl;
        delete this;
    }

    void toastFailed() const override {
        std::wcerr << L"Toast gagal ditampilkan." << std::endl;
        delete this;
    }
};

class NotifHandler {
private:
    INT64 currentToastId = -1;

public:
    NotifHandler() {
        WinToast::instance()->setAppName(L"MyApp");
        WinToast::instance()->setAppUserModelId(
            WinToast::configureAUMI(L"MyCompany", L"MyApp", L"MyProduct", L"1.0")
        );

        if (!WinToast::instance()->initialize()) {
            throw std::runtime_error("Gagal inisialisasi WinToast!");
        }
    }

    void showNotif(const std::wstring& title, const std::wstring& text) {
        if (currentToastId >= 0) {
            WinToast::instance()->hideToast(currentToastId);
            currentToastId = -1;
        }

        WinToastTemplate tmpl(WinToastTemplate::Text02);
        tmpl.setTextField(title, WinToastTemplate::FirstLine);
        tmpl.setTextField(text, WinToastTemplate::SecondLine);

        auto* handler = new ToastHandler();

        currentToastId = WinToast::instance()->showToast(tmpl, handler);

        if (currentToastId < 0) {
            delete handler;
            throw std::runtime_error("Gagal menampilkan toast!");
        }

        std::this_thread::sleep_for(std::chrono::seconds(5));

    }

    void closeNotif() {
        if (currentToastId >= 0) {
            WinToast::instance()->hideToast(currentToastId);
            currentToastId = -1;
        }
    }

};

#endif //BATTERY_MONITOR_APP_NOTIF_H