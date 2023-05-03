template <class T>
ContainerSerial<T>::ContainerSerial()
{
  m_size = 0;
  m_region = nullptr;

  if (m_size != 0)
    throw std::exception();
}

template <class T>
void ContainerSerial<T>::erase(int pos)
{
  checkOutDimension(pos, m_size);

  if (m_size == 1)
  {
    delete[] m_region;

    m_size = 0;

    return;
  }

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

  if (m_size != pos_t)
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
  checkOutDimension(pos, m_size + 1);
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

template <class T>
void ContainerSerial<T>::checkOutDimension(int pos, size_t length)
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