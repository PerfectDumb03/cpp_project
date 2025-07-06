//
// Created by Thomas on 06.07.2025.
//

#ifndef GAMESETTINGS_H
#define GAMESETTINGS_H

class GameSettings {
public:
    void setGameMode();
    int getGameMode() const;

    void setObjectCount();
    int getObjectCount() const;

protected:
    int m_gameMode = 0;
    int m_objectCount = 0;
};

#endif //GAMESETTINGS_H
