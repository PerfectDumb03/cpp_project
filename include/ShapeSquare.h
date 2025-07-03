//
// Created by Luca on 01.07.2025.
//

#ifndef SHAPESQUARE_H
#define SHAPESQUARE_H


#include "../include/Shape.h"

class ShapeSquare : public Shape {
protected:
    int m_height;
    int m_width;
public:
    ShapeSquare(int x, int y, int height, int width=-1, int thickness=-1, std::array<int,3> color={-1,-1,-1});

    //~ShapeSquare() override = default;

    int getHeight();
    int getWidth();


    bool checkCollision(ShapeSquare& FaceRect) override; // checks if the square collides with Face-Rect
private:
    void randomizeSize(std::mt19937 gen) override;
    void setHeight(int newValue);
    void setWidth(int newValue);
};



#endif //SHAPESQUARE_H
