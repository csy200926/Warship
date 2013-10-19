//
//  HelloWorldScene.h
//  box2d
//
//  Created by 程 思源 on 13-10-18.
//  Copyright __MyCompanyName__ 2013年. All rights reserved.
//
#ifndef __HELLO_WORLD_H__
#define __HELLO_WORLD_H__

// When you import this file, you import all the cocos2d classes
#include "cocos2d.h"
#include "Box2D.h"
#include "GLES-Render.h"
class SneakyJoystick;
class MyContactListener;
class HelloWorld : public cocos2d::CCLayer {
public:
    ~HelloWorld();
    HelloWorld();
    
    // returns a Scene that contains the HelloWorld as the only child
    static cocos2d::CCScene* scene();
    void initBG();
    b2Body* addNewSpriteWithCoords(cocos2d::CCPoint p,string name,int tag);
    void update(float dt);
    void tick(float dt);
    
    CCLayer *bgLayer ;
    static b2World* getWorld();
    static HelloWorld* sharedWorld();
private:
    
    cocos2d::CCSprite *player;
    //static b2World* world;
    GLESDebugDraw *m_debugDraw;
    cocos2d::CCTexture2D* m_pSpriteTexture; // weak ref
    SneakyJoystick *joyStick;
    b2Body* playerBody;

    MyContactListener *_contactListener;
    int speed;
};

#endif // __HELLO_WORLD_H__
