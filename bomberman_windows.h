#ifndef BOMBERMAN_WINDOWS_H
#define BOMBERMAN_WINDOWS_H

#include <QMainWindow>
#include "game_rules.h"
#include "macros.h"
#include <QKeyEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class BomberMan_Windows; }
QT_END_NAMESPACE

class BomberMan_Windows : public QMainWindow
{
    Q_OBJECT

public:
    BomberMan_Windows(QWidget *parent = nullptr);
    ~BomberMan_Windows();

private:
    game_rules *level;
    Ui::BomberMan_Windows *ui;
    void set_mainwindow_size(int w, int h);
    void keyPressEvent(QKeyEvent *event);
};
#endif // BOMBERMAN_WINDOWS_H
