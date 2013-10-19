//
//  PhysicsSprite.h
//  box2d
//
//  Created by 程 思源 on 13-10-17.
//
//


/*
* Exmaple:
* PhysicsSprite *sprite = PhysicsSprite::create(
* "missile",
* CCPointMake(screenSize.width/2, screenSize.height/2),
* world);
* sprite->setTag(1);
* playerBody = sprite->getBody();
* bgLayer->addChild(sprite);
*/


#ifndef __box2d__PhysicsSprite__
#define __box2d__PhysicsSprite__

#include <iostream>
#include "cocos2d.h"
class b2Body;
class b2World;

class  PhysicsSprite : public cocos2d::CCSprite
{
    
public:
    
    b2Body* getBody();
    
    static PhysicsSprite* create(std::string pszFileName,cocos2d::CCPoint p,b2World *world);
    bool initWithFile(std::string pszFilename,cocos2d::CCPoint p,b2World *world);
    
    virtual void inheritInit();//子类可以重写这个方法 把基本初始化以外的才做放在这里
    
    void setActive(bool flag);
    
    void setCollisionGroup(int index);
    //virtual void update(float delta);
protected:
    void setBody(b2Body *body);
    b2Body *_body;
};




#endif /* defined(__box2d__PhysicsSprite__) */
