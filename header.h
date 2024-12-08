#ifndef CLI_TASK_MANAGER_H
#define CLI_TASK_MANAGER_H

#include <string>
#include <iostream>

void registerCommand();
void executeCommand(const std::string &input);
class Task {
public:
    std::string name;
    std::string priority;
    std::string dueDate;

    Task();
    Task(const std::string& name, const std::string& priority, const std::string& dueDate);
    ~Task();
};

#endif
