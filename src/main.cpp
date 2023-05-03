#include <iostream>
#include "containerList.hpp"
#include "containerSerial.hpp"

const size_t SIZE_CONTAINER = 10;

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
  try
  {
    ContainerList<int> list{};
    ContainerSerial<int> serial{};

    for (size_t i = 0; i < SIZE_CONTAINER; ++i)
    {
      list.push_back(i);
      serial.push_back(i);
    }

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
              << serial.size()
              << std::endl;

    std::cout << "=======ERASE======="
              << std::endl;

    list.erase(3);
    list.erase(5);
    list.erase(7);

    serial.erase(3);
    serial.erase(5);
    serial.erase(7);

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
  }
  catch (const std::exception &)
  {
    std::cout << "container initialization error !" << std::endl;
  }

  return 0;
}