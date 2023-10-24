#include "UserInterface.hpp"

UserInterface::UserInterface(TaskCollection* tasks) {
  this->tasks = tasks;
  this->nextId = 0;

  userSelectOptions["add"] = userOptions::ADD;
  userSelectOptions["finish"] = userOptions::FINISH;
  userSelectOptions["delete"] = userOptions::DELETE;
  userSelectOptions["quit"] = userOptions::QUIT;
}

bool UserInterface::getAppStatus() const {
  return appRunning;
}


void UserInterface::showInterface() const {
  system("cls");
  std::cout
    << "\t TODO-List in C++ \n"
    << "==== TASKS ==== \n";

  showTasks();

  std::cout
    << "==== Options ====\n"
    << "> [add] new task\n"
    << "> [finish] task\n"
    << "> [delete] task\n"
    << "> [quit] app\n";
}

void UserInterface::showTasks() const {
  for (int taskId : idCollection) {
    std::cout << tasks->getTaskAsString(taskId) << std::endl;
  }
}

void UserInterface::interfaceActivities() {
  std::cout << "Select option: " << std::flush;
  std::string userInput = getUserInput();

  switch (userSelectOptions[userInput]) {
    case userOptions::ADD: {
      addNewTask();
      break;
    }
    case userOptions::FINISH: {
      finishTask();
      break;
    }
    case userOptions::DELETE: {
      deleteTask();
      break;
    }
    case userOptions::QUIT: {
      quitInterface();
      break;
    }
    default: {
      break;
    }
  }
}

std::string UserInterface::getUserInput() {
  std::string input;
  std::cin >> input;
  return input;
}

void UserInterface::addNewTask() {
  std::string taskDescription = "Empty task";
  std::cout << "Task description: " << std::flush;
  std::cin.clear();
  std::getline(std::cin, taskDescription);
  if (taskDescription == "") {
    taskDescription = "EMPTY TASK!";
  }
  idCollection.insert(nextId);
  tasks->insertTask(nextId, taskDescription);
  ++nextId;
}

void UserInterface::finishTask() {
  int targetId = getIdFromUser();
  if (!idCollection.count(targetId)) return;

  tasks->finishTask(targetId);
}

void UserInterface::deleteTask() {
  int targetId = getIdFromUser();
  if (!idCollection.count(targetId)) return;

  tasks->deleteTask(targetId);
  idCollection.erase(targetId);
}


int UserInterface::getIdFromUser() {
  std::cout << "Insert task ID: " << std::flush;
  int givenId;
  std::cin >> givenId;
  return givenId;
}

void UserInterface::quitInterface() {
  appRunning = false;
}