//
// Created by Thomas on 06.07.2025.
//

#include "../include/Leaderboard.h"

void Leaderboard::loadFromFile() {
    m_playerData.clear();
    std::ifstream inFile(m_filename);
    if (!inFile) {
        std::cerr << "Could not open file: " << m_filename << std::endl;
        return;
    }

    std::string line;
    while (std::getline(inFile, line)) {
        std::istringstream lineStream(line);
        std::string name;
        int score, order;
        std::string scoreStr, orderStr;

        // Parse format: name,score,order
        if (std::getline(lineStream, name, ',') &&
            std::getline(lineStream, scoreStr, ',') &&
            std::getline(lineStream, orderStr)) {
            try {
                score = std::stoi(scoreStr);
                order = std::stoi(orderStr);
                m_playerData.push_back({name, score, order});
            } catch (const std::exception& e) {
                std::cerr << "Error parsing line: " << line << "\n";
            }
        }
    }
}

int Leaderboard::getOrder(int score) {
    loadFromFile();
    int count = 0;
    for (const auto& player : m_playerData) {
        if (player.score == score) {
            ++count;
        }
    }
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
    loadFromFile();
    std::cout << "Leaderboard:\n";
    for (const auto& player : m_playerData) {
        std::cout << "Name: " << player.name
                  << ", Score: " << player.score
                  << ", Order: " << player.order << "\n";
    }
}

const std::vector<Leaderboard::PlayerData>& Leaderboard::getPlayerData() {
    return m_playerData;
}