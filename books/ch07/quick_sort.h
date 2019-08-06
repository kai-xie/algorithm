#include <functional>
#include <vector>

template <typename Dtype>
void QuickSort(std::vector<Dtype>& arr, int s, int e,
               std::function <bool(const Dtype& a, const Dtype& b)> comp =
                   [](const Dtype& a, const Dtype& b) -> bool {
                 return a < b;
               });
