//
//  PhysicsSprite.cpp
//  box2d
//
//  Created by 程 思源 on 13-10-17.
//
//

#include "PhysicsSprite.h"
#include "GB2ShapeCache-x.h"
#include "Box2D.h"

#define PTM_RATIO 16
using namespace cocos2d;

PhysicsSprite* PhysicsSprite::create(std::string pszFileName,cocos2d::CCPoint p,b2World *world)
{
    PhysicsSprite *pobSprite = new PhysicsSprite();
    if (pobSprite && pobSprite->initWithFile(pszFileName , p, world))//基类的initwithfile被隐藏了
    {
        
        pobSprite->autorelease();
        return pobSprite;
    }
    
    CC_SAFE_DELETE(pobSprite);
    return NULL;
}


void PhysicsSprite::setBody(b2Body *body)
{
    _body = body;
}

b2Body* PhysicsSprite::getBody()
{
    CCAssert(_body, "body empty!!");
    
    return _body;
}

bool PhysicsSprite::initWithFile(std::string pszFilename,cocos2d::CCPoint p,b2World *world)
{
    if ( !CCSprite::initWithFile((pszFilename+".png").c_str()) )
    {
        return false;
    }
    
    //this->setPosition(p);
    
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    
    bodyDef.position.Set(p.x, p.y);
    bodyDef.userData = this;
    
    b2Body *body = world->CreateBody(&bodyDef);
    
    // add the fixture definitions to the body
    
    GB2ShapeCache *sc = GB2ShapeCache::sharedGB2ShapeCache();
    sc->addFixturesToBody(body, pszFilename);
    this->setAnchorPoint(sc->anchorPointForShape(pszFilename));
    
    
    this->setBody(body);
    
    this->inheritInit();
    //scheduleUpdate();
    return true;
}

void PhysicsSprite::inheritInit()
{
    //CCLog("I am base!");
}

void PhysicsSprite::setActive(bool flag)
{
    if (flag) {
        this->setVisible(true);
        _body->SetActive(true);
    }else
    {
        this->setVisible(false);
        _body->SetActive(false);
    }

}

// Avoid collision.    index must be a positive number
void PhysicsSprite::setCollisionGroup(int index)
{
    for (b2Fixture* f = _body->GetFixtureList(); f; f = f->GetNext())
    {
        b2Filter filter;
        filter.groupIndex = index;
        //do something with the fixture 'f'
        f->SetFilterData(filter);
    }

}
