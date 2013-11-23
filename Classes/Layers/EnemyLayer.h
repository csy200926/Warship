//
//  EnemyLayer.h
//  ParticleBattle2
//
//  Created by 程 思源 on 13-11-18.
//
//

#ifndef __ParticleBattle2__EnemyLayer__
#define __ParticleBattle2__EnemyLayer__

#include <iostream>
#include "cocos2d.h"


class EnemyLayer : public cocos2d::CCLayer
{
public:
    
    CREATE_FUNC(EnemyLayer);
    virtual bool init();

    float counter;
    
    void update(float dt);
};
#endif /* defined(__ParticleBattle2__EnemyLayer__) */
