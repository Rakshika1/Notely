#ifndef TODO_H
#define TODO_H

#include <vector>
#include <string>

// Declare the global variables
extern std::vector<std::string> tasks; // List of tasks
extern std::vector<char> taskStatus; // List to track task completion status (0 = incomplete, 1 = complete)
extern char newTask[256]; // Buffer for new task input

// Function declarations
void addTask();
void removeTask(int index);

#endif // TODO_H
