import torch

# This makes it feel like a real torch op!
def my_mul_add(x: torch.Tensor, y: torch.Tensor, z: torch.Tensor) -> torch.Tensor:
    return torch.ops.my_namespace.my_mul_add.default(x, y, z)

__all__ = ["my_mul_add"]