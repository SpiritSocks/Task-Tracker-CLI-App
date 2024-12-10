#include "header.h"
#include <unordered_map>
#include <functional>
#include <fstream>
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
        std::ifstream file("tasks.csv");
        std::string line;
        std::getline(file,line);
        while(std::getline(file,line)) {
            std::cout<<line<<std::endl;
        }
        file.close();

    }};

    commands["remove"] = {"Remove task", []() {
        std::string taskName;
        std::cout << "Enter the name of the task to remove: ";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::getline(std::cin, taskName);

        std::ifstream fileIn("tasks.csv");
        if (!fileIn.is_open()) {
            std::cerr << "Error: Could not open the file 'tasks.csv' for reading!" << std::endl;
            return;
        }

        std::ofstream fileOut("temp.csv");
        if (!fileOut.is_open()) {
            std::cerr << "Error: Could not open the temporary file for writing!" << std::endl;
            fileIn.close();
            return;
        }

        std::string line;
        bool taskFound = false;

        while (std::getline(fileIn, line)) {
            size_t firstSemicolon = line.find(';');
            if (firstSemicolon != std::string::npos) {
                std::string currentTaskName = line.substr(0, firstSemicolon);
                if (currentTaskName == taskName) {
                    taskFound = true;
                    continue;
                }
            }
            fileOut << line << std::endl;
        }

        fileIn.close();
        fileOut.close();

        if (taskFound) {
            if (std::remove("tasks.csv") != 0 || std::rename("temp.csv", "tasks.csv") != 0) {
                std::cerr << "Error: Could not update the file!" << std::endl;
            } else {
                std::cout << "Task '" << taskName << "' removed successfully." << std::endl;
            }
        } else {
            std::cout << "Task '" << taskName << "' not found!" << std::endl;
            std::remove("temp.csv");
        }
    }};


    commands["add"] = {"Add new task",[]() {
        std::string newTaskName;
        std::string priority;
        std::string dueDate;
        std::ofstream file;
        file.open("tasks.csv", std::ios::app);
        std::cout<<"Enter task name"<<std::endl;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::getline(std::cin, newTaskName);
        std::cout<<"Enter task priority"<<std::endl;
        std::getline(std::cin, priority);
        std::cout<<"Enter task due date"<<std::endl;
        std::getline(std::cin, dueDate);
        tasks[newTaskName] = Task(newTaskName, priority, dueDate);
        file<<newTaskName<<";"<<priority<<";"<<dueDate<<";"<<std::endl;
        std::cout<<"Task added"<<std::endl;
        file.close();
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
