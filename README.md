# Reaction Time Game

## Overview
The **Reaction Time Game** is a simple terminal-based game that tests how quickly you can react to a prompt. The game randomly delays a signal, and once it appears, you must press **Enter** as fast as possible. Your reaction time is recorded, and at the end of the session, your average reaction time is calculated.

## Features
- Randomized delay before the reaction prompt (1 to 3 seconds)
- Early key press detection
- Reaction time measurement in seconds (up to microsecond precision)
- Keeps track of multiple rounds
- Calculates and displays your average reaction time at the end

## How to Play
1. Run the program.
2. Wait for the **REACT!** prompt.
3. Press **Enter** as quickly as you can.
4. Choose whether to play another round or quit.
5. At the end, view your average reaction time.

## Compilation and Execution
### Requirements
- GCC or any C compiler
- A terminal (Linux/macOS or Windows with WSL or MinGW)

### Compilation
```bash
# Compile the game
make
```

### Run the Game
```bash
# Execute the compiled program
./reaction_time_game
```

## Code Structure
- `reaction_game.h`: Contains function prototypes and necessary includes.
- `reaction_game.c`: Implements the main game logic, including:
  - `main()`: Manages the game loop and calculates averages.
  - `play_round()`: Handles reaction timing and early press detection.
  - `calculate_average_reaction_time()`: Computes the average reaction time.
  - `detect_early_press()`: Checks for key presses during the delay.
  - `wait_for_keypress()`: Pauses until user input.

## Future Improvements
- Add a scoring system based on reaction times.
- Implement a graphical interface.
- Allow users to set custom delay ranges.
- Add a leaderboard for high scores.

## License
This project is open-source and available under the MIT License.

---

Happy reacting! 🚀



