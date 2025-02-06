/**
 * @file OpponentGrid.cpp
 * @brief Implementation file for the OpponentGrid class, representing the
 *        opponent's grid in the game.
 *
 * @details This file contains the implementation of the OpponentGrid class
 *          which manages the opponent's ships, the result of the player's
 *          shots, and the sunken ships.
 *
 * @author Aman Chauhan
 * @date 31 Dec 2024
 * @version 1.0
 * @note Master student at Hochschule Darmstadt
 * @matriculation_number 1127928
 */

#include "OpponentGrid.h"
#include <iostream>
#include <set>

using namespace std;

/**
 * @brief Getter method to retrieve the number of columns in the opponent grid.
 *
 * @return The number of columns in the grid.
 */
int OpponentGrid::getColumns() const {
    return columns;
}

/**
 * @brief Getter method to retrieve the number of rows in the opponent grid.
 *
 * @return The number of rows in the grid.
 */
int OpponentGrid::getRows() const {
    return rows;
}

/**
 * @brief Getter method to retrieve the list of sunken ships.
 *
 * @return A constant reference to the vector of sunken ships.
 */
const std::vector<Ship>& OpponentGrid::getSunkenShip() const {
    return sunkenShip;
}

/**
 * @brief Constructor to initialize the OpponentGrid with specified rows and
 *        columns.
 *
 * @param rows The number of rows in the grid.
 * @param columns The number of columns in the grid.
 */
OpponentGrid::OpponentGrid(int rows, int columns) : rows{rows}, columns{columns}
{}

/**
 * @brief Getter method to retrieve the map of shots and their impacts.
 *
 * @return A constant reference to the map of shot impacts.
 */
const std::map<GridPosition, Shot::Impact>& OpponentGrid::getShots() const {
    return shots;
}

/**
 * @brief Getter method to retrieve the list of opponent's ships.
 *
 * @return A constant reference to the vector of opponent's ships.
 */
const std::vector<Ship>& OpponentGrid::getOpponentShips() const {
    return opponentShips;
}

/**
 * @brief Method to record the result of a shot and update the impacts on the
 *        opponent grid.
 *
 * @details This method updates the grid with the result of a shot fired by
 *          the player. It checks whether the shot hits an opponent's ship and
 *          whether the ship is sunk as a result of the shot.
 *
 * @param shot The shot object fired by the player.
 * @param impact The impact of the shot (HIT, SUNKEN, or NONE).
 */
void OpponentGrid::shotResult(const Shot& shot, Shot::Impact impact) {
    // Update map shots with the target shot position (GridPosition) and impact
    GridPosition targetShotPosition = shot.getTargetPosition();
    shots[targetShotPosition] = impact;

    // Check if the opponent's ship is hit
    for (const auto& ship : opponentShips) {
        std::set<GridPosition> opponentShipOccupiedPos = ship.occupiedArea();

        if (opponentShipOccupiedPos.find(targetShotPosition) !=
                opponentShipOccupiedPos.end()) {
            cout << "Opponent ship is hit by the player" << endl;

            // Check if the shot sinks the ship
            bool isSunken = true;
            for (const auto& shipPos : opponentShipOccupiedPos) {
                if (shots.find(shipPos) == shots.end() ||
                    (shots[shipPos] != Shot::Impact::HIT &&
                     shots[shipPos] != Shot::Impact::SUNKEN)) {
                    isSunken = false;
                    break;
                }
            }

            if (isSunken) {
                cout << "Opponent ship is sunken by the player" << endl;
                sunkenShip.push_back(ship);

                // Mark all positions of the ship as SUNKEN
                for (const auto& shipPos : opponentShipOccupiedPos) {
                    shots[shipPos] = Shot::Impact::SUNKEN;
                }
            }
            return; // No need to check further ships
        }
    }
}

/**
 * @brief Default constructor to initialize an empty OpponentGrid with no rows
 *        or columns.
 *
 * @details This constructor sets grid's rows and columns to zero, indicating
 *          an uninitialized state.
 */
OpponentGrid::OpponentGrid() {
    rows = 0;
    columns = 0;
}
