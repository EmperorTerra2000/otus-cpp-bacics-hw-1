#include "containerList.hpp"

template <class T>
ContainerList<T>::ContainerList()
{
  m_last = nullptr;
  m_size = 0;
}

template <class T>
void ContainerList<T>::erase(int pos)
{
  checkOutDimension(pos, m_size);

  Node<T> *current = m_last;

  if (m_size == 1)
  {
    delete current;
    m_size--;

    return;
  }

  // считаю не особо хорошим решением
  size_t pos_t = static_cast<size_t>(pos);

  for (size_t i = 0; i < size() - pos_t; ++i)
  {
    current = current->prev;
  }

  if (pos_t == 1)
  {
    current->next->prev = nullptr;
  }
  else if (pos_t == size())
  {
    current->prev->next = nullptr;
    m_last = current->prev;
  }
  else
  {
    current->next->prev = current->prev;
    current->prev->next = current->next;
  }

  delete current;

  m_size--;
}

template <class T>
void ContainerList<T>::push_back(const T &value)
{
  Node<T> *new_node = new Node<T>{};
  new_node->data = value;   // добавляем элемент
  new_node->next = nullptr; // следующего элемента пока нет
  new_node->prev = m_last;  // предыдущим элементом станет последний
  m_last = new_node;        // добавляем указатель на последний

  if (m_last->prev)
  {
    m_last->prev->next = new_node;
  }

  m_size++; // добавляем размер
}

template <class T>
size_t ContainerList<T>::size()
{
  return m_size;
}

template <class T>
T ContainerList<T>::operator[](int index)
{
  Node<T> *current = m_last;

  for (size_t i = 1; i < size() - index; ++i)
  {
    current = current->prev;
  }

  return current->data;
}

template <class T>
void ContainerList<T>::insert(int pos, const T &value)
{
  checkOutDimension(pos, m_size + 1);

  Node<T> *current = m_last;
  Node<T> *newElement = new Node<T>{};
  size_t pos_t = static_cast<size_t>(pos);

  if (pos_t == size() + 1)
  {
    push_back(value);

    return;
  }

  for (size_t i = 0; i < size() - pos_t; ++i)
  {
    current = current->prev;
  }

  newElement->data = value;
  newElement->prev = current->prev;
  newElement->next = current;

  if (pos_t > 1)
  {
    current->prev->next = newElement;
  }
  current->prev = newElement;

  m_size++;
};

template <class T>
std::string ContainerList<T>::getNameClass()
{
  return "list";
}

template <class T>
void ContainerList<T>::checkOutDimension(int pos, size_t length)
{
  size_t pos_t = static_cast<size_t>(pos);

  if ((pos_t > length) || (pos_t < 1))
  {
    std::cerr << "error: Going beyond the dimension of the container "
              << getNameClass()
              << " : size = "
              << m_size
              << " pos = "
              << pos;
    exit(-1);
  }
}