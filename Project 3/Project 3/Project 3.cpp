// Project 3.cpp 
// Created by Tristin Vang
//

#include <iostream>                      // For cin and cout
#include <fstream>                       // Allows use of filestreams 
#include <iomanip>                       // Allows for certain output methods 
#include <vector>                        // Allows use of vectors
#include <algorithm>

using namespace std;

class mainMenu {
    public:
        mainMenu();
        mainMenu(string nameOfFile, string nameOfOutputFile);
        void countItem();                     // Counts desired user item
        void printOutOptions();               // Prints out display menu for user
        void quantityOfAll();                 // Shows quantity of all items
        void histagram();                     // Shows quantity of all items through a histogram
        void createFile();                    // Creates a file with the data of the quantity of all items
    private:
        ifstream inFS;                    // Input file stream object
        ofstream outFS;                   // Output file stream object
        string fileName;                  // Name of input file
        string outFileName;               // Name of output file
};

mainMenu::mainMenu() {
    fileName = "NoName";
    outFileName = "DeleteMe";
}

mainMenu::mainMenu(string nameOfFile, string nameOfOutputFile) {
    fileName = nameOfFile;
    outFileName = nameOfOutputFile;
}

void mainMenu::printOutOptions() {
    cout << "Enter 1 to find the quantity of a desired item.\n";
    cout << "Enter 2 to view all items and their quanity\n";
    cout << "Enter 3 to view all items and their quanity in the form of a histagram\n";
    cout << "Enter q to exit the menu\n";
}

void mainMenu::countItem() {
    string itemToSearch;                           // Item that user chooses to search for
    string fileString;                             
    int itemCounter = 0;                           // used to hold item quantity information
    char yesNo = 'a';                                                                                        

    cout << "Enter name of item...\n";             // Prompt user to enter name of item
    cin >> itemToSearch;
    
    inFS.open(fileName);                           // Exits if the file fails to load
    if (!inFS.is_open()) {
        cout << fileName << "failed to open.\n" << endl;
        return;
    }

    while (!inFS.fail()) {                         // Loops through file and counts the number of times the item is found
        inFS >> fileString;
        if (fileString == itemToSearch) {
            itemCounter += 1;
        }
    }

    inFS.close();

    if (itemCounter == 0) {                       // If the item was not found then the function prompts the user to try again, if they want to
        cout << "Item not found. Would you like to retry. Enter y for yes or n for no\n";
        while (yesNo != 'y' && yesNo != 'n' && yesNo != 'Y' && yesNo != 'N') {
            try {
                cin >> yesNo;
                if (yesNo != 'y' && yesNo != 'n' && yesNo != 'Y' && yesNo != 'N') {
                throw runtime_error("Invalid input");
                }
            }
            catch (runtime_error& excpt) {
                cout << "Error. " << excpt.what() << ". Try again." << endl;
            }
        }
            
        if (yesNo == 'y' || yesNo == 'Y') {
            this->countItem();
        }
        else {
            cout << "Returning to menu\n";
        }
    }                                                              // If the item was found, then the amount is printed
    else {
        cout << itemToSearch << ": " << itemCounter << endl;
    }
    cout << endl;
}

void mainMenu::quantityOfAll() {
    string fileString;
    vector<string> items;                            // A list that holds the string names of all the items

    inFS.open(fileName);                             // Checks if the fild opened or not
    if (!inFS.is_open()) {
        cout << fileName << "failed to open.\n" << endl;
        return;
    }
    while (!inFS.fail()) {                           // A loop created to find all possible items from the file
        inFS >> fileString;
        if (items.empty()) {                         // If the vector is empty then add the first file string to it
            items.push_back(fileString);
        }
        else{
            bool itExist = false;                          // First assumes that the file string does not exist in the vector
            for (int i = 0; i < items.size(); i++) {       // Iterates through the list to see if the file string exist within the vector
                if (items.at(i) == fileString) {
                    itExist = true;
                    break;
                }
            }
            if (!itExist) {                          // If it does not exist then add the item to the vector
                items.push_back(fileString);
            }
        }
    }
    inFS.close();                                    // close to reset the file for reading

    for (int i = 0; i < items.size(); i++) {         // Double loop, first one iterates through vector while second one iterates through file to see the quantity of each vector item in the file
        int j = 0;
        inFS.open(fileName);
        
        while (!inFS.fail()) {
            inFS >> fileString;
            if (items.at(i) == fileString) {
                j += 1;
            }
        }

        inFS.close();
        cout << items.at(i) << ": " << j << endl;
    }
    cout << endl;
}

void mainMenu::histagram() {
    string fileString;
    vector<string> items;                            // A list that holds the string names of all the items

    inFS.open(fileName);                             // Checks if the fild opened or not
    if (!inFS.is_open()) {
        cout << fileName << "failed to open.\n" << endl;
        return;
    }
    while (!inFS.fail()) {                           // A loop created to find all possible items from the file
        inFS >> fileString;
        if (items.empty()) {                         // If the vector is empty then add the first file string to it
            items.push_back(fileString);
        }
        else {
            bool itExist = false;                          // First assumes that the file string does not exist in the vector
            for (int i = 0; i < items.size(); i++) {       // Iterates through the list to see if the file string exist within the vector
                if (items.at(i) == fileString) {
                    itExist = true;
                    break;
                }
            }
            if (!itExist) {                          // If it does not exist then add the item to the vector
                items.push_back(fileString);
            }
        }
    }
    inFS.close();                                    // close to reset the file for reading

    for (int i = 0; i < items.size(); i++) {         // Double loop, first one iterates through vector while second one iterates through file to see the quantity of each vector item in the file
        int j = 0;
        inFS.open(fileName);

        while (!inFS.fail()) {
            inFS >> fileString;
            if (items.at(i) == fileString) {
                j += 1;
            }
        }

        inFS.close();
        cout << right <<  setw(11) <<items.at(i);
        for (int o = 0; o < j; o++) {
            cout << '*';
        }
        cout << endl;
    }
    cout << endl;
}

void mainMenu::createFile() {
    string fileString;  
    vector<string> items;                            // A list that holds the string names of all the items
    
    

    inFS.open(fileName);                             // Checks if the fild opened or not
    if (!inFS.is_open()) {
        cout << fileName << "failed to open.\n" << endl;
        return;
    }

    while (!inFS.fail()) {                           // A loop created to find all possible items from the file
        inFS >> fileString;
        if (items.empty()) {                         // If the vector is empty then add the first file string to it
            items.push_back(fileString);
        }
        else {
            bool itExist = false;                          // First assumes that the file string does not exist in the vector
            for (int i = 0; i < items.size(); i++) {       // Iterates through the list to see if the file string exist within the vector
                if (items.at(i) == fileString) {
                    itExist = true;
                    break;
                }
            }
            if (!itExist) {                          // If it does not exist then add the item to the vector
                items.push_back(fileString);
            }
        }
    }
    
    inFS.close();                            // close to reset the file for reading
    outFS.open(outFileName);                 // opens outputfile
    if (!outFS.is_open()) {                  // Checks to see if the output file opened up or not
        cout << outFileName << endl;
    }

    for (int i = 0; i < items.size(); i++) {         // Double loop, first one iterates through vector while second one iterates through file to see the quantity of each vector item in the file
        int j = 0;
        inFS.open(fileName);

        while (!inFS.fail()) {
            inFS >> fileString;
            if (items.at(i) == fileString) {
                j += 1;
            }
        }

        inFS.close();
        outFS << items.at(i) << ": " << j << endl;    // Writes data into output file
    }

    outFS.close();    // Closes output file
}

int main(){
    char selectChar;
    mainMenu menu("CS210_Project_Three_Input_File.txt", "frequency.dat");

    selectChar = 'a';
    cout << "WELCOME\n";

    while (selectChar != 'q') {              // The menu loop
        menu.printOutOptions();
        try {                                // try block that catches unusable input
            cin >> selectChar;
            if (selectChar != '1' && selectChar != 'q' && selectChar != 'Q' && selectChar != '2' && selectChar != '3') { 
                throw runtime_error("Invalid input");
            }
            else if (selectChar == '1') {
                menu.countItem();
            }
            else if (selectChar == '2') {
                menu.quantityOfAll();
            }
            else if (selectChar == '3') {
                menu.histagram();
            }
            else if (selectChar == 'q' || selectChar == 'Q') {
                cout << "Bye\n";
            }
        }
        catch (runtime_error& excpt) {
            cout << "Error. " << excpt.what() << ". Try again." << endl;
        }
    }

    menu.createFile();       // Create file function call

    return 0;
}


