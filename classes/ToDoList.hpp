#include <iostream>
#include <string>
#include <vector>

using namespace std;

class List;

class Task{
    private:
        string description;
        int priority;
        bool done;
    public:
        Task(string description, int priority, bool done): description(description), priority(priority), done(done){}

        friend ostream &operator<< (ostream &out, Task task){
            out << task.description << ", Priority: " << task.priority << ", Done Status: " << (task.done ? "Done" : "Not Done");
            return out;
        }

    friend class List;
};

class List{
    private:
        static vector<Task> tasks;
        static void sortTasks(int index = 0) {
            if(index == tasks.size() - 1){
                return;
            }
            for(int i = 1; i < tasks.size() - index; i++) {
                if(tasks[i - 1].priority > tasks[i].priority){
                    Task &temp = tasks[i - 1];
                    tasks[i - 1] = tasks[i];
                    tasks[i] = temp;
                }
            }
            sortTasks(index + 1);
        }
    public:
        static Task createAndAddATask(string description, int priority, bool done){
            Task task = Task(description, priority, done);
            tasks.push_back(task);
            sortTasks();
            return task;
        }

        static void printTasks () {
            for(int i = 0; i < tasks.size(); i++) {
                cout << tasks[i] << endl;
            }
        }
};

vector<Task> List::tasks;

int main() {
    List::createAndAddATask("Wash dishes", 3, false);
    List::createAndAddATask("Complete project", 1, false);
    List::createAndAddATask("Buy groceries", 2, true);

    List::printTasks();

    return 0;
}