cmake_minimum_required(VERSION 3.14)
project(HelloWorldQT)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")
find_package(Qt6 COMPONENTS Widgets REQUIRED)
find_package(GTest REQUIRED)
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
    SnakeWindow.ui
)

target_link_libraries(HelloWorldQT PRIVATE Qt6::Widgets)
include_directories(${GTEST_INCLUDE_DIRS} include)
add_executable(main_test 
    src/my_class.cpp 
    tests/my_class_test.cpp
    )
target_link_libraries(main_test PRIVATE Qt6::Widgets ${GTEST_BOTH_LIBRARIES} pthread)
enable_testing()
add_test(NAME main_test COMMAND main_test)

add_custom_command(TARGET HelloWorldQT POST_BUILD
                   COMMAND ${CMAKE_CURRENT_BINARY_DIR}/HelloWorldQT # Führe das Binary aus
                   COMMAND gcov -o ${CMAKE_CURRENT_BINARY_DIR} *.gcda # Generiere .gcov Dateien für jede .gcda Datei
                   COMMAND mv *.gcov ${CMAKE_SOURCE_DIR} # Verschiebe alle .gcov Dateien an den Anfang des Projekts
                   WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})