//
// Created by Luca on 01.07.2025.
//

#ifndef SHAPE_H
#define SHAPE_H

#include <array>
#include <random>



class Shape {
protected:
    int m_x;
    int m_y;
    int m_speed = 5;
    int thickness = -1;
    std::array<int,3> m_color; // Pointer to RGB color values
public:
    Shape(int x, int y, std::array<int,3> color);
    virtual ~Shape() = default;


    virtual bool checkCollision(const Shape& FaceRect); //checks if the shape collides with Face-Rect
    void move(); //moves shape for the next frame
    virtual bool checkOutOfBounds(int frameHeight); //checks if shape is completely out of bounds


    int getX();
    int getY();
    void setSpeed(int newValue);
    void setThickness(int newValue);


private:
    void randomizeColor();
};
#endif //SHAPE_H
