# 🏦 Digital Banking System (C++)

A **console-based Digital Banking / ATM System** written in **C++**, inspired by basic SBI-style banking operations. This project is suitable for **beginners** and **low-level C++ practice**, focusing on OOP concepts, input/output handling, and menu-driven programs.

---

## 📌 Features

* Create a bank account
* Deposit money
* Withdraw money (with balance check)
* View account details
* Menu-driven console interface
* Loading animation for better UX

---

## 🛠️ Technologies Used

* **Language:** C++
* **Concepts:**

  * Classes & Objects (OOP)
  * Encapsulation
  * Conditional statements
  * Loops
  * Functions
  * Basic terminal control

---

## 📂 Project Structure

```bash
ATM_system/
│
├── code.cpp        # Main source code
└── README.md       # Project documentation
```

---

## ▶️ How to Run the Program

### 🔹 On Linux / macOS

```bash
g++ code.cpp -o atm
./atm
```

### 🔹 On Windows (MinGW)

```bash
g++ code.cpp -o atm.exe
atm.exe
```

---

## 📖 Program Flow

1. Program starts with a welcome screen
2. User chooses whether to create an account
3. User enters:

   * Name
   * Initial deposit
4. Main menu appears:

   * Deposit money
   * Withdraw money
   * Check balance
   * Exit
5. Program runs until the user exits

---

## 🧠 Sample Menu

```
========== SBI MENU ==========
1. Deposit Money
2. Withdraw Money
3. Check Balance
4. Exit
================================
```

---

## ⚠️ Limitations

* Supports **only one user** at a time
* No file handling (data is lost after program ends)
* No input validation for invalid data types (can be improved)

---

## 🚀 Future Improvements

* Add file handling to store account data
* Support multiple user accounts
* Add PIN authentication
* Improve input validation
* Cross-platform screen clearing

---

## 🎯 Learning Outcome

This project helps in understanding:

* How real-world systems can be simulated using C++
* Menu-driven program design
* Object-Oriented Programming fundamentals

---

## 👨‍💻 Author

**Parth Rathod**
Low-Level C++ Projects

---

⭐ If you found this project helpful, don’t forget to star the repository!
