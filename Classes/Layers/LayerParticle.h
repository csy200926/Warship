#pragma once

#ifndef __DEF_GEOSHIP_LAYER_PARTICLES__
#define __DEF_GEOSHIP_LAYER_PARTICLES__

#include "cocos2d.h"

#include "Particles/EmitterExtends.h"





class LayerParticle : public cocos2d::CCLayer
{

public:
    typedef enum {green = 0,
        yellow,
        white,
        red}ParticleType;
    
    LayerParticle(void);
    ~LayerParticle(void);
    
    virtual void update(float delta);
    virtual bool init();
    CREATE_FUNC(LayerParticle);
    
    void CreateParticle(const cocos2d::CCPoint pos,ParticleType type);
    
private:
};



#endif