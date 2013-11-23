//
//  BulletLayer.cpp
//  ParticleBattle2
//
//  Created by 程 思源 on 13-11-18.
//
//

#include "BulletLayer.h"
#include "Objects\Bullets\Bullet.h"

using namespace cocos2d;



bool BulletLayer::init()
{
    
    if ( !CCLayer::init() ) {
        return false;
    }
    int i = 4;
    while (i >= 0) {
        i--;
        Bullet *pBullet = Bullet::create();
        //CCPoint p = convertToWorldSpace(getPosition());
        //CCLog("%f  ,  %f \n \n",p.x,p.y);
        pBullet->setPosition( 800 ,600  );
        //pBullet->setRotation(90);
        addChild(pBullet);
    }

    
    return true;
}