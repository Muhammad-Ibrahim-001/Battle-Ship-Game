# 🚢 Battleship Game (C++ Console Version)

A fully interactive two-player Battleship game built in C++ for the terminal. This project implements ship placement, rotation, attack logic, win detection, and persistent game history logging.

---

## 🎮 Game Overview

This is a classic Battleship game where two players:

- Place ships on a 10×10 grid
- Rotate ships (Vertical / Horizontal)
- Take turns attacking each other
- Win by destroying all opponent ships

The game runs entirely in the console with colored UI elements and ASCII styling.

---

## 🛠 Features

- ✔ 10×10 grid system (A–J rows, 1–10 columns)
- ✔ 4 ship types with different sizes
- ✔ Ship rotation support
- ✔ Input validation (row/column checks)
- ✔ Turn-based attack system
- ✔ Hit (`A`) and Miss (`*`) indicators
- ✔ Win detection
- ✔ Game history logging to file (`Gamesplayed.txt`)
- ✔ Game log viewer from main menu
- ✔ Colored console UI

---

## 🚢 Ship Types

| Ship        | Symbol | Size |
|-------------|--------|------|
| Carrier     | C      | 5    |
| Battleship  | B      | 4    |
| Cruiser     | D      | 3    |
| Destroyer   | S      | 2    |

---

## 📦 Project Structure
```
Battleship/
│
├── main.cpp
├── Gamesplayed.txt   (created automatically after first game)
└── README.md
```

---

## ▶ How to Compile & Run

### Using g++ (Linux / Mac / Windows with MinGW)
```bash
g++ main.cpp -o battleship
./battleship
```

### Using Visual Studio

1. Create a new C++ Console Project
2. Replace `main.cpp` with this file
3. Build and Run

---

## 🎯 How to Play

### 1️⃣ Start Menu

- `1` → Play
- `2` → View Game Log
- `3` → Exit

### 2️⃣ Enter Player Names

If left empty:
- Player 1 defaults to **RED**
- Player 2 defaults to **BLUE**

### 3️⃣ Ship Placement

- Select ship: `C`, `B`, `D`, `S`
- Choose rotation:
  - `1` → Vertical
  - `2` → Horizontal
- Enter position:
  - Row: `A–J`
  - Column: `1–10`

**Example:**
```
A5
```

### 4️⃣ Attack Phase

Players take turns entering attack coordinates:
```
Enter the Location to attack (Example: A4)
```

- `A` → Hit
- `*` → Miss
- Ships are hidden from the opponent's board view

Type `Es` to exit the match early.

---

## 🏆 Win Condition

A player wins when all opponent ship cells are destroyed. The result is:

- Displayed on screen
- Saved to `Gamesplayed.txt`

**Example log entry:**
```
Ibrahim Vs Ali     Ibrahim won
```

---

## 💾 Game History

Game results are stored in `Gamesplayed.txt`. You can view past matches from the main menu.

---

## 🖥 Technical Details

- **Language:** C++
- **Libraries used:**
  - `<iostream>`
  - `<iomanip>`
  - `<chrono>`
  - `<thread>`
  - `<fstream>`
- ANSI escape sequences used for colored console output
- File handling used for persistent match logging

---

## 📌 Notes

- Designed for terminal/console environments.
- ANSI colors may not work properly on very old Windows terminals.
- Input validation is implemented to prevent invalid ship placement and attack positions.

---


## 👨‍💻 Author
**Muhammad Ibrahim**

