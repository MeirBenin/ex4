#pragma once
#include "ObjectFactory.hpp"
#include "GameObject.hpp"
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <memory>
#include <stdexcept>

using std::vector;
using std::string;
using std::stringstream;
using std::ifstream;
using std::unique_ptr;
using std::make_unique;

class ReadFromFile {
public:
    ReadFromFile();
    void read(vector<unique_ptr<GameObject>>&);
private:
    void newObject(vector<unique_ptr<GameObject>>& ,int, sf::Vector2f);
    ifstream m_file;
};
