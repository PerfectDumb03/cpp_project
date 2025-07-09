#ifndef SHAPE_H
#define SHAPE_H

#include <array>
#include <opencv2/core/types.hpp>
#include <random>

class ShapeSquare;

class Shape {
protected:
    int m_x;
    int m_y;
    int m_speed;
    int m_thickness;
    std::array<int,3> m_color;

public:
    Shape(int x, int y, int thickness, std::array<int,3> color);
    virtual ~Shape();


    virtual bool checkCollision(ShapeSquare& FaceRect); //checks if the shape collides with Face-Rect
    void move(); //moves shape for the next frame
    virtual bool checkOutOfBounds(int frameHeight); //checks if shape is completely out of bounds

    int getX();
    int getY();
    int getSpeed();
    cv::Scalar getColor();
    int getThickness();

    void setSpeed(int newValue);

private:
    void randomizeSpeed(std::mt19937 gen);
    void randomizeColor(std::mt19937 gen);
    virtual void randomizeSize(std::mt19937 gen);
};
#endif //SHAPE_H
