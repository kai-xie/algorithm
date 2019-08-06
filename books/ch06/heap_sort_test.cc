#include "heap_sort.h"

#include <vector>
#include <algorithm>    // std::sort
#include <functional>   // std::greater

#include "gtest/gtest.h"
#include "tests/sorting_test_base.h"

class HeapSortTest: public SortingTestBase {};

TEST_F(HeapSortTest, IntTest) {
  std::vector<int> expected_int = input_int;
  std::sort(expected_int.begin(), expected_int.end(), std::greater<int>());
  // HeapSort<int> hs;
  // hs(input_int, std::greater<int>());
  // hs(input_int, std::less<int>());
  HeapSort<int>(input_int, std::greater<int>());
  // HeapSort(input_int, std::greater<int>());  // this would cause error!
  EXPECT_EQ(input_int, expected_int);
}
