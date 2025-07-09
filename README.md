# Terminal Hacker Game 🔐

A simple terminal-based number guessing game written in C++. The player takes on the role of a secret agent trying to hack into secure server rooms by solving number puzzles.

## 🎮 How to Play

Each level presents you with:
- A **sum** and **product** of 3 hidden numbers.
- You must **guess all 3 numbers** correctly using the hints.

You advance to the next level if your guess is correct. Complete all levels to win the game!

## 💡 Game Features

- 5 levels of increasing difficulty.
- Randomized code every time using `rand()` and `srand()`.
- Basic input validation.
- Console-based gameplay.

## 🛠 How to Compile & Run

### Linux / MacOS (using gcc):
```bash
gcc game.c -o game
./game
