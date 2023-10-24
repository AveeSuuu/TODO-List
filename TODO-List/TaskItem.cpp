#include "TaskItem.hpp"

TaskItem::TaskItem() { 
  this->id = NULL;
  taskStatus = false; 
}

TaskItem::TaskItem(int id, const std::string& taskDescription) {
  this->id = id;
  this->taskDescription = taskDescription;
  taskStatus = false;
}

int TaskItem::getId() const {
  return this->id; 
}
std::string TaskItem::getDescription() const {
  return this->taskDescription; 
}

std::string TaskItem::statusToString() {
  return this->taskStatus ? "done" : "not done";
}
