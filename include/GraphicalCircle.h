#ifndef GRAPHICALCIRCLE_H
#define GRAPHICALCIRCLE_H

#include "ShapeCircle.h"
#include <array>

class GraphicalCircle: public ShapeCircle {

public:
    GraphicalCircle(int x, std::array<int,3> color={-1,-1,-1});
    GraphicalCircle(int x, int y, int radius=-1, int thickness=-1, std::array<int,3> color={-1,-1,-1});
    GraphicalCircle(ShapeCircle& circle, int thickness=-1, std::array<int,3> color={-1,-1,-1});
    //~GraphicalCircle() = default;

    void draw(cv::Mat& frame);
};



#endif //GRAPHICALCIRCLE_H
