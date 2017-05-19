#include <iostream> // used to format and output text
#include <vector>   // Allows creation and manipulation of vectors

// Allows test cases
#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"

using namespace std;

// Definitions for example functions
bool functionName(std::string input) { return true; }

int functionExample(int input) { return 25; }

vector<int> vectorFunction1(vector<int> input) { return input; }

vector<double> vectorFunction2(vector<double> input) { return input; }

double divide(double dividend, double divisor) { return (dividend / divisor); }

double getPi() { return 3.14159265359; }


// Main
int main() {
  int result = (new doctest::Context())->run();

  return result;
}

TEST_CASE("Example") {
  CHECK(functionName("input") == true); // Checks for correct bool value
  CHECK(functionExample(0) == 25);      // Checks for correct int value

  CHECK(vectorFunction1({1, 2, 3, 4}) == vector<int>({1, 2, 3, 4}));
  CHECK(vectorFunction2({1, 2, 3, 4}) == vector<double>({1.0, 2.0, 3.0, 4.0}));

  CHECK(divide(5, 2) == 2.5); // Divides 5 by 2  PASSES
  CHECK(getPi() == 3.14);     // FAILS if function returns pi to a greater
                              // precision
                              // than 2 decimal places

  CHECK(getPi() == doctest::Approx(3.14159)); // Passes because doctest::Approx
                                              // overloads the comparisons
                                              // operator
  CHECK(getPi() == doctest::Approx(3.14).epsilon(0.01)); // Adding the epsilon
                                                         // method changes the
                                                         // acceptable percent
                                                         // error
}
