//
//  Weapon.h
//  box2d
//
//  Created by 程 思源 on 13-10-18.
//
//

#ifndef __box2d__Weapon__
#define __box2d__Weapon__

#include <iostream>
#include "cocos2d.h"

class Weapon :public cocos2d::CCSprite
{
public:
    static Weapon* create(const char *pszFileName);    
    bool initWithFile(const char *pszFilename);
    
    virtual void update(float delta);
    virtual void weaponSpecialize();// 用于继承 初始化
private:
    float counter;
};



#endif /* defined(__box2d__Weapon__) */
