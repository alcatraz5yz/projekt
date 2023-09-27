#include "Snake.h"

namespace snakeGame {

    Snake::Snake(std::size_t fieldWidth, std::size_t fieldHeight) :
    mBody{ initSnake(fieldWidth, fieldHeight) } {}
    std::vector<SnakeSegment> Snake::getBody() const {
        return mBody;
    }

    void Snake::moveRight() {
        safeCurrentPosToLastOfFirstElement();
        ++mBody.at(0).pos.x;
        moveRemainingElements();
    }

    void Snake::moveDown() {
        safeCurrentPosToLastOfFirstElement();
        ++mBody.at(0).pos.y;
        moveRemainingElements();
    }

    void Snake::moveLeft() {
        safeCurrentPosToLastOfFirstElement();
        --mBody.at(0).pos.x;
        moveRemainingElements();
    }

    void Snake::moveUp() {
        safeCurrentPosToLastOfFirstElement();
        --mBody.at(0).pos.y;
        moveRemainingElements();
    }

    void Snake::grow() {
        mBody.push_back(SnakeSegment{
            {mBody.at(mBody.size() - 1).prev.x,
            mBody.at(mBody.size() - 1).prev.y}
        });
    }

    void Snake::safeCurrentPosToLastOfFirstElement() {
        mBody.at(0).prev.x = mBody.at(0).pos.x;
        mBody.at(0).prev.y = mBody.at(0).pos.y;
    }

    void Snake::moveRemainingElements() {
        for (std::size_t i = 1; i < mBody.size(); ++i) {
            mBody.at(i).prev.x = mBody.at(i).pos.x;
            mBody.at(i).prev.y = mBody.at(i).pos.y;
            mBody.at(i).pos.x = mBody.at(i - 1).prev.x;
            mBody.at(i).pos.y = mBody.at(i - 1).prev.y;
        }
    }


    std::vector<SnakeSegment> initSnake( std::size_t boardWidth, std::size_t boardHeight) {
        auto x = boardWidth / 2;
        auto y = boardHeight / 2;
        std::vector<SnakeSegment> body{
            SnakeSegment{ {x, y} },
            SnakeSegment{ {x - 1, y} },
        };
        return body;
    }
}