#pragma once

#include <string>

#include "astnode.hpp"

class Sub : public ASTNode
{
public:
  Sub(ASTNode *left, ASTNode *right)
      : ASTNode(std::string("-"), left, right) {}

  Sub(const Sub &other) = delete;

  Sub &operator=(const Sub &other) = delete;

  ~Sub() = default;
};