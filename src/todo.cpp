#include "todo.h"

// Define the global variables
std::vector<std::string> tasks; // List of tasks
std::vector<char> taskStatus; // List to track task completion status
char newTask[256] = ""; // Buffer for new task input

// Function to add a new task
void addTask() {
    if (newTask[0] != '\0') {
        tasks.push_back(newTask);
        taskStatus.push_back(0); // Initialize new task as incomplete (0)
        newTask[0] = '\0'; // Clear input
    }
}

// Function to remove a task
void removeTask(int index) {
    if (index >= 0 && index < tasks.size()) {
        tasks.erase(tasks.begin() + index);
        taskStatus.erase(taskStatus.begin() + index); // Remove corresponding status
    }
}
