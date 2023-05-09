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
>- C++, Git, CMake, Vim, VSCode, raylib, imgui
> ### Inputs/Outputs:
 >- Inputs: Tasks that contain text and dates, reminders
 >- Outputs: Visual time-table of all your tasks. 
 > ### Features:
 >- Task creation
 >- Task lists
 >- Displaying, editing, and deleting tasks
 >- Priority tags (None, Low, Medium, Urgent)
 >- Limited customization (Change of button colors)
 >- Time duration support
 > ## Phase II
 > In addition to completing the "User Interface Specification" and "Class Diagram" sections below, you will need to:
 > * Create an "Epic" (note) for each feature. Place these epics in the `Product Backlog` column
 > * Complete your first *sprint planning* meeting to plan out the next 7 days of work.
 >   * Break down the "Epics" into smaller actionable user stories (i.e. smaller development tasks). Convert them into issues and assign them to team members. Place these in the `TODO` column.
 >   * These cards should represent roughly 7 days worth of development time for your team. Then, once the sprint is over you should be repeating these steps to plan a new sprint, taking you until your second scrum meeting with the reader in phase III.
 > * Schedule two check-ins using Calendly. You need to pick both time slots during your lab on week 6. Your entire team must be present for both check-ins.
 >   * The first check-in needs to be scheduled with your lab TA. During that meeting, you will discuss your project design/class diagram from phase II.
 >   * The second check-in should be scheduled with a reader. During that meeting you will discuss:
 >     * The tasks you are planning for the first sprint
 >     * How work will be divided between the team members
## User Interface Specification
 > Include a navigation diagram for your screens and the layout of each of those screens as desribed below. For all the layouts/diagrams, you can use any tool such as PowerPoint or a drawing program. (Specification requirement is adapted from [this template](https://redirect.cs.umbc.edu/~mgrass2/cmsc345/Template_UI.doc))

### Navigation Diagram
> Draw a diagram illustrating how the user can navigate from one screen to another. Here is an [example](https://creately.com/diagram/example/ikfqudv82/user-navigation-diagram-classic?r=v). It can be useful to label each symbol that represents a screen so that you can reference the screens in the next section or the rest of the document if necessary. Give a brief description of what the diagram represents.

### Screen Layouts
> Include the layout of each of your screens. The layout should describe the screen’s major components such as menus and prompts for user inputs, expected output, and buttons (if applicable). Explain what is on the layout, and the purpose of each menu item, button, etc. If many screens share the same layout, start by describing the general layout and then list the screens that will be using that layout and the differences between each of them.

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









## Class Diagram
 > Include a **class diagram(s)** for your project and a **description** of the diagram(s). Your class diagram(s) should include all the main classes you plan for the project. This should be in sufficient detail that another group could pick up the project this point and successfully complete it. Use proper UML notation (as discussed in the course slides).
 
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
 
