#include "ch06/heap_sort.h"

#include <functional>  // std::function
#include <iostream>
#include <string>
#include <utility>  // std::swap
#include <vector>

#include "utils/macros.h"
#include "utils/utils.h"

#define PARENT_IDX(i) ((i - 1) / 2)
#define LEFT_KID_IDX(i) (2 * (i) + 1)
#define RIGHT_KIT_IDX(i) (2 * (i) + 2)


///////////////////////// function implementation //////////////////////////////
namespace {
template <typename Dtype>
void Heapify(std::vector<Dtype>& sub_arr, int heap_size, int idx,
             std::function<bool(const Dtype&, const Dtype&)> comp) {
  PrintVector(sub_arr, std::string("Heapify starts"));

  int l_idx = LEFT_KID_IDX(idx);
  int r_idx = RIGHT_KIT_IDX(idx);

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
  PrintVector(sub_arr, std::string("Heapify ends"));
}

template <typename Dtype>
void BuildMaxHeap(std::vector<Dtype>& arr,
                  std::function<bool(const Dtype&, const Dtype&)> comp) {
  PrintVector(arr, "BuildMaxHeap starts");

  int heap_size = arr.size();
  for (int i = (heap_size) / 2 - 1; i >= 0; --i) {
    Heapify(arr, heap_size, i, comp);
  }
  PrintVector(arr, "BuildMaxHeap ends");
}

}  // namespace

template <typename Dtype>
void HeapSort(std::vector<Dtype>& arr,
              std::function<bool(const Dtype&, const Dtype&)> comp) {
  if (arr.size() > 1) {
    BuildMaxHeap(arr, comp);
    for (int i = arr.size() - 1, heap_size = arr.size(); i > 0; --i) {
      std::swap(arr[0], arr[i]);
      --heap_size;
      Heapify(arr, heap_size, 0, comp);
    }
  }
}

// instantiate Heapsort
template void HeapSort<int>(std::vector<int>& arr,
                            std::function<bool(const int&, const int&)> comp);

template void HeapSort<float>(
    std::vector<float>& arr,
    std::function<bool(const float&, const float&)> comp);

template void HeapSort<double>(
    std::vector<double>& arr,
    std::function<bool(const double&, const double&)> comp);



//////////////////////////// the class implementation //////////////////////////
// template <typename Dtype>
// void HeapSort<Dtype>::Heapify(
//     std::vector<Dtype>& sub_arr, int heap_size, int idx,
//     std::function<bool(const Dtype&, const Dtype&)> comp) {
//   // PrintVector(sub_arr, std::string("Heapify starts"));

//   int l_idx = LEFT_KID_IDX(idx);
//   int r_idx = RIGHT_KIT_IDX(idx);

//   int selected_idx;
//   if (l_idx < heap_size && !comp(sub_arr[l_idx], sub_arr[idx])) {
//     selected_idx = l_idx;
//   } else {
//     selected_idx = idx;
//   }

//   if (r_idx < heap_size && !comp(sub_arr[r_idx], sub_arr[selected_idx]))
//   {
//     selected_idx = r_idx;
//   }

//   if (selected_idx != idx) {
//     std::swap(sub_arr[selected_idx], sub_arr[idx]);
//     Heapify(sub_arr, heap_size, selected_idx, comp);
//   }
//   // PrintVector(sub_arr, std::string("Heapify ends"));
// }

// template <typename Dtype>
// void HeapSort<Dtype>::BuildMaxHeap(
//     std::vector<Dtype>& arr,
//     std::function<bool(const Dtype&, const Dtype&)> comp) {
//   // PrintVector(arr, "BuildMaxHeap starts");

//   int heap_size = arr.size();
//   for (int i = (heap_size) / 2 - 1; i >= 0; --i) {
//     Heapify(arr, heap_size, i, comp);
//   }
//   // PrintVector(arr, "BuildMaxHeap ends");
// }

// template <typename Dtype>
// void HeapSort<Dtype>::operator()(
//     std::vector<Dtype>& arr,
//     std::function<bool(const Dtype&, const Dtype&)> comp) {
//   if (arr.size() > 1) {
//     BuildMaxHeap(arr, comp);
//     for (int i = arr.size() - 1, heap_size = arr.size(); i > 0; --i) {
//       std::swap(arr[0], arr[i]);
//       --heap_size;
//       Heapify(arr, heap_size, 0, comp);
//     }
//   }
//   // return true;
// }

// INSTANTIATE_CLASS_WITH_INT(HeapSort);
// INSTANTIATE_CLASS_WITH_FLOAT(HeapSort);
// INSTANTIATE_CLASS_WITH_DOUBLE(HeapSort);
