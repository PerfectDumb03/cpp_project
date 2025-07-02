//
// Created by lucan on 02.07.2025.
//

#ifndef SHAPECIRCLE_H
#define SHAPECIRCLE_H
#include "Shape.h"
#include "ShapeSquare.h"


class ShapeCircle : public Shape{
protected:
    int m_radius;
public:
    ShapeCircle(int x, int y, int radius);
    ~ShapeCircle() override = default;

    bool checkCollision(ShapeSquare &FaceRect) override;
    int getRadius();
    int getX();
    int getY();

};



#endif //SHAPECIRCLE_H
