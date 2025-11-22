import torch
from my_ops import add_tensors

a = torch.randn(5, 5)
b = torch.randn(5, 5)
result = add_tensors(a, b)

print("Result :", result)
print("\n Matches torch.add?", torch.allclose(result, a + b))
print("Complete 1!,--- First C++ PYTORCH CODE")