//
//  BLinearMotion.cpp
//  ParticleBattle2
//
//  Created by 程 思源 on 13-11-18.
//
//

#include "BLinearMotion.h"
using namespace cocos2d;


bool BLinearMotion::init()
{
    
    if ( !Entity::init() ) {
        return false;
    }
    
    
    m_speed = 8;
    m_coolDown = 0.005f;
    scheduleUpdate();
    
    return true;
}



void BLinearMotion::update(float dt)
{
    Entity::update(dt);
    
    if (m_isCoolDown)
    {
            getParent()->setPosition( moveForward(getParent()->getRotation()
                                                  ,m_speed
                                                  ,getParent()->getPosition()) );
    }

}