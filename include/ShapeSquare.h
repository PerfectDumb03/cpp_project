//
// Created by Luca on 01.07.2025.
//

#ifndef SHAPESQUARE_H
#define SHAPESQUARE_H


#include "../include/Shape.h"

namespace cv {
    class Rect;
}

class ShapeSquare : public Shape {
protected:
    int m_height;
    int m_width;
public:
    ShapeSquare(int x, int y, int height, int width, std::array<int,3> color);

    ~ShapeSquare() override = default;

    int getHeight();
    int getWidth();

    bool checkCollision(ShapeSquare& FaceRect); // checks if the square collides with Face-Rect
};



#endif //SHAPESQUARE_H
