add_library(simpleLibrary
  TaskList.cpp
  AwardList.cpp
  TaskListGUI.cpp
  AwardListGUI.cpp
)

find_library(M_LIB m)
target_link_libraries(simpleLibrary ${M_LIB})

add_executable(Time_Management.exe
  main.cpp
  TaskList.cpp
  AwardList.cpp
  TaskListGUI.cpp
  AwardListGUI.cpp
)

