//
//  MachineGun.h
//  ParticleBattle2
//
//  Created by 程 思源 on 13-11-18.
//
//

#ifndef __ParticleBattle2__MachineGun__
#define __ParticleBattle2__MachineGun__

#include <iostream>
#include"cocos2d.h"
#include "Objects\Entity\Entity.h"
#include "Layers\GamingLayer.h"
#include "Objects\Enemies\Enemy.h"
class MachineGun : public Entity
{
public:
    
    CREATE_FUNC(MachineGun);
    
    virtual bool init();

    void Shoot(const float angle);
private:
	// rotating speed
    float m_omega;

    void update(float dt);

	// self and taret
    cocos2d::CCSprite *m_pSprite;
	cocos2d::CCPoint m_dir;

	void selectTarget();

    unsigned int m_fireRange;

	inline cocos2d::CCPoint getWorldPosition();
	inline float getWorldRotation();
	inline void setWorldRotation( const float i_worldRotation );
};

cocos2d::CCPoint MachineGun::getWorldPosition()
{
	cocos2d::CCPoint worldPosition = getParent()->convertToWorldSpace(getPosition());
	worldPosition = GamingLayer::getGamingLayer()->getBulletLayer()->convertToNodeSpace(worldPosition);
	return worldPosition;
}
float MachineGun::getWorldRotation()
{
    float newAngle =  360 +( getRotation() + getParent()->getRotation());
    return newAngle;
}
void MachineGun::setWorldRotation( const float i_worldRotation )
{
    setRotation( i_worldRotation - 360 - getParent()->getRotation() );
}
#endif /* defined(__ParticleBattle2__MachineGun__) */
