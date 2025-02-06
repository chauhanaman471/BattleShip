/**
 * @file Board.h
 * @brief Header file for the Board class, representing the game board that
 *        contains both the player's grid (OwnGrid) and the opponent's grid
 *        (OpponentGrid).
 *
 * @details This class manages both grids and provides methods to access and
 *          modify the grids. It contains getter methods to retrieve both the
 *          player's and opponent's grids for various operations.
 *
 * @author Aman Chauhan
 * @date 31 Dec 2024
 * @version 1.0
 * @note Master student at Hochschule Darmstadt
 * @matriculation_number 1127928
 */

#ifndef BOARD_H_
#define BOARD_H_

#include "OwnGrid.h"
#include "OpponentGrid.h"
/**
 * @class Board
 * @brief Class responsible for representing the game board containing
 * player grid and opponent grid.
 */
class Board {
private:
    int rows; ///< The number of rows in the board.
    int columns; ///< The number of columns in the board.
    OwnGrid ownGrid; ///< The player's grid (OwnGrid object).
    OpponentGrid opponentGrid; ///< The opponent's grid (OpponentGrid object).

public:
    /**
     * @brief Constructor to initialize the board with the given rows & columns.
     *
     * @param rows The number of rows in the grid.
     * @param columns The number of columns in the grid.
     */
    Board(int rows, int columns);

    /**
     * @brief Getter method to retrieve the number of columns in the board.
     *
     * @return The number of columns in the grid.
     */
    int getColumns() const;

    /**
     * @brief Getter method to retrieve the number of rows in the board.
     *
     * @return The number of rows in the grid.
     */
    int getRows() const;

    /**
     * @brief Getter method to retrieve the opponent's grid.
     *
     * This method is used when you need to access or print the opponent's grid.
     * It provides a constant reference to the opponent's grid.
     *
     * @return A constant reference to the opponent's grid.
     */
    const OpponentGrid& getOpponentGrid() const;

    /**
     * @brief Getter method to retrieve the player's grid.
     *
     * This method is used when you need to access or print the player's grid.
     * It provides a constant reference to the player's grid.
     *
     * @return A constant reference to the player's grid.
     */
    const OwnGrid& getOwnGrid() const;

    /**
     * @brief Getter method to retrieve the player's grid for modification.
     *
     * This method is used when you need to modify the player's grid (e.g.,
     * placing ships).
     *
     * @return A reference to the player's grid.
     */
    OwnGrid& getOwnGrid();

    /**
     * @brief Getter method to retrieve the opponent's grid for modification.
     *
     * This method is used when you need to modify the opponent's grid (e.g.,
     * registering shot results).
     *
     * @return A reference to the opponent's grid.
     */
    OpponentGrid& getOpponentGrid();
};

#endif /* BOARD_H_ */
