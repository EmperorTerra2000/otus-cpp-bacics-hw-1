#include "containerSerial.hpp"

template <class T>
ContainerSerial<T>::ContainerSerial()
{
  m_size = 0;
  m_region = nullptr;
}

template <class T>
void ContainerSerial<T>::erase(int pos)
{
  // считаю не особо хорошим решением
  size_t pos_t = static_cast<size_t>(pos);

  T *new_region = new T[m_size - 1]; // новая область памяти

  for (size_t i = 0; i < m_size - 1; ++i)
  {
    if (i < pos_t - 1)
    {
      new_region[i] = m_region[i];
    }
    else if (i == pos_t - 1)
    {
      continue;
    }
    else
    {
      new_region[i - 1] = m_region[i];
    }
  }
  new_region[m_size - 2] = m_region[m_size - 1];

  delete[] m_region;
  m_region = new_region;
  m_size--;
}

template <class T>
void ContainerSerial<T>::push_back(const T &value)
{
  if (m_size == 0)
  {
    m_region = new T[++m_size];
    m_region[0] = value;
    return;
  }

  T *new_region = new T[m_size + 1]; // новая область памяти

  for (size_t i = 0; i < m_size; ++i)
  {
    new_region[i] = m_region[i]; // копирование элементов
  }
  new_region[m_size] = value; // добавление нового элемента
  delete[] m_region;          // удаление старой области
  m_region = new_region;      // сохранение новой в мембер
  m_size++;                   // обновление информации о размере
}

template <class T>
void ContainerSerial<T>::insert(int pos, const T &value)
{
  // считаю не особо хорошим решением
  size_t pos_t = static_cast<size_t>(pos);

  T *new_region = new T[m_size + 1]; // новая область памяти

  if (pos_t == m_size + 1)
  {
    for (size_t i = 0; i < m_size; ++i)
    {
      new_region[i] = m_region[i];
    }

    new_region[m_size] = value;
  }
  else
  {
    for (size_t i = 0; i < m_size; ++i)
    {
      if (i < pos_t - 1)
      {
        new_region[i] = m_region[i];
      }
      else if (i == pos_t - 1)
      {
        new_region[i] = value;
      }
      else
      {
        new_region[i] = m_region[i - 1];
      }
    }

    new_region[m_size] = m_region[m_size - 1];
  }

  delete[] m_region;
  m_region = new_region;
  m_size++;
}

template <class T>
T ContainerSerial<T>::operator[](int index)
{
  return m_region[index];
}

template <class T>
size_t ContainerSerial<T>::size()
{
  return m_size;
}

template <class T>
std::string ContainerSerial<T>::getNameClass()
{
  return "serial";
}