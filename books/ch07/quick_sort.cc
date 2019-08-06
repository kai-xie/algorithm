#include "quick_sort.h"

#include <functional>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

#include "utils/utils.h"

template <typename Dtype>
int Partition(std::vector<Dtype>& arr, int s, int e,
              std::function<bool(const Dtype& a, const Dtype& b)> comp) {
  int le_bound = s - 1;
  // int ge_bound = s;
  Dtype pivot = arr[e];
  for (int i = s; i < e; ++i) {
    if (comp(arr[i], pivot)) {
      ++le_bound;
      std::swap(arr[le_bound], arr[i]);
    }
  }
  ++le_bound;
  std::swap(arr[le_bound], arr[e]);
  return le_bound;
}

template <typename Dtype>
void QuickSort(std::vector<Dtype>& arr, int s, int e,
               std::function<bool(const Dtype& a, const Dtype& b)> comp) {
  static int level = 0;

  PrintVector(arr, "QuickSort start, level [" + std::to_string(level) + "]");
  ++level;
  if (s < e) {
    int mid = Partition(arr, s, e, comp);
    QuickSort(arr, s, mid - 1, comp);
    QuickSort(arr, mid + 1, e, comp);
  }
  --level;
  PrintVector(arr, "QuickSort start, level [" + std::to_string(level) + "]");
}

template void QuickSort<int>(
    std::vector<int>& arr, int s, int e,
    std::function<bool(const int& a, const int& b)> comp);

template void QuickSort<float>(
    std::vector<float>& arr, int s, int e,
    std::function<bool(const float& a, const float& b)> comp);

template void QuickSort<double>(
    std::vector<double>& arr, int s, int e,
    std::function<bool(const double& a, const double& b)> comp);

// template <typename Dtype>
// class QuickSort {
// public:
//	void operator()(std::vector<Dtype>& arr, int s, int e,
// std::function<bool(const Dtype& a, const Dtype& b) comp);
//
// private:
//	int Partition(std::vector<Dtype>& arr, int s, int e,
// std::function<bool(const Dtype& a, const Dtype& b) comp);
//};
//
// template<typename Dtype>
// void QuickSort<Dtype>::operator()(std::vector<Dtype>& arr, int s, int e,
// std::function<bool(const Dtype& a, const Dtype& b) comp) { 	if (s < e) {
// int
// mid = Partition(arr, s, e, comp); 		QuickSort(arr, s, mid, comp);
// QuickSort(arr, mid, e, comp);
//	}
//}
//
// template<typename Dtype>
// int QuickSort<Dtype>::Partition(std::vector<Dtype>& arr, int s, int e,
// std::function<bool(const Dtype& a, const Dtype& b) comp) { 	int le_bound = s
// -
// 1;
//	//int ge_bound = s;
//	Dtype pivot = arr[e];
//	for (int i = s; i < e - 1; ++i) {
//		if (comp(arr[i], pivot)) {
//			++le_bound;
//			std::swap(arr[le_bound], arr[i]);
//		}
//	}
//	++le_bound;
//	std::swap(arr[le_bound], arr[e]);
//	return le_bound;
//}

// int main() {
//   std::cout << "Hello World!\n";
//   std::vector<int> arr{2, 8, 7, 1, 3, 5, 6, 4};
//   QuickSort(arr, 0, arr.size() - 1);
//   for (int i = 0; i < arr.size(); ++i) {
//     std::cout << arr[i] << " -> ";
//   }
//   std::cout << "END" << std::endl;
//   return 0;
// }
