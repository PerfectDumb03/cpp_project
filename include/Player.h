//
// Created by tvahl on 02.07.2025.
//

#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player {
    public:
        Player(const std::string& name);
        std::string getName() const;
        int getScore() const;
        void addScore(int points);
        void subtractScore(int points);
    private:
        std::string name;
        int score;
};

#endif // PLAYER_H