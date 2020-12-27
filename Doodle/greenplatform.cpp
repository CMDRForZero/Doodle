/* ! \file greenplatform.cpp
*   \brief Файл содержит реализацию класса GreenPlatform
*   \author Охманович Андрей
*   \date 24.12.2020
*/
#include "greenplatform.h"

GreenPlatform::GreenPlatform():Platform()
{
    setPlatform();
}

GreenPlatform::~GreenPlatform()
{
}

void GreenPlatform::setPlatform()
{
    QPixmap pix;
    pix.load(PLATFORM_PATH);

    setPixmap(pix.scaledToWidth(PLATFORM_WIDTH));
    platformHeight=pix.scaledToWidth(PLATFORM_WIDTH).height();
    setData(PLATFORM_TYPE, NORMAL);
}
