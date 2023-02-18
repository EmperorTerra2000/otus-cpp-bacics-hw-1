#pragma once

#include "istatistics.hpp"

class Mean : public IStatistics
{
public:
  Mean() : sum{0}, quantity{0}
  {
  }

  void update(double next) override
  {
    static unsigned long long counter = 0;

    quantity = ++counter;

    sum += next;
  }

  double eval() const override
  {
    return sum / quantity;
  }

  const char *name() const override
  {
    return "mean";
  }

private:
  double sum;
  unsigned long long quantity;
};