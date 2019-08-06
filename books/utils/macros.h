// #define INSTANTIATE_INT(class_name) template class class_name<int>

// #define INSTANTIATE_FLOAT(class_name) template class class_name<float>

// #define INSTANTIATE_DOUBLE(class_name) template class class_name<double>

#define INSTANTIATE_CLASS_WITH_INT(class_name) template class class_name<int>

#define INSTANTIATE_CLASS_WITH_FLOAT(class_name) \
  template class class_name<float>

#define INSTANTIATE_CLASS_WITH_DOUBLE(class_name) \
  template class class_name<double>;