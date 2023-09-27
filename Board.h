#pragma once
#include "Snake.h"
#include <vector>
#include <random>
#include <iosfwd>

namespace snakeGame {
    enum class SnakeDirection;
    enum class FieldType { empty, snakeSegment, snakeHead, wall, food };
    enum class SnakeDirection { up, right, down, left };

    class Board {
    public:
        Board(std::size_t width, std::size_t height);
        void reset();
        void placeFood();
        void updateSnakePosition();
        bool snakeHitFood() const;
        void eatFood();
        void growSnake();
        bool snakeHitWall() const;
        bool snakeHitSnake() const;
        void moveSnake(SnakeDirection snakeDirection);
        void debugPrintSnakeCoordinates();
        FieldType fieldTypeAt(std::size_t x, std::size_t y);
    private:
        std::vector<std::vector<FieldType>> initFieldWithWalls( std::size_t width, std::size_t height);
        void removeOldSnakePosition(const std::vector<SnakeSegment>& body);
        void addNewSnakePosition(const std::vector<SnakeSegment>& body);
        const std::size_t mWidth;
        const std::size_t mHeight;
        Snake mSnake;
        std::vector<std::vector<FieldType>> mFields;
        std::random_device mRandomDevice;
        std::default_random_engine mGenerator;
        std::uniform_int_distribution<std::size_t> mWidthDistribution;
        std::uniform_int_distribution<std::size_t> mHeightDistribution;
        friend std::wostream& operator<<(std::wostream& os, const Board& obj);
    };
    std::wostream& operator<<(std::wostream& os, const Board& obj);
}