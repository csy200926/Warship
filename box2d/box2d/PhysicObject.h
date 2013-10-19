//
//  PhysicObject.h
//  box2d
//
//  Created by 程 思源 on 13-10-18.
//
//

#ifndef __box2d__PhysicObject__
#define __box2d__PhysicObject__

#include <iostream>
#include "cocos2d.h"
#include "Box2D.h"

class  PhysicObject : public b2Body
{
    
public:
    
    b2Body* getBody();
    
    static PhysicObject* create(std::string pszFileName,cocos2d::CCPoint p,b2World *world);
    bool initWithFile(std::string pszFilename,cocos2d::CCPoint p,b2World *world);
    
    virtual void inheritInit();//子类可以重写这个方法 把基本初始化以外的才做放在这里
    
    void setActive(bool flag);
    //virtual void update(float delta);
protected:
    void setBody(b2Body *body);
    b2Body *_body;
};

#endif /* defined(__box2d__PhysicObject__) */
