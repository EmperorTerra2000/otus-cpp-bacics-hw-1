#pragma once

#include "istatistics.hpp"

class Max : public IStatistics
{
public:
  Max() : m_max{0}
  {
  }

  void update(double next) override
  {
    static bool isFirstTime = true;

    if (isFirstTime)
    {
      m_max = next;
      isFirstTime = false;
    }

    if (next > m_max)
    {
      m_max = next;
    }
  }

  double eval() const override
  {
    return m_max;
  }

  const char *name() const override
  {
    return "max";
  }

private:
  double m_max;
};