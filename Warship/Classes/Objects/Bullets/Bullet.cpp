//
//  Bullet.cpp
//  ParticleBattle2
//
//  Created by 程 思源 on 13-11-18.
//
//

#include "Bullet.h"
#include "Components\BulletComponents\BLinearMotion.h"
#include "GlobalFunc.h"

using namespace cocos2d;
bool Bullet::init()
{
    
    if ( !Entity::init() ) {
        return false;
    }
    
	m_isDead = false;
    
    m_pSprite = CCSprite::create("PenetreBullet.png");
    addChild(m_pSprite);
    
    m_width = m_pSprite->getTexture()->getContentSize().width * 0.4f;
    m_height = m_pSprite->getTexture()->getContentSize().height * 0.4f;
    
    BLinearMotion *pBLinearMotion = BLinearMotion::create();
    pBLinearMotion->setSpeed(15);
    addChild(pBLinearMotion);
    
    m_coolDown = 3;
    scheduleUpdate();
    
    return true;
}

void Bullet::update(float dt)
{
    CCPoint p = getPosition();
    if ( p.x < -20 || p.x > SCRWIDTH * 2 + 20 )
    {
        removeFromParent();
    }
    if ( p.y < -20 || p.y > SCRHEIGHT * 2 + 20 )
    {
        removeFromParent();
    }

}

