#include <torch/library.h>
#include <ATen/TensorIterator.h>

// This is the REAL PyTorch way — no pybind11 def()!
at::Tensor my_mul_add_cpu(const at::Tensor& x,
                          const at::Tensor& y,
                          const at::Tensor& z) {
  auto out = at::empty_like(x);
  auto iter = at::TensorIteratorConfig()
      .add_output(out)
      .add_input(x)
      .add_input(y)
      .add_input(z)
      .build();

  iter.for_each([&](char** data, const int64_t* strides, int64_t n) {
    auto* o = reinterpret_cast<float*>(data[0]);
    auto* a = reinterpret_cast<float*>(data[1]);
    auto* b = reinterpret_cast<float*>(data[2]);
    auto* c = reinterpret_cast<float*>(data[3]);
    for (int64_t i = 0; i < n; ++i) {
      o[i] = a[i] * b[i] + c[i];
    }
  });
  return out;
}

// THIS IS THE DISPATCHER MAGIC
TORCH_LIBRARY(my_namespace, m) {
  m.def("my_mul_add", my_mul_add_cpu);  // schema inferred or explicit
}

// Register for CPU dispatch key
TORCH_LIBRARY_IMPL(my_namespace, CPU, m) {
  m.impl("my_mul_add", my_mul_add_cpu);
}