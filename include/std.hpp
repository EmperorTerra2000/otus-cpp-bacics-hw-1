#pragma once

#include "istatistics.hpp"
#include "mean.hpp"

template <typename T>
class Std : public IStatistics
{
public:
  Std(std::vector<T> &values_) : sum{0}, average{0}, quantity{values_.size()}
  {
    IStatistics *mean = new Mean{values_};

    for (auto iter = values_.cbegin();
         iter != values_.cend();
         ++iter)
    {
      mean->update(*iter);
    }

    average = mean->eval();

    delete mean;
  }

  void update(T next) override
  {
    T sub = next - average;
    sum += std::pow(sub, 2);
  }

  T eval() const override
  {
    T val = sum / quantity;
    return std::sqrt(val);
  }

  const char *name() const override
  {
    return "std";
  }

private:
  T average;
  T sum;
  size_t quantity;
};