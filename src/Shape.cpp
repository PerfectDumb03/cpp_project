//
// Created by Luca on 01.07.2025.
//

#include "../include/Shape.h"
#include <random>

Shape::Shape(int x, int y, int thickness, std::array<int,3> color): m_x(x), m_y(y), m_thickness(thickness), m_color(color) {
    std::random_device rd;
    std::mt19937 gen(rd());
    if (m_color[0]==-1){
        randomizeColor(gen);
    }
    randomizeSpeed(gen);
    Shape::randomizeSize(gen);
}
Shape::~Shape() {
};
void Shape::move() {
    m_y += m_speed;
}

bool Shape::checkOutOfBounds(int frameHeight) {
    return m_y > frameHeight;
}

bool Shape::checkCollision(ShapeSquare& FaceRect) {
    return true;
}

int Shape::getX() {
    return m_x;
}

int Shape::getY() {
    return m_y;
}
int Shape::getSpeed() {
    return m_speed;
}
cv::Scalar Shape::getColor() { //BGR order
    return {static_cast<double>(m_color[2]),
        static_cast<double>(m_color[1]),
        static_cast<double>(m_color[0])};
}
int Shape::getThickness() {
    return m_thickness;
}

void Shape::setSpeed(int newValue) {
    m_speed = newValue;
}

void Shape::randomizeColor(std::mt19937 gen) {
    std::uniform_int_distribution<> dis(0, 255);
    for (int i = 0; i < 3; i++) {
        m_color[i] = dis(gen);
    }
}

void Shape::randomizeSpeed(std::mt19937 gen) {
    std::uniform_int_distribution<> dis(3, 15);
    setSpeed(dis(gen));
}
void Shape::randomizeSize(std::mt19937 gen) {
    std::uniform_int_distribution<> dis(0, 100);
}
