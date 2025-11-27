import torch
from my_ops import my_mul_add

x = torch.randn(10, 10)
y = torch.randn(10, 10)
z = torch.randn(10, 10)

out = my_mul_add(x, y, z)
expected = x * y + z

assert torch.allclose(out, expected)
print("05-dispatcher: SUCCESS — You just registered a real PyTorch operator!")
print("torch.ops.my_namespace.my_mul_add:", torch.ops.my_namespace.my_mul_add)