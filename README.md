# Portfolio

The goal of this project was to create a program that could read a list of items and allow a user to see the frequency of a desired item, frequency of all existing items, and to view a histogram that displayed frequency.

The strength of this program was the simplicity of it. The main function contains a loop which takes in user input and performs a function call depending on the input. 
Since most of the functionality of the code exist within the menu functions it is a lot easier to read and edit the program.

An area of improvement in the program could be the simplifcation of the class functions. The use of vectors, although effective in the program, cause the some of the mainMenu class functions to be a bit bloated. 
A way in which this could be fixed would be to remove the use of vectors and instead created linklists to count the number of unique items in the input file. 

In creating this program, the hardest part for was the creation of mainMenu functions. Both of these functions had to count the frequency of each different item in the list. They way I solved this was that I used a vector to store all the one of every item. 
The way I did this was that I created a loop which added items to the vector given that the items did not already exist in there.
I then created another loop which went throught vecotr and for item, another loop would execute and counted the frequency of itself in the list. 

This project showcases the c++ coding ability to create and define classes, read and create files, and to display user interactable menus. These skills can be applied to various projects that require a programmer to create programs in which a user uses to extract information from.
Situations in which this can applicable in working world could be ones in which a company needs a program to translate files that contain company data into reading and digestible information. 
Another would be a case in which a company lends a program to customers in which they can use to display important data that they have in connection to the company.

To make the code readable, I've added inline comments through the code to explain what the code does. I've also made sure to use white space to help differentiate different parts of the code to other programmers.
Since most of funcatiality of the code depends on the mainMenu class and functions, the program should be easily adaptable. There are not too many code dependency, 
so if a programmer wishes to alter and or add to the program, then only the changes to the mainManu class needs to be and the loop in the main need to be changed.
