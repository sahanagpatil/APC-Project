# Arbitrary Precision Calculator (APC)

## Description

This project performs arithmetic operations on very large integers using a doubly linked list.

📌 Project Overview

The Arbitrary Precision Calculator (APC) is a calculator application developed in C to perform arithmetic operations on large numbers that exceed the standard data types supported by C. It uses a doubly linked list to store and process individual digits, enabling calculations with large integers without relying on built-in numeric limits.

✨ Features

- Addition of large integers(+)
- Subtraction of large integers(-)
- Multiplication of large integers(*)
- Division of large integers(/)
- Sign validation and handling
- Comparison of large numbers
- Doubly linked list implementation for digit storage
- Modular program structure for easy maintenance

🛠️ Technologies Used

- Programming Language: C
- Data Structure: Doubly Linked List
- Build Tool: Makefile
- Development Environment: Visual Studio Code and Ubuntu/Linux

📂 Project Structure

APC-Project/
├── main.c
├── apc.h
├── addition.c
├── subtraction.c
├── multiplication.c
├── division.c
├── compare.c
├── check_sign.c
├── dll.c
├── Makefile
└── README.md

⚙️ How to Compile and Run

Prerequisites

- GCC compiler
- GNU Make
- Linux or Ubuntu environment

Step 1: Clone the Repository

git clone <your-repository-url>

Step 2: Navigate to the Project Directory

cd APC-Project

Step 3: Compile the Project

make

### Step 4: Run the Application

Run the compiled executable:

```bash
./apc
```

If the required command-line arguments are not provided, the program displays the usage instructions:

```text
Usage: ./a.out <operand1> <operator> <operand2>
```

**Example:**

```bash
./apc 12345678901234567890 + 98765432109876543210
```

*Note: The example assumes your program accepts `+` as the addition operator and supports these operands.*
*Note: The executable name and build commands depend on the rules defined in the Makefile.*


🧮 Supported Operations

Operation                  | Description
Addition (+)               | Adds two large integers
Subtraction (-)            | Subtracts one large integer from another
Multiplication (*)         | Multiplies large integers
Division (/)               | Divides one integer by another
Comparison                 | Compares two integers
Sign handling              | Processes positive and negative numbers

🧠 Concepts Demonstrated

- Pointers and dynamic memory management
- Doubly linked lists
- Modular programming in C
- Arithmetic algorithms
- Header files and function declarations
- Compilation using Makefile
- Input validation and sign handling

🎯 Learning Outcomes

- Improved understanding of linked-list data structures
- Practical implementation of arithmetic operations in C
- Experience organizing a multi-file C project
- Familiarity with compiling and debugging C applications in Linux

👩‍💻 Author

Sahana Patil
B.E. Electrical & Electronics Engineering
Embedded Systems Enthusiast
