#include <iostream>
#include "TaskCollection.hpp"

int main() {

  TaskCollection tasks;
  tasks.insertTask(1, "TEST12ASASDASDDASDSA3");
  tasks.insertTask(0, "TESTASDSA3");

  std::cout << tasks.getTaskAsString(0) << std::endl;
  std::cout << tasks.getTaskAsString(1) << std::endl;
  tasks.deleteTask(0);

  std::cout << tasks.getTaskAsString(0) << std::endl;
}