/* ! \file platform.cpp
*   \brief Файл содержит реализацию класса Platform
*   \author Охманович Андрей
*   \date 24.12.2020
*/
#include "platform.h"

Platform::Platform()
{
    setShapeMode(QGraphicsPixmapItem::HeuristicMaskShape);
    setData(TYPE, PLATFORM);
}

Platform::~Platform()
{
}

void Platform::setCoordinate(qreal x, qreal y)
{
    xPos=x;
    yPos=y;
}

qreal Platform::X() const
{
    return xPos;
}

qreal Platform::Y() const
{
    return yPos;
}

int Platform::getHeight() const
{
    return platformHeight;
}

