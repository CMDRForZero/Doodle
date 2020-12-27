/* ! \file spawnplatform.h
*   \brief Файл содержит описание функции - рандомность появления платформ на экране
*   \author Охманович Андрей
*   \date 24.12.2020
*/
#ifndef SPAWNPLATFORM_H
#define SPAWNPLATFORM_H


#include "define.h"
#include "platform.h"
#include "greenplatform.h"


Platform *randomPlatform();
extern bool dropTracker;

#endif // SPAWNPLATFORM_H
