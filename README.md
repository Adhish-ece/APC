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
Standard primitive types in C (`int`, `long int`, `long long int`) are constrained by hardware limits (32-bit or 64-bit) and overflow when dealing with extremely large numbers.

**APC (Arbitrary Precision Calculator)** bypasses standard integer limits by storing digits dynamically inside **Doubly Linked Lists**. This enables accurate arithmetic operations on numbers of virtually unlimited length, bounded only by system memory.

---

## ✨ Features
- **Unlimited Precision Arithmetic:** Perform operations on numbers with hundreds or thousands of digits.
- **Core Math Operations:**
  - Addition (`+`)
  - Subtraction (`-`)
  - Multiplication (`*`)
  - Division (`/`)
- **Dynamic Memory Allocation:** Allocates node memory dynamically for digit blocks.
- **Sign & Zero-Padding Logic:** Supports positive/negative values and automatically strips leading zeros.

---

## 🛠️ Tech Stack
- **Language:** C
- **Data Structure:** Doubly Linked Lists
- **Build Tools:** GCC / GNU Make

---

## 🚀 Getting Started

### Prerequisites
Ensure you have a standard C compiler installed on your system:
- **GCC** or **Clang**
- **Make** (optional)

### Installation

1. **Clone the repository:**
   ```bash
   git clone https://github.com/Adhish-ece/APC.git
   ```

2. **Navigate into the project directory:**
   ```bash
   cd APC
   ```

3. **Compile the program:**
   ```bash
   make
   ```

---

## 💻 Usage

Run the compiled executable from your terminal:

```bash
./apc
```

---

## 📁 Project Structure

```text
APC/
├── main.c           # Program entry point and menu driver
├── add.c            # Addition algorithm implementation
├── sub.c            # Subtraction algorithm implementation
├── mul.c            # Multiplication algorithm implementation
├── div.c            # Division algorithm implementation
├── apc.h            # Header file with struct definitions & prototypes
├── Makefile         # Build automation script
└── README.md        # Project documentation
```

---

## 🤝 Contributing

Contributions, bug reports, and feature requests are welcome!

1. Fork the project repository.
2. Create your feature branch (`git checkout -b feature/NewFeature`)
3. Commit your changes (`git commit -m "Add NewFeature"`)
4. Push to the branch (`git push origin feature/NewFeature`)
5. Open a Pull Request.

---

## 📝 License

Distributed under the MIT License. See `LICENSE` for details.

---

## 📬 Contact

**Adhish** — [@Adhish-ece](https://github.com/Adhish-ece)

Project Link: [https://github.com/Adhish-ece/APC](https://github.com/Adhish-ece/APC)
