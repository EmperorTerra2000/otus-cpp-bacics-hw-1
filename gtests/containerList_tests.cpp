#include <gtest/gtest.h>
#include "../include/containerList.hpp"

// создание контейнера
TEST(containerList, creatureContainer)
{
  ContainerList<int> *list = new ContainerList<int>{};
  ASSERT_TRUE(list);

  delete list;
}

ContainerList<int> cList{};

// добавление элемента через push back
// [22]
TEST(containerList, pushElement)
{
  cList.push_back(22);

  EXPECT_EQ(cList[0], 22);
}

// получение размера контейнера
TEST(containerList, correctSize)
{
  ContainerList<int> list{};

  for (size_t i = 0; i < 10; ++i)
  {
    list.push_back(i);
  }

  EXPECT_EQ(list.size(), static_cast<size_t>(10));
}

// вставка элемента в конец
// [22, 44]
TEST(containerList, addElementEnd)
{
  cList.insert(2, 44);

  EXPECT_EQ(cList[1], 44);
}

// вставка элемента в начало
// [66, 22, 44]
TEST(containerList, addElementBegin)
{
  cList.insert(1, 66);

  EXPECT_EQ(cList[0], 66);
}

// вставка элемента в середину
// [66, 88, 22, 44]
TEST(containerList, addElementMiddle)
{
  cList.insert(2, 88);

  EXPECT_EQ(cList[1], 88);
}

// удаление элемента с конца
// [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
// [0, 1, 2, 3, 4, 5, 6, 7, 8]
TEST(containerList, deleteElementEnd)
{
  ContainerList<int> cList{};

  for (size_t i = 0; i < 10; ++i)
  {
    cList.push_back(i);
  }

  cList.erase(10);

  EXPECT_EQ(cList[cList.size() - 1], 8);
}

// удаление элемента с начала
// [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
// [1, 2, 3, 4, 5, 6, 7, 8, 9]
TEST(containerList, deleteElementBegin)
{
  ContainerList<int> cList{};

  for (size_t i = 0; i < 10; ++i)
  {
    cList.push_back(i);
  }

  cList.erase(1);

  EXPECT_EQ(cList[0], 1);
}

// удаление элемента с cередины
// [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
// [0, 1, 2, 3, 5, 6, 7, 8, 9]
TEST(containerList, deleteElementMiddle)
{
  ContainerList<int> cList{};

  for (size_t i = 0; i < 10; ++i)
  {
    cList.push_back(i);
  }

  cList.erase(5);

  EXPECT_EQ(cList[0], 0);
  EXPECT_EQ(cList[1], 1);
  EXPECT_EQ(cList[2], 2);
  EXPECT_EQ(cList[3], 3);
  EXPECT_EQ(cList[4], 5);
  EXPECT_EQ(cList[5], 6);
  EXPECT_EQ(cList[6], 7);
  EXPECT_EQ(cList[7], 8);
  EXPECT_EQ(cList[8], 9);
}
