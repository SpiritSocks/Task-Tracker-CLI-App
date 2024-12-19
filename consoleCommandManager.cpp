#include "header.h"
#include <unordered_map>
#include <functional>

//Struct "Command" - basically what the command holds
struct Command {
    std::string commandDescription; //Description of command (what it does)
    std::function<void()> action; //An action that the command does
};

std::unordered_map<std::string, Command> commands; //storage of commands
std::unordered_map<std::string, Task> tasks; //storage of tasks

void registerCommand() { //Function that at the beggining of the programm registers all the commands and makes them usable
    
    commands["exit"] = {"Exit the CLI", []() { //Exit command (terminates programme)
        std::cout<<"Exiting..."<<std::endl;
        exit(0);
    }};


    commands["show"] = {"Show task",[]() { //Shows the tasks added
        for (auto& [key, task] : tasks) {
            std::cout << "Task Name: " << task.name << ", Priority: " << task.priority << ", Due Date: " << task.dueDate <<std::endl;
        }
    }};

    commands["remove"] = {"Remove task",[]() { //Command that removes a single task with the given name
        std::string taskName;
        std::cout << "Enter the name of the task to remove: ";
        std::cin >> taskName;

        if (tasks.erase(taskName) > 0) {
            std::cout << "Task \"" << taskName << "\" removed successfully." << std::endl; //If task name is found - removes task
        } else {
            std::cout << "Task \"" << taskName << "\" not found." << std::endl; //If task name is not found - tells the user that thask isn't found
        }
    }};

    commands["add"] = {"Add new task",[]() { //Command that adds a new task to the Task unordered map.
        std::string newTaskName;
        std::cout<<"Enter task name"<<std::endl;
        std::cin>>newTaskName;
        tasks[newTaskName] = Task(newTaskName, "high", "today");
        std::cout<<"Task added"<<std::endl;
    }};

    commands["help"] = {"View all functions", []() { //Command shows the commands avaliable
        std::cout<<"Avaliable commands:"<<std::endl;
        for(const auto &[name, cmd] : commands) {
            std::cout<<" - "<<name<<": "<<cmd.commandDescription<<std::endl;
        }
    }};
}

void executeCommand(const std::string &input) { //Core function that executes a command with the given name
    auto it = commands.find(input);
    if (it != commands.end()) {
        it->second.action();
    } else {
        std::cout << "Unknown command: " << input << '\n';
    }
}
