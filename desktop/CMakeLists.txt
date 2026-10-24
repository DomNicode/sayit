cmake_minimum_required(VERSION 3.21)

project(SayItDesktop VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.10 REQUIRED COMPONENTS Quick)

qt_standard_project_setup(REQUIRES 6.10)

qt_add_executable(sayit-desktop
    src/main.cpp
)

qt_add_qml_module(sayit-desktop
    URI SayIt
    VERSION 1.0
    QML_FILES
        qml/Main.qml
)

set_target_properties(sayit-desktop PROPERTIES
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(sayit-desktop PRIVATE
    Qt6::Quick
)