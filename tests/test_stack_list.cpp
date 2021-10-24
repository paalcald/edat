#define CATCH_CONFIG_MAIN 

#include <iostream>
#include "stack_list.hpp"
#include "catch.hpp"


using namespace pab;
TEST_CASE(" ")
{
std::cout << "Testing linked list based Stack implementation\n";
}
TEST_CASE("Testing empty stack instantiation")
{
  Stack<int> s;
  REQUIRE(s.empty());
}

TEST_CASE("Testing push method")
{
  int n = 100;
  Stack<int> p1;
  for (int i = 1; i < n; i++) {
    p1.push(i);
    REQUIRE(p1.top() == i);
  }
  REQUIRE(p1.size() == n - 1);
}

TEST_CASE("Testing pop method")
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
  for (int i = n - 1; i >= 0; i--) {
    REQUIRE(p1.top() == i);
    p1.pop();
  }
}
