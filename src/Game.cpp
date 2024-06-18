#include "Game.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

Game::Game()
: mWindow(sf::VideoMode(800, 600), "Flappy Bird with SFML")
, mScore(0)
{
    if (!mBackgroundTexture.loadFromFile("./images/road.png")) {
        std::cerr << "Error loading road.png" << std::endl;
    }
    mBackgroundSprite.setTexture(mBackgroundTexture);
    mBird = Bird();

    // Generar un obstáculo inicial
    srand(time(NULL));
    mHurdles.push_back(Hurdle(800, rand() % 400 + 100));

    std::cout << "Press Spacebar to Start" << std::endl;
}

void Game::run() {
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;

    while (mWindow.isOpen()) {
        processEvents();
        timeSinceLastUpdate += clock.restart();
        while (timeSinceLastUpdate > TimePerFrame) {
            timeSinceLastUpdate -= TimePerFrame;
            processEvents();
            update(TimePerFrame);
        }
        render();
    }
}

void Game::processEvents() {
    sf::Event event;
    while (mWindow.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            mWindow.close();
        } else if (event.type == sf::Event::KeyPressed) {
            handlePlayerInput(event.key.code, true);
        }
    }
}

void Game::update(sf::Time deltaTime) {
    mBird.update();
    for (auto &hurdle : mHurdles) {
        hurdle.update();
    }

    if (mHurdles.back().isOffScreen()) {
        mHurdles.push_back(Hurdle(800, rand() % 400 + 100));
        mHurdles.erase(mHurdles.begin());
        mScore++;
    }

    for (auto &hurdle : mHurdles) {
        if (mBird.getBounds().intersects(hurdle.getBounds())) {
            std::cout << "Collision detected! Score: " << mScore << std::endl;
            std::cout << "Do you want to play again? (Y/N)" << std::endl;
            char ch;
            std::cin >> ch;
            if (ch == 'N' || ch == 'n') {
                mWindow.close();
            } else {
                mBird = Bird(); // Reiniciar la posición del pájaro
                mHurdles.clear(); // Limpiar los obstáculos
                mHurdles.push_back(Hurdle(800, rand() % 400 + 100)); // Agregar nuevo obstáculo inicial
                mScore = 0; // Reiniciar el puntaje
            }
        }
    }
}

void Game::render() {
    mWindow.clear();
    mWindow.draw(mBackgroundSprite);
    mBird.render(mWindow);
    for (auto &hurdle : mHurdles) {
        hurdle.render(mWindow);
    }
    mWindow.display();
}

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed) {
    if (key == sf::Keyboard::Space && isPressed) {
        mBird.jump();
    }
}