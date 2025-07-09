#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player {
public:
    Player() = default;
    virtual ~Player() = default;

    void setName();
    std::string getName() const;

    void setScore(int score);
    int getScore() const;
    void resetScore();
    void addScore(int points);
    void subtractScore(int points);

protected:
    std::string m_playerName = "DefaultPlayer";
    int m_playerScore = 0;
};

#endif // PLAYER_H