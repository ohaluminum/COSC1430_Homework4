# COSC1430_Homework4

Overview: You have been greeted by a traveling sales merchant who is selling some wares. You will have access to view the items he is selling and will be able to purchase his wares according to his prices.

Objective: You will be creating a program that focuses on the use of classes and objects. For this assignment, you will be creating a Merchant class and an Antique class.

Main function

  In the main function, perform the following tasks:

  1) Create two arrays of size 10: one of antique objects and one of integers to represent the quantity of antique

  2) Read from standard input the name of the file that stores the initial status of the Merchant's stock

  3) Read the content of the file into the array of Antique objects and quantities. The file format is as follows:

    <Antique 1 name>, <Antique 1 price>, <Antique 1 quantity>
    <Antique 2 name>, <Antique 2 price>, <Antique 2 quantitiy>
    ...
    <Antique 10 name>, <Antique 10 price>, <Antique 10 quantitiy>
    
    You can assume the file will always contain 10 antiques in the above format. If the file cannot be opened, print out the following message:
    Error! File not found.
    
  4) Use the two arrays as arguments to create a Merchant object.

  5) budget (float): variable used to store the amount of money the customer can spend. Take in user input for customer's budget like the following :

    Enter in budget: $
    
  6) Present the user with the following menu:

    Make a selection:
    1 - Haggle
    2 - View menu
    3 - Select an antique
    4 - Leave
    
    If the user enters either 1-4, it will call the corresponding member functions of Merchant class (see below). If the user enters anything but 1-4, then it should output to the screen and return to the menu:
    Invalid option.

Antique Class

  Each Antique object being sold by a Merchant and will have the following attributes:

    name (string)
    price (float)
  
  And will have the following member functions:

    mutators (setName, setPrice)
    accessors (getName, getPrice)
    default constructor that sets name to "" (blank string) and price to 0 when a new Antique object is created
    a function toString that returns a string with the antique information in the following format: <Antique.name>: $<price.2digits>
        
Merchant Class

  A Merchant class will be able to hold 10 different Antique objects and interact with the user to sell to them. It should include the following attributes:

    antiques (array): An Antique array of 10 objects
    quantities (array): An Integer array representing the quantity of each Antique object in stock. This can range from 0 to 10.
    revenue (float): variable used to store the total amount of money earned by the Merchant after each sale
    
  And will have the following member functions:

    Merchant (constructor): the constructor takes as arguments an array of Antiques and an array of quantities to use them to initialize antiques and quantities. revenue should be set to 0.
    
    haggle: function that decreases each and every Antique object's price by 10%. It will print the following:
        You have successfully haggled and everything is 10% off.
        
        Customer cannot haggle more than once. If he tries to haggle more than once, it will print the following:
        Sorry, you have already haggled.

    printMenu: function that prints the items available for sale in the following format:
        1) <Antique name1>: $<price.2digits>
        2) <Antique name2>: $<price.2digits>
        ...
        10) <Antique name10>: $<price.2digits>
        
    selectAntique: this function handles item selection and sale. It begins by printing the message (and ending with a newline):
        Enter antique number:
        
        The antique number is read from standard input and stored. If the antique is not available (quantity = 0), print the following:
        Sorry! Antique is out of stock.
        
        If the user has an insufficient budget, print the following:
        Insufficient funds.
        
        Otherwise, if the sale was successful, decrease the user's budget to reflect the sale, add to revenue, and reduce the quantity of the item by one. Print the following to standard output:
        Enjoy your <Antique.name>!
        
        And append to a text file called "log2.txt" that acts as an itemized receipt like following:
        Sold <Antique.name> for $<price.2digits>
        
    leave: this function terminates the program, and appends the budget and revenue to a text file called "log2.txt" at the end:
        Total revenue: $<revenue.2digits>
        Remaining budget: $<budget.2digits>
        
BONUS (10 points) Extend your above implementation so that your Merchant class can handle different numbers of antiques (other than 10) loaded from the file. Hint: you may consider using dynamic arrays for the antiques and quantities arrays in the Merchant class.
