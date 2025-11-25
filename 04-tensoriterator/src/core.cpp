#include<ATen/TensorIterator.h>
#include<torch/extension.h>

at::Tensor fused_mul_add(const at::Tensor& x, const at::Tensor& y, at::Tensor& z){

    at::Tensor out = at::empty_like(x);

    auto iter = at::TensorIteratorConfig()
                .add_output(out)
                .add_input(x)
                .add_input(y)
                .add_input(z)
                .build();

    iter.for_each([&](char** data, const int64_t* strides, int64_t n) {
        for (int64_t i = 0; i < n; i++) {

            float xv = *reinterpret_cast<float*>(data[1] + i * strides[1]);
            float yv = *reinterpret_cast<float*>(data[2] + i * strides[2]);
            float zv = *reinterpret_cast<float*>(data[3] + i * strides[3]);

            *reinterpret_cast<float*>(data[0] + i * strides[0]) =
                xv * yv + zv;
        }
    });
    return out;
}

PYBIND11_MODULE(TORCH_EXTENSION_NAME, m) {
  m.def("fused_mul_add", &fused_mul_add, "4: x * y + z using TensorIterator ");
}