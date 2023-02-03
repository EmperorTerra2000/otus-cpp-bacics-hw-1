#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>

class GuessTheNumber
{
public:
  GuessTheNumber();
  ~GuessTheNumber();
  void start();
  void setMaxValue(int);
  void showHightScore();

private:
  const std::string high_scores_filename = "high_scores.txt";
  int max_value = 100;

  std::string user_name;
  int attempts_count;
  int random_value;
  int current_value;

  void init();
  void generateRandomValue();
  void setUserName();
  void setCurrentValue();
  void startGame();
  void writingToFile();
  void readingFromFile(std::vector<std::string> &, std::vector<int> &);
  void filterHightScore(std::vector<std::string> &, std::vector<int> &);
};