//
// Created by Thomas on 06.07.2025.
//

#include "../include/Leaderboard.h"

void Leaderboard::loadFromFile() {
    m_playerData.clear();
    std::ifstream inFile("leaderboard.txt");
    std::string line;
    while (std::getline(inFile, line)) {
        std::istringstream lineStream(line);
        std::string name;
        int score;
        int order;
        lineStream >> name >> score >> order;
        m_playerData.push_back({name, score, order});
    }
}

int Leaderboard::getOrder(int score) {
    std::ifstream inFile(m_filename);
    std::string line;
    int count = 0;

    if (!inFile) {
        std::cerr << "Could not open file: " << m_filename << std::endl;
        return 1; // First by default if file not found
    }

    while (std::getline(inFile, line)) {
        std::istringstream ss(line);
        std::string name;
        int existingScore, order;
        char comma;

        if (std::getline(ss, name, ',') && ss >> existingScore >> comma >> order) {
            if (existingScore == score) {
                ++count;
            }
        }
    }

    inFile.close();
    return count + 1;
}

void Leaderboard::appendToFile(const PlayerData& playerData) {
    std::ofstream outFile(m_filename, std::ios::app);
    if (!outFile) {
        std::cerr << "Error opening file for writing." << std::endl;
        return;
    }
    outFile << playerData.name << "," << playerData.score << "," << playerData.order << std::endl;
    outFile.close();
}

void Leaderboard::addPlayer(const std::string& name, const int score) {
    PlayerData playerData = {name, score, getOrder(score)};
    m_playerData.push_back(playerData);
    appendToFile(playerData);
}

void Leaderboard::printLeaderboard() {
    std::ifstream inFile(m_filename);
    std::string line;

    if (!inFile) {
        std::cerr << "Could not open file: " << m_filename << std::endl;
        return;
    }

    std::cout << "Score,Order,Name" << std::endl;
    while (std::getline(inFile, line)) {
        std::istringstream ss(line);
        std::string name;
        int score, order;
        char comma;

        if (std::getline(ss, name, ',') && ss >> score >> comma >> order) {
            std::cout << score << "," << order << "," << name << std::endl;
        }
    }

    inFile.close();
}

const std::vector<Leaderboard::PlayerData>& Leaderboard::getPlayerData() {
    return m_playerData;
}