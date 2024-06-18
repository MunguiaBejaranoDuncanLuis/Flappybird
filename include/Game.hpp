#pragma once

#include <SFML/Graphics.hpp>
#include "Bird.hpp"
#include "Hurdle.hpp"

class Game {
public:
    Game();
    void run();

private:
    void processEvents();
    void update(sf::Time deltaTime);
    void render();
    void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);

    sf::RenderWindow mWindow;
    sf::Texture mBackgroundTexture;
    sf::Sprite mBackgroundSprite;
    Bird mBird;
    std::vector<Hurdle> mHurdles;
    int mScore;

    const sf::Time TimePerFrame = sf::seconds(1.f / 60.f);
};