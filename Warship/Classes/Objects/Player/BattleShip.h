//
//  BattleShip.h
//  HelloCpp
//
//  Created by 程 思源 on 13-11-17.
//
//

#ifndef __HelloCpp__BattleShip__
#define __HelloCpp__BattleShip__

#include <iostream>
#include "cocos2d.h"
#include "Objects\Entity\Entity.h"

class BattleShip : public Entity
{
    
    cocos2d::CCSprite *m_pBody;
    
    float m_maxSpeed;
    float m_acceleration;
    float m_deceleration;
    
    float m_speed;
    float m_omega; // Angular speed

public:
    
    CREATE_FUNC(BattleShip);
    virtual bool init();
    
    //void rotateToVec2( cocos2d::CCPoint );
    
    void update(float dt);
    

    inline void reduceLinerSpeed();
    inline void addLinerSpeed();
    inline void rotateToDir( cocos2d::CCPoint i_dir );
};
#include "BattleShip.inl"


#endif /* defined(__HelloCpp__BattleShip__) */
