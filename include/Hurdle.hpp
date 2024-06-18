#pragma once

#include <SFML/Graphics.hpp>

class Hurdle {
public:
    Hurdle(float x, float gapY);
    void update();
    void render(sf::RenderWindow& window) const;
    bool isOffScreen() const;
    sf::FloatRect getBounds() const;

private:
    sf::Sprite mSprite;
    sf::Texture mTexture;
    float mGapY;
};