//
//  BackGroundLayer.cpp
//  HelloCpp
//
//  Created by 程 思源 on 13-11-17.
//
//

#include "BackGroundLayer.h"
#include "GlobalFunc.h"
#include "GamingLayer.h"

using namespace cocos2d;
bool BackGroundLayer::init()
{
    
    if ( !CCLayer::init() ) {
        return false;
    }
    

    CCSprite *pBGIMG = CCSprite::create("HelloWorld.png");
    pBGIMG->setPosition(ccp(SCRWIDTH, SCRHEIGHT));
    pBGIMG->setScale(4.0f);
    addChild(pBGIMG);
    

    
    return true;
}