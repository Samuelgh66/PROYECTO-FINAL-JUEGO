#ifndef BOMBERMAN_H
#define BOMBERMAN_H

#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include "macros.h"


class bomberman : public QGraphicsPixmapItem
{
public:
    bomberman();
    ~bomberman();
    void set_movement(QKeyEvent *event);
private:

    int up, down, right, left, sprites_counter;
    QPixmap *sprites;

    void copy_bomberman_sprites();
    void set_bomberman_movement_keys();
    void set_sprites_movement(int movement);

};

#endif // BOMBERMAN_H
