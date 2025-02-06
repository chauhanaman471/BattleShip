/**
 * @file Shot.cpp
 * @brief Implementation file for the Shot class, which represents a shot fired
 *        at a target position on the grid.
 *
 * @author Aman Chauhan
 * @date 8 Jan 2025
 * @version 1.0
 * @note Master student at Hochschule Darmstadt
 * @matriculation_number 1127928
 */

#include "Shot.h"

/**
 * @brief Getter method to retrieve the target position of the shot.
 *
 * @return The target position of the shot.
 */
GridPosition Shot::getTargetPosition() const {
    return targetPosition;
}

/**
 * @brief Constructor to initialize the shot with a target position.
 *
 * @param targetPosition The target position where the shot is fired.
 */
Shot::Shot(GridPosition targetPosition) : targetPosition{targetPosition} {
}
