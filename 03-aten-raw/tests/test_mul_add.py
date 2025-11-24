import torch
from my_ops import mul_add

x = torch.randn(5, 5)
y = torch.randn(5, 5)
z = torch.randn(5, 5)

result = mul_add(x, y, z)
expected = x * y + z

assert torch.allclose(result, expected)
print("03-aten-raw: SUCCESS — used real ATen functions like PyTorch core!")