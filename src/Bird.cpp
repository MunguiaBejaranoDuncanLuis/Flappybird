#include "Bird.hpp"

Bird::Bird()
: mVelocity(0.0f)
{
    if (!mTexture.loadFromFile("./images/flappy_bird.png")) {
        throw std::runtime_error("Error loading flappy_bird.png");
    }
    mSprite.setTexture(mTexture);
    mSprite.setPosition(400, 300); // Posicion inicial en el centro de la pantalla
}

void Bird::update() {
    mVelocity += 0.5f; // Gravedad
    mSprite.move(0, mVelocity);

    if (mSprite.getPosition().y > 600 - mSprite.getGlobalBounds().height) {
        mSprite.setPosition(400, 600 - mSprite.getGlobalBounds().height); // Reposicionar en la parte inferior si toca el suelo
        mVelocity = 0;
    }
}

void Bird::render(sf::RenderWindow& window) {
    mSprite.setTexture(mTexture);
    window.draw(mSprite);
}

void Bird::jump() {
    mVelocity = -10.0f; // Impulso del salto
}

sf::FloatRect Bird::getBounds() {
    return mSprite.getGlobalBounds();
}