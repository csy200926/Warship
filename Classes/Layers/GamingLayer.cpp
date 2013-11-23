//
//  GamingLayer.cpp
//  HelloCpp
//
//  Created by 程 思源 on 13-11-17.
//
//

#include "GamingLayer.h"
#include "Objects\Enemies\Enemy.h"
#include "GlobalFunc.h"
#include "Objects\Bullets\Bullet.h"
using namespace cocos2d;

static GamingLayer* pGamingLayer = NULL;

GamingLayer* GamingLayer::getGamingLayer()
{
    if ( pGamingLayer ) {
        return pGamingLayer;
    }
    
    return NULL;
}



bool GamingLayer::init()
{
    
    if ( !CCLayer::init() ) {
        return false;
    }
    
    pGamingLayer = this;

    pTest = BattleShip::create();
    pTest->setPosition(ccp(100,100));

    addChild(pTest,1);
    
    counter = 0;
    scheduleUpdate();
    running = false;
    
    
    return true;
}

#define FREQUENCE_OF_COLLISION_DECTECTION 0.01

void GamingLayer::update(float dt)
{
    if (running == false) {
        return;
    }
    
    counter += dt;
    
    if (counter >= FREQUENCE_OF_COLLISION_DECTECTION) {
        counter = 0;
        
        CCObject *pET;
        CCObject *pB;
        CCARRAY_FOREACH(m_pEnemyLayer->getChildren(),pET )
        {
            Enemy* pEnemy = dynamic_cast<Enemy *>(pET);
            collisionRect enemyRect = pEnemy->getCollisionRect();
            
            if (pEnemy -> isVisible() == false)
                continue;
            
            CCARRAY_FOREACH(m_pBulletLayer->getChildren(), pB)
            {
                
				Entity *pBullet = dynamic_cast<Entity*>(pB);
                collisionRect bulletRect = pBullet->getCollisionRect();
                
                if (pBullet -> isVisible() == false)
                    continue;
                
                if (bulletRect.collisionDetection(enemyRect)) {
                    pEnemy->takeDamages(1);
                    pBullet->getsKilled();
                    GamingLayer::getGamingLayer()->getParticleLayer()->CreateParticle(pBullet->getPosition(),LayerParticle::green);
                    
                }
                
            }
        }
    }

    
}