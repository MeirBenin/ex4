
#include "CollisionHandling.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include "StaticBrick.hpp"
#include "TopBrick.hpp"
#include "DynamicObjects.hpp"
#include "GameKey.hpp"
#include "Coin.hpp"
#include "LifeGift.hpp"
#include "SpeedGift.hpp"
#include "GameKey.hpp"
#include "EndPortal.hpp"
#include "Thorn.hpp"
#include "MovingObjects.hpp"
#include <iostream>

HitMap& CollisionHandling::getMap(){
    
    static HitMap phm;
    phm[Key(typeid(Player      ), typeid(EndPortal   ))] = &playerEndPortal;
    phm[Key(typeid(EndPortal   ), typeid(Player      ))] = &endPortalPlayer;
    phm[Key(typeid(Player      ), typeid(Thorn       ))] = &mObjectsThorn;
    phm[Key(typeid(Thorn       ), typeid(Enemy       ))] = &ThornMObjects;
    phm[Key(typeid(Enemy       ), typeid(Thorn       ))] = &mObjectsThorn;
    phm[Key(typeid(Thorn       ), typeid(Enemy       ))] = &ThornMObjects;
    phm[Key(typeid(Player      ), typeid(Enemy       ))] = &playerEnemy;
    phm[Key(typeid(StaticBrick ), typeid(Player      ))] = &sBrickMObjects;
    phm[Key(typeid(TopBrick    ), typeid(Player      ))] = &topBrickMObjects;
    phm[Key(typeid(TopBrick    ), typeid(Enemy       ))] = &topBrickMObjects;
    phm[Key(typeid(StaticBrick ), typeid(Enemy       ))] = &sBrickEnemy;
    phm[Key(typeid(Enemy       ), typeid(Player      ))] = &enemyPlayer;
    phm[Key(typeid(Player      ), typeid(StaticBrick ))] = &mObjectsSBrick;
    phm[Key(typeid(Player      ), typeid(TopBrick    ))] = &mObjectsTopBrick;
    phm[Key(typeid(Enemy       ), typeid(TopBrick    ))] = &mObjectsTopBrick;
    phm[Key(typeid(Enemy       ), typeid(StaticBrick ))] = &enemySBrick;
    phm[Key(typeid(Player      ), typeid(Coin        ))] = &playerCoin;
    phm[Key(typeid(Player      ), typeid(GameKey     ))] = &playerKey;
    phm[Key(typeid(Player      ), typeid(LifeGift    ))] = &playerLife;
    phm[Key(typeid(Player      ), typeid(SpeedGift   ))] = &playerSpeed;
    phm[Key(typeid(Coin        ), typeid(Player      ))] = &coinPlayer;
    phm[Key(typeid(GameKey     ), typeid(Player      ))] = &keyPlayer;
    phm[Key(typeid(LifeGift    ), typeid(Player      ))] = &lifePlayer;
    phm[Key(typeid(SpeedGift   ), typeid(Player      ))] = &speedPlayer;
    
    return phm;
}

//--------------------------------------------------
HitFunctionPtr CollisionHandling::lookup(const std::type_index& class1,
                                         const std::type_index& class2){
    auto mapEntry = getMap().find(std::make_pair(class1, class2));
    if (mapEntry == getMap().end())
        return nullptr;
    return mapEntry->second;
}

//--------------------------------------------------
void CollisionHandling::processCollision(unique_ptr<GameObject>& object1,
                                         unique_ptr<GameObject>& object2){
    auto class1 = object1.get(), class2 = object2.get();
    auto phf = lookup(typeid(*class1), typeid(*class2));
    if(phf != nullptr)
    phf(object1, object2);
}
//--------------------------------------------------
bool CollisionHandling::isCollide(unique_ptr<GameObject>& object1,
                                  unique_ptr<GameObject>& object2){
    
    return object1->getGlobalBounds().intersects(object2->getGlobalBounds());
    
}

//===========================================================================
//===========================================================================
//===========================================================================
//===========================================================================
//===========================================================================
//===========================================================================
//===========================================================================
//===========================================================================


void CollisionHandling::sBrickEnemy(unique_ptr<GameObject>& object1,
                                    unique_ptr<GameObject>& object2){
    if(leftCollision(object1, object2)||rightCollision(object1, object2))
    ((BaseEnemy*)object2.get())->reDirction();
    sBrickMObjects(object1, object2);
}

void CollisionHandling::enemySBrick(unique_ptr<GameObject>& object1,
                                    unique_ptr<GameObject>& object2){
    sBrickEnemy(object2, object1);
}


void CollisionHandling::enemyPlayer(unique_ptr<GameObject>& object1,
                                    unique_ptr<GameObject>& object2){
    playerEnemy(object2, object1);
}

void CollisionHandling::mObjectsSBrick(unique_ptr<GameObject>& object1,
                                     unique_ptr<GameObject>& object2){
    sBrickMObjects(object2, object1);
}
 
void CollisionHandling::mObjectsTopBrick(unique_ptr<GameObject>& object1,
                                     unique_ptr<GameObject>& object2){
    topBrickMObjects(object2, object1);
}

    
void CollisionHandling::playerEnemy(unique_ptr<GameObject>& object1,
                                    unique_ptr<GameObject>& object2){
    ((Player*)object1.get())->deth();
}

void CollisionHandling::keyPlayer(unique_ptr<GameObject>& gift,unique_ptr<GameObject>& player){
    playerKey(player,gift);
}

void CollisionHandling::coinPlayer(unique_ptr<GameObject>& gift,unique_ptr<GameObject>& player){
    playerCoin(player,gift);
}

void CollisionHandling::speedPlayer(unique_ptr<GameObject>& gift,unique_ptr<GameObject>& player){
    playerSpeed(player,gift);
}

void CollisionHandling::lifePlayer(unique_ptr<GameObject>& gift,unique_ptr<GameObject>& player){
    playerLife(player,gift);
}
void CollisionHandling::playerEndPortal(unique_ptr<GameObject>& player  ,unique_ptr<GameObject>& portal){
    endPortalPlayer(portal,player);
}
void CollisionHandling::mObjectsThorn(unique_ptr<GameObject>& object, unique_ptr<GameObject>& thorn){
    ThornMObjects(thorn,object);
}
//===================================================================================




void CollisionHandling::endPortalPlayer(unique_ptr<GameObject>& endPortal,
                                        unique_ptr<GameObject>& player){
    ((Player*)player.get())->done();
}

void CollisionHandling::ThornMObjects(unique_ptr<GameObject>& thorn,
                                      unique_ptr<GameObject>& object){
    auto topOverlap = topCollision(thorn, object);
    if (topOverlap) {
        ((MovingObjects*)object.get())->deth();
        return;
    }
}

void CollisionHandling::topBrickMObjects(unique_ptr<GameObject>& object1,
                                     unique_ptr<GameObject>& object2){
    
    auto topOverlap = topCollision(object1, object2);
    if (topOverlap) {
        ((MovingObjects*)object2.get())->fixMove(0,topOverlap);
        ((MovingObjects*)object2.get())->onTheGraund();
        return;
    }
}



void CollisionHandling::sBrickMObjects(unique_ptr<GameObject>& object1,
                                     unique_ptr<GameObject>& object2){
    
    auto topOverlap = topCollision(object1, object2);
    if (topOverlap) {
        ((MovingObjects*)object2.get())->fixMove(0,topOverlap);
        ((MovingObjects*)object2.get())->onTheGraund();
        return;
    }
    auto bottomOverlap = bottomCollision(object1, object2);
    if (bottomOverlap) {
        ((MovingObjects*)object2.get())->fixMove(0,bottomOverlap);
        return;
    }
    auto leftOverlap = leftCollision(object1, object2);
    if (leftOverlap) {
        ((MovingObjects*)object2.get())->fixMove(leftOverlap,0);
        return;
    }
    auto rightOverlap = rightCollision(object1, object2);
    if (rightOverlap) {
        ((MovingObjects*)object2.get())->fixMove(rightOverlap,0);
        return;
    }
}


int CollisionHandling::topCollision(unique_ptr<GameObject>& brike,
                                    unique_ptr<GameObject>& object){
    
    auto objectLoc = object->getGlobalBounds();
    auto brikeLoc = brike->getGlobalBounds();
    auto objectLastLoc = ((MovingObjects*)object.get())->getLastLegalLoc();
    
    
    
    
    if ((brikeLoc.contains(objectLoc.left, objectLoc.top + objectLoc.height-1)||
         brikeLoc.contains(objectLoc.left + objectLoc.width-1,
                           objectLoc.top + objectLoc.height-1))&&
        brikeLoc.top > objectLastLoc.top + objectLastLoc.height-1)
        return (brikeLoc.top - (objectLoc.top + objectLoc.height-1)) - 1;
    // bottom of object
    return 0;
}

int CollisionHandling::bottomCollision(unique_ptr<GameObject>& brike,
                                       unique_ptr<GameObject>& object){
    auto objectLoc = object->getGlobalBounds();
    auto brikeLoc = brike->getGlobalBounds();
    auto objectLastLoc = ((MovingObjects*)object.get())->getLastLegalLoc();
    
    
    if ((brikeLoc.contains(objectLoc.left, objectLoc.top)||
         brikeLoc.contains(objectLoc.left + objectLoc.width-1,
                           objectLoc.top))&&
        brikeLoc.top + brikeLoc.height-1 < objectLastLoc.top)
        return ((brikeLoc.top + brikeLoc.height-1) - objectLoc.top ) + 1;
    // top of object
    return 0;
}

int CollisionHandling::leftCollision(unique_ptr<GameObject>& brike,
                                     unique_ptr<GameObject>& object){
    
    auto objectLoc = object->getGlobalBounds();
    auto brikeLoc = brike->getGlobalBounds();
    auto objectLastLoc = ((MovingObjects*)object.get())->getLastLegalLoc();
    
    
    if ((brikeLoc.contains(objectLoc.left, objectLoc.top)||
         brikeLoc.contains(objectLoc.left, objectLoc.top + objectLoc.height-1))&&
        brikeLoc.left + brikeLoc.width-1 < objectLastLoc.left)
        
        return ((brikeLoc.left + brikeLoc.width-1) - objectLoc.left) + 1;
    // left of object
    return 0;
}

int CollisionHandling::rightCollision(unique_ptr<GameObject>& brike,
                                      unique_ptr<GameObject>& object){
    
    auto objectLoc = object->getGlobalBounds();
    auto brikeLoc = brike->getGlobalBounds();
    auto objectLastLoc = ((MovingObjects*)object.get())->getLastLegalLoc();
    
    
    if ((brikeLoc.contains(objectLoc.left + objectLoc.width-1, objectLoc.top)||
         brikeLoc.contains(objectLoc.left + objectLoc.width-1,
                           objectLoc.top + objectLoc.height-1))&&
        brikeLoc.left > objectLastLoc.left + objectLastLoc.width-1)
        return brikeLoc.left -(objectLoc.left + objectLoc.width-1) - 1;
    // right of object
    return 0;
    
}

void CollisionHandling::playerKey(unique_ptr<GameObject>& player,unique_ptr<GameObject>& gift){
    ((Player*)player.get())-> addKey();
    ((DynamicObjects*)gift.get())-> notAvailable();
}
void CollisionHandling::playerCoin(unique_ptr<GameObject>& player,unique_ptr<GameObject>& gift){
    ((Player*)player.get())-> addCoin();
    ((DynamicObjects*)gift.get())-> notAvailable();
}
void CollisionHandling::playerSpeed(unique_ptr<GameObject>& player,unique_ptr<GameObject>& gift){
    ((Player*)player.get())-> addSpeed();
    ((DynamicObjects*)gift.get())-> notAvailable();
}
void CollisionHandling::playerLife(unique_ptr<GameObject>& player,unique_ptr<GameObject>& gift){
     ((Player*)player.get())-> addLife();
    ((DynamicObjects*)gift.get())-> notAvailable();
}

