//
//  Enemy.h
//  ParticleBattle2
//
//  Created by 程 思源 on 13-11-18.
//
//

#ifndef __ParticleBattle2__Enemy__
#define __ParticleBattle2__Enemy__

#include <iostream>
#include "Objects\Entity\Entity.h"
#include "cocos2d.h"
using namespace cocos2d;
class Enemy : public Entity
{
public:

    
    CREATE_FUNC(Enemy);
    
    virtual bool init();
    
    void takeDamages(const unsigned int);

private:
    //void update(float dt);
    cocos2d::CCSprite *m_pSprite;

    unsigned int m_life;

};


#endif /* defined(__ParticleBattle2__Enemy__) */
