/**
 * @file part3testscpp.h
 * @brief Header file for part3tests.cpp functions.
 *
 * @details This file declares the functions used for testing the functionality
 *          of the OwnGrid and OpponentGrid classes, specifically `takeBlow`
 *          and `shotResult` methods. The testing functions ensure that grid
 *          updates correctly when shots are taken.
 *
 * @author Aman Chauhan
 * @date 9 Jan 2025
 * @version 1.0
 * @note Master student at Hochschule Darmstadt
 * @matriculation_number 1127928
 */

#ifndef PART3TESTSCPP_H_
#define PART3TESTSCPP_H_

#include <string>

/**
 * @brief Helper function to assert if a condition is true and print an error
 *        message if it fails.
 *
 * @param condition The condition to test.
 * @param failedMessage The message to display if the condition is false.
 */
void assertTrue2(bool condition, std::string failedMessage);

/**
 * @brief Test function for validating the `takeBlow` method in OwnGrid class
 *        and the `shotResult` method in the OpponentGrid class.
 *
 * @details This function tests whether the `takeBlow` and `shotResult` methods
 *          correctly update grid based on shot outcomes (HIT, SUNKEN, NONE).
 */
void part3tests();

#endif /* PART3TESTSCPP_H_ */
