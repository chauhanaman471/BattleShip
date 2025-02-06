/**
 * @file Ship.cpp
 * @brief Implementation of the Ship class, representing a ship on a grid
 *        with bow and stern positions, and methods to validate and
 *        manipulate these positions.
 *
 * @author Aman Chauhan
 * @date 20 Dec 2024
 * @version 1.0
 * @note Master student at Hochschule Darmstadt
 * @matriculation_number 1127928
 */

#include "Ship.h"
#include <iostream>
#include <set>
using namespace std;

Ship::Ship(const GridPosition &bow, const GridPosition &stern)
    : bow{bow}, stern{stern} {
    cout << "Bow position of the ship: " << bow << endl;
    cout << "Stern Position of the ship: " << stern << endl;
}

bool Ship::isValid() const {
    if ((bow.isValid() && stern.isValid() && length() >= 2 && length() <= 5)
        && ((stern.getColumn() == bow.getColumn())
            || (stern.getRow() == bow.getRow()))) {
        return true;
    } else {
        if (bow.isValid() == false || stern.isValid() == false) {
            cout << "Ship is out of grid boundaries" << endl;
        } else if ((length() >= 2 && length() <= 5) == false) {
            cout << "Ship length is not between 2 or 5" << endl;
            if (length() == -1) {
                cout << "Field occupied by ship is not in a straight line"
                		<< endl;
            }
        } else if ((stern.getColumn() != bow.getColumn())
                || (stern.getRow() != bow.getRow())) {
            cout << "Ship is not positioned horizontally or vertically" << endl;
        }
        return false;
    }
}

int Ship::length() const {
    if (stern.getColumn() == bow.getColumn()) {
        // Ship placed vertically
        return abs(stern.getRow() - bow.getRow()) + 1;
    } else if (stern.getRow() == bow.getRow()) {
        // Ship placed horizontally
        return abs(stern.getColumn() - bow.getColumn()) + 1;
    } else {
        // Ship positioned incorrectly
        return -1;
    }
}

GridPosition Ship::getBow() const {
    return bow;
}

GridPosition Ship::getStern() const {
    return stern;
}

set<GridPosition> Ship::occupiedArea() const {
    set<GridPosition> shipOccupiedPos;

    if (stern.getColumn() == bow.getColumn()) {
        // Ship placed vertically
        char startRowPos = bow.getRow();
        char endRowPos = stern.getRow();

        if (startRowPos < endRowPos) {
            for (char rowIndex = startRowPos; rowIndex <= endRowPos; rowIndex++)
            {
                shipOccupiedPos.insert(GridPosition(rowIndex, bow.getColumn()));
            }
        } else {
            for (char rowIndex = endRowPos; rowIndex <= startRowPos; rowIndex++)
            {
                shipOccupiedPos.insert(GridPosition(rowIndex, bow.getColumn()));
            }
        }
    } else if (bow.getRow() == stern.getRow()) {
        // Ship placed horizontally
        int startColumnPos = bow.getColumn();
        int endColumnPos = stern.getColumn();

        if (startColumnPos < endColumnPos) {
            for (int columnIndex = startColumnPos; columnIndex <= endColumnPos;
            		columnIndex++) {
                shipOccupiedPos.insert(GridPosition(bow.getRow(), columnIndex));
            }
        } else {
            for (int columnIndex = endColumnPos; columnIndex <= startColumnPos;
            		columnIndex++) {
                shipOccupiedPos.insert(GridPosition(bow.getRow(), columnIndex));
            }
        }
    }
    return shipOccupiedPos;
}

set<GridPosition> Ship::blockedArea() const {
    set<GridPosition> shipBlockedPos; // Set to hold the result
    // Directions for 8 possible surrounding positions (vertical, horizontal,
    // and diagonal).
    int directionArray[8][2] = {
        {1, 0},   // Right
        {-1, 0},  // Left
        {0, 1},   // Down
        {0, -1},  // Up
        {1, 1},   // Diagonal Down Right
        {-1, -1}, // Diagonal Up Left
        {-1, 1},  // Diagonal Down Left
        {1, -1}   // Diagonal Up Right
    };

    // For each position in the occupied area, add to the result:
    // - the position itself
    // - all surrounding positions
    for (const auto& occupiedPos : occupiedArea()) {
        shipBlockedPos.insert(occupiedPos); // Insert the occupied position
        // Iterate over the 8 surrounding positions
        for (int directionArrayIndex = 0; directionArrayIndex < 8;
        		directionArrayIndex++) {
            int dx = directionArray[directionArrayIndex][0];
            int dy = directionArray[directionArrayIndex][1];
            int xNewPosition = occupiedPos.getRow() + dx;
            int yNewPosition = occupiedPos.getColumn() + dy;

            // Check if the new position is within grid boundaries
            if (xNewPosition >= 65 && xNewPosition <= 74 &&
            		yNewPosition > 0 && yNewPosition <= 10) {
                // Insert the surrounding position if valid
                shipBlockedPos.insert(GridPosition(xNewPosition, yNewPosition));
            } else {
                // Out of bounds, do nothing
            }
        }
    }
    return shipBlockedPos;
}

ostream& operator<<(ostream &lhs, const set<GridPosition> &rhs) {
    lhs << "{"; // Start with the curly braces
    for (const auto& pos : rhs) {
        lhs << " " << pos;
    }
    lhs << " }"; // End with curly braces
    return lhs;
}
