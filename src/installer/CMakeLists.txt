project(citra-installer VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_AUTOMOC 1)

set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)

add_executable(citra-installer
main.cpp
main.h
mainwindow.ui)

target_link_libraries(citra-installer  PUBLIC
    Qt::Core
    Qt::Gui
    Qt::Widgets
)

if (MSVC)
    include(BundleTarget)
    bundle_target_in_place(citra-installer)
endif()