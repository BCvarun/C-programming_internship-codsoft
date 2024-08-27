//Program which implements todo-list in cpp

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Structure to represent a task
struct Task {
    string description;
    bool completed;
};

// Function to display the menu options
void displayMenu() {
    cout << "\nTo-Do List Manager" << endl;
    cout << "1. Add Task" << endl;
    cout << "2. View Tasks" << endl;
    cout << "3. Mark Task as Completed" << endl;
    cout << "4. Remove Task" << endl;
    cout << "5. Exit" << endl;
    cout << "Choose an option: ";
}

// Function to add a task to the list
void addTask(vector<Task>& tasks) {
    string taskDescription;
    cout << "Enter the task description: ";
    cin.ignore(); // To clear the newline character left in the buffer
    getline(cin, taskDescription);

    Task newTask;
    newTask.description = taskDescription;
    newTask.completed = false;

    tasks.push_back(newTask);
    cout << "Task added successfully!" << endl;
}

// Function to view tasks
void viewTasks(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks available." << endl;
        return;
    }

    cout << "\nTo-Do List:" << endl;
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". " << tasks[i].description
             << " [" << (tasks[i].completed ? "Completed" : "Pending") << "]" << endl;
    }
}

// Function to mark a task as completed
void markTaskAsCompleted(vector<Task>& tasks) {
    int taskNumber;
    cout << "Enter the task number to mark as completed: ";
    cin >> taskNumber;

    if (taskNumber > 0 && taskNumber <= tasks.size()) {
        tasks[taskNumber - 1].completed = true;
        cout << "Task marked as completed!" << endl;
    } else {
        cout << "Invalid task number!" << endl;
    }
}

// Function to remove a task from the list
void removeTask(vector<Task>& tasks) {
    int taskNumber;
    cout << "Enter the task number to remove: ";
    cin >> taskNumber;

    if (taskNumber > 0 && taskNumber <= tasks.size()) {
        tasks.erase(tasks.begin() + taskNumber - 1);
        cout << "Task removed successfully!" << endl;
    } else {
        cout << "Invalid task number!" << endl;
    }
}

int main() {
    vector<Task> tasks;
    int choice;

    while (true) {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                markTaskAsCompleted(tasks);
                break;
            case 4:
                removeTask(tasks);
                break;
            case 5:
                cout << "Exiting To-Do List Manager. Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
