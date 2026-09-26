# APC - Arbitrary Precision Calculator 🚀

Welcome to **APC** (Arbitrary Precision Calculator), hosted by [@Adhish-ece](https://github.com/Adhish-ece).

---

## 📋 Table of Contents
- [About](#-about)
- [Features](#-features)
- [Tech Stack](#-tech-stack)
- [Getting Started](#-getting-started)
  - [Prerequisites](#prerequisites)
  - [Installation](#installation)
- [Usage](#-usage)
- [Contributing](#-contributing)
- [License](#-license)
- [Contact](#-contact)

---

## 💡 About
Standard integer types in C (such as `int` or `long long int`) have memory constraints and fixed limits (e.g., 64-bit). **APC** overcomes these limits by performing arithmetic operations on numbers of arbitrary length using custom dynamic data structures like Doubly Linked Lists.

---

## ✨ Features
- **Arbitrary Precision Arithmetic:** Perform operations on numbers exceeding standard primitive data type limits.
- **Supported Operations:** Addition, Subtraction, Multiplication, and Division.
- **Efficient Memory Usage:** Dynamically allocates memory for digits using linked data structures.
- **Sign Handling:** Handles positive and negative numbers correctly during operations.

---

## 🛠️ Tech Stack
- **Language:** C
- **Data Structures:** Doubly Linked Lists
- **Build System:** GCC / Make

---

## 🚀 Getting Started

### Prerequisites
Make sure you have a C compiler installed on your system:
- **GCC / Clang**
- **Make** (optional, for automated compilation)

### Installation

1. Clone the repository:
   git clone https://github.com/Adhish-ece/APC.git

2. Navigate to the project directory:
   cd APC

3. Compile the source code using GCC:
   gcc *.c -o apc_calculator

---

## 💻 Usage

Run the compiled executable to start the calculator:

./apc_calculator

Example command format inside the program:
<operand1> <operator> <operand2>
Example: 12345678901234567890 + 98765432109876543210

---

## 🤝 Contributing

Contributions are welcome!

1. Fork the Project
2. Create your Feature Branch (`git checkout -b feature/AmazingFeature`)
3. Commit your Changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the Branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

---

## 📝 License

Distributed under the MIT License. See `LICENSE` for details.

---

## 📬 Contact

**Adhish** - [@Adhish-ece](https://github.com/Adhish-ece)

Project Link: https://github.com/Adhish-ece/APC
