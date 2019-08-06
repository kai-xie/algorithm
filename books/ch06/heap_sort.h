#include <functional>
#include <vector>

//////////////////////////// the class implementation //////////////////////////
// template <typename Dtype>
// class HeapSort {
//  public:
//   void operator()(std::vector<Dtype>& arr,
//                   std::function<bool(const Dtype&, const Dtype&)> comp =
//                       [](const Dtype& a, const Dtype& b) { return a < b; });

//  private:
//   void Heapify(std::vector<Dtype>& sub_arr, int heap_size, int idx,
//                std::function<bool(const Dtype&, const Dtype&)> comp);
//   void BuildMaxHeap(std::vector<Dtype>& arr,
//                     std::function<bool(const Dtype&, const Dtype&)> comp);
// };

///////////////////////// function implementation //////////////////////////////
template <typename Dtype>
void HeapSort(std::vector<Dtype>& arr,
                  std::function<bool(const Dtype&, const Dtype&)> comp =
                      [](const Dtype& a, const Dtype& b) {
  return a < b; });
