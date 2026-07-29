# API Reference

Welcome to the API Reference for the *Thru Counter Program*.

This document explains every instruction supported by the smart contract, what it does, when to use it, and what to expect after execution.

---

# Overview

The Thru Counter Program currently supports four instructions.

| Instruction | Purpose |
|------------|---------|
| Create Counter | Creates and initializes a new counter account |
| Increment Counter | Increases the counter value by 1 |
| Decrement Counter | Decreases the counter value by 1 |
| Reset Counter | Sets the counter value back to 0 |

---

# Counter Account

The counter value is stored inside a blockchain account.

Example


Counter = 10


Whenever an instruction is executed, this stored value is updated.

---

# 1. Create Counter

## Description

Creates a new counter account on the blockchain.

If the account already exists, you should not create it again.

---

## Why is it Important?

Before a smart contract can store data, it needs an account to hold that data.

Think of it like creating an empty notebook before writing anything inside it.

Without creating the counter account first, Increment, Decrement and Reset will fail.

---

## Command Used

bash
thru txn execute \
--fee 0 \
--readwrite-accounts \
<COUNTER_ACCOUNT> \
<PROGRAM_ID> \
<CREATE_INSTRUCTION_DATA>


---

## What Happens?

The program:

1. Creates the account.
2. Makes the account writable.
3. Allocates storage.
4. Sets the counter value to *0*.
5. Returns success.

---

## Expected Output

text
Transaction Successful

Counter Created

Counter Value : 0


---

# 2. Increment Counter

## Description

Adds *1* to the current counter value.

---

## Why is it Important?

Incrementing is useful for:

- Counting users
- Tracking visitors
- Recording votes
- Counting transactions
- Keeping statistics

---

## Command Used

bash
thru txn execute \
--fee 0 \
--readwrite-accounts \
<COUNTER_ACCOUNT> \
<PROGRAM_ID> \
<INCREMENT_INSTRUCTION_DATA>


---

## What Happens?

The program:

1. Reads the current value.
2. Adds *1*.
3. Saves the updated value.
4. Emits an event.

---

## Example

Before


Counter = 5


After


Counter = 6


---

## Expected Output

text
Transaction Successful

Previous Value : 5

Current Value : 6


---

# 3. Decrement Counter

## Description

Subtracts *1* from the counter.

---

## Why is it Important?

Many applications require values to decrease.

Examples include:

- Remaining inventory
- Available seats
- Vote removal
- Resource tracking

---

## Safety Check

The counter cannot become negative.

If the value is already zero, it stays at zero.

---

## Command Used

bash
thru txn execute \
--fee 0 \
--readwrite-accounts \
<COUNTER_ACCOUNT> \
<PROGRAM_ID> \
<DECREMENT_INSTRUCTION_DATA>


---

## Example

Before


Counter = 8


After


Counter = 7


---

## Expected Output

text
Transaction Successful

Previous Value : 8

Current Value : 7


---

# 4. Reset Counter

## Description

Resets the counter back to zero.

---

## Why is it Important?

Instead of creating another counter account, you can simply reuse the current one.

This is useful for:

- Starting over
- Clearing statistics
- Testing
- Restarting an application

---

## Command Used

bash
thru txn execute \
--fee 0 \
--readwrite-accounts \
<COUNTER_ACCOUNT> \
<PROGRAM_ID> \
<RESET_INSTRUCTION_DATA>


---

## Example

Before


Counter = 25


After


Counter = 0


---

## Expected Output

text
Transaction Successful

Previous Value : 25

Current Value : 0


---

# Event Emission

Whenever the counter changes, the smart contract emits an event.

Events allow applications to know that the counter value has changed.

Example:


Counter Updated

New Value : 9


---

# Common Errors

## Counter Account Not Found

### Cause

The counter account has not been created.

### Solution

Create the counter account before using any other instruction.

---

## Account Not Writable

### Cause

The transaction does not have permission to modify the counter account.

### Solution

Make sure the account is included as a writable account.

---

## Invalid Instruction

### Cause

The instruction data sent to the program is incorrect.

### Solution

Verify that the correct instruction data is being used.

---

## Invalid Program ID

### Cause

The transaction is being sent to the wrong smart contract.

### Solution

Double-check the Program ID before executing the transaction.

---

# Summary

The Thru Counter Program provides four simple instructions:


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


Together, these instructions demonstrate how a smart contract can create accounts, store data, modify on-chain state, and emit events
