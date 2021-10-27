#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_FAST_COMPILE

#include <iostream>
#include "catch.hpp"

using namespace pab;

TEST_CASE(" ")
{
  std::cout << "Testing Stack " << STACK_H << "\n";
}

TEST_CASE("testing empty queue.")
{
  Stack<int> s;
}

TEST_CASE("testing push method.")
{
  int n = 100;
  Stack<int> p1;
  for (int i = 0; i < n; i++) {
    p1.push(i);
  }
  REQUIRE(p1.size() == n);
}

TEST_CASE("testing pop method.")
{
  int n = 100;
  int m = 4;
  Stack<int> p1;
  for (int j = 0; j < m; j++) {
    for (int i = 0; i < n; i++) {
      p1.push(i);
    }
    REQUIRE(p1.size() == n);
    for (int i = 0; i < n; i++) {
      p1.pop();
    }
    REQUIRE(p1.empty());
  }
}

TEST_CASE("Testing top method")
{
  int n = 100;
  Stack<int> p1;
  for (int i = 0; i < n; i++) {
    p1.push(i);
    REQUIRE(p1.top() == i);
  }
  for (int i = 0; i < n; i++) {
    p1.pop();
  }
}
