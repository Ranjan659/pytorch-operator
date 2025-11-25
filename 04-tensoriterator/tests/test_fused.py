import torch
from my_ops import fused_mul_add

x = torch.randn(100, 100)
y = torch.randn(100, 100)
z = torch.randn(100, 100)

result = fused_mul_add(x, y, z)
expected = x * y + z

assert torch.allclose(result, expected, rtol=1e-5, atol=1e-6)
print("04-tensoriterator: SUCCESS — You just used the same tool as PyTorch core!")