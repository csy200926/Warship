//
//  MachineGun.h
//  ParticleBattle2
//
//  Created by 程 思源 on 13-11-18.
//
//

#ifndef __ParticleBattle2__MachineGun__
#define __ParticleBattle2__MachineGun__

#include <iostream>
#include"cocos2d.h"
#include "ModuleAbstract.h"
#include "Layers\GamingLayer.h"
#include "Objects\Enemies\Enemy.h"

class MachineGun : public ModuleAbstract
{
public:
    
    CREATE_FUNC(MachineGun);
    
    virtual bool init();
private:


	//void selectTarget();
	void fire();
    void update(float dt);

	// self
    cocos2d::CCSprite *m_pSprite;

	float m_diffuseRate;;

};


#endif /* defined(__ParticleBattle2__MachineGun__) */
