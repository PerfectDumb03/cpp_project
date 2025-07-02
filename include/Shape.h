//
// Created by Luca on 01.07.2025.
//

#ifndef SHAPE_H
#define SHAPE_H


class ShapeSquare;

class Shape {
protected:
    int m_x;
    int m_y;
    int m_speed = 5;

public:
    Shape(int x, int y);
    virtual ~Shape() = default;


    virtual bool checkCollision(ShapeSquare& FaceRect); //checks if the shape collides with Face-Rect
    void move(); //moves shape for the next frame
    virtual bool checkOutOfBounds(int frameHeight); //checks if shape is completely out of bounds


    int getX();
    int getY();
    void setSpeed(int newValue);
    int getSpeed();
};
#endif //SHAPE_H
