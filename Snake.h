#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include <cstddef>

namespace snakeGame {

    struct Point {
        std::size_t x;
        std::size_t y;
    };

    struct SnakeSegment
    {
        Point pos{ 0 , 0 };
        Point prev{ pos };
    };

    class Snake
    {
    public:
        Snake(std::size_t boardWidth, std::size_t boardHeight);

        std::vector<SnakeSegment> getBody() const;

        void moveRight();
        void moveDown();
        void moveLeft();
        void moveUp();
        void grow();

    private:
        void safeCurrentPosToLastOfFirstElement();
        void moveRemainingElements();

        std::vector<SnakeSegment> mBody;
    };

    std::vector<SnakeSegment> initSnake(
        std::size_t fieldWidth, std::size_t fieldHeight);

}
#endif