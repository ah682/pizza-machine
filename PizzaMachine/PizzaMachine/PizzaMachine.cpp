// PizzaMachine.cpp : This file contains the 'main' function. Program execution begins and ends there.

// Heading Library
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

/*Initilising variables before function use */
//Topping Prices
const double hamPrice = 0.80;
const double mushroomPrice = 0.50;
const double pepperoniPrice = 1.00;
const double olivesPrice = 0.30;
const double pineapplePrice = 0.60;
const double extraCheesePrice = 1.20;

//Numbers to choose toppings
const int ham = 1;
const int mushroom = 2;
const int pepperoni = 3;
const int olives = 4;
const int pineapple = 5;
const int extraCheese = 6;

//Main Menu
const int mainMenu = 0;

//Exit
const int exitApp = 0;

//Pizza Prices
const double sevenInchPrice = 3.0;
const double nineInchPrice = 5.50;
const double fourteenInchPrice = 7.25;

//Pizza Selection
const int sevenInchPizza = 1;
const int nineInchPizza = 2;
const int fourteenInchPizza = 3;

//Adding Credits to the machine
double creditsTotal = 0;
double creditsAdd;
double noCredits = 0;

//Pizza Menu SelectioN
const int addCredits = 1;
const int orderPizza = 2;

//Array Sizes
const int indexMinus = 1;
const int three = 3;
const int four = 4;
const int six = 6;
const int seven = 7;

//Arrays
double selectTopping[seven]{ exitApp, hamPrice, mushroomPrice, pepperoniPrice, olivesPrice, pineapplePrice, extraCheesePrice };
string toppingName[six]{ "Ham", "Mushroom", "Pepperoni", "Olives", "Pineapple", "Extra Cheese" };

double selectPizzaSize[four]{ exitApp, sevenInchPrice, nineInchPrice, fourteenInchPrice };
string pizzaSizeName[three]{ "Seven Inch Pizza", "Nine Inch Pizza", "Fourteen Inch Pizza" };
double selectOption[three]{ exitApp, addCredits, orderPizza };

// Function Protoypes
void AddCredits();
void AdditionalToppings();
void PizzaAppMenu();

//Enum
enum exitType
{
    exitMessage,
    menuMessage
};

exitType message;



//Function which allows for printing out ASCII art line by line via txt file
void printASCII(string filename)
{
    string line = "";
    ifstream inFile;
    inFile.open(filename);
    if (inFile.is_open())
    {
        while (getline(inFile, line))
        {
            cout << line << endl;
        }
    }
}

//Exits Pizza App
void exitPizzaApp()
{
    if (message == menuMessage)
    {
        cout << "Thank you, enjoy your pizza!" << endl << "you now have " << creditsTotal << " credits" << endl;
        PizzaAppMenu();
    }
    else
    {
        cout << "---EXITING APPLICATION---";
        exit(0);
    }

}
//When selectToppings function is ran, the function will, notify user not enough credits and to add more, or will notify user that toppings have been succesfully added
void ToppingsTest(double topping, string toppingName)
{
    creditsTotal -= topping;
    if (creditsTotal < noCredits)
    {
        cout << "You do not have enough credits to continue this order, add more credits?";
        string yesOrNoCredits;
        cin >> yesOrNoCredits;
    }
    else if (creditsTotal > noCredits)
    {
        cout << "You have added" << toppingName << "to your pizza." << endl << "you now have " << creditsTotal << " credits" << endl;
    }
}

//When selectSize function is ran, the function will, notify user not enough credits and to add more, or will notify user that toppings have been succesfully added
void PizzaSizeCheck(double pizzaSize, string pizzaSizeName)
{
    creditsTotal -= pizzaSize;
    if (creditsTotal < noCredits)
    {
        cout << "You do not have enough credits to continue this order, add more credits?";
        string yesOrNoCredits;
        cin >> yesOrNoCredits;
    }
    else if (creditsTotal > noCredits)
    {
        cout << "You have chosen " << pizzaSizeName << " you now have " << creditsTotal << " credits" << endl;
    }
}



//Function for user to select toppings
void SelectToppings()
{
    //Selecting Toppings// 
    cout << endl << "Please choose from the following toppings:" << endl << "1. Ham     [0.80 credits]" << endl << "2. Mushrooms     [0.50 credits]" << endl << "3. Pepperoni     [1.00 credits]" << endl << "4. Olives     [0.30 credits]" << endl << "5. Pineapple     [0.60 credits]" << endl << "6. Extra Cheese     [1.20 credits]" << endl << "0. Return to main menu" << endl;
    cout << "Please select a topping!: ";
    int i; cin >> i;

    //If Entering Select Number is not equal to 1, 2, 3, 4, 5,or 6, makes user re-type code
    while (i > seven)
    {
        cout << "Sorry you must choose from 1 to 2, 3, 4, 5, 6 OR 0" << endl;
        cin >> i;
    }
    if (selectTopping[i] == exitApp)
    {

        message = menuMessage;
        exitPizzaApp();
    }
    else if (selectTopping[i] == selectTopping[i]) //Works now, it was comparing the index number with the actual value of the array, now its just saying if the index is the same as the index, so when you enter and have index code, it calculates the code by the number IN THE INDEX
    {
        ToppingsTest(selectTopping[i], toppingName[i - indexMinus]);
    }

    AdditionalToppings();
}


//Function which allows user to select their pizza size
void SelectSize()
{
    int i;

    cout << endl << endl;
    cout << "ORDER PIZZA - SELECT SIZE" << endl << "Please choose from the following options:" << endl << endl;
    cout << "1. 7 inch [3.0 credits]" << endl << "2. 9 inch [5.50 credits]" << endl << "3. 14 inch [7.25 credits]" << endl << "0. Return to Main Menu" << endl << "........................................" << endl;
    cout << "Please select a pizza size!: ";
    cin >> i;

    //If Entering Select Number is not equal to integers 0 to 4 makes user re-type code
    while (i > four)
    {
        cout << "Sorry you must choose from 0 to 3" << endl;
        cin >> i;
    }
    if (selectPizzaSize[i] == exitApp)
    {
        exitPizzaApp();
    }
    else if (selectPizzaSize[i] == selectPizzaSize[i]) //Works now, it was comparing the index number with the actual value of the array, now its just saying if the index is the same as the index, so when you enter and have index code, it calculates the code by the number IN THE INDEX
    {
        PizzaSizeCheck(selectPizzaSize[i], pizzaSizeName[i - indexMinus]);
    }
    SelectToppings();
}

//Displays menu and allows the user to select an option, the option will run corresponding function
void PizzaAppMenu()
{
    int i;
    string filename = "ASCIItxt/pizzamenu.txt"; //Pizza menu ASCII Art

    //Pizza Logo from string "pizzamenu.txt" is printed out each time function is used.
    printASCII(filename);

    //Allows user to select an option and that option as a function will run
    cout << "1. Add Credits" << endl << "2. Order Pizza" << endl << "0. Exit" << endl << "Please select an option!: ";
    cin >> i;

    while (i > three)
    {
        cout << "Sorry you must choose from 0 to 2" << endl;
        cin >> i;
    }
    if (selectOption[i] == exitApp)
    {
        message = exitMessage;
        exitPizzaApp();
    }
    else if (selectOption[i] == selectOption[addCredits]) //Works now, it was comparing the index number with the actual value of the array, now its just saying if the index is the same as the index, so when you enter and have index code, it calculates the code by the number IN THE INDEX
    {
        AddCredits();
    }
    else if (selectOption[i] == selectOption[orderPizza])
    {
        SelectSize();
    }

}


//Allows user to add credits multiple times, or sends user back to menu
void AddCredits()
{
    cout << "ADD CREDITS" << endl << "Enter the amount of credits you wish to add" << endl;
    cin >> creditsAdd;
    creditsTotal += creditsAdd;
    cout << "You have added " << creditsAdd << " credits you now have " << creditsTotal << " Credits" << endl << endl;
    cout << "Would you like to add more credits? 'Y' for YES, 'N' for NO: ";
    string yesNo;
    cin >> yesNo;
    if (yesNo == "Y")
    {
        AddCredits();
    }
    if (yesNo == "N")
    {
        PizzaAppMenu();
    }

}

//Notifies the user if they wish to add additional toppings
void AdditionalToppings()
{
    cout << "Would you like to add additional toppings?" << endl << "Please input 'Y' for yes and 'N' for no ";
    string yesOrNo;
    cin >> yesOrNo;
    if (yesOrNo == "Y")
    {
        SelectToppings();
    }
    else if (yesOrNo == "N")
    {
        message = menuMessage;
        exitPizzaApp();
    }
}

int main()
{
    string fileName = "ASCIItxt/pizza.txt"; //String for pizza image to be displayed once
    printASCII(fileName); //Prints file of fileName ascii
    PizzaAppMenu(); //Runs whole program through series of functions
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
