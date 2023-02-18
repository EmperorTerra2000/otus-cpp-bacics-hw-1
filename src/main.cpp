#include <iostream>

#include <vector>
#include "istatistics.hpp"
#include "min.hpp"
#include "max.hpp"
#include "mean.hpp"
#include "std.hpp"

int main()
{
  std::vector<IStatistics *> statistics = {
      new Min{},
      new Max{},
      new Mean{},
      new Std{}};

  if (std::cin.peek() == '\n')
  {
    std::cerr << "error: enter numbers";
    return 1;
  }

  double val = 0;
  while (std::cin >> val)
  {
    for (auto &stat : statistics)
    {
      stat->update(val);
    }
  }

  for (auto &stat : statistics)
  {
    std::cout << stat->name() << " = " << stat->eval() << std::endl;
  }

  // Clear memory - delete all objects created by new
  for (auto &stat : statistics)
  {
    delete stat;
  }

  // Handle invalid input data
  if (!std::cin.eof() && !std::cin.good())
  {
    std::cerr << "Invalid input data\n";
    return 1;
  }

  return 0;
}