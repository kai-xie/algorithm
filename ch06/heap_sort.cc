// heap_sort.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <functional>  // std::function
#include <iostream>
#include <string>
#include <utility>  // std::swap
#include <vector>

#include "glog/logging.h"

#define PARENT_IDX(i) ((i - 1) / 2)
#define LEFT_KID_IDX(i) (2 * (i) + 1)
#define RIGHT_KIT_IDX(i) (2 * (i) + 2)

template <typename T>
void Show(const std::vector<T>& arr, std::string info = "") {
  std::cout << info << std::endl;
  for (int i = 0; i < arr.size(); ++i) {
    std::cout << arr[i] << " -> ";
  }
  std::cout << "END" << std::endl;
}

// The order is determined by
template <typename Dtype>
class HeapSort {
 public:
  void operator()(std::vector<Dtype>& arr,
                  std::function<bool(const Dtype&, const Dtype&)> comp);

 private:
  void Heapify(std::vector<Dtype>& sub_arr, int heap_size, int idx,
               std::function<bool(const Dtype&, const Dtype&)> comp);
  void BuildMaxHeap(std::vector<Dtype>& arr,
                    std::function<bool(const Dtype&, const Dtype&)> comp);
};

template <typename Dtype>
void HeapSort<Dtype>::Heapify(
    std::vector<Dtype>& sub_arr, int heap_size, int idx,
    std::function<bool(const Dtype&, const Dtype&)> comp) {
  Show(sub_arr, std::string("Heapify starts"));

  int l_idx = LEFT_KID_IDX(idx);
  int r_idx = RIGHT_KIT_IDX(idx);
  std::cout << "idx, left, right: " << idx << ", " << l_idx << ", " << r_idx
            << std::endl;

  int selected_idx;
  if (l_idx < heap_size && !comp(sub_arr[l_idx], sub_arr[idx])) {
    selected_idx = l_idx;
  } else {
    selected_idx = idx;
  }

  if (r_idx < heap_size && !comp(sub_arr[r_idx], sub_arr[selected_idx])) {
    selected_idx = r_idx;
  }

  if (selected_idx != idx) {
    std::swap(sub_arr[selected_idx], sub_arr[idx]);
    Heapify(sub_arr, heap_size, selected_idx, comp);
  }
  Show(sub_arr, std::string("Heapify ends"));
}

template <typename Dtype>
void HeapSort<Dtype>::BuildMaxHeap(
    std::vector<Dtype>& arr,
    std::function<bool(const Dtype&, const Dtype&)> comp) {
  Show(arr, "BuildMaxHeap starts");

  int heap_size = arr.size();
  for (int i = (heap_size) / 2 - 1; i >= 0; --i) {
    Heapify(arr, heap_size, i, comp);
  }
  Show(arr, "BuildMaxHeap ends");
}

template <typename Dtype>
void HeapSort<Dtype>::operator()(
    std::vector<Dtype>& arr,
    std::function<bool(const Dtype&, const Dtype&)> comp) {
  if (arr.size() > 1) {
    BuildMaxHeap(arr, comp);
    for (int i = arr.size() - 1, heap_size = arr.size(); i > 0; --i) {
      std::swap(arr[0], arr[i]);
      --heap_size;
      Heapify(arr, heap_size, 0, comp);
    }
  }
  // return true;
}

int main(int argc, char* argv[]) {
  // Initialize Google's logging library.
  google::InitGoogleLogging(argv[0]);
  google::ParseCommandLineFlags(&argc, &argv, true);
  // GLOG_logtostderr=1;
  FLAGS_alsologtostderr = true;
  // FLAGS_colorlogtostderr = true; //输出彩色日志到stderr
  // FLAGS_v = 4;

  // std::vector<int> arr{ 14, 16, 10, 8, 7, 9, 3, 2, 4, 1 };
  std::vector<int> arr{4, 1, 3, 2, 16, 9, 10, 14, 8, 7};

  Show(arr, "main starts");

  HeapSort<int> hs;
  hs(arr, [](const int& a, const int& b) { return a > b; });
  // HeapSort<int>(arr, [](const int& a, const int& b) -> bool { return a < b;
  // });

  Show(arr, "main ends");
  // VLOG(INFO) << "ALL ends!";
  LOG(INFO) << "glog log(info), color test: error, warning, ERROR, WARNING";
  VLOG(1) << "I'm printed when you run the program with --v=1 or higher";
  VLOG(2) << "I'm printed when you run the program with --v=2 or higher";
  if (VLOG_IS_ON(2)) {
    LOG(INFO) << "vlog > 2";
  }
  // LOG(ERROR) << "glog error";
  // CHECK(false) << "all ends with glog";

  return 0;
}
