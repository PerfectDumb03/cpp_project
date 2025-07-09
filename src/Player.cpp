#include "../include/Player.h"
#include "../include/InputHandler.h"
#include <iostream>
#include <bits/ostream.tcc>

//Name
void Player::setName() {
    m_playerName = InputHandler::requestPlayerName();
}

std::string Player::getName() const {
    return m_playerName;
}

//Score
void Player::setScore(int score) {
    m_playerScore = score;
}

int Player::getScore() const {
    return m_playerScore;
}

void Player::resetScore() {
    m_playerScore = 0;
}

void Player::addScore(int points) {
    if (m_playerScore  + points < 0) {
        m_playerScore = 0;
    } else {
        m_playerScore += points;
    }
}

void Player::subtractScore(int points) {
    if (m_playerScore > 0 ) {
        m_playerScore -= points;
    }
}