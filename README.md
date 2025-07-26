# 🎮 Tic Tac Toe Console Game in C++

A feature-rich **Tic Tac Toe game** built in C++ for the Windows console. This game supports:

- 🧑‍🤝‍🧑 Player vs Player (PvP) mode
- 🤖 Player vs Computer (PvC) mode with basic AI
- 🎨 Animated text and full-screen console borders for better UX
- 🧠 Smart AI move blocking logic
- 🔁 Replay and main menu system

---

## 🛠️ Features

- Custom console UI with full-screen borders and cursor positioning
- Input validation (e.g., empty, out-of-range, and invalid characters)
- Clean board rendering with stylized layout
- Smart AI (blocks user win or takes winning move if available)
- Multiple game sessions with a menu system

---

## ▶️ How to Play

### 1. Compile the Program

Make sure you have a **C++ compiler** that supports the Windows API (like `g++` via MinGW or Dev-C++).

Use the following command in your terminal:

```bash
g++ -o tictactoe.exe tictactoe.cpp -std=c++11
```

> Replace `tictactoe.cpp` with the filename if different.

### 2. Run the Game

```bash
./tictactoe.exe
```

### 3. Menu Options

You will be prompted with a menu:
- **1** – Player vs Player
- **2** – Player vs Computer
- **3** – Exit Game

---

## 🧠 AI Logic (PvC Mode)

The AI plays as **O** and:
1. Tries to win if possible.
2. Otherwise, blocks the player if they're about to win.
3. Else, selects the next available spot.

---

## ⌨️ Controls

- Enter numbers **1-9** to select a board position.
- Positions map like this:

```
1 | 2 | 3
---------
4 | 5 | 6
---------
7 | 8 | 9
```

---

## 📦 Dependencies

- Windows-only: Uses **Windows.h** for cursor control and border drawing.
- C++ Standard Libraries: `<iostream>`, `<chrono>`, `<thread>`, `<limits>`, etc.

---

## 📸 Screenshots

> You can add screenshots here later to demonstrate PvP mode, PvC mode, and the win/draw screen.

---

## ⚠️ Known Limitations

- Windows-only (due to use of `windows.h` and `SetConsoleCursorPosition`)
- Console UI only (no graphics or sound)
- No score tracking yet

---

## 🙋‍♂️ Author

Developed by **Chamikara Prabhashwara Dikkumbura**  
📧 Contact: _[add your email or GitHub link if desired]_

---

## 📄 License

This project is open-source. You can freely modify and distribute it for educational or personal use.
