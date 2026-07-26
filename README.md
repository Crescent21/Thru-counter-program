# 🚀 Thru Counter Program

A simple smart contract written in *C* using the *Thru SDK*.

This project demonstrates the complete lifecycle of building and interacting with a smart contract on the Thru blockchain.

---

# Features

- ✅ Deploy a Counter Program
- ✅ Create Counter Account
- ✅ Generate State Proof
- ✅ Execute Transactions
- ✅ Increment Counter Value

### Coming Soon

- Decrement Counter
- Reset Counter
- Set Counter Value
- Access Control

---

# Prerequisites

Before starting, install:

- Ubuntu Linux
- Git
- GitHub Account
- Thru CLI
- Thru SDK

---

# Clone Repository

bash
git clone git@github.com:Crescent21/Thru-counter-program.git

cd thru-counter-program


---

# Build the Program

bash
make


---

# Deploy Program

bash
thru program deploy build/tn_counter_program.so


Example output


Program deployed successfully

Program ID:

taxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx


Save your Program ID.

---

# Derive Counter Address

bash
thru program derive-address <PROGRAM_ID> count_acc


Example


Derived Address:

taxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx


---

# Create State Proof

bash
thru txn make-state-proof creating <COUNTER_ACCOUNT>


Copy:

- Proof Size
- Proof Data

---

# Build Create Instruction

Instruction format


instruction_type
+
account_index
+
seed
+
proof_size
+
proof_bytes


Example


000000000200636f756e745f6163630000000000000000000000000000000000000000000000680000003502...


---

# Create Counter

bash
thru txn execute \
--fee 0 \
--readwrite-accounts <COUNTER_ACCOUNT> \
<PROGRAM_ID> \
<INSTRUCTION_DATA>


Expected Result


Execution Result: 0

State Units Consumed: 1


---

# Increment Counter

Instruction Data


010000000200


Execute

bash
thru txn execute \
--fee 0 \
--readwrite-accounts <COUNTER_ACCOUNT> \
<PROGRAM_ID> \
010000000200


---

# Verify Counter

bash
thru account get <COUNTER_ACCOUNT>


The counter value should increase every time you execute the increment transaction.

---

# Project Structure


.
├── examples/
│   └── tn_counter_program.c
├── include/
├── src/
├── Makefile
└── README.md


---

# Common Errors

## Git Push Failed


Repository not found


Solution

Verify your remote.

bash
git remote -v


---

## Authentication Failed


Password authentication is not supported.


Solution

Use SSH instead of HTTPS.

Generate SSH Key

bash
ssh-keygen -t ed25519 -C "your_email@example.com"


Start SSH Agent

bash
eval "$(ssh-agent -s)"


Add Key

bash
ssh-add ~/.ssh/id_ed25519


Copy Public Key

bash
cat ~/.ssh/id_ed25519.pub


Add it to GitHub:

Settings

↓

SSH and GPG Keys

↓

New SSH Key

Test

bash
ssh -T git@github.com


You should see


Hi <username>!

You've successfully authenticated.


---

# Useful Commands

Deploy

bash
thru program deploy


Derive Address

bash
thru program derive-address


Generate Proof

bash
thru txn make-state-proof


Execute Transaction

bash
thru txn execute


Git Push

bash
git push


---

# What I Learned

- Smart Contract Development
- C Programming
- Program Derived Addresses
- State Proofs
- Transaction Execution
- Account Management
- Git
- GitHub
- SSH Authentication

---

# Future Improvements

- Counter Decrement
- Counter Reset
- Counter Set Value
- Ownership Verification
- Event Logging

---

# Acknowledgements

Built using the Thru SDK.

Official Documentation:

https://docs.thru.org

---

## Author

GILGAMESH

GitHub

https://github.com/Crescent21
