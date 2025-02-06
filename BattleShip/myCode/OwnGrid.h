/**
 * @file OwnGrid.h
 * @brief Header file for the OwnGrid class, which represents the player's
 *        grid in the battleship game.
 *
 * @details The OwnGrid class handles the grid where the player's ships are
 *          placed, tracks the shots taken, and manages the ship types and
 *          their positions. It provides methods for placing ships, handling
 *          the impact of shots, and retrieving information about the grid.
 *
 * @author Aman Chauhan
 * @date 27 Dec 2024
 * @version 1.0
 * @note Master student at Hochschule Darmstadt
 * @matriculation_number 1127928
 */

#ifndef OWNGRID_H_
#define OWNGRID_H_

#include "Ship.h"
#include "Shot.h"
#include <vector>
#include <map>
#include <set>

/**
 * @class OwnGrid
 * @brief Class representing the player's grid in the battleship game.
 *
 * @details This class manages the grid, where ships are placed and where
 *          shots are taken. It provides functionality for placing ships,
 *          handling shot impacts, and querying information about the grid,
 *          such as the ship positions and shot positions.
 */
class OwnGrid {
private:
    int rows; /**< The number of rows in the grid. */
    int columns; /**< The number of columns in the grid. */
    std::vector<Ship> ships; /**< Vector to store ships placed on the grid. */
    std::map<int, int> shipTypes; /**< Map to store the count of
    								  each ship type. */
    std::set<GridPosition> shotAt; /**< Set to store the positions where shots
                                       were taken. */

public:
    /**
     * @brief Default constructor for the OwnGrid class.
     *
     * @details Initializes the grid with default values.
     */
    OwnGrid();

    /**
     * @brief Constructor to initialize the OwnGrid with specified rows and
     *        columns.
     *
     * @param rows The number of rows in the grid.
     * @param columns The number of columns in the grid.
     */
    OwnGrid(int rows, int columns);

    /**
     * @brief Getter method to retrieve the number of columns in the grid.
     *
     * @return The number of columns in the grid.
     */
    int getColumns() const;

    /**
     * @brief Getter method to retrieve the number of rows in the grid.
     *
     * @return The number of rows in the grid.
     */
    int getRows() const;

    /**
     * @brief Method to place a ship on the grid.
     *
     * @param ship The ship to be placed on the grid.
     * @return true if the ship was successfully placed, false otherwise.
     */
    bool placeShip(const Ship& ship);

    /**
     * @brief Getter method to retrieve all the ships placed on the grid.
     *
     * @return A constant reference to the vector of ships.
     */
    const std::vector<Ship>& getShips() const;

    /**
     * @brief Method to take a shot at the grid and determine the impact.
     *
     * @param shot The shot to be taken at the grid.
     * @return The impact result of the shot.
     */
    Shot::Impact takeBlow(const Shot& shot);

    /**
     * @brief Getter method to retrieve all the positions where shots have
     *        been taken.
     *
     * @return A constant reference to the set of positions where shots
     *         have been taken.
     */
    const std::set<GridPosition>& getShotAt() const;
};

#endif /* OWNGRID_H_ */
