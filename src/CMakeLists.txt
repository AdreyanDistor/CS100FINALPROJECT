add_library(simpleLibrary
TaskList.cpp
AwardList.cpp
)

find_library(M_LIB m)
target_link_libraries(simpleLibrary ${M_LIB})

CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

ADD_EXECUTABLE(Time_Management.exe
	main.cpp
	TaskList.cpp
    AwardList.cpp
	AwardListGUI.cpp
)



