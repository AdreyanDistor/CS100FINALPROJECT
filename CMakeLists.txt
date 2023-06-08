CMAKE_MINIMUM_REQUIRED(VERSION 3.2)

project(TimeManagement)

ADD_SUBDIRECTORY(test/googletest)

ADD_EXECUTABLE(run
    test/test.cpp
    src/TaskList.cpp
    src/TaskListGUI.cpp
    src/AwardList.cpp
    src/AwardListGUI.cpp
)

TARGET_LINK_LIBRARIES (run gtest gtest_main)