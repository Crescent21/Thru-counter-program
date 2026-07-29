# Thru Counter Program

A simple smart contract written in **C** using the **Thru SDK** that demonstrates how to create and manage an on-chain counter.

This project is designed for beginners learning blockchain development with Thru. It explains how to create a blockchain account, store on-chain data, update state, and emit events through simple counter operations.

---

# Features

The Thru Counter Program currently supports four instructions:

## ✅ Create Counter

Creates a new counter account on the blockchain and initializes its value.

Initial value:

```
Counter = 0
```

---

## ✅ Increment Counter

Increases the counter value by **1**.

Example:

```
Before: 5

After : 6
```

---

## ✅ Decrement Counter

Decreases the counter value by **1**.

The counter will never go below zero.

Example:

```
Before: 3

After : 2
```

---

## ✅ Reset Counter

Resets the counter back to **0**.

Example:

```
Before: 15

After : 0
```

---

# Why This Project?

This project demonstrates important blockchain concepts, including:

- Smart contract development
- On-chain account creation
- Persistent state management
- Reading and writing account data
- Event emission
- Instruction handling
- Transaction execution

It serves as an excellent starting point for developers who want to learn how blockchain programs work.

---

# Project Structure

```
Thru-counter-program/

├── docs/
│   ├── API.md
│   ├── ARCHITECTURE.md
│   ├── DEPLOYMENT.md
│   ├── INSTALL.md
│   ├── SCREENSHOTS.md
│   └── USAGE.md
│
├── examples/
│   ├── tn_counter_program.c
│   ├── tn_counter_program.h
│   └── Local.mk
│
├── screenshots/
│
├── README.md
├── CONTRIBUTING.md
├── CHANGELOG.md
├── LICENSE
└── GNUmakefile
```

---

# Prerequisites

Before running this project, make sure you have:

- Git
- Make
- Thru SDK
- A supported Linux environment (recommended)

---

# Installation

Clone the repository.

```bash
git clone https://github.com/Crescent21/Thru-counter-program.git
```

Move into the project.

```bash
cd Thru-counter-program
```

Build the smart contract.

```bash
make
```

If the build completes successfully, the compiled binary will be available inside:

```
build/thruvm/bin/
```

---

# Deployment

Create the program.

```bash
thru program create thru_program build/thruvm/bin/tn_counter_program_c.bin
```

Check its status.

```bash
thru program status thru_program
```

Generate the counter address.

```bash
thru program derive-address <PROGRAM_ID> count_acc
```

Convert the seed to hexadecimal.

```bash
thru program seed-to-hex count_acc
```

For a complete deployment walkthrough, see:

```
docs/DEPLOYMENT.md
```

---

# Usage

The program supports the following operations:

- Create Counter
- Increment Counter
- Decrement Counter
- Reset Counter

Detailed examples and explanations are available in:

```
docs/USAGE.md
```

---

# Documentation

Additional documentation can be found in the **docs** folder.

| Document | Description |
|----------|-------------|
| INSTALL.md | Installation guide |
| DEPLOYMENT.md | Deployment guide |
| USAGE.md | Usage examples |
| API.md | API reference |
| ARCHITECTURE.md | Internal architecture |
| SCREENSHOTS.md | Project screenshots |

---

# Example Workflow

```
Build Project
      │
      ▼
Create Program
      │
      ▼
Create Counter
      │
      ▼
Increment
      │
      ▼
Increment
      │
      ▼
Decrement
      │
      ▼
Reset
```

---

# Roadmap

Future improvements may include:

- Set Counter Value
- Multiply Counter
- Divide Counter
- Multiple Counter Accounts
- Automated Testing
- CI/CD Integration
- Additional Examples

---

# Contributing

Contributions are welcome!

If you'd like to improve this project:

1. Fork the repository.
2. Create a feature branch.
3. Make your changes.
4. Test your changes.
5. Submit a Pull Request.

For more information, read:

```
CONTRIBUTING.md
```

---

# Changelog

See:

```
CHANGELOG.md
```

for the history of project updates.

---

# License

This project is licensed under the **MIT License**.

See the `LICENSE` file for details.

---

# Acknowledgements

- Thru SDK
- Thru Blockchain Community
- Open Source Contributors

---

# Author

**Toyosi**

GitHub: https://github.com/Crescent21
