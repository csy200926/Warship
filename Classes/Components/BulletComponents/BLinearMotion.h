//
//  BLinearMotion.h
//  ParticleBattle2
//
//  Created by 程 思源 on 13-11-18.
//
//

#ifndef __ParticleBattle2__BLinearMotion__
#define __ParticleBattle2__BLinearMotion__

#include <iostream>
#include "Objects\Entity\Entity.h"
class BLinearMotion : public Entity
{
public:
    
    CREATE_FUNC(BLinearMotion);
    
    virtual bool init();
    
    inline void setSpeed( const int i_speed )
    {
        m_speed = i_speed;
    }
private:
    float m_speed;
    
    void update(float dt);

};
#endif /* defined(__ParticleBattle2__BLinearMotion__) */
