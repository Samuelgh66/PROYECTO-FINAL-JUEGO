#include "bomberman.h"

bomberman::bomberman()
{
    sprites = new QPixmap;

    sprites_counter = 0;
    set_bomberman_movement_keys();
    copy_bomberman_sprites();
    set_sprites_movement(Qt::Key_D);
    setPos(0,0);
}

bomberman::~bomberman()
{
    delete sprites;
}

void bomberman::set_movement(QKeyEvent *event)
{
    if(event->key()==up) setY(y()-bomberman_speed);
    else if(event->key()==down) setY(y()+bomberman_speed);
    else if(event->key()==right) setX(x()+bomberman_speed);
    else if(event->key()==left) setX(x()-bomberman_speed);

    set_sprites_movement(event->key());
}

void bomberman::copy_bomberman_sprites()
{
    QPixmap img;
    img.load(":/Imagenes/bomberman_sprites.png");
    *sprites = img.copy(bomberman_sprites_posx,
                        bomberman_sprites_posy,
                        bomberman_sprites_col*design_width,
                        bomberman_sprites_fil*design_height);
}

void bomberman::set_bomberman_movement_keys()
{
    up = Qt::Key_W;
    down = Qt::Key_S;
    right = Qt::Key_D;
    left = Qt::Key_A;
}

void bomberman::set_sprites_movement(int movement)
{
    QPixmap sprite;

    if(movement == up) sprite = sprites->copy((3+sprites_counter)*design_width,1*design_height,design_width,design_height);
    else if(movement == down) sprite = sprites->copy((3+sprites_counter)*design_width,0*design_height,design_width,design_height);
    else if(movement == left) sprite = sprites->copy(sprites_counter*design_width,0*design_height,design_width,design_height);
    else if (movement == right) sprite = sprites->copy(sprites_counter*design_width,1*design_height,design_width,design_height);

    sprite = sprite.scaled(sprite.width()*game_scale,sprite.height()*game_scale);
    setPixmap(sprite);
    sprites_counter++;

    if(sprites_counter > 2) sprites_counter = 0;
}
