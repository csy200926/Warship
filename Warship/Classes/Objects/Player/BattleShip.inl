//
//  BattleShip.inl.c
//  HelloCpp
//
//  Created by 程 思源 on 13-11-18.
//
//
#ifndef __BattleShipH__
#define __BattleShipH__

#include "BattleShip.h"


void BattleShip::addLinerSpeed( )
{
    if ( m_speed >= m_maxSpeed ) {
        return;
    }
    m_speed += m_acceleration;
}

void BattleShip::reduceLinerSpeed( )
{
    if ( m_speed <= 0 ) {
        m_speed = 0;
        return;
    }
    m_speed -= m_deceleration;
}
void BattleShip::rotateToDir( cocos2d::CCPoint i_dir )
{
    // Navigate the ship to pointed direction
    float newAngle = rotateToVec2WithOmega(i_dir, m_omega, getRotation());
    setRotation( newAngle );
}
#endif