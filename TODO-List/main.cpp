#include <iostream>
#include "UserInterface.hpp"

int main() {
  TaskCollection task;
  UserInterface interface(&task);

  while (interface.getAppStatus()) {
    interface.showInterface();
    interface.interfaceActivities();
  }
}