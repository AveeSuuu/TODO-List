#pragma once
#include <set>
#include <iostream>
#include "TaskCollection.hpp"

enum class userOptions {
  ADD, FINISH, DELETE, QUIT
};

class UserInterface {
private:
  TaskCollection* tasks;
  unsigned int nextId;
  std::set<int> idCollection;
  std::map<std::string, userOptions> userSelectOptions;
  bool appRunning = true;
public:
  UserInterface(TaskCollection* tasks);
  bool getAppStatus() const;
  void showInterface() const;
  void interfaceActivities();
private:
  void showTasks() const;
  std::string getUserInput();
  void addNewTask();
  void finishTask();
  void deleteTask();
  void quitInterface();
  int getIdFromUser();
};