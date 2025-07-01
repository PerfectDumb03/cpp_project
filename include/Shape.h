//
// Created by Luca on 01.07.2025.
//

#ifndef SHAPE_H
#define SHAPE_H

class Shape {
protected:
    int m_x;
    int m_y;
    int m_speed;
public:
    Shape(int x, int y, int speed);
    virtual ~Shape() = default;

    virtual bool checkCollision(const Shape& FaceRect); //checks if the shape collides with Face-Rect
    void move(); //moves shape for the next frame
    virtual bool checkOutOfBounds(int frameHeight); //checks if shape is completely out of bounds
};
#endif //SHAPE_H
