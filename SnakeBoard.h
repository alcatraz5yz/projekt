#ifndef SNAKEBOARD_H
#define SNAKEBOARD_H

#include <QFrame>
#include <QBasicTimer>

#include "Board.h"

class SnakeBoard : public QFrame {
    Q_OBJECT
public:
    SnakeBoard(QWidget* parent = nullptr);

    QSize sizeHint() const override;
    QSize minimumSizeHint() const override;

public slots:
    void start();
    void pause();
    void gameOver();

signals:
    void scoreChanged(int score);
    void delayChanged(int delay);

protected:
    void paintEvent(QPaintEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
    void timerEvent(QTimerEvent *event) override;

private:
    int squareWidth();
    int squareHeight();

    void drawField(
        QPainter& painter, int x, int y, snakeGame::FieldType fieldType);

    void drawWall(QPainter& painter, int x, int y);
    void drawFood(QPainter& painter, int x, int y);

    void drawSnakeHead(QPainter& painter, int x, int y);
    void drawSnakeSegment(QPainter& painter, int x, int y);

    static constexpr auto boardWidth{40};
    static constexpr auto boardHeight{20};

    static constexpr auto initDelay{300};
    static constexpr auto initPoints{100};

    QBasicTimer timer;

    snakeGame::Board board{boardWidth, boardHeight};
    snakeGame::SnakeDirection snakeDirection{snakeGame::SnakeDirection::right};

    bool isStarted{false};
    bool isPaused{false};
    bool isGameOver{false};
    bool snakeWasMoved{true};
    int score{0};
    int delay{initDelay};
    int points{initPoints};
};

#endif // SNAKEBOARD_H