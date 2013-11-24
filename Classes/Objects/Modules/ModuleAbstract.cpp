#include "ModuleAbstract.h"


bool ModuleAbstract::init()
{
	if ( !Entity::init() ) {
        return false;
    }
	m_fireRateCounter = 0;
	m_isCoolDown = false;
	m_pTarget = NULL;
	return true;
}

void ModuleAbstract::selectTarget()
{
	// Auto aimming and firing at target
	CCObject *pE;
	Entity *pEnemy;
	CCPoint worldPosition = getWorldPosition();

	CCARRAY_FOREACH(GamingLayer::getGamingLayer()->getEnemyLayer()->getChildren(), pE)
	{
		pEnemy = dynamic_cast<Entity*>(pE);
			
		if (ccpDistance(pEnemy->getPosition(), worldPosition) <= m_fireRange )
		{
			if ( pEnemy->isDead() == false )
			{
				m_pTarget = pEnemy;
				break;
			}
		}
	}
	pEnemy = NULL;

}

void ModuleAbstract::update(float dt)
{
	Entity::update(dt);
	// weapon will not fire if this function didn't get updated
	fireRateCoolDown(dt);
}

void ModuleAbstract::fire()
{

}

void ModuleAbstract::rotateToTarget()
{
	if (m_pTarget)
	{
		CCPoint worldPosition = getWorldPosition();
		CCPoint dir = ccp(m_pTarget->getPosition().x - worldPosition.x ,
		m_pTarget->getPosition().y - worldPosition.y );

		// Rotate to target dir
		float angle = rotateToVec2WithOmega( dir , m_omega, getWorldRotation());
		setWorldRotation(angle);
	}
}


void ModuleAbstract::fireRateCoolDown(float dt)
{
	m_fireRateCounter += dt;
	if (m_fireRateCounter >= m_fireRate)
	{
		m_fireRateCounter = 0.0f;
		m_isReadyToFire = true;
	}else
		m_isReadyToFire = false;
}
