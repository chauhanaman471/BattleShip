/**
 * @file GridPosition.h
 * @brief Header file for the GridPosition class, representing a grid position
 *        with row and column.
 *
 * @author Aman Chauhan
 * @date 19 Dec 2024
 * @version 1.0
 * @details This class encapsulates the grid position using row and column,
 *          providing utility methods and operator overloads for comparisons
 *          and output. It supports functionalities like equality checks,
 *          conversion to string, and validation of the grid position.
 *
 * @note Master student at Hochschule Darmstadt
 * @matriculation_number 1127928
 */

#ifndef GRIDPOSITION_H_
#define GRIDPOSITION_H_

#include <string>

/**
 * @class GridPosition
 * @brief Represents a position on a grid using row and column.
 *
 * This class allows you to create and manipulate grid positions, which are
 * defined by a row (represented by a character) and a column (represented
 * by an integer). It includes methods to validate positions, compare them,
 * and convert them to string format.
 */
class GridPosition {
private:
    char row;    ///< Row position of the grid, represented by a character.
    int column;  ///< Column position of the grid, represented by an integer.

public:
    /**
     * @brief Constructor to initialize a grid position with row and column.
     * @param row Character representing the row of the grid.
     * @param column Integer representing the column of the grid.
     */
    GridPosition(char row, int column);

    /**
     * @brief Constructor to initialize a grid position with a string argument.
     * @param position String representing the grid position (e.g., "A1", "B2").
     */
    GridPosition(std::string position);

    /**
     * @brief Checks the validity of the grid position.
     * @details Ensures that the row is between 'A' and 'Z' and the column is
     *          greater than 0.
     * @return True if the grid position is valid, false otherwise.
     */
    bool isValid() const;

    /**
     * @brief Overloads the equality operator to compare two grid positions.
     * @param other Another GridPosition object to compare.
     * @return True if both positions are the same, false otherwise.
     */
    bool operator==(GridPosition other) const;

    /**
     * @brief Type cast operator to return the grid position as a string.
     * @return String representation of the grid position (e.g., "A1").
     */
    operator std::string() const;

    /**
     * @brief Overloads the less-than operator for comparing grid positions.
     * @param other Another GridPosition object to compare.
     * @return True if this position is less than the other, false otherwise.
     */
    bool operator<(GridPosition other) const;

    /**
     * @brief Getter function to retrieve the column position.
     * @return Integer representing the column of the grid.
     */
    int getColumn() const;

    /**
     * @brief Getter function to retrieve the row position.
     * @return Character representing the row of the grid.
     */
    char getRow() const;

    /**
     * @brief Overloads the << operator for outputting a GridPosition object.
     * @param lhs Output stream to which the position is written.
     * @param rhs GridPosition object to output.
     * @return Reference to the output stream.
     */
    friend std::ostream& operator<<(std::ostream& lhs, const GridPosition& rhs);
};

/**
 * @brief Overloads the << operator for outputting a GridPosition object.
 * @param lhs Output stream to which the position is written.
 * @param rhs GridPosition object to output.
 * @return Reference to the output stream.
 */
std::ostream& operator<<(std::ostream& lhs, const GridPosition& rhs);

#endif /* GRIDPOSITION_H_ */
