# Deployment Guide

Welcome! 👋

This guide explains how to build, deploy, and use the **Thru Counter Program**.

If this is your first time deploying a smart contract, don't worry. Every step is explained in detail.

---

# Before You Begin

Before deploying the program, make sure you have completed the following:

- ✅ Installed the Thru SDK
- ✅ Installed Git
- ✅ Successfully built the project
- ✅ Internet connection
- ✅ A funded wallet/account (if required by your network)

---

# Step 1 — Open the Project

# Deployment Guide

Welcome! 👋

In this guide, you'll learn how to deploy the *Thru Counter Program* from scratch.

If you've never deployed a smart contract before, don't worry. We'll explain every command and what it does.

---

# Step 1 – Build the Program

Before deployment, you must compile the project.

Run:

bash
make


## What does this command do?

The make command compiles your C source code into a binary that can run on the Thru Virtual Machine (ThruVM).

## Expected Output

text
Compiling C source...
Linking Thru program...
Creating binary...
Creating assembly dump...


If you don't see any errors, your program has been built successfully.

---

# Step 2 – Create the Program

Now create your smart contract on the blockchain.

Run:

bash
thru program create thru_program build/thruvm/bin/tn_counter_program_c.bin


## What does this command do?

Let's break it down.

### thru program create

Creates a new smart contract on the blockchain.

### thru_program

This is the *seed* (name) used to generate your program address.

You can choose another name if you want.

### build/thruvm/bin/tn_counter_program_c.bin

This is the compiled smart contract that was created after running make.

---

## Expected Output

You should see something similar to:

text
Program created successfully.


---

# Step 3 – Check the Program Status

To verify the program exists, run:

bash
thru program status thru_program


## What does this do?

Checks whether your smart contract has been created successfully.

## Expected Output

text
Program Status

Ready


---

# Step 4 – Generate the Counter Account Address

The counter needs its own blockchain account to store data.

Generate it using:

bash
thru program derive-address <PROGRAM_ID> count_acc


Replace <PROGRAM_ID> with the address of your deployed program.

## What does this do?

It creates a deterministic account address using:

- your program
- the seed count_acc

Every time you use the same program and seed, you'll get the same address.

---

## Expected Output

text
Counter Address

taxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx


Save this address.

You'll use it whenever you interact with the counter.

---

# Step 5 – Convert the Seed to Hexadecimal

Run:

bash
thru program seed-to-hex count_acc


## Why is this needed?

The blockchain stores instruction data as hexadecimal (hex) instead of normal text.

This command converts:


count_acc


into its hexadecimal representation.

## Expected Output

text
636f756e745f616363


---

# Step 6 – Create the Counter Account

Now execute the Create instruction.

bash
thru txn execute \
  --fee 0 \
  --readwrite-accounts \
  <COUNTER_ACCOUNT> \
  <PROGRAM_ID> \
  <CREATE_INSTRUCTION_DATA>


## What does this command do?

- Executes a blockchain transaction.
- Creates the counter account.
- Initializes the counter value.
- Sets the starting value to *0*.

---

## Expected Output

text
Transaction Successful

Counter Created

Counter Value: 0


---

# Step 7 – Increment the Counter

Run:

bash
thru txn execute \
  --fee 0 \
  --readwrite-accounts \
  <COUNTER_ACCOUNT> \
  <PROGRAM_ID> \
  <INCREMENT_INSTRUCTION_DATA>


## What does this command do?

Reads the current counter value and increases it by *1*.

Example:

Before


Counter = 3


After


Counter = 4


---

## Expected Output

text
Transaction Successful

Previous Value : 3

Current Value : 4


---

# Step 8 – Decrement the Counter

After adding the decrement instruction to the project, run the corresponding transaction.

The program reduces the counter by *1*.

The counter will never go below zero.

---

# Step 9 – Reset the Counter

Run the Reset instruction.

The counter becomes:


0


This lets you reuse the same account without creating another one.

---

# Common Mistakes

## "Program not found"

The smart contract has not been created.

Run:

bash
thru program create ...


first.

---

## "Account not found"

The counter account has not been created yet.

Run the Create Counter instruction before trying Increment, Decrement or Reset.

---

## Build Failed

Make sure you ran:

bash
make


without errors.

---

# Complete Workflow


Build Project
      │
      ▼
Create Program
      │
      ▼
Check Program Status
      │
      ▼
Generate Counter Address
      │
      ▼
Convert Seed to Hex
      │
      ▼
Create Counter
      │
      ▼
Increment
      │
      ▼
Decrement
      │
      ▼
Reset


---

# Congratulations 🎉

You have successfully:

- Built a Thru smart contract.
- Created a blockchain program.
- Generated a counter account.
- Executed transactions.
- Updated on-chain state.

You now understand the complete deployment workflow of the Thru Counter Program.
