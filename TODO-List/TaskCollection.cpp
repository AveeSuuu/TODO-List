#include "TaskCollection.hpp"

void TaskCollection::insertTask(const TaskItem& task) {
  taskMap[task.getId()] = task;
}

void TaskCollection::insertTask(int id, const std::string& taskDescription) {

  if (findTask(id)) return;

  TaskItem task(id, taskDescription);
  taskMap[id] = task;
}

bool TaskCollection::findTask(int id) {
  return taskMap.find(id) != taskMap.end();
}

std::string TaskCollection::getTaskAsString(int id) {
  if (!findTask(id)) return "Task not found";

  TaskItem task = taskMap[id];
  std::string returnMessage;
  returnMessage += 
    " | " + std::to_string(task.getId()) + 
    " | " + task.getDescription() +
    " | " + task.statusToString() + 
    " |";
  return returnMessage;
}

void TaskCollection::deleteTask(int id) {
  if (!findTask(id)) return;
  taskMap.erase(id);
}