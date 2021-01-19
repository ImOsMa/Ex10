// Copyright 2021 Islam Osmanov
#include <iostream>
#include <string>
#include "MyStack.h"
#include "postfix.h"


int main() {
  std::string expr1 = "2 + 6 * 3 / (4 - 2)";
  std::string endexpr1 = infix2postfix(expr1);
  std::cout << endexpr1 << std::endl;
  std::string expr2 = "34 + 25 * 3 / 16";
  std::string endexpr2 = infix2postfix(expr2);
  std::cout << endexpr2 << std::endl;
  std::string expr3 = "1 / 2 + 2.5";
  std::string endexpr3 = infix2postfix(expr3);
  std::cout << endexpr3 << std::endl;
  return 0;
}
