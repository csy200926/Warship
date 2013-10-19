//
//  BulletCache.cpp
//  spaceshooter
//
//  Created by 程 思源 on 13-4-24.
//
//

#include "BulletCache.h"
using namespace cocos2d;
/*
BulletCache* BulletCache::create()
{
	BulletCache * pRet = new BulletCache();
    if (pRet && pRet->init())
    {
        pRet->autorelease();
    }
    else
    {
        CC_SAFE_DELETE(pRet);
    }
	return pRet;
}

*/

BulletCache::BulletCache()
{
    bullets = new CCArray();
    bulletBatch = CCSpriteBatchNode::create("Icon-Small.png");
    
    this->addChild(bulletBatch);
    
    
    for (int i = 0; i < 100; i++)
    {
        Bullet *bullet = Bullet::create("Icon-Small.png");
        bullet->setVisible(false);
        bullets->addObject(bullet);
        bulletBatch->addChild(bullet);
    }
    
    nextInActivitedBullet = 0;
}

void BulletCache::shootBulletAt(CCPoint pos, CCPoint vel, CCString frameName)
{
    
    CCLog("%d",bullets->count());
    
    Bullet *bullet = (Bullet *)bullets->objectAtIndex(nextInActivitedBullet);
    nextInActivitedBullet ++;
    if (nextInActivitedBullet >= bullets->count())
        nextInActivitedBullet = 0;
    
    bullet->shootBulletAt(pos, vel, frameName);

}