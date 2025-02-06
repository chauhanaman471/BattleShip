/**
 * @file part1tests.cpp
 * @brief Implementation for utility functions and test cases in Battleship.
 *
 * This file contains implementation for utility functions used in the testing
 * of Battleship project components. It includes a simple assertion function
 * and a suite of test cases to verify the functionality of GridPosition and
 * Ship classes and their methods.
 *
 * @author Aman Chauhan
 * @date 5 Jan 2025
 * @version 1.0
 * @note Master student at Hochschule Darmstadt
 *       Matriculation Number: 1127928
 */

#include "part1testscpp.h"
#include <iostream>
#include "Board.h"

using namespace std;

/**
 * @brief Outputs the failedMessage to the console if the condition is false.
 *
 * This function is used in test cases to ensure that expected conditions hold
 * true during execution. If the condition evaluates to false, it logs the
 * specified failure message to the console.
 *
 * @param condition The condition to verify.
 * @param failedMessage The message to log if the condition is false.
 */
void assertTrue(bool condition, string failedMessage) {
    if (!condition) {
    	cout << "Error:" <<failedMessage << endl;
    }
}

/**
 * @brief Runs a suite of test cases for the Battleship project.
 *
 * This function validates the implementation of the `GridPosition` and `Ship`
 * classes, including their constructors, methods, and operators. Each test
 * outputs diagnostic messages to help verify the correctness of the program.
 */
void part1tests() {
    // Testing the working of the GridPosition constructor
    cout << "Class GridPosition: Constructor Testing" << endl<<endl;
    assertTrue(GridPosition{"A1"}.isValid(), "A1 is not valid position");
    assertTrue(GridPosition{'A', 1}.isValid(), "A,1 is not valid position");
    assertTrue(!GridPosition{'A', -1}.isValid(), "A,-1 is valid position");
    assertTrue(!GridPosition{'#', 1}.isValid(), "#,1 is valid position");

    // Testing the working of the getters and cast to string
    cout << "Class GridPosition: getter and cast to string Testing"
    		<< endl<<endl;
    GridPosition pos1 = GridPosition{'B', 13};
    assertTrue(pos1.getRow() == 'B',
               "GridPosition:GridPosition doesn't set row properly");
    assertTrue(pos1.getColumn() == 13,
               "GridPosition:GridPosition doesn't set column properly");
    assertTrue((string)pos1 == "B13", "Conversion to string fails");

    // Testing the working of overloaded < and == operator
    cout << "Class GridPosition: Overloaded comparison '<' & '==' Testing"
    		<<endl<<endl;
    assertTrue(GridPosition{"A1"} < GridPosition{"B1"},
               "Grid Position with bigger row is not considered greater");
    assertTrue(GridPosition{"A1"} < GridPosition{"A2"},
               "Grid Position with bigger column is not considered greater");
    assertTrue(GridPosition{"A1"} == GridPosition{"A1"},
               "Equal Grid Position are not considered");

    // Testing the working of the Ship Constructor
    cout << "Class Ship: Constructor Testing " << endl<<endl;
    assertTrue(!Ship{GridPosition{"B1"}, GridPosition{"B1"}}.isValid(),
               "Ship of size 1 is valid");  // Can't create ship of length <2
    assertTrue(!Ship{GridPosition{"B1"}, GridPosition{"B6"}}.isValid(),
               "Ship of size >5 is valid"); // Can't create ship of length >5
    assertTrue(!Ship{GridPosition{"B1"}, GridPosition{"C2"}}.isValid(),
           "Can create ship which is not aligned horizontally or vertically");

    // Testing the working of length() method of Ship Class
    cout << "Class Ship: length() method Testing " << endl<<endl;
    assertTrue(Ship{GridPosition{"B2"}, GridPosition{"B4"}}.length() == 3,
               "Ship is not of length 3");
    assertTrue(Ship{GridPosition{"B2"}, GridPosition{"E2"}}.length() == 4,
               "Ship is not of length 4");

    // Testing the working of occupiedArea() method of ship class
    cout << "Class Ship: occupiedArea() method Testing" << endl<<endl;
    assertTrue(Ship{GridPosition{"B2"}, GridPosition{"E2"}}.occupiedArea() ==
                   set<GridPosition>{GridPosition{"B2"}, GridPosition{"C2"},
                                     GridPosition{"D2"}, GridPosition{"E2"}},
               "Occupied area not correct");

    // Testing the working of BlockedArea() method of ship class
    cout << "Class Ship: BlockedArea() method Testing" << endl<<endl;
    assertTrue(Ship{GridPosition{"B2"}, GridPosition{"C2"}}.blockedArea() ==
                   set<GridPosition>{GridPosition{"A1"}, GridPosition{"A2"},
                                     GridPosition{"A3"}, GridPosition{"D1"},
                                     GridPosition{"D2"}, GridPosition{"D3"},
                                     GridPosition{"B1"}, GridPosition{"C1"},
                                     GridPosition{"B3"}, GridPosition{"C3"},
                                     GridPosition{"B2"}, GridPosition{"C2"}},
               "Blocked area not correct");
}
