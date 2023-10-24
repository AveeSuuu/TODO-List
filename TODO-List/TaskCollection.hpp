#pragma once
#include <map>
#include "TaskItem.hpp"

class TaskCollection {
private:
  std::map<int, TaskItem> taskMap;
public:
  void insertTask(const TaskItem& task);
  void insertTask(int id, const std::string& taskDescription);
  bool findTask(int id);
  std::string getTaskAsString(int id);
  void deleteTask(int id);
};