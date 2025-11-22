# 1-First-Extension

This project is a **PyTorch C++ extension** example.  
It demonstrates how to write a simple custom C++ operator, compile it as a Python module, and call it from Python.

## Project Structure
1-first-extension/
├── src/
│   └── core.cpp                   # C++ source for the add_tensors operator
├── my_ops/
│   ├── init.py                # Python wrapper for the extension
├── tests/
│   └── test_add.py                # Simple test for add_tensors
├── setup.py                       # Build script for the extension
├── pyproject.toml                 # Ensures torch is available during build
└── README.md                       # This file


## Requirements

- Python 3.10+ (tested on 3.12)
- PyTorch 2.x
- C++ compiler
  - Linux/macOS: `g++` or `clang`
  - Windows: MSVC (Visual Studio Build Tools)

**Recommended:** Use a virtual environment

```bash
python -m venv venv
source venv/bin/activate          # Linux/macOS
# or
venv\Scripts\activate             # Windows

Installation
Install in editable mode (this builds the C++ extension):
Bashpip install -e .