cmake_minimum_required(VERSION 3.14)
project(HelloWorldQT)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
find_package(Qt6 COMPONENTS Widgets REQUIRED)
add_executable(HelloWorldQT
    main.cpp
    SnakeWindow.h
    SnakeWindow.cpp
    SnakeBoard.h
    SnakeBoard.cpp
    Board.h
    Board.cpp
    Snake.h
    Snake.cpp
    # Snake_qt.pro
    SnakeWindow.ui
    # ui_SnakeWindow.cpp
    )
target_link_libraries(HelloWorldQT PRIVATE Qt6::Widgets)
