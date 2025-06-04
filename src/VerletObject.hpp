#pragma once 
#include <SFML/Graphics.hpp>

class VerletObject{
    protected:
        sf::Vector2f current_position;
        sf::Vector2f new_position;
        sf::Vector2f acceleration;
    public:
        virtual ~VerletObject() = default;
        virtual void update_position(float dt){
            const sf::Vector2f old_position = current_position;
            const sf::Vector2f old_velocity = current_position - new_position;
            const sf::Vector2f new_velocity = old_velocity + (acceleration * dt);
            new_position = old_position + (old_velocity * dt) + (acceleration * dt * dt);
            acceleration = {};
        }
        void set_position(sf::Vector2f position){
            current_position = position;
        }
        sf::Vector2f get_position(){
            return current_position;
        }
        sf::Vector2f get_acceleration(){
            return acceleration;
        }
};