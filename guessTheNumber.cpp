#include "guessTheNumber.h"

GuessTheNumber::GuessTheNumber()
{
  attempts_count = 0;
}

GuessTheNumber::~GuessTheNumber()
{
}

void GuessTheNumber::start()
{
  generateRandomValue();
  init();
}

void GuessTheNumber::setMaxValue(int newValue)
{
  max_value = newValue;
}

void GuessTheNumber::init()
{
  setUserName();
  startGame();
  writingToFile();

  showHightScore();
}

void GuessTheNumber::generateRandomValue()
{
  std::srand((unsigned int)std::time(nullptr)); // use current time as seed for random generator
  random_value = std::rand() % max_value;
}

void GuessTheNumber::setUserName()
{
  std::cout << "Hi! Enter your name, please:" << std::endl;
  std::cin >> user_name;
}

void GuessTheNumber::setCurrentValue()
{
  std::cin >> current_value;

  if (std::cin.fail())
  {
    std::cout << "Bad value!" << std::endl;
    return;
  }
}

void GuessTheNumber::startGame()
{
  std::cout << "Enter your guess:" << std::endl;

  do
  {
    setCurrentValue();
    attempts_count++;

    if (current_value < random_value)
    {
      std::cout << "greater than " << current_value << std::endl;
    }
    else if (current_value > random_value)
    {
      std::cout << "less than " << current_value << std::endl;
    }
    else
    {
      std::cout << "you win! "
                << "attempts = " << attempts_count << std::endl;
      break;
    }
  } while (true);
}

void GuessTheNumber::writingToFile()
{
  // We should open the output file in the append mode - we don't want
  // to erase previous results.
  std::ofstream out_file{high_scores_filename, std::ios_base::app};
  if (!out_file.is_open())
  {
    std::cout << "Failed to open file for write: " << high_scores_filename << "!" << std::endl;
    return;
  }

  // Append new results to the table:
  out_file << user_name << ' ';
  out_file << attempts_count;
  out_file << std::endl;

  out_file.close();
}

void GuessTheNumber::readingFromFile(std::vector<std::string> &vUserName, std::vector<int> &vHightScore)
{
  std::ifstream in_file{high_scores_filename};
  if (!in_file.is_open())
  {
    std::cout << "Failed to open file for read: " << high_scores_filename << "!" << std::endl;
    return;
  }

  std::cout << std::endl
            << "High scores table:" << std::endl;

  std::string username;
  int high_score = 0;
  while (true)
  {
    // Read the username first
    in_file >> username;
    // Read the high score next
    in_file >> high_score;
    // Ignore the end of line symbol
    in_file.ignore();

    if (in_file.fail())
    {
      break;
    }
    vUserName.push_back(username);
    vHightScore.push_back(high_score);
  }

  in_file.close();
}

void GuessTheNumber::showHightScore()
{
  std::vector<std::string> vUserName;
  std::vector<int> vHightScore;

  readingFromFile(vUserName, vHightScore);
  filterHightScore(vUserName, vHightScore);

  for (auto iterUserName = vUserName.begin(); iterUserName != vUserName.end(); ++iterUserName)
  {
    if (*iterUserName == "-1")
      continue;
    std::cout << *iterUserName << '\t' << vHightScore[iterUserName - vUserName.begin()] << std::endl;
  }
}

void GuessTheNumber::filterHightScore(std::vector<std::string> &vUserName, std::vector<int> &vHightScore)
{
  for (auto iterUserName = vUserName.begin(); iterUserName != vUserName.end(); ++iterUserName)
  {
    while (true)
    {
      auto iterFind = std::find(iterUserName + 1, vUserName.end(), *iterUserName);

      if (iterFind == vUserName.end() || *iterUserName == "-1" && *iterFind == "-1")
      {
        break;
      }

      if (vHightScore[iterUserName - vUserName.begin()] <= vHightScore[iterFind - vUserName.begin()])
      {
        *iterFind = "-1";
      }
      else
      {
        *iterUserName = "-1";
        break;
      }
    }
  }
}
