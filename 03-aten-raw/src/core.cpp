#include <ATen/Tensor.h>
#include <ATen/Operators.h>
#include <torch/extension.h>

// Real ATen style — no torch::Tensor operator+ allowed
at::Tensor mul_add(const at::Tensor& x,
                   const at::Tensor& y,
                   const at::Tensor& z) {
    // These are the real ATen functions used in PyTorch core
    return at::add(at::mul(x, y), z);
}

PYBIND11_MODULE(TORCH_EXTENSION_NAME, m) {
    m.def("mul_add", &mul_add,
          "x * y + z using raw ATen (Day 3)",
          py::arg("x"), py::arg("y"), py::arg("z"));
}