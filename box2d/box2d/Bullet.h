//
//  Bullet.h
//  box2d
//
//  Created by 程 思源 on 13-10-17.
//
//

#ifndef __box2d__Bullet__
#define __box2d__Bullet__

#include <iostream>
#include "PhysicsSprite.h"

class Bullet : public PhysicsSprite
{
    
    
public:
    static Bullet* create(std::string pszFileName,cocos2d::CCPoint p,b2World *world);//隐藏了父类的方法，只有加了域名才能调用父类的初始化方法。。大概是这样
    void inheritInit();
    void update(float delta);
};

#endif /* defined(__box2d__Bullet__) */
