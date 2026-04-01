# Battery Monitor  (C++ Windows)
[![License](https://img.shields.io/badge/license-MIT-blue.svg)](LICENSE)


A lightweight background application that monitors battery status and shows notifications based on charge level.

## ✨ Features

- 🔴 Notify when battery is low (< 30%) and not charging
- 🟢 Notify when battery is almost full (> 96%) and charging
- 🔕 Runs silently in background (no console window)
- ⚡ Lightweight and minimal CPU usage

---

## 🛠️ Tech Stack

- C++20
- WinAPI (GetSystemPowerStatus)
- WinToast (Windows notification)
- CMake

---

## ⚙️ How It Works

The app continuously checks battery status:

- If battery < 30% and unplugged → show "Plug charger"
- If battery > 96% and plugged → show "Unplug charger"

checked time period 1 minute

---

## 🚀 Build & Run

as usual

---

## 🤝 Contributing

This project is still in early development and open for improvements.

I would love to collaborate and grow this project together with others.  
If you have ideas, improvements, or want to add new features, feel free to contribute.

You can start by:
- Opening an issue (bug report / feature request)
- Submitting a pull request
- Improving documentation

[see details...](CONTRIBUTING.md)

Let’s build something useful together 🚀

---

## 💡 Vision

The goal of this project is to evolve into a more complete battery monitoring tools for Windows, including:

- Better notification system
- Customizable battery thresholds
- System tray integration
- Lightweight and efficient background service

Contributions in any form are highly appreciated 🙌

---

## 📄 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

