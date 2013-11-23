//
//  GamingLayer.h
//  HelloCpp
//
//  Created by 程 思源 on 13-11-17.
//
//

#ifndef __HelloCpp__GamingLayer__
#define __HelloCpp__GamingLayer__

#include <iostream>
#include "cocos2d.h"
#include "Objects\Player\BattleShip.h"

#include "EnemyLayer.h"
#include "BulletLayer.h"
#include "BackGroundLayer.h"
#include "LayerParticle.h"

class GamingLayer : public cocos2d::CCLayer
{
public:
    
    bool running;
    BattleShip *pTest;
    
    CREATE_FUNC(GamingLayer);
    virtual bool init();
    static GamingLayer* getGamingLayer();
    
    
    inline BulletLayer *getBulletLayer();
    inline BackGroundLayer * getBackGroundLayer();
    inline EnemyLayer *getEnemyLayer();
    inline LayerParticle *getParticleLayer();
    
    inline void setBulletLayer(BulletLayer *);
    inline void setBackGroundLayer(BackGroundLayer *);
    inline void setEnemyLayer(EnemyLayer *);
    inline void setParticleLayer(LayerParticle *);
    
private:
    // update counter
    float counter;
    
    LayerParticle *m_pLayerParticle;
    BulletLayer *m_pBulletLayer;
    BackGroundLayer *m_pBackGroundLayer;
    EnemyLayer *m_pEnemyLayer;
    
    void update(float dt);
};
#include "GamingLayer.inl"
#endif /* defined(__HelloCpp__GamingLayer__) */
