#pragma once

#include <cmath>
#include <vector>

#include "istatistics.hpp"
#include "mean.hpp"

class Std : public IStatistics
{
public:
  Std()
  {
  }

  ~Std()
  {
  }

  void update(double next) override
  {
    sequenceValues.push_back(next);
  }

  double eval() const override
  {
    double sum = 0;
    double average = 0;
    double sumAverage = 0;
    size_t length = sequenceValues.size();

    for (auto iter = sequenceValues.cbegin();
         iter != sequenceValues.cend();
         ++iter)
    {
      sumAverage += *iter;
    }

    average = sumAverage / length;

    for (auto iter = sequenceValues.cbegin();
         iter != sequenceValues.cend();
         ++iter)
    {
      sum += std::pow(*iter - average, 2);
    }

    return std::sqrt(sum / length);
  }

  const char *name() const override
  {
    return "std";
  }

private:
  std::vector<double> sequenceValues;
};