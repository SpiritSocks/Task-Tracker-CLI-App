#ifndef CLI_TASK_MANAGER_H
#define CLI_TASK_MANAGER_H

#include <string>
#include <iostream>

void registerCommand(); //Registers new command
void executeCommand(const std::string &input); //Function that executes a command, which is given by user input in the console

class Task { //Task class. It stores the name, priority and due date of the task
public:
    std::string name;
    std::string priority;
    std::string dueDate;

    Task(); //default constructor
    Task(const std::string& name, const std::string& priority, const std::string& dueDate); //constructor
    ~Task(); //destructor
};

#endif
