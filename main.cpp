#include <iostream>
#include "header.h"

int main() {
    registerCommand();
    std::string command;
    std::cout<<"Welcome to your task mamager!"<<std::endl;
    do{

        std::cin>>command;
        executeCommand(command);


    }while(command!="exit");
    return 0;
}