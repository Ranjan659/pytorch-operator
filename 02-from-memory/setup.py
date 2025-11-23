from setuptools import setup

def get_extensions():
    from torch.utils.cpp_extension import CppExtension
    return [
        CppExtension(
            "my_ops._core",
            ["src/core.cpp"],
            extra_compile_args=["-O3"],
        )
    ]

def get_cmdclass():
    from torch.utils.cpp_extension import BuildExtension
    return {"build_ext": BuildExtension}

setup(
    name="my_ops",
    version="0.0.2",
    packages=["my_ops"],
    ext_modules=get_extensions(),
    cmdclass=get_cmdclass(),
    zip_safe=False,
)
