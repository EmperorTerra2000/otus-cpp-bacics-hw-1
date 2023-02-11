#pragma once

#include <string>

#include "astnode.hpp"

class Mul : public ASTNode
{
public:
  Mul(ASTNode *left, ASTNode *right)
      : ASTNode(std::string("*"), left, right) {}

  Mul(const Mul &other) = delete;

  Mul &operator=(const Mul &other) = delete;

  ~Mul() = default;
};