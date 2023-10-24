#include <iostream>
#include "TaskItem.hpp"

int main() {

  TaskItem task(1, "!Test task class!");
  std::cout << task.getId() << " " + task.getDescription() + " " + task.statusToString();
}