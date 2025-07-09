//
// Created by Thomas on 06.07.2025.
//

#include "../include/GameOverScreen.h"
#include <limits>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

// Destroy playing window before calling function (e.g., cv::destroyWindow(windowName);)
void GameOverScreen::show(const std::string& playerName, int score) {
    // Generate black frame
    cv::Mat gameOverFrame = cv::Mat::zeros(600, 800, CV_8UC3);

    // Define text
    std::string gameOverText = "GAME OVER";
    std::string scoreText = playerName + "'s Score: " + std::to_string(score);
    std::string closeText = "Press any key to exit...";
    int font = cv::FONT_HERSHEY_SIMPLEX;

    //Center score text for names with different length
    cv::Size textSize = cv::getTextSize(scoreText, font, 1.5, 2, 0);
    cv::Point scoreTextPos((gameOverFrame.cols - textSize.width) / 2, 300);

    // Draw text
    cv::putText(gameOverFrame, gameOverText, cv::Point(200, 200), font, 2.0, cv::Scalar(0, 0, 255), 3); // rot
    cv::putText(gameOverFrame, scoreText, scoreTextPos, font, 1.5, cv::Scalar(255, 255, 255), 2); // weiß
    cv::putText(gameOverFrame, closeText, cv::Point(200, 400), font, 1.0, cv::Scalar(100, 255, 100), 1); // grünlich

    // Show image
    cv::imshow("Game Over", gameOverFrame);
    cv::waitKey();
    cv::destroyWindow("Game Over");
}