#pragma once
#include <QWidget>

namespace Ui { class SnakeWindow; }

class SnakeWindow : public QWidget {
    Q_OBJECT

public:
    explicit SnakeWindow(QWidget *parent = nullptr);
    ~SnakeWindow();

private:
    Ui::SnakeWindow *ui;
};