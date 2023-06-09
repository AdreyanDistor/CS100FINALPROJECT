[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-718a45dd9cf7e7f842a935f5ebbe5719a5e09af4491e668f4dbf3b35d5cca122.svg)](https://classroom.github.com/online_ide?assignment_repo_id=10940843&assignment_repo_type=AssignmentRepo)
 > As you complete each section you **must** remove the prompt text. Every *turnin* of this project includes points for formatting of this README so keep it clean and keep it up to date. 
 > Prompt text is any lines beginning with "\>"
 > Replace anything between \<...\> with your project specifics and remove angle brackets. For example, you need to name your project and replace the header right below this line with that title (no angle brackets). 
# Time Management App
 
 > Authors: [Adreyan Distor](https://github.com/AdreyanDistor) [Isabelle Celo](https://github.com/isabellecelo) [Nolan Vernon](https://github.com/slow-poker) [Ojasvi Godha](https://github.com/ogod1)

## Project Description
This program is a terminal based task manager. The user is able to view their current tasks, in order of date, and accumulate points according to the number of tasks they mark as complete. Their points can be used to purchase awards that they create themselves from the award shop. Each task has a name, deadline, tag, and description. The number of points the user gains from marking a task as complete corresponds to the specific tag the task is assigned. If the user were to complete a task that is marked overdue, they would only gain half the number of points. The user is also able to filter their task list according to today’s tasks and tags.
 ### Why is it important or interesting to us? 
This project is important to our group since we are all students who thrive off organization. Although we have many other resources to keep track of our tasks, we wanted to create a program that implemented a system to encourage productivity and discourage procrastination. The award shop/point system will give the user motivation to complete their tasks in order to reward themselves and the overdue system that decreases the number of points the user gains may encourage the user to complete their tasks before the deadline. 
### Technologies:
C++ - This project will be programmed primarily using C++ 11.

Visual Studio Code - This is a text and code editor that we will use to write and test code in Windows/Mac.

Git - Git allows us to make changes to the GitHub repository that houses our project.

Valgrind - Valgrind is a Linux tool which detects errors and memory management bugs in C++ code. We will use it to fix memory leaks in our code.

Github - GitHub is a version control system that allows multiple users to share and edit code together online, as well as manage the development of the project with a collection of Agile tools. Github allows for the creation of task boards to sort features into “To-do, doing, done” categories to organize the implementation of program features between multiple group members.

CMake - CMake is a Linux tool which allows us to compile C++ code into executable programs that will run in Linux.

Google Test Framework - This is a collection of tools made by Google which will allow us to create and run test cases for our project code. This will allow us to test the functionality and edge cases for our program and ensure that all program inputs have the intended outputs.

### Inputs/Outputs:
Inputs: The user will be able to create the tasks with specs including: task name, deadline, tag, and description. They will also be able to create awards in the awards shop with an award name and price.

Outputs: The user will be able to see an organized list of all their tasks they added in order of date (by default) or based on any filters they apply. They also will be able to view the award shop that houses any awards they create.

## User Interface Specification
### Navigation Diagram
![Navigation Diagram drawio (1)](https://github.com/cs100/final-project-scelo002-nvern003-adist003-ogodh001/assets/117056281/655814ca-66a0-4fa2-93bd-7b9449ca8d60)



### Screen Layouts
<img width="835" alt="Screenshot 2023-05-08 at 6 33 36 PM" src="https://user-images.githubusercontent.com/117539128/236972337-1c39eed3-2959-4157-8156-009154182e8d.png">

<img width="827" alt="Screenshot 2023-05-08 at 6 34 35 PM" src="https://user-images.githubusercontent.com/117539128/236972348-00f2e80c-ed56-4cc6-98d7-498a4813fd52.png">

Basic Homescreen:
On the main screen, you are able to see the main functionalities of the application. The homescreen presents the (master) To-Do-List with each task listed with a due date and its tag, the filtering buttons, the undo button, the points the user has collected, and the shop icon. Clicking the circle to the left of a task will delete the task from the To-Do-List, add the designated number of points to the points count, and bring the user to the Completed Task Message Screen. Pressing the plus sign at the bottom of the To-Do-List would bring the user to the Editing Task Screen that will allow them to add a new task. The undo button will allow for a previously deleted task to be restored. Each filter button (date, today, overdue, and ALL) will allow the user to order the task list by date (ascending), only display tasks due that day, highlight the overdue tasks in red, and choose which tasks of a certain tag to display. The filters are shown as enabled if they are circled in red. The user may also click on any task to open up the Editing Task Screen to either edit or read the description of the task. Clicking on the icon in the bottom right will bring the user to the shop. 

Completed Task Message Screen:
This screen is accessable once the user marks a task as complete. The screen presents an animated gif of the application's dinosaur mascot, and tells the user how many points they received from finishing the task. The user is able to exit by simply clicking any part of the screen. 

Editing Task Screen:
The editing task screen is accessable by either clicking the "+" button at the bottom of the To-Do-List to edit a task or by clicking on any existing task. The screen presents 2 textboxes that are used to name the task and add a description to the task. The date and tag textboxes will open drop-down menus to fill those data in. The user can exit the screen by clicking the black "X" which will either cancel the formation of a new task or the checkmark at the bottom which will add the new task to the list. 

Awards Shop Screen:
The awards shop screen is accessed by clicking the shop icon in the bottom right corner of the Basic Home Screen. The list of every existing award is presented. The user can buy or use the awards using the buttons to the left of the list, or add a new award by clicking the "+" at the bottom of the list. The user can exit the shop by clicking the home button in the bottom right corner of the screen which will take them back to the Home Screen.

Adding Awards Screen:
This screen is accessed by clicking the "+" at the bottom of the awards list in the Awards Shop Screen. A pop-up opens with two textboxes: one for the awards name and another for the price of the awards. The user may exit this screen by either clicking the "X" in the left corner to cancel the formation of a new task or clicking the checkmark at the bottom right which will confirm the formation of a new task. 

### Class Diagram
![FinalProjUML drawio (1)](https://github.com/cs100/final-project-scelo002-nvern003-adist003-ogodh001/assets/126242225/4afd006d-165d-4cde-b610-9a12e2bbd5cc)

There are two main classes in which each includes a node struct. First there is the TaskList class with a TaskNode struct. Each node is its own task object which is why there is the struct. Each TaskNode has 8 variables: title, day, month, year, a description, the tag, a boolean to mark them overdue, and a TaskNode refernece to the next node. There are also a functions that are a mix of modifiers and display functions. The modifiers are there to help edit the variables and make it easier to write unit tests. The display functions are helper functions that output certain data in a desired format. The TaskList class itself has 3 protected variables which are 3 TaskNode* references to the head, tail, and the most recently deleted node. There a lot of functions that allow the user to interact with the list. There is also a subclass, TaskListGUI, which focuses on the display aspect of the list. The AwardList class is strucutured in a similar way. The Awards class defines an award object. Each award object has 3 private variables: its name, cost, and how many a user has "bought." We are not using a linked list to store the awards because it can easily be stored in a vector of award objects which will be initialized in the main function. Just like the TaskList class there are multiple public functions that allow for different types of interactions. There are 2 protected variables in this class: a vector that holds Award object references and an integer for the total points the user has. There is also a subclass that has 2 functions that focus on display. 

 > ## Phase III
 > TaskListGUI: We added TaskListGUI to apply the Single Responsibility Principle, and the Liskov Principle. We applied it by moving any functions that display information about TaskLists into TaskListGUI, meaning the TaskList's class only job is to manage information, while TaskListGUI's only job is to display, and let the user interact with information related to TaskList. The Liskov principle was applied because TaskListGUI can be used as a TaskList object.
 > AwardListGUI: We added TaskListGUI to apply the Single Responsibility Principle, and the Liskov Principle. We applied it by moving any functions that display information about AwardLists into AwardListGUI, meaning the AwardList's class only job is to manage information, while TaskListGUI's only job is to display, and let the user interact with information related to AwardList. The Liskov principle was applied because AwardList can replace a AwardList object.

 > ## Final deliverable
 > All group members will give a demo to the reader during lab time. ou should schedule your demo on Calendly with the same reader who took your second scrum meeting. The reader will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Project board.
 > * Make sure your README file and Project board are up-to-date reflecting the current status of your project (e.g. any changes that you have made during the project such as changes to your class diagram). Previous versions should still be visible through your commit history. 
 
 ## Screenshots
 ![image](https://github.com/cs100/final-project-scelo002-nvern003-adist003-ogodh001/assets/46554183/ee2239fe-6194-4671-91f0-a1ef1d5677fd)
 ![image](https://github.com/cs100/final-project-scelo002-nvern003-adist003-ogodh001/assets/46554183/edccd090-66e2-4e41-9e54-5547658b22e7)
![image](https://github.com/cs100/final-project-scelo002-nvern003-adist003-ogodh001/assets/46554183/1d6e2f49-da44-42a7-9a79-b42d5cdb10e3)
![image](https://github.com/cs100/final-project-scelo002-nvern003-adist003-ogodh001/assets/46554183/1d52b5a9-e8f6-4437-8209-1a0c56308b07)
![image](https://github.com/cs100/final-project-scelo002-nvern003-adist003-ogodh001/assets/46554183/53982fb1-52fc-4007-810e-d7bd75cbcf53)
![image](https://github.com/cs100/final-project-scelo002-nvern003-adist003-ogodh001/assets/46554183/4e58e875-fa4c-46f5-8c09-9fc2ce2dafc3)

## Installation/Usage
 > Instructions on installing and running your application
 
 ## Testing
 > Our project was tested using the googletest submodule to generate a test file using "cmake ."->"make"->"./runTests" that contains 74 tests. We also used Valgrind to check that we were memcheck clean using "./valgrind --leak-check=yes". We also had to run some visual tests to check the GUI's spacing and other small details.
 
