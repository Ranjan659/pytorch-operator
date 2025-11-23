#include<torch/extension.h>

torch::Tensor add_tensors(torch::Tensor a, torch::Tensor b){
    TORCH_CHECK(a.device() == b.device(), "Both tensors must be on same device");
    TORCH_CHECK(a.sizes() == b.sizes(), "Shapes must match");
    TORCH_CHECK(a.scalar_type() == b.scalar_type(), "Dtypes must match");

    return a + b;
}

PYBIND11_MODULE(TORCH_EXTENSION_NAME, m){
    m.def("add_tensors", &add_tensors, "1: Add two tensors in c++");
}