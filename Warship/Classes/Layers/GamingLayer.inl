//
//  GamingLayer.inl.c
//  ParticleBattle2
//
//  Created by 程 思源 on 13-11-18.
//
//

#ifndef __HelloCpp__GamingLayerINL__
#define __HelloCpp__GamingLayerINL__

#include "GamingLayer.h"
// Getter
inline BulletLayer *GamingLayer::getBulletLayer()
{
    return m_pBulletLayer;
}
inline BackGroundLayer * GamingLayer::getBackGroundLayer()
{
    return m_pBackGroundLayer;
}
inline EnemyLayer *GamingLayer::getEnemyLayer()
{
    return m_pEnemyLayer;
}
inline LayerParticle *GamingLayer::getParticleLayer()
{
    return m_pLayerParticle;
}





// Setter
inline void GamingLayer::setParticleLayer(LayerParticle * i_pLayerParticle)
{
    m_pLayerParticle = i_pLayerParticle;
}
inline void GamingLayer::setBulletLayer(BulletLayer * i_pBulletLayer)
{
    m_pBulletLayer = i_pBulletLayer;
}
inline void GamingLayer::setBackGroundLayer(BackGroundLayer * i_pBackGroundLayer)
{
    m_pBackGroundLayer = i_pBackGroundLayer;
}
inline void GamingLayer::setEnemyLayer(EnemyLayer * i_pEnemyLayer)
{
    m_pEnemyLayer = i_pEnemyLayer;
}
#endif