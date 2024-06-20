#pragma once

#include <SFML/Graphics.hpp>

class Hurdle {
public:
    Hurdle(float x, float gapY);
    void update();
    void render(sf::RenderWindow& window);
    bool isOffScreen();
    sf::FloatRect getBounds();

private:
    sf::Sprite mSprite;
    sf::Texture mTexture;
    float mGapY;
};