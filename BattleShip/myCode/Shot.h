/**
 * @file Shot.h
 * @brief Header file for the Shot class, which represents a shot fired at a
 *        target position on the grid during the game.
 *
 * @author Aman Chauhan
 * @date 8 Jan 2025
 * @version 1.0
 * @note Master student at Hochschule Darmstadt
 * @matriculation_number 1127928
 */

#ifndef SHOT_H_
#define SHOT_H_

#include "GridPosition.h"

/**
 * @class Shot
 * @brief Represents a shot fired at a specific target position on the grid.
 *
 * The class includes information about the target position and the impact
 * of the shot (whether it was a hit, sunken, or none).
 */
class Shot {
public:
    /**
     * @enum Impact
     * @brief Enum to represent the impact of a shot.
     *
     * - NONE: No impact, shot missed.
     * - HIT: Shot hit a ship.
     * - SUNKEN: Shot sunk a ship.
     */
    enum Impact {
        NONE,   /**< No impact, shot missed */
        HIT,    /**< Shot hit a ship */
        SUNKEN  /**< Shot sunk a ship */
    };

private:
    GridPosition targetPosition;
    /**< The target position of the shot on the grid */

public:
    /**
     * @brief Constructor to initialize the shot with a target position.
     *
     * @param targetPosition The target position where the shot is fired.
     */
    Shot(GridPosition targetPosition);

    /**
     * @brief Getter method to retrieve the target position of the shot.
     *
     * @return The target position of the shot.
     */
    GridPosition getTargetPosition() const;
};

#endif /* SHOT_H_ */
