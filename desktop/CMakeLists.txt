cmake_minimum_required(VERSION 3.21)

project(SayItDesktop VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.10 REQUIRED COMPONENTS Quick Test)

qt_standard_project_setup(REQUIRES 6.10)

qt_add_executable(sayit-desktop
    src/main.cpp
)

qt_add_qml_module(sayit-desktop
    URI SayIt
    VERSION 1.0
    QML_FILES
        qml/Main.qml
        SOURCES src/AppController.h
        SOURCES src/AppController.cpp
        SOURCES src/VoiceClient.h
        SOURCES src/MockVoiceClient.h
        SOURCES src/MockVoiceClient.cpp
)

set_target_properties(sayit-desktop PROPERTIES
    WIN32_EXECUTABLE TRUE
)

target_include_directories(sayit-desktop PRIVATE
    src
)

target_link_libraries(sayit-desktop PRIVATE
    Qt6::Quick
)


#Tests
enable_testing()

qt_add_executable(tst_appcontroller
    tests/tst_appcontroller.cpp
    src/AppController.h
    src/AppController.cpp
    src/VoiceClient.h
)

target_include_directories(tst_appcontroller PRIVATE src)

target_link_libraries(tst_appcontroller PRIVATE
    Qt6::Test
    Qt6::Qml
)

add_test(NAME tst_appcontroller COMMAND tst_appcontroller)