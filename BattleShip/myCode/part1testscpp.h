/**
 * @file part1testscpp.h
 * @brief Header file for testing utility functions for Battleship project.
 *
 * This file contains declarations for utility functions used in the testing
 * of Battleship project components. It includes a simple assertion function
 * and a suite of test cases to verify the functionality of GridPosition and
 * Ship class and its methods in the project.
 *
 * @author Aman Chauhan
 * @date 5 Jan 2025
 * @version 1.0
 * @note Master student at Hochschule Darmstadt
 *       Matriculation Number: 1127928
 */

#ifndef PART1TESTSCPP_H_
#define PART1TESTSCPP_H_

#include <string>

/**
 * @brief Asserts that a condition is true and logs a message if not.
 *
 * This function is used in test cases to verify that a condition holds true.
 * If the condition evaluates to false, a failure message is printed to the
 * console.
 *
 * @param condition The condition to verify.
 * @param failedMessage The message to print if the assertion fails.
 */
void assertTrue(bool condition, std::string failedMessage);

/**
 * @brief Runs a suite of test cases for the Battleship project.
 *
 * This function contains test cases that validate the behavior of various
 * components in the Battleship project, including classes and methods. It
 * ensures that the implementation adheres to the expected functionality.
 */
void part1tests();

#endif // PART1TESTSCPP_H_

