#pragma once

#include <string>

#include "astnode.hpp"

class Div : public ASTNode
{
public:
  Div(ASTNode *left, ASTNode *right)
      : ASTNode(std::string("/"), left, right) {}

  Div(const Div &other) = delete;

  Div &operator=(const Div &other) = delete;

  ~Div() = default;
};