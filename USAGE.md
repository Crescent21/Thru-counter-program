# Usage Guide

Welcome to the **Thru Counter Program**.

This guide explains how to use the smart contract after it has been built and deployed.

---

# Prerequisites

Before using this program, ensure that:

- The Thru SDK is installed.
- The project has been built successfully.
- The smart contract has been deployed.
- You have a valid Program ID.
- You have created or have access to a counter account.

---

# Supported Instructions

The counter program supports the following operations:

- Create Counter
- Increment Counter
- Decrement Counter
- Reset Counter

---

# 1. Create Counter

## What is it?

The **Create Counter** instruction creates a new on-chain counter account and initializes its value.

Every counter must be created before it can be incremented, decremented or reset.

---

## Why is it Important?

Without creating the counter account first, the smart contract has no place to store the counter value.

This instruction initializes the account and prepares it for future transactions.

---

## Example

```bash
thru txn execute \
  --program <PROGRAM_ID> \
  --instruction create \
  --account <COUNTER_ACCOUNT>
```

---

## Expected Output

```text
Transaction Successful

Counter Account Created

Counter Value: 0
```

---

## Result

Before:

```
Counter does not exist
```

After:

```
Counter = 0
```

---

# 2. Increment Counter

## What is it?

The Increment instruction increases the counter value by **1**.

---

## Why is it Important?

Incrementing is commonly used in blockchain applications to:

- Count users
- Count votes
- Track transactions
- Record application activity
- Generate sequential identifiers

---

## Example

```bash
thru txn execute \
  --program <PROGRAM_ID> \
  --instruction increment \
  --account <COUNTER_ACCOUNT>
```

---

## Expected Output

```text
Transaction Successful

Previous Value : 4

Current Value  : 5
```

---

## Result

Before

```
Counter = 4
```

After

```
Counter = 5
```

---

# 3. Decrement Counter

## What is it?

The Decrement instruction decreases the counter value by **1**.

---

## Why is it Important?

Useful when tracking:

- Remaining inventory
- Available slots
- Vote removal
- Task completion
- Resource consumption

The counter never goes below zero.

---

## Example

```bash
thru txn execute \
  --program <PROGRAM_ID> \
  --instruction decrement \
  --account <COUNTER_ACCOUNT>
```

---

## Expected Output

```text
Transaction Successful

Previous Value : 8

Current Value  : 7
```

---

## Result

Before

```
Counter = 8
```

After

```
Counter = 7
```

---

# 4. Reset Counter

## What is it?

Reset sets the counter value back to **0**.

---

## Why is it Important?

Instead of deleting and recreating a counter account, Reset allows you to reuse the existing account.

This is useful for:

- Starting a new counting cycle
- Clearing statistics
- Resetting application state
- Testing

---

## Example

```bash
thru txn execute \
  --program <PROGRAM_ID> \
  --instruction reset \
  --account <COUNTER_ACCOUNT>
```

---

## Expected Output

```text
Transaction Successful

Previous Value : 23

Current Value  : 0
```

---

## Result

Before

```
Counter = 23
```

After

```
Counter = 0
```

---

# Complete Example Workflow

```
Create Counter
        │
        ▼
Counter = 0
        │
        ▼
Increment
        │
        ▼
Counter = 1
        │
        ▼
Increment
        │
        ▼
Counter = 2
        │
        ▼
Increment
        │
        ▼
Counter = 3
        │
        ▼
Decrement
        │
        ▼
Counter = 2
        │
        ▼
Reset
        │
        ▼
Counter = 0
```

---

# Common Errors

## Counter Account Not Found

### Cause

The counter account has not been created.

### Solution

Run the Create Counter instruction first.

---

## Invalid Instruction

### Cause

The instruction type is incorrect.

### Solution

Ensure the correct instruction is being sent to the smart contract.

---

## Account Not Writable

### Cause

The transaction does not have write permission for the counter account.

### Solution

Mark the counter account as writable before executing the transaction.

---

# Best Practices

- Always create a counter before modifying it.
- Verify every transaction succeeds before sending another.
- Test your smart contract on a development environment before production.
- Keep your Program ID and account information organized.
- Use Reset instead of recreating the account when starting a new counting cycle.

---

# Next Step

After learning how to use the counter, continue to:

- **DEPLOYMENT.md** — Learn how to deploy the program.
- **API.md** — Explore the instruction reference and account layout.
- **ARCHITECTURE.md** — Understand how the smart contract works internally.
