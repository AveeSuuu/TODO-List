#pragma once
#include <string>

class TaskItem {
private:
  unsigned int id;
  std::string taskDescription;
  bool taskStatus;
public:
  TaskItem();
  TaskItem(int id, const std::string& taskDescription);

  int getId() const;
  std::string getDescription() const;
  std::string statusToString() const;
  void setAsChecked();
};

