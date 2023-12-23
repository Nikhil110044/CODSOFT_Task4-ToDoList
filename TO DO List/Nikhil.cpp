#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent a task
struct Task {
    string description;
    bool completed;

    Task(const string& desc) : description(desc), completed(false) {}
};

// Function prototypes
void addTask(vector<Task>& tasks, const string& description);
void viewTasks(const vector<Task>& tasks);
void markAsCompleted(vector<Task>& tasks, int taskIndex);
void removeTask(vector<Task>& tasks, int taskIndex);

int main() {
    vector<Task> tasks;

    int choice;
    string description;
    do {
        // Display menu
        cout << "\n===== TO-DO List by Nikhil =====" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Remove Task" << endl;
        cout << "5. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                // Add Task
                cout << "Enter task description: ";
                cin.ignore(); // Clear the newline character from the buffer
                getline(cin, description);
                addTask(tasks, description);
                break;
            case 2:
                // View Tasks
                viewTasks(tasks);
                break;
            case 3:
                // Mark Task as Completed
                if (!tasks.empty()) {
                    viewTasks(tasks);
                    int taskIndex;
                    cout << "Enter the index of the task to mark as completed: ";
                    cin >> taskIndex;
                    markAsCompleted(tasks, taskIndex);
                } else {
                    cout << "No tasks to mark as completed." << endl;
                }
                break;
            case 4:
                // Remove Task
                if (!tasks.empty()) {
                    viewTasks(tasks);
                    int taskIndex;
                    cout << "Enter the index of the task to remove: ";
                    cin >> taskIndex;
                    removeTask(tasks, taskIndex);
                } else {
                    cout << "No tasks to remove." << endl;
                }
                break;
            case 5:
                // Quit
                cout << "Exiting TO-DO List Manager. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
        }

    } while (choice != 5);

    return 0;
}

void addTask(vector<Task>& tasks, const string& description) {
    tasks.push_back(Task(description));
    cout << "Task added successfully!" << endl;
}

void viewTasks(const vector<Task>& tasks) {
    cout << "\n===== TO-DO List =====" << endl;
    if (tasks.empty()) {
        cout << "No tasks to display." << endl;
    } else {
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". " << tasks[i].description << " - "
                 << (tasks[i].completed ? "Complete" : "Pending") << endl;
        }
    }
}

void markAsCompleted(vector<Task>& tasks, int taskIndex) {
    if (taskIndex >= 1 && taskIndex <= static_cast<int>(tasks.size())) {
        tasks[taskIndex - 1].completed = true;
        cout << "Task marked as completed!" << endl;
    } else {
        cout << "Invalid task index. Please enter a valid index." << endl;
    }
}

void removeTask(vector<Task>& tasks, int taskIndex) {
    if (taskIndex >= 1 && taskIndex <= static_cast<int>(tasks.size())) {
        tasks.erase(tasks.begin() + taskIndex - 1);
        cout << "Task removed successfully!" << endl;
    } else {
        cout << "Invalid task index. Please enter a valid index." << endl;
    }
}
