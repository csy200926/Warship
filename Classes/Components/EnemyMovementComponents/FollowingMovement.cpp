//
//  FollowingMovement.cpp
//  ParticleBattle2
//
//  Created by 程 思源 on 13-11-19.
//
//

#include "FollowingMovement.h"
#include "Layers\GamingLayer.h"

using namespace cocos2d;


bool FollowingMovement::init()
{
    
    if ( !Entity::init() ) {
        return false;
    }
    m_pTarget = GamingLayer::getGamingLayer()->pTest;
    
    m_state = State_chasing;
    m_targetPos = m_pTarget->getPosition();
    
    
    // minimun distance that start chasing
   // m_minFollowingDistance = 1600;
    m_minContactDistance = 400;
    
    m_omega = 3.0f;
    m_speed = 10;
    m_coolDown = 0.01f;
    scheduleUpdate();
    
    return true;
}

cocos2d::CCPoint FollowingMovement::getARandomTargetPoint()
{
    
    float rotation = getParent()->getRotation();
    
    int offsetX = sin( CC_DEGREES_TO_RADIANS( rotation ) ) * m_speed;
    int offsetY = cos( CC_DEGREES_TO_RADIANS( rotation ) ) * m_speed;

    return ccp(-(offsetX * 10)  ,-(offsetY * 10)  );
}



void FollowingMovement::update(float dt)
{
    Entity::update(dt);
    
 
    
    if (m_isCoolDown)
    {

        if( ccpDistance(getParent()->getPosition(), m_targetPos) < 1600)
        {
            
            if (m_state == State_chasing)
            {
                m_targetPos = m_pTarget->getPosition();
                if (ccpDistance(getParent()->getPosition(), m_targetPos) < m_minContactDistance)
                {
                    m_state = State_goingRandom;
                    m_targetPos = getARandomTargetPoint();
                }
            }
            else if ( m_state == State_goingRandom )
            {
                if (ccpDistance(getParent()->getPosition(), m_targetPos) < m_minContactDistance)
                    m_state = State_chasing;
            }

        }
        
        
       goTo();
    }
}


