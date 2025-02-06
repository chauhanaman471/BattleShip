/**
 * @file part3tests.cpp
 * @brief Test file for validating methods in OwnGrid and OpponentGrid classes.
 *
 * @details This file contains tests for the `takeBlow` method in the OwnGrid
 *          class and the `shotResult` method in the OpponentGrid class. The
 *          tests verify whether shots are correctly registered as HIT, SUNKEN,
 *          or NONE on the respective grids.
 *
 * @author Aman Chauhan
 * @date 9 Jan 2025
 * @version 1.0
 * @note Master student at Hochschule Darmstadt
 * @matriculation_number 1127928
 */

#include "part3testscpp.h"
#include <iostream>
#include "Board.h"
#include "Shot.h"

using namespace std;

/**
 * @brief Helper function to assert if a condition is true and print an error
 *        message if it fails.
 *
 * @param condition The condition to test.
 * @param failedMessage The message to display if the condition is false.
 */
void assertTrue2(bool condition, string failedMessage) {
    if (!condition) {
        cout << "Error: " << failedMessage << endl;
    }
}

/**
 * @brief Test function for validating the `takeBlow` method in OwnGrid class
 *        and the `shotResult` method in the OpponentGrid class.
 *
 * @details This function tests the correct functionality of the following:
 *          1.`takeBlow` method in OwnGrid for registering shots as HIT or MISS.
 *          2.`shotResult` method in OpponentGrid for recording shot impacts
 *             (HIT, MISS, SUNKEN).
 */
void part3tests() {
    // Testing the working of the takeBlow method in OwnGrid class
    cout << "Class OwnGrid: takeBlow() method Testing" << endl << endl;

    // Place ship on the grid position I2-I6 on ownGrid
    OwnGrid ownGrid;
    assertTrue2(ownGrid.placeShip(Ship{GridPosition{"I2"}, GridPosition{"I6"}}),
                "Ship can't be placed in the given Grid Position");

    // Putting shot at one of ship occupied position (I5)
    Shot targetPosition1{GridPosition{"I5"}};
    Shot::Impact shotResult1 = ownGrid.takeBlow(targetPosition1);
    assertTrue2((shotResult1 == Shot::Impact::HIT) == true,
    		"Shot didn't hit the ship");

    // Putting shot at a non-occupied position (I7)
    Shot targetPosition2{GridPosition{"I7"}};
    Shot::Impact shotResult2 = ownGrid.takeBlow(targetPosition2);
    assertTrue2((shotResult2 == Shot::Impact::HIT) == false,
    		"Shot hit the ship");

    // Testing the working of the shotResult method in OpponentGrid class
    cout << "Class OpponentGrid: shotResult() method Testing" << endl << endl;

    // Working with opponent Grid
    OpponentGrid opponentGrid;

    // Updating specific positions in the grid with shot results
    opponentGrid.shotResult(Shot{GridPosition{"A8"}}, Shot::Impact::HIT);
    opponentGrid.shotResult(Shot{GridPosition{"A9"}}, Shot::Impact::NONE);
    opponentGrid.shotResult(Shot{GridPosition{"I8"}}, Shot::Impact::SUNKEN);
    opponentGrid.shotResult(Shot{GridPosition{"I9"}}, Shot::Impact::SUNKEN);
    opponentGrid.shotResult(Shot{GridPosition{"I10"}}, Shot::Impact::SUNKEN);

    // Check if the position is marked with ^ or O for miss and Hit
    assertTrue2((opponentGrid.getShots()
    		.at(GridPosition{"A8"}) == Shot::Impact::HIT)==true,
    		"Shot is not marked as HIT");
    assertTrue2((opponentGrid.getShots()
    		.at(GridPosition{"A9"}) == Shot::Impact::NONE)==true,
                "Shot is not marked as MISS");
    assertTrue2((opponentGrid.getShots()
    		.at(GridPosition{"I8"}) == Shot::Impact::SUNKEN)==true,
                "Shot is not marked as SUNKEN");
}
