//
//  Bullet.cpp
//  box2d
//
//  Created by 程 思源 on 13-10-17.
//
//

#include "Bullet.h"
#include "Box2D.h"
Bullet* Bullet::create(std::string pszFileName,cocos2d::CCPoint p,b2World *world)
{
    Bullet *pobSprite = new Bullet();
    if (pobSprite && pobSprite->initWithFile(pszFileName , p, world))
    {
        
        pobSprite->autorelease();
        return pobSprite;
    }
    
    CC_SAFE_DELETE(pobSprite);
    return NULL;
}

void Bullet::inheritInit()//这里还是隐藏？？
{
    //scheduleUpdate();

    //PhysicsSprite::test();
    //cocos2d::CCLog("I am derived!");
}

void Bullet::update(float delta)
{
    
    
}