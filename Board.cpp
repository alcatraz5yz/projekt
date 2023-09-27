#include "Board.h"
#include <algorithm>
#include <iostream>

namespace snakeGame {

    Board::Board(std::size_t width, std::size_t height) : 

        mWidth{width},
        mHeight{height},
        mSnake{ width, height },
        mFields{ initFieldWithWalls(width, height) },
        mRandomDevice{},
        mGenerator{ mRandomDevice() },
        mWidthDistribution{ 2, width - 3 },
        mHeightDistribution{ 2, height - 3 } { }

    void Board::reset() {
        mFields = initFieldWithWalls(mWidth, mHeight);
        mSnake = Snake{mWidth,mHeight};
    }

    void Board::placeFood() {
        for (;;) {
            auto x = mWidthDistribution(mGenerator);
            auto y = mHeightDistribution(mGenerator);

            if(mFields.at(y).at(x) == FieldType::empty){
                mFields.at(y).at(x) = FieldType::food;
                return;
            }
        }
    }

    void Board::updateSnakePosition() {
        auto snakeBody = mSnake.getBody();
        removeOldSnakePosition(snakeBody);
        addNewSnakePosition(snakeBody);
    }

    bool Board::snakeHitFood() const {
        auto pos = mSnake.getBody().at(0).pos;
        return mFields.at(pos.y).at(pos.x) == FieldType::food;
    }

    void Board::eatFood() {
        auto pos = mSnake.getBody()[0].pos;
        mFields.at(pos.y).at(pos.x) = FieldType::empty;
    }

    void Board::growSnake() {
        mSnake.grow();
    }

    bool Board::snakeHitWall() const {
        auto pos = mSnake.getBody()[0].pos;
        return mFields.at(pos.y).at(pos.x) == FieldType::wall;
    }

    bool Board::snakeHitSnake() const {
        auto pos = mSnake.getBody()[0].pos;
        return mFields.at(pos.y).at(pos.x) == FieldType::snakeSegment;
    }

    void Board::moveSnake(SnakeDirection snakeDirection) {
        switch (snakeDirection) {
        case SnakeDirection::right:
            mSnake.moveRight();
            break;

        case SnakeDirection::down:
            mSnake.moveDown();
            break;

        case SnakeDirection::left:
            mSnake.moveLeft();
            break;

        case SnakeDirection::up:
            mSnake.moveUp();
            break;
        }
    }

    void Board::debugPrintSnakeCoordinates() {
        auto body = mSnake.getBody();
        for (std::size_t i = 0; i < body.size(); ++i) {
            auto pos = body.at(i).pos;
            std::wcout << "nr:" << i << "x:" << pos.x << "\t" << "y:" << pos.y << "\t";
            auto field = mFields.at(pos.y).at(pos.x);
            switch(field) {
            case FieldType::snakeHead:
                std::wcout << L"Head\t";
                [[fallthrough]];
            case FieldType::snakeSegment:
                std::wcout << L"Body\n";
                [[fallthrough]];
            default:
                std::wcout << L"    \n";
            }
        }
    }

    FieldType Board::fieldTypeAt(std::size_t x, std::size_t y) {
        return mFields.at(y).at(x);
    }

    std::vector<std::vector<FieldType>> Board::initFieldWithWalls(
        std::size_t width, std::size_t height) {
        std::vector<FieldType> row(width, FieldType::empty);
        std::vector<std::vector<FieldType>> field(height, row);
        std::fill(field.at(0).begin(), field.at(0).end(), FieldType::wall);
        std::fill(field.at(field.size() - 1).begin(), field.at(field.size() - 1).end(), FieldType::wall);
        for (auto it_row = field.begin() + 1; it_row < field.end() - 1; ++it_row) {
            (*it_row).at(0) = FieldType::wall;
            (*it_row).at(it_row->size() - 1) = FieldType::wall;
        }
        return field;
    }

    void Board::removeOldSnakePosition(const std::vector<SnakeSegment>& body) {
        for (const auto& snakeSegment : body) {
            auto prev = snakeSegment.prev;
            mFields.at(prev.y).at(prev.x) = FieldType::empty;
        }
    }

    void Board::addNewSnakePosition(const std::vector<SnakeSegment>& body) {
        auto first{ true };
        for (const auto& snakeSegment : body) {
            auto pos = snakeSegment.pos;

            if (first) {
                mFields.at(pos.y).at(pos.x) = FieldType::snakeHead;
                first = false;
            }
            else {
                mFields.at(pos.y).at(pos.x) = FieldType::snakeSegment;
            }
        }
    }

    std::wostream& operator<<(std::wostream& os, const Board& obj) {
        for (const auto& row : obj.mFields) {
            for (const auto& element : row) {
                switch(element){
                case FieldType::empty:
                    os << L' ';
                    break;
                case FieldType::wall:
                    os << L'#';
                    break;
                case FieldType::food:
                    os << L'*';
                    break;
                case FieldType::snakeHead:
                    os << L'@';
                    break;
                case FieldType::snakeSegment:
                    os << L'o';
                    break;
                }
            }
            os << '\n';
        }
        return os;
    }
}