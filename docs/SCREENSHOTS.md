# Screenshots

Welcome!

This document contains screenshots of the *Thru Counter Program*.

Screenshots help beginners understand what they should expect to see while building, deploying and testing the project.

---

# Why are Screenshots Important?

When learning something new, reading commands is sometimes not enough.

Screenshots help you:

- Verify that you are following the correct steps.
- Compare your terminal output with the examples.
- Quickly identify mistakes.
- Build confidence while learning.

---

# 1. Project Folder

This screenshot shows the project after cloning it from GitHub.

Example:


my-thru-project/

├── build/
├── docs/
├── examples/
├── screenshots/
├── README.md
├── GNUmakefile
└── LICENSE


Screenshot:

> Add an image named:


screenshots/project-folder.png


---

# 2. Building the Project

Run:

bash
make


This compiles the smart contract.

Expected terminal output:


Compiling...

Linking...

Creating binary...

Creating assembly dump...


Screenshot:


screenshots/build-success.png


---

# 3. Program Creation

Run:

bash
thru program create thru_program build/thruvm/bin/tn_counter_program_c.bin


This uploads the compiled program to the blockchain.

Expected Output:


Program created successfully.


Screenshot:


screenshots/program-create.png


---

# 4. Program Status

Run:

bash
thru program status thru_program


Purpose:

Verify that your smart contract was created successfully.

Expected Output:


Program Status

Ready


Screenshot:


screenshots/program-status.png


---

# 5. Derive Counter Address

Run:

bash
thru program derive-address <PROGRAM_ID> count_acc


Purpose:

Generate the blockchain address that stores the counter.

Screenshot:


screenshots/derive-address.png


---

# 6. Convert Seed to Hex

Run:

bash
thru program seed-to-hex count_acc


Purpose:

Convert the seed into hexadecimal format.

Expected Output:


636f756e745f616363


Screenshot:


screenshots/seed-to-hex.png


---

# 7. Create Counter

Run the Create Counter transaction.

Purpose:

Initialize the counter.

Expected Result:


Counter = 0


Screenshot:


screenshots/create-counter.png


---

# 8. Increment Counter

Run the Increment instruction.

Purpose:

Increase the counter by one.

Example:

Before


Counter = 0


After


Counter = 1


Screenshot:


screenshots/increment-counter.png


---

# 9. Decrement Counter

Run the Decrement instruction.

Purpose:

Reduce the counter value by one.

Example:

Before


Counter = 5


After


Counter = 4


Screenshot:


screenshots/decrement-counter.png


---

# 10. Reset Counter

Run the Reset instruction.

Purpose:

Reset the counter to zero.

Example:

Before


Counter = 15


After


Counter = 0


Screenshot:


screenshots/reset-counter.png


---

# 11. GitHub Repository

Take a screenshot of your GitHub repository homepage after pushing your project.

This helps visitors see the final project structure.

Screenshot:


screenshots/github-homepage.png


---

# Tips for Taking Good Screenshots

- Use a clean terminal.
- Increase the terminal font size if needed.
- Capture the full command and its output.
- Avoid showing sensitive information such as private keys or tokens.
- Use clear, high-resolution images.

---

# Conclusion

Screenshots make documentation easier to follow, especially for beginners.

As you continue improving the project, update this folder with new screenshots to keep the documentation current.
