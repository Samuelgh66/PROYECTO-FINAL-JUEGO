#ifndef GAME_RULES_H
#define GAME_RULES_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QBrush>
#include <QColor>
#include "bomberman.h"

class game_rules: public QGraphicsScene
{
public:
    game_rules(QGraphicsView *graph);
    ~game_rules();
    void set_bomberman_movement(QKeyEvent *event);
private:
    QGraphicsView *graph;
    bomberman *BomberMan;

    void set_graphicsview_color(int r, int g, int b, int a);
    void set_scene_dimensions();
    void set_scenario();
};

#endif // GAME_RULES_H
