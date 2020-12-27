/* ! \file platform.h
*   \brief Файл содержит описание класса Platform - местоположение платформы на игровом экране
*   \author Охманович Андрей
*   \date 24.12.2020
*/
#ifndef PLATFORM_H
#define PLATFORM_H


#include <QGraphicsPixmapItem>

#include "define.h"

class Platform: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Platform();
    virtual ~Platform();

    void setCoordinate(qreal x, qreal y);
    qreal X() const;
    qreal Y() const;
    int getHeight() const;

    virtual void setPlatform()=0;
protected:
    qreal xPos, yPos;
    int platformHeight;
};

#endif // PLATFORM_H
