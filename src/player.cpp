//
// Created by Thomas on 03.07.2025.
//
#include "../include/Player.h"

//Name
void Player::setName(std::string name) {
    playerName = name;
}

std::string Player::getName() const {
    return playerName;
}

//Score
void Player::setScore(int score) {
    playerScore = score;
}

int Player::getScore() const {
    return playerScore;
}

void Player::resetScore() {
    playerScore = 0;
}

void Player::addScore(int points) {
    playerScore += points;
}

void Player::subtractScore(int points) {
    playerScore -= points;
}