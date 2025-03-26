# Tetris-Console-Game-C++

## Tetris Game - C++ Project Documentation

### 🖥️ Cross-Platform Support: Windows, macOS, and Linux

### Group: Code Experts
1. **202401204** - Shlok Nareshkumar Ukani
2. **202401239** - Vamja Krish Pravinbhai
3. **202401243** - Virugama Meetkumar Aniruddhbhai
4. **202401226** - Thesiya Madhav Manish

## 📌 Introduction
Tetris is a tile-matching puzzle game where players rotate and arrange falling tetrominoes to clear lines and earn points. This C++ implementation runs in a terminal window and features smooth gameplay mechanics, score tracking, and progressive difficulty.

## 🎮 Features
- Classic 10x20 Tetris grid.
- Implementation of all seven standard tetrominoes (I, O, T, S, Z, J, L).
- Real-time user input handling with smooth movement and rotation.
- Dynamic gravity system that increases speed as the game progresses.
- Line-clearing mechanics with score tracking.
- Pause and resume functionality.
- Game-over detection when blocks reach the top.
- **Colorful UI**: Each tetromino is displayed in a unique color for better visual distinction.
- **Cross-Platform Support**: Runs on Windows, macOS, and Linux with terminal-based rendering.

## 📂 File Structure
The project consists of the following files:

| File | Description |
|------|------------|
| `main.cpp` | The only source file, containing the entire game logic, including game loop, rendering, input handling, and mechanics. |

## 🛠️ Game Mechanics
The game is structured to follow basic Tetris mechanics:
- **Tetromino Handling**: Pieces can move left, right, rotate, and drop.
- **Collision Detection**: Ensures valid movements within the grid.
- **Line Clearing**: Detects and removes full rows, shifting the board.
- **Scoring System**: Points are awarded based on cleared lines.
- **Game Progression**: The falling speed increases as more lines are cleared.

## 🎮 Controls
| Key | Action |
|-----|--------|
| ← | Move left |
| → | Move right |
| ↑ | Rotate piece |
| ↓ | Soft drop |
| Spacebar | Hard drop |
| ESC | Pause/Quit |

## 🚀 How to Run the Game
1. Compile the project using a C++ compiler:
   ```sh
   g++ main.cpp -o tetris_game
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
- Speed increases every 10 cleared lines

## 📸 Screenshots
## Game Start 
![Game Start](https://github.com/user-attachments/assets/6cbbcf8a-ced7-4d4b-ba9e-8ae24a97d639)

## In-Game
![In-Game](https://github.com/user-attachments/assets/aa85aea4-d98f-4855-8e71-fcd8ef48c878)

## Game Over
![Game Over](https://github.com/user-attachments/assets/5cf3fda3-3f9f-4304-ba1f-8f48a8d486d0)


## 🎥 Gameplay Video
## 1
https://github.com/user-attachments/assets/8b7a48e0-11b4-4c00-a1a7-ec098fa5fdfd
## 2
https://github.com/user-attachments/assets/d51f90e0-283c-4860-b599-b452e0d65872


## 🎯 Conclusion
This Tetris game provides a fun and engaging console experience while demonstrating C++ programming concepts, including real-time input handling, game loops, and logic optimization. We learn many interseting things from this project

---

