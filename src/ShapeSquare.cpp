//
// Created by Luca on 01.07.2025.
//

#include "../include/ShapeSquare.h"



ShapeSquare::ShapeSquare(int x, int y, int height, int width, int thickness, std::array<int,3> color)
:Shape(x, y, thickness, color), m_height(height), m_width(width){
    if (getHeight()==-1 || getWidth() ==-1) {
        std::random_device rd;
        std::mt19937 gen(rd());
        ShapeSquare::randomizeSize(gen);
    }
}

bool ShapeSquare::checkCollision(ShapeSquare& FaceRect){
    if (m_x < FaceRect.getX() + FaceRect.getWidth() &&   // rechte Kante von Rechteck 1 > linke Kante von Rechteck 2
        m_x + m_width > FaceRect.getX() &&               // linke Kante von Rechteck 1 < rechte Kante von Rechteck 2
        m_y < FaceRect.getY() + FaceRect.getHeight() &&  // untere Kante von Rechteck 1 > obere Kante von Rechteck 2
        m_y + m_height > FaceRect.getY()) {              // obere Kante von Rechteck 1 < untere Kante von Rechteck 2
        return true;
        }
    return false;
}

void ShapeSquare::randomizeSize(std::mt19937 gen) {
    std::uniform_int_distribution<> dis(5, 75);
    int r = dis(gen);
    setHeight(r);
    setWidth(r);
}

int ShapeSquare::getHeight() {
    return m_height;
}
int ShapeSquare::getWidth() {
    return m_width;
}
void ShapeSquare::setHeight(int newValue) {
    m_height = newValue;
}
void ShapeSquare::setWidth(int newValue) {
    m_width = newValue;
}
