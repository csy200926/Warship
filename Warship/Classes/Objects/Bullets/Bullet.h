//
//  Bullet.h
//  ParticleBattle2
//
//  Created by 程 思源 on 13-11-18.
//
//

#ifndef __ParticleBattle2__Bullet__
#define __ParticleBattle2__Bullet__

#include <iostream>
#include "Objects\Entity\Entity.h"

class Bullet : public Entity
{
public:
    
    CREATE_FUNC(Bullet);
    
    virtual bool init();
    
    cocos2d::CCRect collisionRect;
private:
    void update(float dt);
    cocos2d::CCSprite *m_pSprite;


};

#endif /* defined(__ParticleBattle2__Bullet__) */
