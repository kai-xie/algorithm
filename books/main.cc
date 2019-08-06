#include <functional>  // std::function
#include <iostream>
#include <string>
#include <utility>  // std::swap
#include <vector>

#include "glog/logging.h"

#include "ch06/heap_sort.h"
#include "utils/utils.h"

template <typename T>
bool Greater(const T& a, const T& b) {
  return a > b;
}

template <typename T>
bool Less(const T& a, const T& b) {
  return a < b;
}

int main(int argc, char* argv[]) {
  // Initialize Google's logging library.
  google::InitGoogleLogging(argv[0]);
  google::ParseCommandLineFlags(&argc, &argv, true);
  // GLOG_logtostderr=1;
  FLAGS_alsologtostderr = true;
  FLAGS_colorlogtostderr = true;  //输出彩色日志到stderr
  // FLAGS_v = 4;

  // std::vector<int> arr{ 14, 16, 10, 8, 7, 9, 3, 2, 4, 1 };
  std::vector<int> arr{4, 1, 3, 2, 16, 9, 10, 14, 8, 7};

  PrintVector(arr, "main starts");
  // HeapSort<int> hs;
  // hs(arr, [](const int& a, const int& b) { return a > b; });

  // hs(arr, std::greater<int>());
  // hs(arr, std::less<int>());
  // hs(arr, Greater<int>);
  // hs(arr, Less<int>);
  HeapSort<int>(arr, [](const int& a, const int& b) -> bool { return a < b; });
  // HeapSort(arr, std::less<int>());

  PrintVector(arr, "main ends");

  VLOG(1) << "I'm printed when you run the program with --v=1 or higher";
  VLOG(2) << "I'm printed when you run the program with --v=2 or higher";
  if (VLOG_IS_ON(2)) {
    LOG(INFO) << "vlog > 2";
  }

  LOG(INFO) << "glog log(info), color test: INFO";
  LOG(WARNING) << "glog log(warning), color test: WARNING";
  LOG(ERROR) << "glog log(error), color test: ERROR";
  // LOG(FATAL) << "glog log(fatal), color test: FATAL";

  return 0;
}
