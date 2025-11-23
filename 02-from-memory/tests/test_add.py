import torch
from my_ops import add_tensors

a = torch.randn(6, 6)
b = torch.randn(6, 6)
result = add_tensors(a, b)

print("Result :", result)
print("\n Matches torch.add?", torch.allclose(result, a + b))
print("Complete 2!,--- Rewrite C++ PYTORCH CODE")