#include "header.h"
#include <iostream>

Task::Task() = default; //Defualt constructor 
Task::Task(const std::string& name, const std::string& priority, const std::string& dueDate) { //Actual constructor that creates the Task object using the input parameters
    this->name = name;
    this->priority = priority;
    this->dueDate = dueDate;
}
Task::~Task(){}; //Destructor
