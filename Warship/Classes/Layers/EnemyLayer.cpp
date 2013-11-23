//
//  EnemyLayer.cpp
//  ParticleBattle2
//
//  Created by 程 思源 on 13-11-18.
//
//

#include "EnemyLayer.h"
#include "Objects\Enemies\Enemy.h"

using namespace cocos2d;



bool EnemyLayer::init()
{
    
    if ( !CCLayer::init() ) {
        return false;
    }
    Enemy* ET = Enemy::create();
    ET->setPosition(300,300);
    ET->setRotation(CCRANDOM_0_1() * 360);
    addChild(ET);
    


    scheduleUpdate();
    counter = 0;
    
    return true;
}

void EnemyLayer::update(float dt)
{
    counter += dt;
    if (counter >= 3.0f) {
        counter = 0;
        
        Enemy* ET = Enemy::create();
        
        addChild(ET);
        
        ET->setPosition(ccp(CCRANDOM_0_1() * SCRWIDTH * 2,CCRANDOM_0_1() * SCRHEIGHT * 2));
        ET->setRotation(CCRANDOM_0_1() * 360);
    }
}