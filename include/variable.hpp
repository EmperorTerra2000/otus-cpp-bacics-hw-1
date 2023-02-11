#pragma once

#include <string>

#include "astnode.hpp"

class Variable : public ASTNode
{
public:
  Variable(std::string var)
      : ASTNode(var) {}

  Variable(const Variable &other) = delete;

  Variable &operator=(const Variable &other) = delete;

  ~Variable() = default;
};