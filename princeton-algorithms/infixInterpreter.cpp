#include <cstdlib>
#include <iostream>
#include <map>
#include <stack>
#include <vector>

bool isoperator(int c) {
  return c == '+' || c == '-' || c == '*' || c == '/';
}

std::vector<int> parseToReversePolish(std::string &str) {
  std::vector<int> output;
  std::stack<int> op;

  std::map<int, int> prec;
  prec.insert({'+', 10});
  prec.insert({'-', 10});
  prec.insert({'*', 20});
  prec.insert({'/', 20});

  auto it = str.begin();
  auto end = str.end();
  while (it < end) {
    // Diagnostic printing start
    std::cout << "\nProcessing: " << *it << "\nOperator stack: ";
    std::stack<int> opcopy = op;
    while (!opcopy.empty()) {
      std::cout << (char)opcopy.top() << ' ';
      opcopy.pop();
    }
    std::cout << "\nOutput queue: ";
    for (int entry : output) std::cout << entry << ' ';
    std::cout << "\n\n";
    // Diagnostic printing end

    if (*it == ' ') {
      std::cout << "  whitespace\n";
      it++;
      continue;
    }

    std::string num;
    while (isdigit(*it)) {
      num += *it;
      it++;
    }
    if (num != "") {
      std::cout << "  number: " << std::atoi(num.c_str()) << '\n';
      output.push_back(std::atoi(num.c_str()));
      continue;
    }

    if (isoperator(*it)) {
      std::cout << "  operator: " << *it << "\n";
      while (!op.empty() && prec[op.top()] > prec[*it]) {
        // pop ops from stack to queue
        output.push_back(op.top());
        op.pop();
      }
      op.push(*it);
      it++;
      continue;
    }

    if (*it == '(') {
      std::cout << "  left paren\n";
      op.push(*it);
      it++;
      continue;
    }

    if (*it == ')') {
      std::cout << " right paren\n";
      while (!op.empty() && op.top() != '(') {
        output.push_back(op.top());
        op.pop();
      }
      op.pop();
      it++;
    }
  }

  while (!op.empty()) {
    output.push_back(op.top());
    op.pop();
  }

  std::cout << "\nResult:\n";
  for (int entry : output) std::cout << entry << ' ';
  std::cout << "\n\n";

  return output;
}

int evaluate(std::vector<int> &reversePolish) {
  std::stack<int> evalStack;

  auto it = reversePolish.begin();
  auto end = reversePolish.end();
  while (it < end) {
    while (!isoperator(*it)) {
      evalStack.push(*it);
      it++;
    }

    if (it >= end) {
      std::cerr << "input ended unexpectedly\n";
      return -1;
    }

    int rhs = evalStack.top();
    evalStack.pop();
    int lhs = evalStack.top();
    evalStack.pop();
    int op = *it;
    int result;

    switch (op) {
      case '+':
        std::cout << lhs << '+' << rhs << '\n';
        result = lhs + rhs;
        break;
      case '-':
        std::cout << lhs << '-' << rhs << '\n';
        result = lhs - rhs;
        break;
      case '*':
        std::cout << lhs << '*' << rhs << '\n';
        result = lhs * rhs;
        break;
      case '/':
        std::cout << lhs << '/' << rhs << '\n';
        result = lhs / rhs;
        break;
      default:
        std::cerr << "unknown operator\n";
        return -1;
    }
    
    evalStack.push(result);
    it++;
  }

  if (evalStack.size() != 1) {
    std::cerr << "stuff left on stack\n";
    return -1;
  }

  return evalStack.top();
}

int main() {
  std::string s = "4 + 18 / (9 - 3)";
  std::vector<int> ordered = parseToReversePolish(s);
  std::cout << evaluate(ordered) << '\n';
}
