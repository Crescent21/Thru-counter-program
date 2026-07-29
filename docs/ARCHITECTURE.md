# Architecture

Welcome to the Architecture Guide for the *Thru Counter Program*.

This document explains how the smart contract works internally. If you're new to blockchain development, don't worry—everything is explained step by step.

---

# What is Architecture?

Architecture describes how different parts of the project work together.

Think of it like the blueprint of a house.

Before building a house, you need a blueprint showing where everything goes.

A smart contract works the same way.

---

# High-Level Overview

The Thru Counter Program follows a simple workflow.


User
   │
   ▼
Thru CLI
   │
   ▼
Blockchain
   │
   ▼
Counter Smart Contract
   │
   ▼
Counter Account
   │
   ▼
Updated Counter Value


Every time a user sends a transaction, it follows this path.

---

# Main Components

The project is made up of five important parts.

## 1. User

The user is the person interacting with the smart contract.

Examples include:

- Developer
- Tester
- Blockchain user

The user sends commands using the Thru CLI.

Example:

bash
thru txn execute ...


---

## 2. Thru CLI

The Thru Command Line Interface (CLI) is the bridge between you and the blockchain.

Instead of communicating directly with the blockchain, you use the CLI.

The CLI packages your command into a transaction and sends it to the network.

---

## 3. Blockchain

The blockchain receives the transaction.

Its job is to:

- Verify the transaction.
- Execute the smart contract.
- Store the updated data permanently.

---

## 4. Smart Contract

The smart contract is the brain of the application.

It contains all the rules for how the counter should behave.

Supported instructions include:

- Create Counter
- Increment Counter
- Decrement Counter
- Reset Counter

Every transaction is processed here.

---

## 5. Counter Account

The counter account stores the counter value.

Example:


Counter = 12


Whenever the smart contract updates the counter, the new value is saved here.

---

# Program Flow

Let's see what happens when you increment the counter.


User

↓

Runs Command

↓

Thru CLI

↓

Transaction Created

↓

Blockchain

↓

Smart Contract

↓

Reads Counter

↓

Adds One

↓

Stores New Value

↓

Emits Event

↓

Returns Success


---

# Create Counter Flow


User

↓

Execute Create Instruction

↓

Create Account

↓

Allocate Storage

↓

Initialize Counter

↓

Counter = 0

↓

Success


---

# Increment Flow


Current Counter

↓

Read Value

↓

+1

↓

Store Updated Value

↓

Emit Event

↓

Return Success


Example

Before


Counter = 7


After


Counter = 8


---

# Decrement Flow


Current Counter

↓

Read Value

↓

Check if Value > 0

↓

Subtract One

↓

Store Updated Value

↓

Emit Event

↓

Return Success


Example

Before


Counter = 4


After


Counter = 3


If the counter is already zero:

Before


Counter = 0


After


Counter = 0


The smart contract prevents negative values.

---

# Reset Flow


Read Counter

↓

Replace Value

↓

0

↓

Store Value

↓

Emit Event

↓

Success


Example

Before


Counter = 23


After


Counter = 0


---

# Event Flow

Whenever the counter changes, the smart contract emits an event.


Counter Updated

↓

Blockchain Event

↓

Application Receives Event

↓

Display Updated Counter


Events allow applications to react whenever the counter changes.

---

# Error Handling

The smart contract checks for common problems before updating the counter.

Examples include:

- Invalid instruction
- Counter account not found
- Account not writable
- Invalid instruction data

If any of these checks fail, the transaction is rejected to protect the blockchain state.

---

# Why This Architecture?

This design keeps the project:

- Simple
- Easy to understand
- Easy to maintain
- Easy to extend

Future instructions such as *Multiply, **Divide, or **Set Counter* can be added without changing the overall structure.

---

# Summary

The Thru Counter Program follows a straightforward architecture:


User
   │
   ▼
Thru CLI
   │
   ▼
Blockchain
   │
   ▼
Smart Contract
   │
   ▼
Counter Account
   │
   ▼
Updated Value


This separation of responsibilities makes the project easy to understand for beginners while demonstrating the core concepts of blockchain smart contract development
