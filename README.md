# Account Manager (C++)

Short description of a project:
A simple file-based account management system written in C++. It allows users to create accounts, store them as text files, and retrieve account information using a unique card number.

---

## Table of contents

* [Description](#description)
* [Current Features](#current-features)
* [Planned Features](#planned-features)
* [How to Run](#how-to-run)
* [Example Output](#example-output)
* [Authors](#authors)

---

## Description

The Account Manager project is a simple C++ program that manages user accounts using file storage. Each account contains personal information such as first name, last name, birth year, and a discount reason.

When an account is created, the program generates a unique card number using the user’s birth year combined with a random number. This card number is used as the filename and stored inside the `accounts/` directory.

The system can also verify existing accounts by reading the corresponding file, loading the data, and displaying it to the user.

---

## Current Features

- Create a new account with personal details
- Generate a unique card number
- Save account data into a `.txt` file
- Verify if an account exists using card number
- Load and display account information from file
- Basic error handling for missing accounts

---

## Planned Features

- Prevent duplicate card numbers
- Add password authentication
- Add ability to update account details
- Add account deletion feature
- Migrate from file storage to database system

---

## How to Run

Compile:

```bash
g++ Ticket_machine.cpp -o program
```

---

## Example output

Example of a user buying a ticket with an existing account and getting full discount due to veteran status:

<img width="537" height="469" alt="image" src="https://github.com/user-attachments/assets/119da310-7175-4fe6-ab61-b7036286dd32" />

Example of a user buying a reduced ticket with no account:

<img width="476" height="484" alt="image" src="https://github.com/user-attachments/assets/f3d30950-df66-4191-b241-550d22506d67" />

Account creation menu:

<img width="455" height="550" alt="image" src="https://github.com/user-attachments/assets/6798d5c2-6fa3-4f1a-bd21-4d75d8d4fa7d" />

## Authors

* Dariusz Florków
* Alexander Elliott


