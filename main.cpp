#include "main.h"

int main(int argc, char **argv)
{
  GuessTheNumber *game = new GuessTheNumber();

  // To check - does use print some other argument we should check if the argc >= 2
  if (argc >= 2)
  {
    std::string arg1_value{argv[1]};

    if (arg1_value == "-table")
    {
      game->showHightScore();
    }
    else if (arg1_value == "-max")
    {
      // We've detected the '-max' argument. And we extect that after this argument there is a value:
      int parameter_value;
      if (argc < 3)
      {
        std::cout << "Wrong usage! The argument '-max' requires some value!" << std::endl;
        return -1;
      }

      // We need to parse the string to the int value
      parameter_value = std::stoi(argv[2]);
      std::cout << "The '-max' value = " << parameter_value << std::endl;

      game->setMaxValue(parameter_value);
      game->start();
    }
    else
    {
      std::cout << "Wrong usage! The parameter " << arg1_value << " dont exist !" << std::endl;
      return -1;
    }
  }
  else
  {
    game->start();
  }

  return 0;
}