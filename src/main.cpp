#include <iostream>

#include <vector>
#include "istatistics.hpp"
#include "min.hpp"
#include "max.hpp"
#include "mean.hpp"
#include "std.hpp"

template <typename T>
void fillValues(std::vector<T> &, std::istream &);

int main()
{
  std::vector<double> sequenceValues;
  const size_t statistics_count = 4;
  IStatistics *statistics[statistics_count];

  fillValues(sequenceValues, std::cin);

  statistics[0] = new Min{sequenceValues};
  statistics[1] = new Max{sequenceValues};
  statistics[2] = new Mean{sequenceValues};
  statistics[3] = new Std{sequenceValues};

  for (size_t i = 0; i < statistics_count; ++i)
  {
    for (auto iter = sequenceValues.cbegin();
         iter != sequenceValues.cend();
         ++iter)
    {
      statistics[i]->update(*iter);
    }
  }

  // Print results if any
  for (size_t i = 0; i < statistics_count; ++i)
  {
    std::cout << statistics[i]->name() << " = " << statistics[i]->eval() << std::endl;
  }

  // Clear memory - delete all objects created by new
  for (size_t i = 0; i < statistics_count; ++i)
  {
    delete statistics[i];
  }

  return 0;
}

template <typename T>
void fillValues(std::vector<T> &sequenceValues_, std::istream &stream_)
{
  for (;;)
  {
    T n;
    stream_ >> n;

    if (stream_.fail())
    {
      if (stream_.eof())
      {
        break;
      }

      if (!stream_.eof() && !stream_.good())
      {
        std::cerr << "Invalid input data\n";
        exit(-1);
      }
    }
    else
      sequenceValues_.push_back(n);
  }
}