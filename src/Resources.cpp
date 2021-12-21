#include "Resources.hpp"
#include <stdexcept>


Resources& Resources::instance()
{
    static auto instance = Resources();
    return instance;
}

Resources::Resources(){
    m_textureMap = std::map<std::string,sf::Texture>();
}

sf::Texture& Resources::getTexture(std::string fileName){
    auto it = m_textureMap.find(fileName);
    if (it == m_textureMap.end()){
        m_textureMap.emplace(fileName,sf::Texture());
        it = m_textureMap.find(fileName);
        if(!it->second.loadFromFile(std::string(fileName)))
            throw std::runtime_error("");
    }
    return it ->second;
}

