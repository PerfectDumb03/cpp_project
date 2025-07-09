#ifndef GAMESETTINGS_H
#define GAMESETTINGS_H

class GameSettings {
public:
    void setGameMode();
    int getGameMode() const;

    void setObjectCount();
    int getObjectCount() const;

    int getframeHeight() const;
    void setFrameHeight(int height);

    int getFrameWidth() const;
    void setFrameWidth(int width);

protected:
    int m_gameMode = 0;
    int m_objectCount = 0;
    int m_frameHeight = 480;
    int m_frameWidth = 640;
};

#endif //GAMESETTINGS_H
