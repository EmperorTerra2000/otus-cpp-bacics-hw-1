#include <gtest/gtest.h>
#include "../include/containerList.hpp"

class ListTest : public ::testing::Test
{
protected:
  void SetUp() override
  {
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
  }

  ContainerList<int> list{};
};

// создание контейнера
TEST(containerList, creatureContainer)
{
  try
  {
    ContainerList<int> list{};
    ASSERT_TRUE(true);
  }
  catch (const std::exception &)
  {
    ASSERT_TRUE(false);
  }
}

// добавление элемента через push back
// [22]
TEST(containerList, pushElement)
{
  ContainerList<int> list{};
  list.push_back(22);

  EXPECT_EQ(list[0], 22);
}

// получение размера контейнера
TEST_F(ListTest, correctSize)
{
  EXPECT_EQ(list.size(), static_cast<size_t>(10));
}

// вставка элемента в конец
// [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
TEST_F(ListTest, addElementEnd)
{
  list.insert(11, 10);

  EXPECT_EQ(list[10], 10);
}

// вставка элемента в начало
// [-1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
TEST_F(ListTest, addElementBegin)
{
  list.insert(1, -1);

  EXPECT_EQ(list[0], -1);
}

// вставка элемента в середину
// [0, 1, 2, 3, 4, 100, 5, 6, 7, 8, 9]
TEST_F(ListTest, addElementMiddle)
{
  list.insert(5, 100);

  EXPECT_EQ(list[4], 100);
}

// удаление элемента с конца
// [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
// [0, 1, 2, 3, 4, 5, 6, 7, 8]
TEST_F(ListTest, deleteElementEnd)
{
  list.erase(10);

  EXPECT_EQ(list[list.size() - 1], 8);
}

// удаление элемента с начала
// [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
// [1, 2, 3, 4, 5, 6, 7, 8, 9]
TEST_F(ListTest, deleteElementBegin)
{
  list.erase(1);

  EXPECT_EQ(list[0], 1);
}

// удаление элемента с cередины
// [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
// [0, 1, 2, 3, 5, 6, 7, 8, 9]
TEST_F(ListTest, deleteElementMiddle)
{
  list.erase(5);

  EXPECT_EQ(list[0], 0);
  EXPECT_EQ(list[1], 1);
  EXPECT_EQ(list[2], 2);
  EXPECT_EQ(list[3], 3);
  EXPECT_EQ(list[4], 5);
  EXPECT_EQ(list[5], 6);
  EXPECT_EQ(list[6], 7);
  EXPECT_EQ(list[7], 8);
  EXPECT_EQ(list[8], 9);
}
