#include "game_rules.h"

game_rules::game_rules(QGraphicsView *graph)
{
    this->graph = graph;
    BomberMan = new bomberman;

    set_scene_dimensions();
    set_graphicsview_color(56,135,0,255);
    set_scenario();
}

game_rules::~game_rules()
{
    delete BomberMan;
}

void game_rules::set_bomberman_movement(QKeyEvent *event)
{
    BomberMan->set_movement(event);
}

void game_rules::set_graphicsview_color(int r, int g, int b, int a)
{
    QBrush brush;
    QColor color;

    color.setRgb(r,g,b,a);
    brush.setColor(color);
    setBackgroundBrush(brush);
    graph->setBackgroundBrush(brush);
}

void game_rules::set_scene_dimensions()
{
    setSceneRect(0,0,graph->width()-2,graph->height()-2);
    graph->setScene(this);
}

void game_rules::set_scenario()
{
    addItem(BomberMan);
}
