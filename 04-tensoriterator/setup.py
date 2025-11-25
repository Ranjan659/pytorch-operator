from setuptools import setup
from torch.utils.cpp_extension import CppExtension, BuildExtension

setup(
    name="my_ops",
    version="0.0.4",
    packages=["my_ops"],
    ext_modules=[
        CppExtension(
            "my_ops._core",
            ["src/core.cpp"],
            extra_compile_args=["-O3", "-march=native"]
        )
    ],
    cmdclass={"build_ext": BuildExtension},
    zip_safe=False,
)