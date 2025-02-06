/**
 * @file OwnGrid.cpp
 * @brief Implementation of the OwnGrid class, representing the player's grid.
 *
 * @details This file contains the implementation of the OwnGrid class, which
 *          handles the grid where the player's ships are placed, shot positions
 *          are tracked, and manages the placement logic of ships.
 *
 * @author Aman Chauhan
 * @date 27 Dec 2024
 * @version 1.0
 * @note Master student at Hochschule Darmstadt
 * @matriculation_number 1127928
 */

#include "OwnGrid.h"
#include <iostream>
#include <algorithm>  // Standard library for algorithms like set_intersection
#include <set>
using namespace std;

/**
 * @brief Getter method to retrieve the number of columns in the grid.
 *
 * @return The number of columns in the grid.
 */
int OwnGrid::getColumns() const {
    return columns;
}

/**
 * @brief Getter method to retrieve the number of rows in the grid.
 *
 * @return The number of rows in the grid.
 */
int OwnGrid::getRows() const {
    return rows;
}

/**
 * @brief Getter method to retrieve the list of ships on the grid.
 *
 * @return A constant reference to the vector containing all placed ships.
 */
const std::vector<Ship>& OwnGrid::getShips() const {
    return ships;
}

/**
 * @brief Method to place a ship on the grid.
 *
 * @param ship The ship to be placed.
 * @return true if the ship was successfully placed, false otherwise.
 */
bool OwnGrid::placeShip(const Ship &ship) {
    int shipLength = ship.length();  // Get the ship length

    // Display the type of ship based on length
    if (shipLength == 5) {
        cout << "Player wishes to place a carrier ship of length 5" << endl;
    } else if (shipLength == 4) {
        cout << "Player wishes to place a battleship of length 4" << endl;
    } else if (shipLength == 3) {
        cout << "Player wishes to place a destroyer ship of length 3" << endl;
    } else if (shipLength == 2) {
        cout << "Player wishes to place a submarine of length 2" << endl;
    }

    // Validate the ship's placement
    if (ship.isValid() == false) {
        return false;
    }

    // Check if there is room for more ships of the same length
    if (shipTypes[shipLength] <= 0) {
        if (shipTypes[shipLength] == 0) {
            if (shipLength == 5) {
                cout << "Only 1 carrier ship can be placed. "
                		"Carrier ship quantity exceeds" << endl;
            } else if (shipLength == 4) {
                cout << "Only 2 battleships can be placed. "
                		"Battleship quantity exceeds" << endl;
            } else if (shipLength == 3) {
                cout << "Only 3 destroyer ships can be placed. "
                		"Destroyer ship quantity exceeds" << endl;
            } else if (shipLength == 2) {
                cout << "Only 4 submarines can be placed. "
                		"Submarine quantity exceeds" << endl;
            }
        }
        return false;
    }

    // Check if the new ship touches an existing ship
    set<GridPosition> existingShipsPosition;
    for (const auto& existingShip : ships) {
        existingShipsPosition = existingShip.blockedArea();
    }
    // New ship's occupied area
    set<GridPosition> tempShipPosition = ship.occupiedArea();
    // To store the intersection of blocked areas
    set<GridPosition> intersectionShips;

    set_intersection(existingShipsPosition.begin(), existingShipsPosition.end(),
                      tempShipPosition.begin(), tempShipPosition.end(),
                      inserter(intersectionShips, intersectionShips.begin()));

    if (!intersectionShips.empty()) {
        cout << "Ships are touching each other" << endl;
        return false;
    }

    // Decrement the count of ships available for this ship length
    shipTypes[shipLength]--;

    // Add the new ship to the grid
    ships.push_back(ship);
    return true;
}

/**
 * @brief Default constructor to initialize the OwnGrid object.
 *
 * @details Initializes the grid with default values and the ship types with
 *          predefined values.
 */
OwnGrid::OwnGrid() {
    rows = 0;
    columns = 0;
    shipTypes = {
        {5, 1},  // Carrier ship (1)
        {4, 2},  // Battleship (2)
        {3, 3},  // Destroyer (3)
        {2, 4}   // Submarine (4)
    };
}

/**
 * @brief Parameterized constructor to initialize the OwnGrid with given rows
 *        and columns.
 *
 * @param rows The number of rows in the grid.
 * @param columns The number of columns in the grid.
 */
OwnGrid::OwnGrid(int rows, int columns) : rows{rows}, columns{columns},
		shipTypes{
    {5, 1}, {4, 2}, {3, 3}, {2, 4}
} {}

/**
 * @brief Getter method to retrieve the set of shot positions.
 *
 * @return A constant reference to the set of positions where shots have been
 *         taken.
 */
const std::set<GridPosition>& OwnGrid::getShotAt() const {
    return shotAt;
}

/**
 * @brief Method to take a shot at the grid and determine the impact on ships.
 *
 * @param shot The shot object containing the target position.
 * @return The impact of the shot (HIT, SUNKEN, or NONE).
 */
Shot::Impact OwnGrid::takeBlow(const Shot &shot) {
    GridPosition target = shot.getTargetPosition();  // Get the target position

    // Iterate over all ships to check if the target position is a hit
    for (const auto& ship : ships) {
        set<GridPosition> shipOccupiedPositions = ship.occupiedArea();

        // If the target is within this ship's occupied positions, it's a hit
        if (shipOccupiedPositions.find(target) != shipOccupiedPositions.end()){
            shotAt.insert(target);  // Add the shot to the list of shots taken

            // Check if all parts of the ship are hit
            set<GridPosition> setIntersection;
            set_intersection(shipOccupiedPositions.begin(),
            				shipOccupiedPositions.end(),
                            shotAt.begin(),
							shotAt.end(),
                            inserter(setIntersection, setIntersection.begin()));

            // If the whole ship is hit, it's sunken
            if (setIntersection.size() == shipOccupiedPositions.size()) {
                return Shot::Impact::SUNKEN;  // Ship is sunken
            }

            return Shot::Impact::HIT;  // It's a hit but not sunken
        }
    }

    // If no ship is hit, record the shot and return NONE
    shotAt.insert(target);
    return Shot::Impact::NONE;
}
