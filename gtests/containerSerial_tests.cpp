#include <gtest/gtest.h>
#include "../include/containerSerial.hpp"

// создание контейнера
TEST(containerSerial, creatureContainer)
{
  ContainerSerial<int> *list = new ContainerSerial<int>{};
  ASSERT_TRUE(list);

  delete list;
}

ContainerSerial<int> cSerial{};

// добавление элемента через push back
// [22]
TEST(containerSerial, pushElement)
{
  cSerial.push_back(22);

  EXPECT_EQ(cSerial[0], 22);
}

// получение размера контейнера
TEST(containerSerial, correctSize)
{
  ContainerSerial<int> list{};

  for (size_t i = 0; i < 10; ++i)
  {
    list.push_back(i);
  }

  EXPECT_EQ(list.size(), static_cast<size_t>(10));
}

// вставка элемента в конец
// [22, 44]
TEST(containerSerial, addElementEnd)
{
  cSerial.insert(2, 44);

  EXPECT_EQ(cSerial[1], 44);
}

// вставка элемента в начало
// [66, 22, 44]
TEST(containerSerial, addElementBegin)
{
  cSerial.insert(1, 66);

  EXPECT_EQ(cSerial[0], 66);
}

// вставка элемента в середину
// [66, 88, 22, 44]
TEST(containerSerial, addElementMiddle)
{
  cSerial.insert(2, 88);

  EXPECT_EQ(cSerial[1], 88);
}

// удаление элемента с конца
// [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
// [0, 1, 2, 3, 4, 5, 6, 7, 8]
TEST(containerSerial, deleteElementEnd)
{
  ContainerSerial<int> cSerial{};

  for (size_t i = 0; i < 10; ++i)
  {
    cSerial.push_back(i);
  }

  cSerial.erase(10);

  EXPECT_EQ(cSerial[cSerial.size() - 1], 8);
}

// удаление элемента с начала
// [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
// [1, 2, 3, 4, 5, 6, 7, 8, 9]
TEST(containerSerial, deleteElementBegin)
{
  ContainerSerial<int> cSerial{};

  for (size_t i = 0; i < 10; ++i)
  {
    cSerial.push_back(i);
  }

  cSerial.erase(1);

  EXPECT_EQ(cSerial[0], 1);
}

// удаление элемента с cередины
// [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
// [0, 1, 2, 3, 5, 6, 7, 8, 9]
TEST(containerSerial, deleteElementMiddle)
{
  ContainerSerial<int> cSerial{};

  for (size_t i = 0; i < 10; ++i)
  {
    cSerial.push_back(i);
  }

  cSerial.erase(5);

  EXPECT_EQ(cSerial[0], 0);
  EXPECT_EQ(cSerial[1], 1);
  EXPECT_EQ(cSerial[2], 2);
  EXPECT_EQ(cSerial[3], 3);
  EXPECT_EQ(cSerial[4], 5);
  EXPECT_EQ(cSerial[5], 6);
  EXPECT_EQ(cSerial[6], 7);
  EXPECT_EQ(cSerial[7], 8);
  EXPECT_EQ(cSerial[8], 9);
}
