#pragma once

template <class T>
class ContainerSerial
{
private:
  size_t m_size;
  T *m_region;

public:
  ContainerSerial();

  ContainerSerial(const ContainerSerial &other) = default;
  ContainerSerial &operator=(const ContainerSerial &other) = default;
  ~ContainerSerial() = default;

  void push_back(const T &value);
  void insert(int pos, const T &value);
  void erase(int pos);
  size_t size();
  std::string getNameClass();

  T operator[](int index);
};

#include "../src/containerSerial.inl"