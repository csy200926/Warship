//
//  PhysicObject.cpp
//  box2d
//
//  Created by 程 思源 on 13-10-18.
//
//

#include "PhysicObject.h"
#include "GB2ShapeCache-x.h"
#include "Box2D.h"

#define PTM_RATIO 16
using namespace cocos2d;

PhysicObject* PhysicObject::create(std::string pszFileName,cocos2d::CCPoint p,b2World *world)
{
    CCSprite *pobSprite = CCSprite::create((pszFileName+".png").c_str());

    pobSprite->setPosition(p);
    
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    
    bodyDef.position.Set(p.x/PTM_RATIO, p.y/PTM_RATIO);
    bodyDef.userData = pobSprite;
    
    PhysicObject *body = world->CreateBody(&bodyDef);
    
    // add the fixture definitions to the body
    
    GB2ShapeCache *sc = GB2ShapeCache::sharedGB2ShapeCache();
    sc->addFixturesToBody(body, pszFileName);
    pobSprite->setAnchorPoint(sc->anchorPointForShape(pszFileName));
    

    
    return body;
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
    
    this->setPosition(p);
    
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    
    bodyDef.position.Set(p.x/PTM_RATIO, p.y/PTM_RATIO);
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
