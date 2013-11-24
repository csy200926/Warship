#pragma once

#include <iostream>
#include"cocos2d.h"
#include "Objects\Entity\Entity.h"
#include "Layers\GamingLayer.h"
#include "Objects\Enemies\Enemy.h"

class ModuleAbstract : public Entity
{
public:
    
    CREATE_FUNC(ModuleAbstract);
    
    virtual bool init();
protected:
	// rotating speed
    float m_omega;
    unsigned int m_fireRange;
	float m_fireRate;
	bool m_isReadyToFire;

	Entity *m_pTarget;

    virtual void update(float dt);
	virtual void selectTarget();
	virtual void fire();//�Ժ����д�ɴ��벻ͬ�����Զ����ù���ģʽ��Ȼ��Ͳ���virtual��

	//������ò���virtual  �Ժ��ȥ��д���𣿣�
	void rotateToTarget();

	// Inline Functions
	inline cocos2d::CCPoint getWorldPosition();
	inline float getWorldRotation();
	inline void setWorldRotation( const float i_worldRotation );

private:
	float m_fireRateCounter;
	void fireRateCoolDown(float dt);
};


//------------------inline-------------------------
cocos2d::CCPoint ModuleAbstract::getWorldPosition()
{
	cocos2d::CCPoint worldPosition = getParent()->convertToWorldSpace(getPosition());
	worldPosition = GamingLayer::getGamingLayer()->getBulletLayer()->convertToNodeSpace(worldPosition);
	return worldPosition;
}
float ModuleAbstract::getWorldRotation()
{
    float newAngle =  360 +( getRotation() + getParent()->getRotation());
    return newAngle;
}
void ModuleAbstract::setWorldRotation( const float i_worldRotation )
{
    setRotation( i_worldRotation - 360 - getParent()->getRotation() );
}