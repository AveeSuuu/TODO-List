#include "TaskItem.hpp"

int TaskItem::getId() const {
  return this->id; 
}
std::string TaskItem::getDescription() const {
  return this->taskDescription; 
}

std::string TaskItem::statusToString() {
  return this->taskStatus ? "done" : "not done";
}
