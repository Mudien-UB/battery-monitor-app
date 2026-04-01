cmake_minimum_required(VERSION 3.10)
project(battery_monitor_app)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_WIN32_EXECUTABLE ON)

add_executable(battery_monitor_app
        main.cpp
        lib/WinToast/wintoastlib.cpp
        include/notif.h
        include/battery.h
)

target_include_directories(battery_monitor_app PRIVATE lib)

target_link_libraries(battery_monitor_app PRIVATE
        ole32
        shell32
        uuid
)
target_link_options(battery_monitor_app PRIVATE "/ENTRY:mainCRTStartup")
