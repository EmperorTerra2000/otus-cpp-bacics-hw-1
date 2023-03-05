#pragma once

template <class T>
struct Node
{
  T data;
  Node<T> *next;
  Node<T> *prev;
};

template <class T>
class ContainerList
{
private:
  Node<T> *m_last;
  size_t m_size;

public:
  ContainerList();

  ContainerList(const ContainerList &other) = default;
  ContainerList &operator=(const ContainerList &other) = default;
  ~ContainerList() = default;

  void push_back(const T &value);
  void insert(int pos, const T &value);
  void erase(int pos);
  size_t size();
  std::string getNameClass();

  T operator[](int index);
};

#include "../src/containerList.inl"