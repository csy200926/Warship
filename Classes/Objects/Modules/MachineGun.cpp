//
//  MachineGun.cpp
//  ParticleBattle2
//
//  Created by 程 思源 on 13-11-18.
//
//

#include "MachineGun.h"
#include "Objects\Bullets\Bullet.h"
#include "Layers\BulletLayer.h"

using namespace cocos2d;
bool MachineGun::init()
{

	if ( !ModuleAbstract::init() ) {
        return false;
    }
    
    m_pSprite = CCSprite::create("CloseNormal.png");
    addChild(m_pSprite);
	
	m_pTarget = NULL;

	// Weapon Properties
    m_omega = 5;
    m_coolDown = 0.01;
    m_fireRange = 500;
	m_fireRate = 0.1;

	m_diffuseRate = 10.0;

	// Updaters
	m_isReadyToFire = false;
	m_isCoolDown = false;

    scheduleUpdate();
    
    return true;
}

void MachineGun::update(float dt)
{
	ModuleAbstract::update(dt);

	if (m_isCoolDown)
	{
		if (m_pTarget == NULL)
		{
			selectTarget();
		}
		if (m_pTarget)
		{
			if (m_pTarget->isDead() == false && ccpDistance( m_pTarget->getPosition(),getWorldPosition()) < m_fireRange)
			{

				rotateToTarget();
				// Shoot to target
				fire();
			}else
				m_pTarget = NULL;
		}
	}
}


void MachineGun::fire()
{

	float angle = (360 +( getRotation() + getParent()->getRotation()))+ ( 2* m_diffuseRate * CCRANDOM_0_1() - m_diffuseRate); 

	if (m_isReadyToFire)
	{
		Bullet *pBullet = Bullet::create();
           
		CCPoint spawnPosition = getParent()->convertToWorldSpace(getPosition());
		spawnPosition = GamingLayer::getGamingLayer()->getBulletLayer()->convertToNodeSpace(spawnPosition);
		pBullet->setPosition( spawnPosition );
        
		pBullet->setRotation( angle );
		GamingLayer::getGamingLayer()->getBulletLayer()->addChild(pBullet);
	}
}

