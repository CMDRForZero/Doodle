/* ! \file game.cpp
*   \brief Файл содержит реализацию функции
*   \author Охманович Андрей
*   \date 24.12.2020
*/
#include <cstdlib>

#include "spawnplatform.h"

bool dropTracker;

Platform *randomPlatform()
{

    Platform *basePointer;
    basePointer = new GreenPlatform;
    dropTracker=false;

    return basePointer;
}
