//
//  FollowingMovement.h
//  ParticleBattle2
//
//  Created by 程 思源 on 13-11-19.
//
//

#ifndef __ParticleBattle2__FollowingMovement__
#define __ParticleBattle2__FollowingMovement__

#include <iostream>
#include "Objects\Entity\Entity.h"
#include "cocos2d.h"


class FollowingMovement : public Entity
{
public:
    
    CREATE_FUNC(FollowingMovement);
    
    virtual bool init();

private:
    typedef enum
    {
        State_chasing = 0,
        State_goingRandom = 5
    }State;
    
    State m_state;
    
    float m_speed;
    float m_omega;
    
    cocos2d::CCPoint m_targetPos;
    
    // 最小跟踪距离
   // float m_minFollowingDistance;
    float m_minContactDistance;//最小交火距离. 小于这个距离会开火然后开向一个随机点
    
    cocos2d::CCNode *m_pTarget;
    
    void update(float dt);
    cocos2d::CCPoint getARandomTargetPoint();

	inline void goTo();
};
#endif /* defined(__ParticleBattle2__FollowingMovement__) */

void FollowingMovement::goTo()
{
	cocos2d::CCPoint dir = ccpSub(m_targetPos, getParent()->getPosition());
    getParent()->setRotation(rotateToVec2WithOmega(dir, m_omega, getParent()->getRotation()));
    
    
   cocos2d::CCPoint newPos = moveForward(getParent()->getRotation(),
                                 m_speed,
                                 getParent()->getPosition());
    getParent()->setPosition(newPos);
}