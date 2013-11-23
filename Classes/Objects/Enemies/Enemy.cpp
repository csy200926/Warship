//
//  Enemy.cpp
//  ParticleBattle2
//
//  Created by 程 思源 on 13-11-18.
//
//

#include "Enemy.h"
#include "Components\EnemyMovementComponents\FollowingMovement.h"

using namespace cocos2d;
bool Enemy::init()
{
    
    if ( !Entity::init() ) {
        return false;
    }
    
    FollowingMovement *pFollowingMovement = FollowingMovement::create();
    
    m_pSprite = CCSprite::create("LittleFlight.png");
    addChild(m_pSprite);
    addChild(pFollowingMovement);
    
	m_isDead = false;

    m_life = 5;
    m_coolDown = 3;
    //scheduleUpdate();
    
    return true;
}
void Enemy::takeDamages(const unsigned int i_damge)
{

    m_life -= i_damge;
    
    if (m_life <= 0 ) 
        getsKilled();
}

