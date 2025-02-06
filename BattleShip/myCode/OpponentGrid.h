/**
 * @file OpponentGrid.h
 * @brief Header file for the OpponentGrid class, representing the opponent's
 * grid in a battleship game.
 *
 * @details This file defines the OpponentGrid class, which manages opponent's
 *          ships, the shots taken by the player, and the resulting impacts.
 *          It tracks the opponent's ships, sunken ships, and the shot results.
 *          The class provide method to record shot result, track sunken ship
 *          and get the current state of the opponent's grid.
 *
 * @author Aman Chauhan
 * @date 31 Dec 2024
 * @version 1.0
 * @note Master student at Hochschule Darmstadt
 * @matriculation_number 1127928
 */

#ifndef OPPONENTGRID_H_
#define OPPONENTGRID_H_

#include <vector>
#include "Ship.h"
#include "Shot.h"
#include <map>

/**
 * @class OpponentGrid
 * @brief Class to manage the opponent's grid, shots, and sunken ships.
 *
 * @details The OpponentGrid class manages the grid used to track opponent's
 *          ships, storing the opponent's ships, tracking the shots taken by
 *          player, and handling results of these shots. The class also tracks
 *          sunken ship & provide methods to retrieve the status of grid & shot
 */
class OpponentGrid {
private:
    int rows;  /**< The number of rows in the grid. */
    int columns;  /**< The number of columns in the grid. */
    /**< A list that stores the opponent's sunken ships. */
    std::vector<Ship> sunkenShip;
    /**< A list that stores the opponent's ships. */
    std::vector<Ship> opponentShips;
    /**< A map that stores shot impacts for each shot fired on the grid. */
    std::map<GridPosition, Shot::Impact> shots;

public:
    /**
     * @brief Constructor to initialize OpponentGrid with
     * specified rows and columns.
     *
     * @param rows The number of rows in the grid.
     * @param columns The number of columns in the grid.
     */
    /**< Constructor implementation for initializing the grid. */
    OpponentGrid(int rows, int columns);

    /**
     * @brief Default constructor to initialize an OpponentGrid
     * with default dimensions.
     */
    OpponentGrid(); /**< Default constructor implementation. */

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
     * @brief Getter method to retrieve the list of sunken ships.
     *
     * @return A constant reference to the vector of sunken ships.
     */
    const std::vector<Ship>& getSunkenShip() const;

    /**
     * @brief Getter method to retrieve the map of shots and their impacts.
     *
     * @return A constant reference to the map of shot impacts, where  key is
     *         position of the shot and the value is impact of the shot (HIT,
     *         SUNKEN, or NONE).
     */
    const std::map<GridPosition, Shot::Impact>& getShots() const;

    /**
     * @brief Method to record the result of a shot and update the impacts.
     *
     * This method updates the grid with the result of a shot fired by player.
     * It stores the result of the shot (e.g., HIT, SUNKEN, NONE) and checks if
     * opponent's ship is sunken based on the shot results.
     *
     * @param shot The shot object that was fired by the player.
     * @param impact The impact result of the shot (HIT, SUNKEN, NONE).
     */
    void shotResult(const Shot& shot, Shot::Impact impact);

    /**
     * @brief Getter method to retrieve the list of opponent's ships.
     *
     * @return A constant reference to the vector of the opponent's ships.
     */
    const std::vector<Ship>& getOpponentShips() const;
};

#endif /* OPPONENTGRID_H_ */
