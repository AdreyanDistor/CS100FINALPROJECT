[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-718a45dd9cf7e7f842a935f5ebbe5719a5e09af4491e668f4dbf3b35d5cca122.svg)](https://classroom.github.com/online_ide?assignment_repo_id=10940843&assignment_repo_type=AssignmentRepo)
 > As you complete each section you **must** remove the prompt text. Every *turnin* of this project includes points for formatting of this README so keep it clean and keep it up to date. 
 > Prompt text is any lines beginning with "\>"
 > Replace anything between \<...\> with your project specifics and remove angle brackets. For example, you need to name your project and replace the header right below this line with that title (no angle brackets). 
# Time Management App
 
 > Authors: \<[Adreyan Distor](https://github.com/AdreyanDistor)\> \<[Isabelle Celo](https://github.com/isabellecelo)\> \<[Nolan Vernon](https://github.com/slow-poker)\> \<[Ojasvi Godha](https://github.com/ogod1)\>

## Project Description
 > ### Why is it important or interesting to us? 
 >- With the mayhem of modern life, you need a way to keep track of your life. Time is limited, so it must be managed. Our project is an app that will help people, students in particular.
 > ### Technologies:
>- C++, Git, CMake, Vim, VSCode, imgui
> ### Inputs/Outputs:
 >- Inputs: Tasks that contain text and dates, reminders
 >- Outputs: Visual time-table of all your tasks. 
 > ### Features:
 >- Task creation
 >- Task lists
 >- Displaying, editing, and deleting tasks
 >- Classification tags 
 >- Time duration support
 >- Awards (for motivation) 
 
 > ## Phase II
## User Interface Specification
### Navigation Diagram
![Copy of Untitled Diagram drawio](https://user-images.githubusercontent.com/126242225/236991885-e1513c80-1619-4702-8411-f328d836b384.png)

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
![FinalProjUML drawio](https://github.com/cs100/final-project-scelo002-nvern003-adist003-ogodh001/assets/126242225/8f2938a5-180c-4af2-a226-90102b395ef4)

There are two main classes in which one of them includes a node struct. The TaskList class is a linked list of all the tasks. Each node is its own task object which is why there is the TaskNode struct. Each TaskNode has 10 private variables: title, day, month, year, a description, the tag, two booleans to mark them overdue and/or complete, the time its due, and a TaskNode refernece to the next node. There is also a function in the struct so we can output a TaskNode in the required format. Then there is the Awards class which defines an award object. Each award object has 3 private variables: its name, cost, and how many a user has "bought." We are not using a linked list to store the awards because it can easily be stored in a vector of award objects which will be initialized in the main function. 

 > ## Phase III
 > You will need to schedule a check-in for the second scrum meeting with the same reader you had your first scrum meeting with (using Calendly). Your entire team must be present. This meeting will occur on week 8 during lab time.
 
 > BEFORE the meeting you should do the following:
 > * Update your class diagram from Phase II to include any feedback you received from your TA/grader.
 > * Considering the SOLID design principles, reflect back on your class diagram and think about how you can use the SOLID principles to improve your design. You should then update the README.md file by adding the following:
 >   * A new class diagram incorporating your changes after considering the SOLID principles.
 >   * For each update in your class diagram, you must explain in 3-4 sentences:
 >     * What SOLID principle(s) did you apply?
 >     * How did you apply it? i.e. describe the change.
 >     * How did this change help you write better code?
 > * Perform a new sprint plan like you did in Phase II.
 > * You should also make sure that your README file (and Project board) are up-to-date reflecting the current status of your project and the most recent class diagram. Previous versions of the README file should still be visible through your commit history.
 
> During the meeting with your reader you will discuss: 
 > * How effective your last sprint was (each member should talk about what they did)
 > * Any tasks that did not get completed last sprint, and how you took them into consideration for this sprint
 > * Any bugs you've identified and created issues for during the sprint. Do you plan on fixing them in the next sprint or are they lower priority?
 > * What tasks you are planning for this next sprint.

 
 > ## Final deliverable
 > All group members will give a demo to the reader during lab time. ou should schedule your demo on Calendly with the same reader who took your second scrum meeting. The reader will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Project board.
 > * Make sure your README file and Project board are up-to-date reflecting the current status of your project (e.g. any changes that you have made during the project such as changes to your class diagram). Previous versions should still be visible through your commit history. 
 
 ## Screenshots
 > Screenshots of the input/output after running your application
 ## Installation/Usage
 > Instructions on installing and running your application
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 
