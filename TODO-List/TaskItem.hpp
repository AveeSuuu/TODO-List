#pragma once
#include <string>
class TaskItem{
private:
  unsigned int id;
  std::string taskDescription;
  bool taskStatus;
public:
  TaskItem(int id, const std::string& taskDescription) {
    this->id = id;
    this->taskDescription = taskDescription;
    taskStatus = false;
  }

  int getId() const;
  std::string getDescription() const;
  std::string statusToString();
};

