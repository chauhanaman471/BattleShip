/**
 * @file ConsoleView.cpp
 * @brief Implementation file for the ConsoleView class, which prints the game
 *        board in the console.
 *
 * @author Aman Chauhan
 * @date 2 Jan 2025
 * @version 1.0
 * @note Master student at Hochschule Darmstadt
 * @matriculation_number 1127928
 */

#include "ConsoleView.h"
#include <iostream>
using namespace std;
#include <vector>

/**
 * @brief Constructor to initialize the ConsoleView with a pointer to the Board.
 *
 * @param board Pointer to the Board object that holds the game data.
 */
ConsoleView::ConsoleView(Board *board) : board{board} {
}

/**
 * @brief Method to print the game board for both player and opponent grids.
 *        It displays the grids side by side with appropriate markings for
 *        ships, hits, misses, and sunken ships.
 */
void ConsoleView::print() const {
    // Print board dimensions
    cout << "Board dimension: rows> " << board->getRows() << endl;
    cout << "Board dimension: columns> " << board->getColumns() << endl << endl;

    cout << "Player Grid \t\t\t\t\t" << "Opponent Grid" << endl;

    // Print column headers for both grids
    cout << " "; // Space for row labels

    // Print column numbers for player grid
    for (int playerColumnIndex = 1; playerColumnIndex <= board->getColumns();
         playerColumnIndex++) {
        if (playerColumnIndex != 10) {
            cout << "  "; // Two spaces for all columns except the 10th
        } else {
            cout << " 1 "; // Align 1 above column 10
            cout << "\t\t\t ";
            // Print column numbers for opponent grid
            for (int opponentColumnIndex = 1; opponentColumnIndex <=
                 board->getColumns(); opponentColumnIndex++) {
                if (opponentColumnIndex != 10) {
                    cout << "  "; // Two spaces for all columns except the 10th
                } else {
                    cout << " 1 "; // Align 1 above column 10
                }
            }
        }
    }
    cout << endl;

    // Print second row with numbers 1-9 and 0 for both player & opponent grids
    cout << " "; // Space for row labels
    for (int playerColumnIndex = 1; playerColumnIndex <= board->getColumns();
         playerColumnIndex++) {
        cout << " " << playerColumnIndex % 10; // Print column numbers
    }
    cout << "\t\t\t ";
    for (int opponentColumnIndex = 1; opponentColumnIndex <=
         board->getColumns(); opponentColumnIndex++) {
        cout << " " << opponentColumnIndex % 10; // Print column numbers
    }
    cout << endl;

    // Initialize player and opponent grids with '~' (water)
    vector<vector<char>> playerBoardGrid(board->getRows(),
                                        vector<char>(board->getColumns(), '~'));
    vector<vector<char>> opponentBoardGrid(board->getRows(),
                                        vector<char>(board->getColumns(), '~'));

    // Mark player ship positions with '#'
    for (const auto& ship : board->getOwnGrid().getShips()) {
        for (const auto& shipOccupiedPos : ship.occupiedArea()) {
            playerBoardGrid[shipOccupiedPos.getRow() - 'A']
                           [shipOccupiedPos.getColumn() - 1] = '#';
        }
    }

    // Update player board with shots
    for (const auto& shotsPosition : board->getOwnGrid().getShotAt()) {
        bool isHit = false;
        for (const auto& shipOccupiedPos : board->getOwnGrid().getShips()) {
            if (shipOccupiedPos.occupiedArea().count(shotsPosition)) {
                isHit = true;
                break;
            }
        }
        if (isHit) {
            playerBoardGrid[shotsPosition.getRow() - 'A']
                           [shotsPosition.getColumn() - 1] = 'O'; // Hit
        } else {
            playerBoardGrid[shotsPosition.getRow() - 'A']
                           [shotsPosition.getColumn() - 1] = '^'; // Miss
        }
    }

    // Update opponent board with shots
    for (const auto& shot : board->getOpponentGrid().getShots()) {
        const GridPosition& shotPosition = shot.first;
        const Shot::Impact& impact = shot.second;

        if (impact == Shot::Impact::SUNKEN) {
            opponentBoardGrid[shotPosition.getRow() - 'A']
                             [shotPosition.getColumn() - 1] = '#';
        } else if (impact == Shot::Impact::HIT) {
            opponentBoardGrid[shotPosition.getRow() - 'A']
                             [shotPosition.getColumn() - 1] = 'O';
        } else if (impact == Shot::Impact::NONE) {
            opponentBoardGrid[shotPosition.getRow() - 'A']
                             [shotPosition.getColumn() - 1] = '^';
        }
    }

    // Print both grids side by side row by row
    char rowLabelValue = 'A'; // Starting ASCII value for row labels
    for (int rowIndex = 0; rowIndex < board->getRows(); rowIndex++) {
        cout << char(rowLabelValue) << " "; // Print row label for player grid
        for (int playerColumnIndex = 0; playerColumnIndex < board->getColumns();
             playerColumnIndex++) {
            cout << playerBoardGrid[rowIndex][playerColumnIndex] << " ";
        }

        cout << "\t\t\t"; // Space between grids

        cout << char(rowLabelValue) << " "; // Print row label for opponent grid
        for (int opponentColumnIndex = 0; opponentColumnIndex <
             board->getColumns(); opponentColumnIndex++) {
            cout << opponentBoardGrid[rowIndex][opponentColumnIndex] << " ";
        }

        cout << endl;
        rowLabelValue++; // Move to the next row label
    }
}
