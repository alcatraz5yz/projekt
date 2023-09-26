#include "SnakeBoard.h"

#include <QKeyEvent>
#include <QColor>
#include <QPainter>
#include <QRgb>
#include <QTimerEvent>

#include <QDebug>

using namespace snakeGame;

SnakeBoard::SnakeBoard(QWidget* parent)
    : QFrame{parent},
    board{boardWidth, boardHeight},
    snakeDirection{SnakeDirection::right}
{
    setFrameStyle(QFrame::Panel | QFrame::Sunken);
    setFocusPolicy(Qt::StrongFocus);

    board.updateSnakePosition();
    board.placeFood();
}

QSize SnakeBoard::sizeHint() const
{
    return QSize(boardWidth * 15 + frameWidth() * 2,
                 boardHeight * 15 + frameWidth() * 2);
}

QSize SnakeBoard::minimumSizeHint() const
{
    return QSize(boardWidth * 5 + frameWidth() * 2,
                 boardHeight * 5 + frameWidth() * 2);
}

void SnakeBoard::start()
{
    if (isGameOver) {
        isGameOver = false;
        board.reset();
        board.updateSnakePosition();
        board.placeFood();

        score = 0;
        points = initPoints;
        delay = initDelay;
    }

    if (isPaused)
        return;

    isStarted = true;

    emit scoreChanged(score);
    emit delayChanged(delay);

    timer.start(delay, this);
}

void SnakeBoard::pause()
{
    if (!isStarted)
        return;

    isPaused = !isPaused;
    if (isPaused) {
        timer.stop();
    }
    else {
        timer.start(delay, this);
    }
    update();
}

void SnakeBoard::gameOver()
{
    timer.stop();
    isGameOver = true;
    isStarted = false;
}

void SnakeBoard::paintEvent(QPaintEvent *event)
{
    QFrame::paintEvent(event);

    QPainter painter(this);
    QRect rect = contentsRect();


    if(isGameOver) {
        QFont font;
        font.setPixelSize(20);
        painter.setFont(font);
        painter.drawText(rect, Qt::AlignCenter, tr("Game Over"));
        return;
    }

    if(!isStarted) {
        QFont font;
        font.setPixelSize(20);
        painter.setFont(font);
        painter.drawText(rect, Qt::AlignCenter, tr(
            "Press start\n Use arrow keys to control the Snake"));
        return;
    }

    if (isPaused) {
        QFont font;
        font.setPixelSize(20);
        painter.setFont(font);
        painter.drawText(rect, Qt::AlignCenter, tr("Pause"));
        return;
    }

    auto boardTop = rect.bottom() - boardHeight * squareHeight();

    for (int i = 0; i < boardHeight; ++i) {
        for (int j = 0; j < boardWidth; ++j) {
            auto fieldType =
                board.fieldTypeAt(
                    static_cast<std::size_t>(j),
                    static_cast<std::size_t>(i));
            drawField(painter, rect.left() + j * squareWidth(),
                      boardTop + i * squareHeight(), fieldType);
        }
    }
}


void SnakeBoard::keyPressEvent(QKeyEvent *event)
{
    auto key = event->key();

    if (key == Qt::Key_P) {
        emit pause();
    }
    if (key == Qt::Key_Space) {
        emit start();
    }
    else if (!isStarted || isGameOver || !snakeWasMoved) {
        QFrame::keyPressEvent(event);
        return;
    }

    switch (key) {
    case Qt::Key_Left:       
        if (snakeDirection != SnakeDirection::right) {
            snakeDirection = SnakeDirection::left;
            snakeWasMoved = false;
        }
        break;
    case Qt::Key_Right:
        if (snakeDirection != SnakeDirection::left) {
            snakeDirection = SnakeDirection::right;
            snakeWasMoved = false;
        }
        break;
    case Qt::Key_Down:
        if (snakeDirection != SnakeDirection::up) {
            snakeDirection = SnakeDirection::down;
            snakeWasMoved = false;
        }
        break;
    case Qt::Key_Up:
        if (snakeDirection != SnakeDirection::down) {
            snakeDirection = SnakeDirection::up;
            snakeWasMoved = false;
        }
        break;
    default:
        QFrame::keyPressEvent(event);
    }
}

void SnakeBoard::timerEvent(QTimerEvent *event)
{
    if (isGameOver){
        QFrame::timerEvent(event);
        return;
    }

    if (event->timerId() == timer.timerId()) {

        board.moveSnake(snakeDirection);
        snakeWasMoved = true;

        if (board.snakeHitFood()) {
            board.eatFood();
            board.growSnake();
            board.updateSnakePosition();
            board.placeFood();
            score += points;
            points += static_cast<double>(initDelay / delay) * initPoints;
            delay -= 4;

            emit scoreChanged(score);
            emit delayChanged(delay);
        }
        else if (board.snakeHitWall() || board.snakeHitSnake()) {
            emit gameOver();
        }
        else {
            board.updateSnakePosition();
        }

        update();

        timer.start(delay, this);
    }
    else {
        QFrame::timerEvent(event);
    }
}

int SnakeBoard::squareWidth()
{
    return contentsRect().width() / boardWidth;
}

int SnakeBoard::squareHeight()
{
    return contentsRect().height() / boardHeight;
}

void SnakeBoard::drawField(
    QPainter& painter, int x, int y, snakeGame::FieldType fieldType)
{
    switch(fieldType){
    case FieldType::empty:
        break;
    case FieldType::wall:
        drawWall(painter, x, y);
        break;
    case FieldType::food:
        drawFood(painter, x, y);
        break;
    case FieldType::snakeHead:
        drawSnakeHead(painter, x, y);
        break;
    case FieldType::snakeSegment:
        drawSnakeSegment(painter, x, y);
        break;
    }
}

void SnakeBoard::drawWall(QPainter& painter, int x, int y) {
    constexpr auto colorBrown = 0xbf8040;

    QColor color = QRgb{colorBrown};
    painter.fillRect(x + 1, y + 1, squareWidth() - 2, squareHeight() - 2,
                     color);

    painter.setPen(color.lighter());
    painter.drawLine(x, y + squareHeight() - 1, x, y);
    painter.drawLine(x, y, x + squareWidth() - 1, y);

    painter.setPen(color.darker());
    painter.drawLine(x + 1, y + squareHeight() - 1,
                     x + squareWidth() - 1, y + squareHeight() - 1);
    painter.drawLine(x + squareWidth() - 1, y + squareHeight() - 1,
                     x + squareWidth() - 1, y + 1);
}







void SnakeBoard::drawFood(QPainter& painter, int x, int y)
{
    constexpr auto colorRed = 0xff0000;
    QColor color = QRgb{colorRed};
    painter.setPen(color.lighter());
    painter.setBrush(QBrush{color});
    painter.drawEllipse(x +1,y +1,squareWidth() -3, squareHeight() -3);
}

void SnakeBoard::drawSnakeHead(QPainter& painter, int x, int y)
{
    constexpr auto colorDarkerLimeGreen = 0x00b300;

    QColor color = QRgb{colorDarkerLimeGreen};
    painter.fillRect(x + 1, y + 1, squareWidth() - 2, squareHeight() - 2,
                     color);

    painter.setPen(color.lighter());
    painter.drawLine(x, y + squareHeight() - 1, x, y);
    painter.drawLine(x, y, x + squareWidth() - 1, y);

    painter.setPen(color.darker());
    painter.drawLine(x + 1, y + squareHeight() - 1,
                     x + squareWidth() - 1, y + squareHeight() - 1);
    painter.drawLine(x + squareWidth() - 1, y + squareHeight() - 1,
                     x + squareWidth() - 1, y + 1);
}

void SnakeBoard::drawSnakeSegment(QPainter& painter, int x, int y)
{
    constexpr auto colorLimeGreen = 0x00e600;

    QColor color = QRgb{colorLimeGreen};
    painter.fillRect(x + 1, y + 1, squareWidth() - 2, squareHeight() - 2,
                     color);

    painter.setPen(color.lighter());
    painter.drawLine(x, y + squareHeight() - 1, x, y);
    painter.drawLine(x, y, x + squareWidth() - 1, y);

    painter.setPen(color.darker());
    painter.drawLine(x + 1, y + squareHeight() - 1,
                     x + squareWidth() - 1, y + squareHeight() - 1);
    painter.drawLine(x + squareWidth() - 1, y + squareHeight() - 1,
                     x + squareWidth() - 1, y + 1);
}