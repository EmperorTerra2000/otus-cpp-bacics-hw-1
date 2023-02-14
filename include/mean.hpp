#pragma once

#include "istatistics.hpp"

template <typename T>
class Mean : public IStatistics
{
public:
  Mean(std::vector<T> &values_) : sum{0}, quantity{values_.size()}
  {
  }

  void update(T next) override
  {
    sum += next;
  }

  T eval() const override
  {
    return sum / quantity;
  }

  const char *name() const override
  {
    return "mean";
  }

private:
  T sum;
  size_t quantity;
};