#pragma once

#include <string>

#include "astnode.hpp"

class Add : public ASTNode
{
public:
  Add(ASTNode *left, ASTNode *right)
      : ASTNode(std::string("+"), left, right) {}

  Add(const Add &other) = delete;

  Add &operator=(const Add &other) = delete;

  ~Add() = default;
};
