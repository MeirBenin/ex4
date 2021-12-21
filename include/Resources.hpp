#pragma once

#include <SFML/Graphics.hpp>
#include <string>



class Resources
{
public:
    static Resources& instance();
    sf::Texture& getTexture(std::string);
private:
    Resources();
    Resources(const Resources&) = delete;
    Resources& operator=(const Resources&) = delete;
    std::map<std::string,sf::Texture> m_textureMap;
};
