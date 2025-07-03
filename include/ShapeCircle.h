//
// Created by lucan on 02.07.2025.
//

#ifndef SHAPECIRCLE_H
#define SHAPECIRCLE_H
#include "Shape.h"

class ShapeSquare; //forward declaration


class ShapeCircle : public Shape{
protected:
    int m_radius;
public:
    ShapeCircle(int x, int y, int radius, int thickness, std::array<int,3> color);
    //~ShapeCircle() override = default;

    bool checkCollision(ShapeSquare &FaceRect) override;
    int getRadius();
    cv::Point  getCenter();
    void setRadius(int newValue);
    void randomizeSize(std::mt19937 gen) override;
};



#endif //SHAPECIRCLE_H
