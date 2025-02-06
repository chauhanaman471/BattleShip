/**
 * @file main.cpp
 * @brief Entry point for the Battleship program.
 *
 * @details This program simulates basic functionality for a Battleship game.
 *          It includes operations to create grid positions, validate them,
 *          compare their sizes, and check the validity of a ship's position.
 *          The program demonstrates the process of placing ships on a grid,
 *          taking shots, and displaying the results on the console view.
 *
 * @author Aman Chauhan
 * @date 19 Dec 2024
 * @version 1.0
 * @note Master student at Hochschule Darmstadt
 * @matriculation_number 1127928
 */

#include <iostream>
#include <cstdlib>
#include <string>
#include <set>
#include "GridPosition.h"
#include "Ship.h"
#include "OwnGrid.h"
#include "OpponentGrid.h"
#include "Board.h"
#include "ConsoleView.h"
#include "Shot.h"
#include "part1testscpp.h"
#include "part2testscpp.h"
#include "part3testscpp.h"

using namespace std;

int main() {

	part1tests ();
	part2tests ();
	part3tests ();
    /**
     * @brief Create an object of the Board class with 10x10 grid dimensions.
     *
     * This object initializes both the player's grid and the opponent's grid.
     */
    Board myBoard {10,10};

    /**
     * @brief Create an object of ConsoleView and pass a reference to the board.
     *
     * This object is used to print both the player's and opponent's grids.
     */
    ConsoleView myBoardConsole{&myBoard};
    myBoardConsole.print();

    /**
     * @brief Arrange ships on the player's grid at specified locations.
     *
     * The ships are placed at the following positions:
     * - Ship 1: B2 to B4
     * - Ship 2: D4 to G4
     * - Ship 3: F6 to F9
     */
    cout << "Placing ships in player Grid" << endl;

    Ship myShip1{GridPosition{'B',2}, GridPosition{'B',4}};
    Ship myShip2{GridPosition{"D4"}, GridPosition{"G4"}};
    Ship myShip3{GridPosition{'F',6}, GridPosition{"F9"}};

    /**
     * @brief Test if ships can be placed in the player's grid.
     *
     * If all ships are successfully placed, print their occupied areas and
     * update the grid. Otherwise, print an error message.
     */
    if (myBoard.getOwnGrid().placeShip(myShip1) &&
        myBoard.getOwnGrid().placeShip(myShip2) &&
        myBoard.getOwnGrid().placeShip(myShip3)) {

        cout << "All 3 ships can be placed in the player grid" << endl;
        cout << "Occupied Position 1: " << myShip1.occupiedArea() << endl;
        cout << "Occupied Position 2: " << myShip2.occupiedArea() << endl;
        cout << "Occupied Position 3: " << myShip3.occupiedArea() << endl;
        myBoardConsole.print();
    } else {
        cout << "All 3 ships can't be placed in the player grid" << endl;
    }

    /**
     * @brief Simulate opponent placing shots at the player's grid.
     *
     * Shots are placed at various positions to simulate hits and misses.
     */
    cout << "Opponent placing shots at players grid" << endl;
    myBoard.getOwnGrid().takeBlow(Shot{GridPosition{"B3"}});
    myBoard.getOwnGrid().takeBlow(Shot{GridPosition{"B4"}});
    myBoard.getOwnGrid().takeBlow(Shot{GridPosition{"B5"}});
    myBoard.getOwnGrid().takeBlow(Shot{GridPosition{"F4"}});
    myBoard.getOwnGrid().takeBlow(Shot{GridPosition{"H4"}});

    myBoardConsole.print();

    /**
     * @brief Simulate the player placing shots at the opponent's grid.
     *
     * The player is informed manually about the results of their shots,
     * including whether they hit or sunk an opponent's ship.
     */
    cout << "Player placing shots at opponent grid" << endl;
    myBoard.getOpponentGrid().shotResult(Shot{GridPosition{"C2"}},
    		Shot::Impact::NONE);
    myBoard.getOpponentGrid().shotResult(Shot{GridPosition{"C3"}},
    		Shot::Impact::SUNKEN);
    myBoard.getOpponentGrid().shotResult(Shot{GridPosition{"C4"}},
    		Shot::Impact::SUNKEN);
    myBoard.getOpponentGrid().shotResult(Shot{GridPosition{"C5"}},
    		Shot::Impact::SUNKEN);

    myBoard.getOpponentGrid().shotResult(Shot{GridPosition{"F5"}},
    		Shot::Impact::NONE);
    myBoard.getOpponentGrid().shotResult(Shot{GridPosition{"G4"}},
    		Shot::Impact::NONE);
    myBoard.getOpponentGrid().shotResult(Shot{GridPosition{"G5"}},
    		Shot::Impact::HIT);
    myBoard.getOpponentGrid().shotResult(Shot{GridPosition{"G6"}},
    		Shot::Impact::HIT);
    myBoard.getOpponentGrid().shotResult(Shot{GridPosition{"I5"}},
    		Shot::Impact::NONE);

    myBoardConsole.print();

    return 0;
}
