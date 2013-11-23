//
//  BattleShip.cpp
//  HelloCpp
//
//  Created by 程 思源 on 13-11-17.
//
//

#include "BattleShip.h"
#include "GlobalFunc.h"
#include "Layers/GamingLayer.h"
#include "Objects/Modules/MachineGun.h"
using namespace cocos2d;


bool BattleShip::init()
{
    
    if ( !Entity::init() )
    {
        return false;
    }
    
    m_pBody = CCSprite::create("money.png");
    addChild(m_pBody,1);
    
    
    m_omega         = 3;
    m_speed         = 0;
    m_maxSpeed      = 5;
    m_acceleration  = 2;
    m_deceleration  = 0.5;
    m_coolDown      = 0.01;
    
    


    
    
    // Modules offset
    const float offset = 20;
    
   /* MachineGun* pModule = MachineGun::create();
    pModule->setPosition(ccp(-offset, offset));
    addChild(pModule,2);
    MachineGun* pModule2 = MachineGun::create();
    pModule2->setPosition(ccp(offset, offset));
    addChild(pModule2,2);
   /* MachineGun* pModule3 = MachineGun::create();
    pModule3->setPosition(ccp(-offset, 0));
    addChild(pModule3,2);
    MachineGun* pModule4 = MachineGun::create();
    pModule4->setPosition(ccp(offset, 0));
    addChild(pModule4,2);*/
    MachineGun* pModule5 = MachineGun::create();
    pModule5->setPosition(ccp(-offset, -offset));
    addChild(pModule5,2);
    MachineGun* pModule6 = MachineGun::create();
    pModule6->setPosition(ccp(offset, -offset));
    addChild(pModule6,2);
   

    
    scheduleUpdate();
    

    return true;
}




void BattleShip::update(float dt)
{
    Entity::update(dt);
    
    if ( m_isCoolDown )
    {
        setPosition( moveForward(getRotation(), m_speed, getPosition()) );
        reduceLinerSpeed( );
    }
    
}

