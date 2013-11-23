//
//  UILayer.h
//  HelloCpp
//
//  Created by 程 思源 on 13-11-17.
//
//

#ifndef __HelloCpp__UILayer__
#define __HelloCpp__UILayer__

#include <iostream>
#include "cocos2d.h"


class SneakyJoystick;


class UILayer : public cocos2d::CCLayer
{
public:
    
    CREATE_FUNC(UILayer);
    
    virtual bool init();
    
    void update(float dt);


private:
    SneakyJoystick *pJoyStick;
    
    float m_counter;
    
};
#endif /* defined(__HelloCpp__UILayer__) */
