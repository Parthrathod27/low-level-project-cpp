# 🎮 Tic Tac Toe Game (C++ | OOP Based)

A **console-based Tic Tac Toe game** developed in **C++ using Object-Oriented Programming (OOP)** principles.  
This project focuses on clean architecture, modular design, and core C++ concepts such as classes, encapsulation, and game logic separation.

---

## 🚀 Features

- Two Player Game  
  - Player 1 → **X**  
  - Player 2 → **O**
- Fully **OOP-based design**
- 3×3 game board using a 2D array
- Turn-based gameplay
- Input validation:
  - Handles non-numeric input
  - Validates input range (1–9)
  - Prevents overwriting occupied positions
- Win detection:
  - Rows
  - Columns
  - Diagonals
- Draw condition after 9 valid moves
- Clean and readable console output

---

## 🧠 Object-Oriented Design

### 🟦 Board Class
- Manages the 3×3 grid
- Displays the board
- Places player moves
- Checks win conditions

### 🟩 Player Class
- Stores player name
- Stores player symbol (X / O)

### 🟥 Game Class
- Controls the game loop
- Handles turn switching
- Validates user input
- Determines win or draw

---

## 🛠️ Technologies Used

- **Language:** C++
- **Programming Paradigm:** Object-Oriented Programming (OOP)
- **Concepts Covered:**
  - Classes & Objects
  - Encapsulation
  - Constructors
  - Conditional Logic
  - Loops
  - Input Validation
  - Game Loop Design

---

## ▶️ How to Run the Project

1. Clone the repository
   ```bash
   git clone <your-repository-link>
