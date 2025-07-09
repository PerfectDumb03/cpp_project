#ifndef CATCHBALLS_H
#define CATCHBALLS_H

#include "GameMode.h"

class DogeBalls: public GameMode {
public:
    DogeBalls(GameHandler& gameHandler);
    ~DogeBalls() = default;
};
#endif //CATCHBALLS_H
