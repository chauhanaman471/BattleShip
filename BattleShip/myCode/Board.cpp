/**
 * @file Board.cpp
 * @brief Implementation file for the Board class, which manages the game board
 *        containing both the player's grid (OwnGrid) and the opponent's grid
 *        (OpponentGrid).
 *
 * @author Aman Chauhan
 * @date 31 Dec 2024
 * @version 1.0
 * @note Master student at Hochschule Darmstadt
 * @matriculation_number 1127928
 */

#include "Board.h"

/**
 * @brief Getter method to retrieve the number of columns in the board.
 *
 * @return The number of columns in the grid.
 */
int Board::getColumns() const {
    return columns;
}

/**
 * @brief Getter method to retrieve the opponent's grid.
 *
 * This method is used when you need to access or print the opponent's grid.
 *
 * @return A constant reference to the opponent's grid.
 */
const OpponentGrid& Board::getOpponentGrid() const {
    return opponentGrid;
}

/**
 * @brief Getter method to retrieve the player's grid.
 *
 * This method is used when you need to access or print the player's grid.
 *
 * @return A constant reference to the player's grid.
 */
const OwnGrid& Board::getOwnGrid() const {
    return ownGrid;
}

/**
 * @brief Getter method to retrieve the number of rows in the board.
 *
 * @return The number of rows in the grid.
 */
int Board::getRows() const {
    return rows;
}

/**
 * @brief Constructor to initialize the board with the given rows and columns.
 *
 * @param rows The number of rows in the grid.
 * @param columns The number of columns in the grid.
 */
Board::Board(int rows, int columns)
    : rows{rows}, columns{columns}, ownGrid{rows, columns},
	  opponentGrid{rows, columns} {
}

/**
 * @brief Getter method to retrieve the player's grid for modification.
 *
 * This method is used when you need to modify the player's grid (e.g., placing
 * ships).
 *
 * @return A reference to the player's grid.
 */
OwnGrid& Board::getOwnGrid() {
    return ownGrid;
}

/**
 * @brief Getter method to retrieve the opponent's grid for modification.
 *
 * This method is used when you need to modify the opponent's grid (e.g.,
 * registering shot results).
 *
 * @return A reference to the opponent's grid.
 */
OpponentGrid& Board::getOpponentGrid() {
    return opponentGrid;
}
