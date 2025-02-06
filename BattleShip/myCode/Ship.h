/**
 * @file Ship.h
 * @brief Header file for the Ship class.
 *
 * @details This file defines the Ship class, which represents a ship with a
 *          bow and a stern on a grid. The class allows checking the validity
 *          of the ship's position, calculating the length of the ship, and
 *          determining the grid positions occupied by the ship.
 *
 * @author Aman Chauhan
 * @date 20 Dec 2024
 * @version 1.0
 * @note Master student at Hochschule Darmstadt
 * @matriculation_number 1127928
 */

#ifndef SHIP_H_
#define SHIP_H_

#include "GridPosition.h"
#include <set>

/**
 * @class Ship
 * @brief Class representing a ship with a bow and stern.
 *
 * @details The Ship class contains two `GridPosition` objects representing
 *          the bow (front) and stern (back) of the ship. It includes methods
 *          for checking the validity of the ship's position, calculating the
 *          ship's length, and determining all the grid positions the ship
 *          occupies.
 */
class Ship {
private:
    GridPosition bow;  ///< Front position (bow) of the ship on the grid.
    GridPosition stern; ///< Back position (stern) of the ship on the grid.

public:
    /**
     * @brief Constructor to initialize the Ship with a bow and stern.
     * @param bow The front position of the ship (GridPosition).
     * @param stern The back position of the ship (GridPosition).
     */
    Ship(const GridPosition &bow, const GridPosition &stern);

    /**
     * @brief Checks if the ship's position (bow and stern) is valid.
     * @return True if both bow and stern positions are valid; otherwise, false.
     */
    bool isValid() const;

    /**
     * @brief Calculates the length of the ship based on its bow and stern
     *        positions.
     * @return The length of the ship.
     */
    int length() const;

    /**
     * @brief Returns a set of all the grid positions occupied by the ship.
     * @return A set of `GridPosition` objects representing the occupied grid
     *         positions.
     */
    std::set<GridPosition> occupiedArea() const;

    /**
     * @brief Returns a set of grid positions that are blocked by the ship.
     * @return A set of `GridPosition` objects representing the blocked grid
     *         positions.
     */
    std::set<GridPosition> blockedArea() const;

    /**
     * @brief Getter to retrieve the bow position of the ship.
     * @return The bow position (GridPosition).
     */
    GridPosition getBow() const;

    /**
     * @brief Getter to retrieve the stern position of the ship.
     * @return The stern position (GridPosition).
     */
    GridPosition getStern() const;
};

/**
 * @brief Overloads the output stream operator to print the set of grid
 *        positions occupied by the ship.
 * @param lhs The output stream.
 * @param rhs The set of `GridPosition` objects representing the ship's
 *            occupied area.
 * @return The output stream with the grid positions printed.
 */
std::ostream& operator<<(std::ostream& lhs, const std::set<GridPosition> &rhs);

#endif /* SHIP_H_ */
