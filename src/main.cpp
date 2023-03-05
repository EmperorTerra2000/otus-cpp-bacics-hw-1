#include <iostream>
#include "containerList.hpp"
#include "containerSerial.hpp"

template <class T>
void show(T container)
{
  std::cout << container.getNameClass() << " => ";
  for (size_t i = 0; i < container.size(); i++)
  {
    std::cout << container[i] << ' ';
  }

  std::cout << std::endl;
}

int main()
{
  ContainerList<int> list{};
  ContainerSerial<int> serial{};

  list.push_back(0);
  list.push_back(1);
  list.push_back(2);
  list.push_back(3);
  list.push_back(4);
  list.push_back(5);
  list.push_back(6);
  list.push_back(7);
  list.push_back(8);
  list.push_back(9);

  serial.push_back(0);
  serial.push_back(1);
  serial.push_back(2);
  serial.push_back(3);
  serial.push_back(4);
  serial.push_back(5);
  serial.push_back(6);
  serial.push_back(7);
  serial.push_back(8);
  serial.push_back(9);

  std::cout << "=======CONTAINERS======="
            << std::endl;

  show(list);
  show(serial);

  std::cout << "=======CONTAINERS SIZE======="
            << std::endl;

  std::cout << list.getNameClass()
            << " => "
            << list.size()
            << std::endl;
  std::cout << serial.getNameClass()
            << " => "
            << list.size()
            << std::endl;

  std::cout << "=======ERASE======="
            << std::endl;

  list.erase(3);
  list.erase(5);
  list.erase(7);

  serial.erase(3);
  serial.erase(5);
  serial.erase(9);

  show(list);
  show(serial);

  std::cout << "=======ADD TO BEGIN======="
            << std::endl;

  list.insert(1, 10);
  serial.insert(1, 10);

  show(list);
  show(serial);

  std::cout << "=======ADD TO MIDDLE======="
            << std::endl;

  list.insert((list.size() / 2) + 1, 20);
  serial.insert((serial.size() / 2) + 1, 20);

  show(list);
  show(serial);

  std::cout << "=======ADD TO END======="
            << std::endl;

  list.insert(list.size() + 1, 30);
  serial.insert(serial.size() + 1, 30);

  show(list);
  show(serial);

  return 0;
}