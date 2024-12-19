#include <iostream>
#include "header.h"

int main() {
    registerCommand(); //"Registers" commands and makes them usable 
    std::string command; //Input string for the name of the command
    do { //Using "do/while loop" since I want the program to work continuously until "exit" command is used and the progam is terminated

        std::cin>>command; //User enters command name
        executeCommand(command); //Command is executed


    }while(command!="exit"); //Loop continues until "exit" command is used
    return 0;
}
