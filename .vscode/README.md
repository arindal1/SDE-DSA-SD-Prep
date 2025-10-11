# 🧩 C++ Build and Run Setup (VS Code + MinGW)

This repository contains a ready-to-use **VS Code configuration** for compiling and running C++ programs with **MinGW**.
It includes support for **I/O redirection**, making it perfect for **competitive programming** or **DSA practice**.

---

## ⚙️ Features

* 🧱 **Automatic compilation** using `g++` (C++17)
* 📥 **Input redirection** from `input.txt`
* 📤 **Output redirection** to `output.txt`
* 💡 **Integrated IntelliSense** for C++ with MinGW
* 🧰 **Simple single-file builds** — no CMake needed

---

## 📁 Folder Structure

```
.
├── .vscode/
│   ├── tasks.json            # Defines build & run tasks
│   ├── c_cpp_properties.json # IntelliSense + compiler config
├── input.txt                 # Input file (for redirection)
├── output.txt                # Output file (generated automatically)
└── main.cpp                  # Your C++ source file
```

---

## 🚀 How to Use

1. **Install MinGW** and ensure `g++` is added to your system PATH.
2. **Open this folder in VS Code**.
3. Create or open any `.cpp` file (e.g., `main.cpp`).
4. Add your test input to `input.txt`.
5. Press **Ctrl + Shift + B** → select **“Run with I/O redirection”**.

Your program will:

* Compile with `g++`
* Read input from `input.txt`
* Write output to `output.txt`

---

## 🛠️ Example

**main.cpp**

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    cout << a + b << endl;
    return 0;
}
```

**input.txt**

```
5 7
```

**output.txt (after run)**

```
12
```

---

## 🧠 Notes

* Uses **C++17 standard** (`-std=c++17`)
* Output executable is named after the file (e.g., `main.exe`)
* Compatible with **Windows + MinGW**
* Update paths in `.vscode/c_cpp_properties.json` if your MinGW location differs

