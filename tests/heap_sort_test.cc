#include <vector>
#include <algorithm>    // std::sort
#include <functional>   // std::greater

#include "gtest/gtest.h"

#include "ch06/heap_sort.h"

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

class HeapSortTest: public SortingTestBase {};

TEST_F(HeapSortTest, IntTest) {
  std::vector<int> expected_int = input_int;
  std::sort(expected_int.begin(), expected_int.end());
  // HeapSort<int> hs;
  // hs(input_int, std::greater<int>());
  // hs(input_int, std::less<int>());
  HeapSort<int>(input_int, std::greater<int>());
  // HeapSort(input_int, std::greater<int>());  // this would cause error!
  EXPECT_EQ(input_int, expected_int);
}
