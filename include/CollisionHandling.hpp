#pragma once
#include "GameObject.hpp"
#include <iostream>
#include <typeinfo>
#include <map>
#include <string>
#include <typeindex>

using std::unique_ptr;
using HitFunctionPtr = void (*)(unique_ptr<GameObject>&,unique_ptr<GameObject>&);
using Key = std::pair<std::type_index, std::type_index>;
using HitMap = std::map<Key, HitFunctionPtr>;


class CollisionHandling {
public:
    HitMap& getMap();
    bool isCollide(unique_ptr<GameObject>&,unique_ptr<GameObject>&);
    void processCollision(unique_ptr<GameObject>&,unique_ptr<GameObject>&);
private:
    HitFunctionPtr lookup(const std::type_index& ,const std::type_index&);
    
    static void enemyPlayer(unique_ptr<GameObject>&,unique_ptr<GameObject>&);
    static void mObjectsSBrick(unique_ptr<GameObject>&,unique_ptr<GameObject>&);
    static void sBrickMObjects(unique_ptr<GameObject>&,unique_ptr<GameObject>&);
    static void mObjectsTopBrick(unique_ptr<GameObject>&,unique_ptr<GameObject>&);
    static void topBrickMObjects(unique_ptr<GameObject>&,unique_ptr<GameObject>&);
    static void playerEnemy(unique_ptr<GameObject>&,unique_ptr<GameObject>&);
    static void playerKey(unique_ptr<GameObject>&,unique_ptr<GameObject>&);
    static void playerCoin(unique_ptr<GameObject>&,unique_ptr<GameObject>&);
    static void playerSpeed(unique_ptr<GameObject>&,unique_ptr<GameObject>&);
    static void playerLife(unique_ptr<GameObject>&,unique_ptr<GameObject>&);
    static int topCollision(unique_ptr<GameObject>&,unique_ptr<GameObject>&);
    static int bottomCollision(unique_ptr<GameObject>&,unique_ptr<GameObject>&);
    static int leftCollision(unique_ptr<GameObject>&,unique_ptr<GameObject>&);
    static int rightCollision(unique_ptr<GameObject>&,unique_ptr<GameObject>&);
    static void sBrickEnemy(unique_ptr<GameObject>&,unique_ptr<GameObject>&);
    static void enemySBrick(unique_ptr<GameObject>&,unique_ptr<GameObject>&);
    static void keyPlayer(unique_ptr<GameObject>&,unique_ptr<GameObject>&);
    static void coinPlayer(unique_ptr<GameObject>&,unique_ptr<GameObject>&);
    static void speedPlayer(unique_ptr<GameObject>&,unique_ptr<GameObject>&);
    static void lifePlayer(unique_ptr<GameObject>&,unique_ptr<GameObject>&);
    static void playerEndPortal(unique_ptr<GameObject>&,unique_ptr<GameObject>&);
    static void endPortalPlayer(unique_ptr<GameObject>&,unique_ptr<GameObject>&);
    static void mObjectsThorn(unique_ptr<GameObject>&,unique_ptr<GameObject>&);
    static void ThornMObjects(unique_ptr<GameObject>&,unique_ptr<GameObject>&);

};

