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
![Game Start](https://github.com/user-attachments/assets/570300a2-16a2-43ed-92ea-2dd6b4bbd581)
## In-Game
![In-Game](https://github.com/user-attachments/assets/75a31b21-0921-45f0-b2e5-941526fe89fe)
## Game Over
![Game Over](https://github.com/user-attachments/assets/5c91e969-69e9-445e-a425-5802b30f3571)

## 🎥 Gameplay Video
[Watch the Gameplay](screenshots/gameplay.mp4)


## 🎯 Conclusion
This Tetris game provides a fun and engaging console experience while demonstrating C++ programming concepts, including real-time input handling, game loops, and logic optimization. Future improvements may include additional game modes and a graphical user interface.

---

