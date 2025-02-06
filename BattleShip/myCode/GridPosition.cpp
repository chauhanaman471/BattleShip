/**
 * @file GridPosition.cpp
 * @brief Implementation file for the GridPosition class.
 *
 * @author Aman Chauhan
 * @date 19 Dec 2024
 * @version 1.0
 * @details Contains implementations of the constructors, methods, and
 *          operator overloads for the GridPosition class.
 *
 * @note Master student at Hochschule Darmstadt
 * @matriculation_number 1127928
 */

#include "GridPosition.h"
#include <iostream>

using namespace std;

/**
 * @brief Constructor to initialize a grid position with row and column.
 * @param row Character representing the row.
 * @param column Integer representing the column.
 */
GridPosition::GridPosition(char row, int column) : row{row}, column{column} {}

/**
 * @brief Constructor to initialize a grid position with a string argument.
 * @param position String representing the grid position (e.g., "B10").
 * @details Extracts the row as the first character and the column as an
 *          integer from the input string.
 */
GridPosition::GridPosition(std::string position)
    : row{position[0]}, column{stoi(position.substr(1))} {}

/**
 * @brief Checks the validity of the grid position.
 * @details Ensures the row is between 'A' and 'Z' and the column is greater
 *          than 0.
 * @return True if the grid position is valid, false otherwise.
 */
bool GridPosition::isValid() const {
    return (column > 0 && row >= 'A' && row <= 'Z');
}

/**
 * @brief Overloads the equality operator to compare two grid positions.
 * @param other Another GridPosition object to compare.
 * @return True if both positions are the same, false otherwise.
 */
bool GridPosition::operator==(GridPosition other) const {
    return (row == other.row) && (column == other.column);
}

/**
 * @brief Getter function to retrieve the column position.
 * @return Integer representing the column.
 */
int GridPosition::getColumn() const {
    return column;
}

/**
 * @brief Getter function to retrieve the row position.
 * @return Character representing the row.
 */
char GridPosition::getRow() const {
    return row;
}

/**
 * @brief Type cast operator to convert the grid position into a string.
 * @details Concatenates the row and column into a string representation
 *          (e.g., "A1").
 * @return String representation of the grid position.
 */
GridPosition::operator std::string() const {
    return (string(1, row) + to_string(column));
}

/**
 * @brief Overloads the less-than operator to compare grid positions.
 * @param other Another GridPosition object to compare.
 * @details Compares row ASCII values first; if equal, compares column values.
 * @return True if this position is less than the other, false otherwise.
 */
bool GridPosition::operator<(GridPosition other) const {
    if (int(row) < int(other.row)) {
        return true;
    } else if (int(row) == int(other.row)) {
        return column < other.column;
    }
    return false;
}

/**
 * @brief Overloads the << operator for outputting a GridPosition object.
 * @param lhs Output stream to which the position is written.
 * @param rhs GridPosition object to output.
 * @return Reference to the output stream.
 */
ostream& operator<<(ostream& lhs, const GridPosition& rhs) {
    return lhs << rhs.getRow() << rhs.getColumn();
}
