#pragma once

#include "istatistics.hpp"

template <typename T>
class Max : public IStatistics
{
public:
  Max(std::vector<T> &values_) : m_max{values_[0]}
  {
  }

  void update(T next) override
  {
    if (next > m_max)
    {
      m_max = next;
    }
  }

  T eval() const override
  {
    return m_max;
  }

  const char *name() const override
  {
    return "max";
  }

private:
  T m_max;
};