#include <vector>

#include "gtest/gtest.h"

class SortingTestBase : public ::testing::Test {
 protected:
  void SetUp() override {
    input_int = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
  }

  void TearDown() override {
    input_int.clear();
  }
  std::vector<int> input_int;
};
