//
// Created by Luca on 01.07.2025.
//

#ifndef SHAPE_H
#define SHAPE_H
#include <array>
#include <opencv2/core/types.hpp>

class ShapeSquare;

class Shape {
protected:
    int m_x;
    int m_y;
    int m_speed = 5;
    int m_thickness;
    std::array<int,3> m_color;

public:
    Shape(int x, int y, int thickness, std::array<int,3> color);
    virtual ~Shape() = default;


    virtual bool checkCollision(ShapeSquare& FaceRect); //checks if the shape collides with Face-Rect
    void move(); //moves shape for the next frame
    virtual bool checkOutOfBounds(int frameHeight); //checks if shape is completely out of bounds


    int getX();
    int getY();
    int getSpeed();
    cv::Scalar getColor();
    int getThickness();

    void setSpeed(int newValue);

};
#endif //SHAPE_H
