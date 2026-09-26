# APC - Arbitrary Precision Calculator 🚀

Welcome to **APC** (Arbitrary Precision Calculator), designed and implemented by [@Adhish-ece](https://github.com/Adhish-ece).

---

## 📋 Table of Contents
- [About](#-about)
- [Features](#-features)
- [Tech Stack](#-tech-stack)
- [Getting Started](#-getting-started)
  - [Prerequisites](#prerequisites)
  - [Installation](#installation)
- [Usage](#-usage)
- [Project Structure](#-project-structure)
- [Contributing](#-contributing)
- [License](#-license)
- [Contact](#-contact)

---

## 💡 About
Standard integer types in C (`int`, `long int`, `long long int`) are constrained by hardware limits (32-bit or 64-bit) and overflow when dealing with extremely large numbers.

**APC (Arbitrary Precision Calculator)** bypasses primitive integer limits by storing digits dynamically inside **Doubly Linked Lists**. This enables arithmetic operations on numbers of virtually unlimited length, limited only by available system RAM.

---

## ✨ Features
- **Unlimited Precision Arithmetic:** Compute operations on numbers with hundreds or thousands of digits.
- **Core Math Operations:**
  - Addition (`+`)
  - Subtraction (`-`)
  - Multiplication (`*`)
  - Division (`/`)
- **Dynamic Memory Allocation:** Memory is requested dynamically per digit block using doubly linked nodes.
- **Sign & Zero-Padding Logic:** Full support for positive/negative signs and automatic removal of leading zeros.

---

## 🛠️ Tech Stack
- **Language:** C
- **Data Structure:** Doubly Linked Lists
- **Build Tools:** GCC / GNU Make

---

## 🚀 Getting Started

### Prerequisites
Make sure you have a C compiler installed on your system:
- **GCC** or **Clang**
- **Make** (optional)

### Installation

1. Clone the repository:
   git clone https://github.com/Adhish-ece/APC.git

2. Navigate into the repository:
   cd APC

3. Compile the program using GCC:
   gcc *.c -o apc

---

## 💻 Usage

Run the compiled executable from your terminal:

./apc

### Example Usage:
Enter two large numbers alongside the operator:
123456789012345678901234567890 + 987654321098765432109876543210

Output:
1111111110111111111011111111100

---

## 📁 Project Structure

APC/
├── main.c           # Program entry point and menu driver
├── add.c            # Addition algorithm logic
├── sub.c            # Subtraction algorithm logic
├── mul.c            # Multiplication algorithm logic
├── div.c            # Division algorithm logic
├── apc.h            # Function declarations and structure definition
├── Makefile         # Build script
└── README.md        # Project documentation

---

## 🤝 Contributing

Contributions, issues, and feature requests are welcome!

1. Fork the repository
2. Create your feature branch (`git checkout -b feature/NewFeature`)
3. Commit your changes (`git commit -m 'Add NewFeature'`)
4. Push to the branch (`git push origin feature/NewFeature`)
5. Open a Pull Request

---

## 📝 License

Distributed under the MIT License. See `LICENSE` for details.

---

## 📬 Contact

**Adhish** - [@Adhish-ece](https://github.com/Adhish-ece)

Project Link: https://github.com/Adhish-ece/APC
