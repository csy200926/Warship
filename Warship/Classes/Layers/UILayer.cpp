//
//  UILayer.cpp
//  HelloCpp
//
//  Created by 程 思源 on 13-11-17.
//
//

#include "UILayer.h"
#include "SneakyInput/SneakyJoystick.h"
#include "SneakyInput/SneakyJoystickSkinnedBase.h"
#include "GamingLayer.h"
#include "GlobalFunc.h"

using namespace cocos2d;
bool UILayer::init()
{
    
    if ( !CCLayer::init() ) {
        return false;
    }
    m_counter = 0.0f;
    
    pJoyStick = new SneakyJoystick();
    pJoyStick->autorelease();
    pJoyStick->initWithRect(CCRectZero);
    pJoyStick->setAutoCenter(true);
    pJoyStick->setHasDeadzone(true);
    pJoyStick->setDeadRadius(10);
    
    SneakyJoystickSkinnedBase *pJoystickSkin = new SneakyJoystickSkinnedBase();
    pJoystickSkin->autorelease();
    pJoystickSkin->init();
    pJoystickSkin->setBackgroundSprite(CCSprite::create("button-default.png"));
    pJoystickSkin->setThumbSprite(CCSprite::create("button-disabled.png"));
    pJoystickSkin->getThumbSprite()->setScale(0.5f);
    pJoystickSkin->setPosition(ccp(50, 50));
    pJoystickSkin->setJoystick(pJoyStick);

    addChild(pJoystickSkin);
    pJoystickSkin->setPosition(ccp(100, 100));
    
    
    scheduleUpdate();
    
    return true;
}


void UILayer::update(float dt)
{
    CCPoint velocity = pJoyStick->getVelocity(); // range  0-1

    
    if (velocity.x != 0 || velocity.y != 0) {
        
        m_counter += dt;
        
        if ( m_counter >= 0.01 )
        {
            m_counter = 0;
            
            // Navigate the ship to pointed direction
            GamingLayer::getGamingLayer()->pTest->rotateToDir( velocity );
            GamingLayer::getGamingLayer()->pTest->addLinerSpeed();
            
        }
    
    }


}



