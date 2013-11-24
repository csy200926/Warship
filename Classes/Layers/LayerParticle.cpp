#include "LayerParticle.h"

#include "GamingLayer.h"



LayerParticle::LayerParticle(void)
{
}


LayerParticle::~LayerParticle(void)
{
}

void LayerParticle::update(float delta)
{
    cocos2d::CCLayer::update(delta);
}

bool LayerParticle::init()
{
    cocos2d::CCLayer::init();
    
    scheduleUpdate();
    
    return true;
}

void LayerParticle::CreateParticle(const cocos2d::CCPoint pos,ParticleType type)
{
    EmitterExtends* pe = EmitterExtends::create();

    switch (type)
    {
		case green:
			pe->SetParColor(0.2f,0.8f,0.2f);
			pe->SetParSize(1.0f);
			break;
		case yellow:
			pe->SetParColor(0.6f,0.6f,0.2f);
			pe->SetParSize(0.5f);
			break;
		case white:
			pe->SetParColor(0.6f,0.6f,0.6f);
			pe->SetParSize(1.0f);
			break;
		case red:
			pe->SetParColor(0.8f,0.2f,0.2f);
			pe->SetParSize(0.4f);
			break;
		default:
			break;
    }
    
    pe->SetBorder(cocos2d::CCRect(0,0,1920,1280));
    pe->retain();
    pe->setAutoRemoveOnFinish(true);
    pe->setPosition(pos);
    addChild(pe);
}


