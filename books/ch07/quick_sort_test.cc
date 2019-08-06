#include "quick_sort.h"

#include <vector>
#include <algorithm>    // std::sort
#include <functional>   // std::greater

#include "gtest/gtest.h"
#include "tests/sorting_test_base.h"


class QuickSortTest: public SortingTestBase {};

TEST_F(QuickSortTest, IntTest) {
  std::vector<int> expected_int = input_int;
  std::sort(expected_int.begin(), expected_int.end(), std::greater<int>());

  QuickSort<int>(input_int, 0, input_int.size() -1, std::greater<int>());
  EXPECT_EQ(input_int, expected_int);
}
