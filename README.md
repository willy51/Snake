# 🐍 Snake in C++ with SFML  

A **Snake** game built with **C++** and **SFML 3** 🎮. Eat apples 🍏 and beat your high score!  

## 🚀 Installation & Run  

1. **Install SFML** → [https://www.sfml-dev.org/download.php](https://www.sfml-dev.org/download.php)  
2. **Compile with CMake**:  
   ```bash
   mkdir build && cd build
   cmake ..
   cmake --build .
   ./SnakeGame
   ```
   **Or using g++**:  
   ```bash
   g++ -std=c++20 -o SnakeGame src/*.cpp -Iinclude -lsfml-graphics -lsfml-window -lsfml-system
   ./SnakeGame
   ```

## 🎮 Controls  
- **Arrow keys** → Move  

## 📌 Possible Improvements  
🔊 Sound | 🎨 Better Graphics | 🎖 Score Saving | 🎮 Multiplayer  

