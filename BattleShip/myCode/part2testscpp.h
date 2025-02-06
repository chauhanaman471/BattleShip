/**
 * @file part2testscpp.h
 * @brief Header file for Part 2 test cases of the Battleship project.
 *
 * This header file declares the utility functions and test cases used for
 * validating the functionality of the `OwnGrid` class in the Battleship
 * project. It includes an assertion function and a test suite.
 *
 * @details The `assertTrue1` function is used to verify conditions during
 * test execution, while `part2tests` provides a suite of test cases for
 * the `OwnGrid` class.
 *
 * @note Adheres to the coding standards for maximum line length (80
 * characters) to ensure code readability and maintainability.
 *
 * @author Aman Chauhan
 * @date 9 Jan 2025
 * @version 1.0
 * @note Master student at Hochschule Darmstadt
 *       Matriculation Number: 1127928
 */

#ifndef PART2TESTSCPP_H_
#define PART2TESTSCPP_H_

#include <string>

/**
 * @brief Outputs the failed message if the condition is false.
 *
 * This utility function is used during testing to verify expected
 * conditions. If the condition evaluates to false, the function
 * logs the provided error message to the console.
 *
 * @param condition The condition to verify.
 * @param failedMessage The message to display if the condition is false.
 */
void assertTrue1(bool condition, std::string failedMessage);

/**
 * @brief Executes test cases for the `OwnGrid` class.
 *
 * This function runs a suite of test cases to validate the functionality
 * of the `placeShip()` method in the `OwnGrid` class, ensuring proper
 * handling of ship placement and invalid scenarios.
 */
void part2tests();

#endif /* PART2TESTSCPP_H_ */
