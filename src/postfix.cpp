// Copyright 2021 Islam Osmanov
#include <iostream>
#include <string>
#include "MyStack.h"
#include "postfix.h"

int priority(char element) {
  if (element == '(') {
    return 1;
  } else if (element == ')') {
    return 2;
  } else if (element == '+' || element == '-') {
    return 3;
  } else if (element == '*' || element == '/') {
    return 4;
  } else {
    return 0;
  }
}

std::string infix2postfix(std::string expr) {
  MyStack<char> opStack(200);
  std::string changeExpr;
  int n = expr.length();
  for (int i = 0; i < n; i++) {
    if (expr[i] == ' ') {
      continue;
    }
    if (!priority(expr[i]) && (expr[i] >= 48 && expr[i] <= 57 ||
    expr[i] == '.')) {
      changeExpr += expr[i];
      if ((!priority(expr[i + 1]) || expr[i + 1]) && (expr[i + 1] < 48 ||
      expr[i + 1] > 57) &&
      expr[i + 1] != '.') {
        changeExpr += ' ';
      }
      continue;
    } else if (priority(expr[i]) == 2) {
      while (priority(opStack.get()) != 1) {
        changeExpr += opStack.pop();
        changeExpr += ' ';
      }
      opStack.pop();  
     } else if (priority(opStack.get()) < priority(expr[i]) &&
   !opStack.isEmpty()) {
      opStack.push(expr[i]);
    } else if (opStack.isEmpty()) {
      opStack.push(expr[i]);
    } else if (expr[i] == '(') {
      opStack.push(expr[i]);
    } else {
      while (priority(expr[i]) <= priority(opStack.get()) &&
      opStack.isEmpty() == 0) {
        if (priority(opStack.get()) == 1 || priority(opStack.get()) == 2) {
          char buf = opStack.pop();
          changeExpr += "";
        } else {
          changeExpr += opStack.pop();
          changeExpr += ' ';
        }
      }
      opStack.push(expr[i]);
    }
  }
  while (!opStack.isEmpty()) {
    if (priority(opStack.get()) == 1 || priority(opStack.get()) == 2) {
      char buf = opStack.pop();
      changeExpr += "";
    } else {
      changeExpr += opStack.pop();
      changeExpr += ' ';
    }
  }
  changeExpr.pop_back();
  return changeExpr;
}
