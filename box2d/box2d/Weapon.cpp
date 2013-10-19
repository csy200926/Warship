//
//  Weapon.cpp
//  box2d
//
//  Created by 程 思源 on 13-10-18.
//
//

#include "Weapon.h"
#include "Bullet.h"
#include "HelloWorldScene.h"

Weapon* Weapon::create(const char *pszFileName)
{
    Weapon *pobSprite = new Weapon();
    if (pobSprite && pobSprite->initWithFile(pszFileName))
    {
        
        pobSprite->autorelease();
        return pobSprite;
    }
    
    CC_SAFE_DELETE(pobSprite);
    return NULL;
}

bool Weapon::initWithFile(const char *pszFilename)
{
    if ( !CCSprite::initWithFile(pszFilename) )
    {
        return false;
    }
    counter = 0.0f;
    this->weaponSpecialize();
    scheduleUpdate();
    return true;
}

void Weapon::weaponSpecialize()
{
    
}

void Weapon::update(float delta)
{
    
    counter += delta;
    if (counter >= 1.0f) {
        counter = 0.0f;
        
        b2World* world = HelloWorld::getWorld();

        Bullet *bullet = Bullet::create("missile", ccp(this->getParent()->getPosition().x / 32,this->getParent()->getPosition().y /32), world);
   
        HelloWorld::sharedWorld()->bgLayer->addChild(bullet);
        CCLOG("%f,%f",this->getParent()->getPosition().x,this->getParent()->getPosition().y);
   
        
        b2Body* body = bullet->getBody();
        bullet->setCollisionGroup(-10);
        b2Vec2 v;
        v.Set(10.0f, 10.0f);
        
        body->SetLinearVelocity(v);
    }
    
}
