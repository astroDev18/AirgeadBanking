# AirgeadBanking
## Purpose
My submission for Project 5-1 at SNHU. The purpose of the project was to develop a working application that would allow students 
to track their financial investments and predict how they would perform. 

### What the requirements were:
Airjead Bankings program input requirements were:
- **Initial Investment Amount** - The starting amount of your investment (a positive real number).
- **Monthly Deposit** - The amount you plan on contributing to the growth of your investment each month.
- **Annual Interest (Compounded)** - Interest that is added to the principal sum of your investment and its previously accumulated interest. 
- **Number of Years** - The number of years your investment has to grow.
- **A way to view the data** - An ability to "Press any key to continue..." so user can see their results.

After the program has recieved the user data that has been input, it should calculate and display two reports. 
- The first report should display the year-end balances and the year-end interest if no additional monthly deposits are made.
- The second report should show the year end earned interest based on the monthly deposit value the user input. 

Finally, the user is able to test out different program inputs to see how their investments would perform. 

## What I did well
In this project I felt good about how I handled the menu loop to create a smooth and repeatable interface for the user to interact with. 
It handled all possible errors in input and loops until the user is ready to exit.

## Where could I enhance the code further?
In the future, I could add a greater detailed investment plan. I could intake more variables, like monthly expenses, and generate seperate graphs
for these scenarios.

## What pieces of the code did I find most challenging to write?
For me the most difficult areas was generating the table and calculating the financial formulas. I had to figure out how to take the variables I had
and use them to find the correct outputs. 
Afterwards I had to integrate them into the table to generate a financial report, which required me to format the output and ensure
the table worked under all scenarios. 

## What skills from this project do I think will be transferable to future ones?
One skill I significantly developed was the ability to create properly functioning menu loops and handle calling indivisual functions in each scenario.
This was a tricky step to competently develop, and I felt I created a good working example in the end. Due to the looping nature of it, you have to ensure
it handles all cases without terminating the program until the user decides to exit.

## How did I make the project readable, maintainable, and adaptable?
In my development I wrote comments above all my functions and throughout my program to allow others to easily pick up on my programs functionality.
I compartmentalized sections of the code so the code can easily be refactored and updated in the future.
