#include <Hurdle.hpp>

Hurdle::Hurdle(float x, float gapY)
: mGapY(gapY)
{
    if (!mTexture.loadFromFile("./images/pipe.png")) {
        throw std::runtime_error("Error loading pipe.png");
    }
    mSprite.setTexture(mTexture);
    mSprite.setPosition(x, gapY);
}

void Hurdle::update() {
    mSprite.move(-5, 0);
}

void Hurdle::render(sf::RenderWindow& window) {
    mSprite.setTexture(mTexture);
    window.draw(mSprite);
}

bool Hurdle::isOffScreen() {
    return mSprite.getPosition().x + mSprite.getGlobalBounds().width < 0;
}

sf::FloatRect Hurdle::getBounds() {
    return mSprite.getGlobalBounds();
}