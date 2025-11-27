#include <torch/library.h>

// Proper schema + dispatcher registration
TORCH_LIBRARY(my_namespace, m) {
  m.def("my_mul_add(Tensor x, Tensor y, Tensor z) -> Tensor");
}

TORCH_LIBRARY_IMPL(my_namespace, CPU, m) {
  m.impl("my_mul_add", torch::CppFunction::makeUnboxedKernel(my_mul_add_cpu));
}