#include <iostream>
#include "header.h"

int main() {
    registerCommand();
    std::string command;
    do {

        std::cin>>command;
        executeCommand(command);


    }while(command!="exit");
    return 0;
}