#pragma once
#include <map>
#include "TaskItem.hpp"

class TaskCollection {
private:
  std::map<int, TaskItem> taskMap;
public:
  void insertTask(const TaskItem& task);
  void insertTask(int id, const std::string& taskDescription);
  void finishTask(int id);
  void deleteTask(int id);
  bool findTask(int id) const;
  std::string getTaskAsString(int id) const;
};