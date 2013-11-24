#pragma once

#ifndef __DEF_GEOSHIP_SPRITE_ENTITY__
#define __DEF_GEOSHIP_SPRITE_ENTITY__

#include "cocos2d.h"
#include "GlobalFunc.h"



class Entity : public cocos2d::CCNode
{
public:
	Entity(void);
	~Entity(void);
	virtual void getsKilled();
	inline bool isDead();

    collisionRect getCollisionRect();
private:
    float m_publicCounter;

protected:
	// To avoid collision dectction conflicts,
	// We do not simply remove from parent
	bool m_isDead;
        
    // collisionRect size
    float m_width; // 长的一半尺寸
    float m_height;// 宽的一半尺寸
        
    bool    m_isCoolDown;
    float   m_coolDown;
    virtual bool init();

    virtual void update(float dt);

};

bool Entity::isDead()
{
	return m_isDead;
}


#endif

