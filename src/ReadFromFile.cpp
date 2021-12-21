
#include "ReadFromFile.hpp"


ReadFromFile::ReadFromFile(){
    m_file.open("stageMap.txt");
    if (!m_file.good())throw std::runtime_error("open file erorr");
}


void ReadFromFile::read(vector<unique_ptr<GameObject>>& dataStruct){
    
    auto size = sf::Vector2i();
    auto line = string();
    int object = 0;
    auto loc = sf::Vector2f(0,0);

    if(!std::getline(m_file, line))throw std::runtime_error("");
    
    auto lineStream = std::istringstream(line);
    lineStream.exceptions(std::ios::failbit | std::ios::badbit);

    lineStream >> size.x;
    lineStream >> size.y;

    for (int row = 0; row < size.x; row++) {

        if(!std::getline(m_file, line))
            throw std::runtime_error("read erorr in  line" + std::to_string(row));
        lineStream = std::istringstream(line);

        for (int col = 0; col < size.y; col++){
            lineStream >> object;
            loc = sf::Vector2f(col,row);
            newObject(dataStruct, object, loc);
        }
    }
}


void ReadFromFile::newObject(vector<unique_ptr<GameObject>>& dataStruct,
                             int index, sf::Vector2f loc){
    if(index >(int)ObjectIndex::Empty && index < (int)ObjectIndex::ObjectIndexSize){
        
        auto creatFunc = ObjectFactory::create(ObjectIndex((ObjectIndex)index));
        
        if((ObjectIndex)index == ObjectIndex::Player)
        dataStruct.insert(dataStruct.begin(),creatFunc(loc));
        else
        dataStruct.push_back(creatFunc(loc));
        
    }
}
