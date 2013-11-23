#include "Entity.h"
#include "Layers\GamingLayer.h"


Entity::Entity(void)
{
}


Entity::~Entity(void)
{
}


bool Entity::init()
{
    
    if ( !CCNode::init() )
    {
        return false;
    }
    
    // Public action cooldown
    m_publicCounter = 0.0f;
    m_isCoolDown = false;
    m_coolDown = 0.0f;
    
    // Default collisionRect size
    m_width  = 20; // 长的一半尺寸
    m_height = 20; // 宽的一半尺寸
    
	m_isDead = false;
    
    return true;
    
}


void Entity::update(float dt)
{

    
    m_publicCounter += dt;
    
    if ( m_publicCounter >= m_coolDown )
    {
        m_publicCounter = 0;
        m_isCoolDown = true;
    }
    else
        m_isCoolDown = false;
}

collisionRect Entity::getCollisionRect()
{
    collisionRect rect;
    
    cocos2d::CCPoint leftTop     = ccp(-m_width, m_height);
    cocos2d::CCPoint rightTop    = ccp( m_width, m_height);
    cocos2d::CCPoint leftBottom  = ccp(-m_width, -m_height);
    cocos2d::CCPoint rightBottom = ccp( m_width, -m_height);
    
    
    leftTop = convertToWorldSpace(leftTop);
    leftTop = GamingLayer::getGamingLayer()->convertToNodeSpace(leftTop);
    rect.leftTop = leftTop;
    
    rightTop = convertToWorldSpace(rightTop);
    rightTop = GamingLayer::getGamingLayer()->convertToNodeSpace(rightTop);
    rect.rightTop = rightTop;
    
    leftBottom = convertToWorldSpace(leftBottom);
    leftBottom = GamingLayer::getGamingLayer()->convertToNodeSpace(leftBottom);
    rect.leftBottom = leftBottom;
    
    rightBottom = convertToWorldSpace(rightBottom);
    rightBottom = GamingLayer::getGamingLayer()->convertToNodeSpace(rightBottom);
    rect.rightBottom = rightBottom;

    return rect;
}



