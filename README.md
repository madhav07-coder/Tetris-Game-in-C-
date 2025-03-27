## Tetris Console Game - C++ Project Documentation

### 🖥️ Cross-Platform Support: Windows, macOS, and Linux

### Group: Code Experts

1. **202401204** - Shlok Nareshkumar Ukani
2. **202401239** - Vamja Krish Pravinbhai
3. **202401243** - Virugama Meetkumar Aniruddhbhai
4. **202401226** - Thesiya Madhav Manish

## 📌 Introduction

Tetris is a classic tile-matching puzzle game where players rotate and arrange falling tetrominoes to clear lines and earn points. This C++ implementation runs in a terminal window and features smooth gameplay mechanics, score tracking, and increasing difficulty over time.

## 🎮 Features

- **Classic Tetris Gameplay**: Play on a 10x20 grid with all seven standard tetrominoes (I, O, T, S, Z, J, L).
- **Real-Time Input & Dynamic Controls**:
  - Smooth movement and rotation using arrow keys.
  - Soft drop (↓) and hard drop (Spacebar) functionality.
  - **Hold Feature**: Store a tetromino for later use (activated with 'C').
  - Pause/resume game with the ESC key.
- **Dynamic Gravity & Scoring**:
  - The falling speed increases as you clear more lines.
  - Level advances every 5 lines cleared, further increasing game speed.
- **Visual Enhancements**:
  - Colorful tetrominoes using ANSI escape codes.
  - Real-time display of the next tetromino and the held tetromino.
- **High Score Management**:
  - Saves high scores to a file (`highscore.txt`).
  - Displays the highest score achieved across game sessions.
- **Cross-Platform Support**: Runs on Windows, macOS, and Linux with terminal-based rendering.

## 📂 File Structure
The project consists of the following files:

| File               | Description                                                                                    |
| ------------------ | ---------------------------------------------------------------------------------------------- |
| `block_stacks.cpp` | Contains the entire game logic, including game loop, rendering, input handling, and mechanics. |

## 🛠️ Game Mechanics
The game follows standard Tetris rules:

- **Tetromino Handling**: Pieces can move left, right, rotate, and drop.
- **Collision Detection**: Ensures valid movements within the grid.
- **Line Clearing**: Detects and removes full rows, shifting the board down.
- **Scoring System**: Points are awarded based on cleared lines.
- **Game Progression**: The falling speed increases as more lines are cleared.
- **Restart Feature**: After game over, players can restart by pressing 'R'.

## 🎮 Controls

| Key      | Action        |
| -------- | ------------- |
| ←        | Move left     |
| →        | Move right    |
| ↑        | Rotate piece  |
| ↓        | Soft drop     |
| Spacebar | Hard drop     |
| 'C'      | Hold piece    |
| ESC      | Pause/Quit    |
| 'R'      | Restart game  |

## 🚀 How to Run the Game

1. Compile the project using a C++ compiler:
   ```sh
   g++ block_stacks.cpp -o tetris_game
   ```
2. Run the executable:
   ```sh
   ./tetris_game   # Linux/macOS
   tetris_game.exe # Windows
   ```
3. Use the arrow keys and spacebar to play the game.

## 🏆 Scoring System

- 1 Line Cleared: 100 Points
- 2 Lines Cleared: 300 Points
- 3 Lines Cleared: 500 Points
- 4 Lines (Tetris): 800 Points
- Speed increases every 5 cleared lines.


## 📸 Screenshots
## Game Start 
![Game Start](https://github.com/user-attachments/assets/2f7f0a6a-d76f-4cef-92dc-a21b48e06704)

## In-Game
![In-Game](https://github.com/user-attachments/assets/a534452e-0ccc-4af6-a7d4-4721868ee471)

## Game Over
![Game Over](https://github.com/user-attachments/assets/79057b7e-1c93-4f79-a5b8-a38eaee0c419)

## 🎥 Gameplay Video
## 1
[https://github.com/user-attachments/assets/8b7a48e0-11b4-4c00-a1a7-ec098fa5fdfd](https://github.com/user-attachments/assets/e3c889b8-57fb-4fcc-a9ae-56a47a5a9daf)


## 🎯 Conclusion
This Tetris game provides a fun and engaging console experience while demonstrating C++ programming concepts, including real-time input handling, game loops, and logic optimization. Through features like the hold option, restart functionality, and high score tracking, it enhances the traditional Tetris gameplay while offering a challenging experience. This project helped us improve our understanding of game development, input handling, and terminal-based graphics using C++.

---


