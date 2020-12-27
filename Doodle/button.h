/* ! \file button.h
*   \brief Файл содержит описание класса Button - кнопок
*   \author Охманович Андрей
*   \date 24.12.2020
*/
#ifndef BUTTON_H
#define BUTTON_H


#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>

#include "define.h"

class Button: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Button(QString resPath, QString hoverPath, QGraphicsItem *parent=nullptr);
signals:
    void clicked();
private:
    QString resPath, hoverPath;
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *);
    void hoverEnterEvent(QGraphicsSceneHoverEvent *);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *);
};

#endif // BUTTON_H
