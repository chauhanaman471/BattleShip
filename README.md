# Battleship Game Project

## Overview
This project is an Object-Oriented implementation of the classic Battleship game in C++. It provides a grid-based model where a player can arrange ships, track shots, and determine hits and sunken ships. The game is designed as a single-player version where players interact with a command-line interface to manage their board and track their opponent's moves manually.

## Features
### 1. Game Mechanics
- Representation of ships, shots, and board states.
- Validation of ship placement based on standard Battleship rules.
- Tracking of shots and displaying hits, misses, and sunken ships.

### 2. Object-Oriented Design
- Uses STL containers (`vector`, `map`, `set`) for data handling.

### 3. Console-Based User Interface
- Displays the board with player and opponent grids.
- Allows users to place ships and track shots interactively.

## Usage
After running the program, users can:
- Arrange ships on their grid.
- Track their shots and the opponent's shots.
- View the game board updates after each move.

## Code Structure
- `GridPosition.cpp/.h`: Represents a grid cell on the board.
- `Ship.cpp/.h`: Defines ships and their placement rules.
- `Board.cpp/.h`: Manages the player and opponent grids.
- `ConsoleView.cpp/.h`: Handles the display of the game board.


