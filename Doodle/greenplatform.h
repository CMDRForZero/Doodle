/* ! \file greenplatform.h
*   \brief Файл содержит описание класса GreenPlatform - зеленой платформы
*   \author Охманович Андрей
*   \date 24.12.2020
*/
#ifndef GREENPLATFORM_H
#define GREENPLATFORM_H


#include "platform.h"

class GreenPlatform: public Platform
{
public:
    GreenPlatform();
    virtual ~GreenPlatform();

    void setPlatform();
};

#endif // GREENPLATFORM_H
