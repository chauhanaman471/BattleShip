/**
 * @file ConsoleView.h
 * @brief Header file for the ConsoleView class, which handles the visualization
 *        and printing of the game board in the console.
 *
 * @author Aman Chauhan
 * @date 2 Jan 2025
 * @version 1.0
 * @note Master student at Hochschule Darmstadt
 * @matriculation_number 1127928
 */

#ifndef CONSOLEVIEW_H_
#define CONSOLEVIEW_H_
#include "Board.h"

/**
 * @class ConsoleView
 * @brief Class responsible for displaying the game board in the console view.
 */
class ConsoleView {
private:
    Board *board; /**< Pointer to the Board object containing the game grids. */

public:
    /**
     * @brief Constructor to initialize the ConsoleView with a pointer to Board.
     *
     * @param board Pointer to Board object that holds the grids & game data.
     */
    ConsoleView(Board *board);

    /**
     * @brief Method to print the game board to the console.
     */
    void print() const;
};

#endif /* CONSOLEVIEW_H_ */
