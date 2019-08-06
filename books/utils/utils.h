#include <iostream>
#include <vector>

#include "glog/logging.h"

// template <typename T>
// void PrintVector(const std::vector<T>& arr, std::string description = "") {
//   std::cout << description << std::endl;
//   for (int i = 0; i < arr.size(); ++i) {
//     std::cout << arr[i] << " -> " << std::flush;
//   }
//   std::cout << "END" << std::endl;
// }

template <typename T>
void PrintVector(const std::vector<T>& arr, std::string description = "") {
  VLOG(1) << description;
  std::ostringstream vec_view;
  for (int i = 0; i < arr.size(); ++i) {
    vec_view << arr[i] << " -> ";
  }
  vec_view << "END_OF_VECTOR";
  VLOG(1) << vec_view.str();
}
