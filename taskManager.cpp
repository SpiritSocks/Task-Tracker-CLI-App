#include "header.h"
#include <iostream>

Task::Task() = default;
Task::Task(const std::string& name, const std::string& priority, const std::string& dueDate) {
    this->name = name;
    this->priority = priority;
    this->dueDate = dueDate;
}
Task::~Task(){};