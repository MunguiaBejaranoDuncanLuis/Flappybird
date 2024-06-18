#pragma once

#include <SFML/Graphics.hpp>

class Bird {
public:
    Bird();
    void update();
    void render(sf::RenderWindow& window);
    void jump();
    sf::FloatRect getBounds();

private:
    sf::Sprite mSprite;
    sf::Texture mTexture;
    float mVelocity;
};