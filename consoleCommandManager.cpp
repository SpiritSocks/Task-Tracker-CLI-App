#include "header.h"
#include <unordered_map>
#include <functional>

//Создаем структуру консольной команды
struct Command {
    std::string commandDescription;
    std::function<void()> action;
};

std::unordered_map<std::string, Command> commands;
std::unordered_map<std::string, Task> tasks;

void registerCommand() {
    commands["exit"] = {"Exit the CLI", []() {
        std::cout<<"Exiting..."<<std::endl;
        exit(0);
    }};


    commands["show"] = {"Show task",[]() {
        for (auto& [key, task] : tasks) {
            std::cout << "Task Name: " << task.name << ", Priority: " << task.priority << ", Due Date: " << task.dueDate <<std::endl;
        }
    }};

    commands["remove"] = {"Remove task",[]() {
        std::string taskName;
        std::cout << "Enter the name of the task to remove: ";
        std::cin >> taskName;

        if (tasks.erase(taskName) > 0) {
            std::cout << "Task \"" << taskName << "\" removed successfully." << std::endl;
        } else {
            std::cout << "Task \"" << taskName << "\" not found." << std::endl;
        }
    }};

    commands["add"] = {"Add new task",[]() {
        std::string newTaskName;
        std::cout<<"Enter task name"<<std::endl;
        std::cin>>newTaskName;
        tasks[newTaskName] = Task(newTaskName, "high", "today");
        std::cout<<"Task added"<<std::endl;
    }};

    commands["help"] = {"View all functions", []() {
        std::cout<<"Avaliable commands:"<<std::endl;
        for(const auto &[name, cmd] : commands) {
            std::cout<<" - "<<name<<": "<<cmd.commandDescription<<std::endl;
        }
    }};
}

void executeCommand(const std::string &input) {
    auto it = commands.find(input);
    if (it != commands.end()) {
        it->second.action();
    } else {
        std::cout << "Unknown command: " << input << '\n';
    }
}
