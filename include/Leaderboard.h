//
// Created by Thomas on 06.07.2025.
//

#ifndef LEADERBOARD_H
#define LEADERBOARD_H
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

#include "GameMode.h"

#endif //LEADERBOARD_H
class Leaderboard {
private:
    struct PlayerData {
        int gameMode;
        std::string name;
        int score;
        int order;
    };

public:
    Leaderboard(const std::string& file) : m_filename(file) {
        loadFromFile();
    }
    ~Leaderboard() = default;
    void addPlayer(int gameMode, const std::string& name, const int score);
    void printLeaderboard();
    void printLeaderboardByGamemode(int mode);
    const std::vector<PlayerData>& getPlayerData();

private:
    std::vector<PlayerData> m_playerData;
    std::string m_filename;
    void loadFromFile();
    int getOrder(int score);
    void appendToFile(const PlayerData& playerData);
};
