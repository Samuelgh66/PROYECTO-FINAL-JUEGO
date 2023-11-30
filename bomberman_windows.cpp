#include "bomberman_windows.h"
#include "ui_bomberman_windows.h"

BomberMan_Windows::BomberMan_Windows(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::BomberMan_Windows)
{
    ui->setupUi(this);

    set_mainwindow_size(game_scale*design_width*16+2,game_scale*design_height*15+2);
    ui->graphicsView->setGeometry(0,2*game_scale*design_height,width(),height());

    level =  new game_rules(ui->graphicsView);
}

BomberMan_Windows::~BomberMan_Windows()
{
    delete ui;
    delete level;
}

void BomberMan_Windows::set_mainwindow_size(int w, int h)
{
    setGeometry(0,0,w,h);
    setMinimumSize(w,h);
    setMaximumSize(w,h);
}

void BomberMan_Windows::keyPressEvent(QKeyEvent *event)
{
    level->set_bomberman_movement(event);
}

