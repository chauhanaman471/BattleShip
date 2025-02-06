/**
 * @file part2tests.cpp
 * @brief Implementation of test cases for Part 2 of the Battleship project.
 *
 * This file contains the implementation of utility functions and test cases
 * to validate the functionality of the `OwnGrid` class in the Battleship
 * project. Specifically, it tests the placement of ships using `placeShip()`
 * method and ensures correct behavior under different conditions.
 *
 * @author Aman Chauhan
 * @date 9 Jan 2025
 * @version 1.0
 * @note Master student at Hochschule Darmstadt
 *       Matriculation Number: 1127928
 */

#include "part2testscpp.h"
#include <iostream>
#include "Board.h"

using namespace std;

/**
 * @brief Outputs the failedMessage to the console if the condition is false.
 *
 * A simple assertion function used in test cases to verify expected
 * conditions. If the condition evaluates to false, it logs the specified
 * error message to the console.
 *
 * @param condition The condition to verify.
 * @param failedMessage The message to log if the condition is false.
 */
void assertTrue1(bool condition, string failedMessage) {
    if (!condition) {
        cout << "Error: " << failedMessage << endl;
    }
}

/**
 * @brief Runs a suite of test cases for the `OwnGrid` class.
 *
 * This function tests the `placeShip()` method in `OwnGrid` class, ensuring
 * proper placement of ships and handling of invalid scenarios such as edge
 * placement, overlapping ships, and diagonal positioning.
 */
void part2tests() {
    // Testing the working of the placeShip() method in OwnGrid class
    cout << "Class OwnGrid: placeShip() method Testing" << endl<<endl;

    OwnGrid playerGrid;

    // Placing ship of length = 5
    assertTrue1(playerGrid.placeShip(Ship{GridPosition{"I2"},
                                          GridPosition{"I6"}}),
                "Ship cannot be placed");

    // Ship is intersecting (touching) with I2-I6, or exceeds the limit for
    // ships of length 5
    assertTrue1(!playerGrid.placeShip(Ship{GridPosition{"J2"},
                                           GridPosition{"J6"}}),
                "Ship can be placed");

    // Ship to be placed on edge of grid, but diagonal placement is not allowed
    assertTrue1(!playerGrid.placeShip(Ship{GridPosition{"I10"},
                                           GridPosition{"J9"}}),
                "Ship cannot be placed");
}
