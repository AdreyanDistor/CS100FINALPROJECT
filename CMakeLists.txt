CMAKE_MINIMUM_REQUIRED(VERSION 3.2)

project(TimeManagement)

ADD_SUBDIRECTORY(googletest)

ADD_EXECUTABLE(runTests
    test/test.cpp
    src/TaskList.cpp
    src/TaskListGUI.cpp
    src/AwardList.cpp
    src/AwardListGUI.cpp
)

ADD_EXECUTABLE(TimeManager
    src/main.cpp
    src/TaskList.cpp
    src/TaskListGUI.cpp
    src/AwardList.cpp
    src/AwardListGUI.cpp
)

TARGET_LINK_LIBRARIES (runTests gtest gtest_main)