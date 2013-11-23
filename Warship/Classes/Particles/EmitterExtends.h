#pragma once

#ifndef __DEF_GEOSHIP_PARTICLE_FIREWORK__
#define __DEF_GEOSHIP_PARTICLE_FIREWORK__

#include "cocos2d.h"


class EmitterExtends : public cocos2d::CCParticleSystemQuad
{
public:
    EmitterExtends(void);
    ~EmitterExtends(void);
    
    //override init function of sprite
    virtual bool init();
    virtual void update(float delta);
    void SetBorder(const cocos2d::CCRect border);
    void SetParColor(float r,float g,float b);
    //0.0f - 1.0f
    void SetParSize(float s);
    CREATE_FUNC(EmitterExtends);
    
protected:
    cocos2d::CCRect m_border;
};



#endif

