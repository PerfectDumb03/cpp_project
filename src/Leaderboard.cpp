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
        int gameMode, score, order;
        std::string gameModeStr, scoreStr, orderStr;

        // Parse format: gameMode, name,score,order
        if (std::getline(lineStream, gameModeStr, ',') &&
            std::getline(lineStream, name, ',') &&
            std::getline(lineStream, scoreStr, ',') &&
            std::getline(lineStream, orderStr)) {
            try {
                gameMode = std::stoi(gameModeStr);
                score = std::stoi(scoreStr);
                order = std::stoi(orderStr);
                m_playerData.push_back({gameMode, name, score, order});
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
    outFile << playerData.gameMode << "," << playerData.name << "," << playerData.score << "," << playerData.order << std::endl;
    outFile.close();
}

void Leaderboard::addPlayer(int gameMode, const std::string& name, const int score) {
    PlayerData playerData = {gameMode, name, score, getOrder(score)};
    m_playerData.push_back(playerData);
    appendToFile(playerData);
}

void Leaderboard::printLeaderboard() {
    loadFromFile();
    std::cout << "Leaderboard:\n";
    for (const auto& player : m_playerData) {
        std::cout << "Gamemode: " << player.gameMode
                  << ", Name: " << player.name
                  << ", Score: " << player.score
                  << ", Order: " << player.order << "\n";
    }
}

void Leaderboard::printLeaderboardByGamemode(int mode) {
    // Filter only matching gamemode
    std::vector<PlayerData> filtered;
    for (const auto& player : m_playerData) {
        if (player.gameMode == mode) {
            filtered.push_back(player);
        }
    }

    // Sort by score descending, then order ascending
    std::sort(filtered.begin(), filtered.end(), [](const PlayerData& a, const PlayerData& b) {
        if (a.score != b.score) return a.score > b.score; // Higher score first
        return a.order < b.order;                         // Lower order first
    });

    // Print header
    std::cout << "Gamemode " << mode << " Leaderboard:\n";
    std::cout << "Score\tOrder\tName\n";

    for (const auto& player : filtered) {
        std::cout << player.score << "\t" << player.order << "\t" << player.name << "\n";
    }
}

const std::vector<Leaderboard::PlayerData>& Leaderboard::getPlayerData() {
    return m_playerData;
}