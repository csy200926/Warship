//
//  GameScene.cpp
//  HelloCpp
//
//  Created by 程 思源 on 13-11-17.
//
//

#include "GameScene.h"
#include "Layers/BackGroundLayer.h"
#include "Layers/GamingLayer.h"
#include "Layers/BulletLayer.h"
#include "Layers/EnemyLayer.h"
#include "Layers/LayerParticle.h"

#include "Layers/UILayer.h"
#include "GlobalFunc.h"

using namespace cocos2d;

bool GameScene::init()
{

    if ( !CCScene::init() )
    {
        return false;
    }
    
    GamingLayer *pGamingLayer = GamingLayer::create();
    addChild(pGamingLayer);
    
    BackGroundLayer *pBackGroundLayer = BackGroundLayer::create();
    // BGLayer has to go with GamingLayer Because of the use of follow
    pGamingLayer->addChild(pBackGroundLayer, 0);
    
    BulletLayer *pBulletLayer = BulletLayer::create();
    // BulletLayer has to go with GamingLayer Because of the use of follow
    pGamingLayer->addChild(pBulletLayer, 1);
    
    EnemyLayer *pEnemyLayer = EnemyLayer::create();
    // EnemyLayer has to go with GamingLayer Because of the use of follow
    pGamingLayer->addChild(pEnemyLayer, 1);
    
    LayerParticle *pLayerParticle = LayerParticle::create();
    // EnemyLayer has to go with GamingLayer Because of the use of follow
    pGamingLayer->addChild(pLayerParticle, 2);
    
    pGamingLayer->setBackGroundLayer( pBackGroundLayer );
    pGamingLayer->setBulletLayer( pBulletLayer );
    pGamingLayer->setEnemyLayer( pEnemyLayer );
    pGamingLayer->setParticleLayer(pLayerParticle);
    
    // Fixing the player to the center of the screen
    CCFollow *pFollow = new CCFollow();
    pFollow->initWithTarget((CCNode* )pGamingLayer->pTest,CCRectMake(0, 0, SCRWIDTH * 2, SCRHEIGHT * 2));
    pGamingLayer->runAction(pFollow);
    pFollow->release();

    
    UILayer *pUILayer = UILayer::create();
    addChild(pUILayer);
    
  
    pGamingLayer->running = true;
    return true;
}