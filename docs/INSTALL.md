# Installation Guide

Welcome! 👋

This guide will help you install everything you need to build and run the **Thru Counter Program**.

If this is your first time using the Thru SDK, don't worry—we'll go through each step together.

---

# What You'll Need

Before you begin, make sure you have:

- A computer running **Ubuntu Linux** (Ubuntu 22.04 or later is recommended)
- An internet connection
- A terminal
- About 2 GB of free storage

---

# Step 1 — Update Your System

Open your terminal and run:

```bash
sudo apt update
sudo apt upgrade -y
```

This updates your system packages and helps prevent installation problems.

---

# Step 2 — Install Git

Git is used to download projects from GitHub.

Install Git by running:

```bash
sudo apt install git -y
```

Check that Git was installed successfully:

```bash
git --version
```

You should see something like:

```
git version 2.xx.x
```

---

# Step 3 — Install the Thru SDK

The Thru SDK contains everything needed to build and deploy Thru smart contracts.

Follow the official installation guide provided by the Thru team.

After installation, verify it by running:

```bash
thru --version
```

If you see a version number, the SDK is installed correctly.

If you get:

```
thru: command not found
```

the SDK has not been installed correctly or it isn't in your PATH.

---

# Step 4 — Verify the Compiler

The Thru SDK installs the RISC-V compiler used to build smart contracts.

Check that it works:

```bash
riscv64-unknown-elf-gcc --version
```

If a version number is displayed, you're ready to build.

---

# Step 5 — Download This Project

Clone the repository:

```bash
git clone git@github.com:Crescent21/Thru-counter-program.git
```

Move into the project folder:

```bash
cd Thru-counter-program
```

---

# Step 6 — Build the Smart Contract

Compile the project by running:

```bash
make
```

If everything is installed correctly, you should see messages showing the project being compiled and linked.

When the build finishes successfully, the compiled program will be created inside:

```
build/thruvm/
```

---

# Troubleshooting

## "thru: command not found"

The Thru SDK is either not installed or not available in your terminal.

Try reopening your terminal after installing the SDK.

---

## "make: command not found"

Install Make:

```bash
sudo apt install make -y
```

---

## Build Errors

If the project fails to build:

1. Check that the Thru SDK is installed correctly.
2. Verify the RISC-V compiler is available.
3. Run:

```bash
make clean
make
```

---

# What's Next?

Congratulations! 🎉

If your build completed successfully, you're ready to deploy the smart contract.

Continue to:

**`docs/DEPLOYMENT.md`**
