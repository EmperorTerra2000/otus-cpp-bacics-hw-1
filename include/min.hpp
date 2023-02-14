#pragma once

#include "istatistics.hpp"

template <typename T>
class Min : public IStatistics
{
public:
  Min(std::vector<T> &values_) : m_min{values_[0]}
  {
  }

  void update(T next) override
  {
    if (next < m_min)
    {
      m_min = next;
    }
  }

  T eval() const override
  {
    return m_min;
  }

  const char *name() const override
  {
    return "min";
  }

private:
  T m_min;
};