#pragma once

#include "istatistics.hpp"

class Min : public IStatistics
{
public:
  Min() : m_min{0}
  {
  }

  void update(double next) override
  {
    static bool isFirstTime = true;

    if (isFirstTime)
    {
      m_min = next;
      isFirstTime = false;
    }

    if (next < m_min)
    {
      m_min = next;
    }
  }

  double eval() const override
  {
    return m_min;
  }

  const char *name() const override
  {
    return "min";
  }

private:
  double m_min;
};