#include <gtest/gtest.h>
#include "../include/containerSerial.hpp"

class SerialTest : public ::testing::Test
{
protected:
  void SetUp() override
  {
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
  }

  ContainerSerial<int> serial{};
};

// создание контейнера
TEST(containerSerial, creatureContainer)
{
  try
  {
    ContainerSerial<int> serial{};
    ASSERT_TRUE(true);
  }
  catch (const std::exception &)
  {
    ASSERT_TRUE(false);
  }
}

// добавление элемента через push back
// [22]
TEST(containerSerial, pushElement)
{
  ContainerList<int> serial{};
  serial.push_back(22);

  EXPECT_EQ(serial[0], 22);
}

// получение размера контейнера
TEST_F(SerialTest, correctSize)
{
  EXPECT_EQ(serial.size(), static_cast<size_t>(10));
}

// вставка элемента в конец
// [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
TEST_F(SerialTest, addElementEnd)
{
  serial.insert(11, 10);

  EXPECT_EQ(serial[10], 10);
}

// вставка элемента в начало
// [-1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
TEST_F(SerialTest, addElementBegin)
{
  serial.insert(1, -1);

  EXPECT_EQ(serial[0], -1);
}

// вставка элемента в середину
// [0, 1, 2, 3, 4, 100, 5, 6, 7, 8, 9]
TEST_F(SerialTest, addElementMiddle)
{
  serial.insert(5, 100);

  EXPECT_EQ(serial[4], 100);
}

// удаление элемента с конца
// [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
// [0, 1, 2, 3, 4, 5, 6, 7, 8]
TEST_F(SerialTest, deleteElementEnd)
{
  serial.erase(10);

  EXPECT_EQ(serial[serial.size() - 1], 8);
}

// удаление элемента с начала
// [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
// [1, 2, 3, 4, 5, 6, 7, 8, 9]
TEST_F(SerialTest, deleteElementBegin)
{
  serial.erase(1);

  EXPECT_EQ(serial[0], 1);
}

// удаление элемента с cередины
// [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
// [0, 1, 2, 3, 5, 6, 7, 8, 9]
TEST_F(SerialTest, deleteElementMiddle)
{
  serial.erase(5);

  EXPECT_EQ(serial[0], 0);
  EXPECT_EQ(serial[1], 1);
  EXPECT_EQ(serial[2], 2);
  EXPECT_EQ(serial[3], 3);
  EXPECT_EQ(serial[4], 5);
  EXPECT_EQ(serial[5], 6);
  EXPECT_EQ(serial[6], 7);
  EXPECT_EQ(serial[7], 8);
  EXPECT_EQ(serial[8], 9);
}
