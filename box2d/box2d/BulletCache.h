//
//  BulletCache.h
//  spaceshooter
//
//  Created by 程 思源 on 13-4-24.
//
//

#ifndef __spaceshooter__BulletCache__
#define __spaceshooter__BulletCache__

#include <iostream>
#include "cocos2d.h"
#include "Bullet.h"

class BulletCache : public cocos2d::CCNode {
    
    cocos2d::CCArray *bullets;//用来管理子弹的数组
    int nextInActivitedBullet;
    
    
    cocos2d::CCSpriteBatchNode *bulletBatch;

    
public:
    BulletCache();
    
    static BulletCache *create(void);
    
    void shootBulletAt(cocos2d::CCPoint pos,cocos2d::CCPoint vel,cocos2d::CCString);
    
    
};


#endif /* defined(__spaceshooter__BulletCache__) */
