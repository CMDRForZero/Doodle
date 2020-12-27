/* ! \file button.cpp
*   \brief Файл содержит реализацию класса Button
*   \author Охманович Андрей
*   \date 24.12.2020
*/
#include "button.h"

Button::Button(QString resPath, QString hoverPath, QGraphicsItem *parent):
    QGraphicsPixmapItem (parent),
    resPath(resPath),
    hoverPath(hoverPath)
{
    setAcceptHoverEvents(true);

    QPixmap pix;
    pix.load(resPath);

    setPixmap(pix.scaledToWidth(BUTTON_WIDTH));
}

void Button::mousePressEvent(QGraphicsSceneMouseEvent *)
{
    emit clicked();
}

void Button::hoverEnterEvent(QGraphicsSceneHoverEvent *)
{
    QPixmap pix;
    pix.load(hoverPath);

    setPixmap(pix.scaledToWidth(BUTTON_WIDTH));
}

void Button::hoverLeaveEvent(QGraphicsSceneHoverEvent *)
{
    QPixmap pix;
    pix.load(resPath);

    setPixmap(pix.scaledToWidth(BUTTON_WIDTH));
}
