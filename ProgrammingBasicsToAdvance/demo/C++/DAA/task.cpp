#include <iostream>
#include <vector>
#include <algorithm>

struct Task
{
    int number;
    int timeTaken;
    int deadline;
};

bool compareTasks(const Task &task1, const Task &task2)
{
    if (task1.deadline == task2.deadline)
    {
        return task1.timeTaken > task2.timeTaken;
    }
    return task1.deadline < task2.deadline;
}

int main()
{
    int n;
    std::cin >> n;

    std::vector<int> tasksTime(n);
    std::vector<int> tasksDeadline(n);

    for (int i = 0; i < n; i++)
    {
        std::cin >> tasksTime[i];
    }
    for (int i = 0; i < n; i++)
    {
        std::cin >> tasksDeadline[i];
    }

    std::vector<Task> taskList(n);
    for (int i = 0; i < n; i++)
    {
        taskList[i].number = i + 1;
        taskList[i].timeTaken = tasksTime[i];
        taskList[i].deadline = tasksDeadline[i];
    }

    std::sort(taskList.begin(), taskList.end(), compareTasks);

    int completedTasks = 0;
    std::vector<int> selectedTasks;

    for (int i = 0; i < n; i++)
    {
        if (taskList[i].deadline >= completedTasks + taskList[i].timeTaken)
        {
            completedTasks += taskList[i].timeTaken;
            selectedTasks.push_back(taskList[i].number);
        }
    }

    std::cout << "Max number of tasks = " << selectedTasks.size() << std::endl;
    std::cout << "Selected task numbers: ";
    for (int i = 0; i < selectedTasks.size(); i++)
    {
        std::cout << selectedTasks[i];
        if (i != selectedTasks.size() - 1)
        {
            std::cout << ", ";
        }
    }
    std::cout << std::endl;

    return 0;
}
