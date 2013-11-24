#include "EmitterExtends.h"



EmitterExtends::EmitterExtends(void)
{
    m_border = cocos2d::CCRect();
}


EmitterExtends::~EmitterExtends(void)
{
}

void EmitterExtends::SetBorder(const cocos2d::CCRect border)
{
    m_border = border;
}

bool EmitterExtends::init()
{
    if(!CCParticleSystemQuad::initWithTotalParticles(1000) )  return false;
    
    //configue of particles
    setTexture(cocos2d::CCTextureCache::sharedTextureCache()->addImage("ParticleType1.png"));
    
    setRotationIsDir(true);
    
    // duration
    m_fDuration = 0.1f;
    
    setEmitterMode(cocos2d::kCCParticleModeGravity);
    
    // Gravity Mode: gravity
    setGravity(ccp(0,0));
    
    // Gravity Mode: speed of particles
    setSpeed(200);
    setSpeedVar(100);
    
    // Gravity Mode: radial
    setRadialAccel(0);
    setRadialAccelVar(0);
    
    // Gravity Mode: tangential
    setTangentialAccel(0);
    setTangentialAccelVar(0);
    
    // angle
    m_fAngle = 0;
    m_fAngleVar = 180;
    
    // emitter position
	setPosition(cocos2d::CCPointZero);
    setPosVar(cocos2d::CCPointZero);
    
    // life of particles
    m_fLife = 3.0f;
    m_fLifeVar = 1.0;
    
    // size, in pixels
    m_fStartSize = 15.0f;
    m_fStartSizeVar = 10.0f;
    m_fEndSize = cocos2d::kCCParticleStartSizeEqualToEndSize;
    
    // emits per second
    m_fEmissionRate = 500;

	m_ePositionType = cocos2d::kCCPositionTypeRelative;
    
    // additive
    this->setBlendAdditive(true);
    
    return true;
}

void EmitterExtends::SetParColor(float r,float g,float b)
{
    // color of particles
    m_tStartColor.r = r;
    m_tStartColor.g = g;
    m_tStartColor.b = b;
    m_tStartColor.a = 1.0f;
    m_tStartColorVar.r = 0.0f;
    m_tStartColorVar.g = g * 0.4;
    m_tStartColorVar.b = 0.0f;
    m_tStartColorVar.a = 0.0f;
    m_tEndColor.r = r;
    m_tEndColor.g = g;
    m_tEndColor.b = b;
    m_tEndColor.a = 0.0f;
    m_tEndColorVar.r = 0.0f;
    m_tEndColorVar.g = 0.0f;
    m_tEndColorVar.b = 0.0f;
    m_tEndColorVar.a = 0.0f;
}


void EmitterExtends::SetParSize(float s)
{
    // Gravity Mode: speed of particles
    setSpeed(200 * s);
    setSpeedVar(100 * s);
    // life of particles
    m_fLife = 3.0f * s;
    m_fLifeVar = 1.0 * s;
    m_fEmissionRate = 500 * s;
}

void EmitterExtends::update(float delta)
{
    cocos2d::CCParticleSystemQuad::update(delta);
    //bounce back from borders
    unsigned int pidx = 0;
    if (m_bVisible)
    {
        while (pidx < m_uParticleCount)
        {
            cocos2d::tCCParticle& p = m_pParticles[pidx];
            if((p.pos.x + p.startPos.x < m_border.getMinX() && p.modeA.dir.x < 0) || (p.pos.x + p.startPos.x > m_border.getMaxX()  && p.modeA.dir.x > 0))
            {
                p.modeA.dir.x = -p.modeA.dir.x;
                //dir to rotation
                p.rotation = -CC_RADIANS_TO_DEGREES(ccpToAngle(p.modeA.dir));
            }
            if((p.pos.y + p.startPos.y < m_border.getMinY() && p.modeA.dir.y < 0) || (p.pos.y + p.startPos.y > m_border.getMaxY()  && p.modeA.dir.y > 0))
            {
                p.modeA.dir.y = -p.modeA.dir.y;
                //dir to rotation
                p.rotation = -CC_RADIANS_TO_DEGREES(ccpToAngle(p.modeA.dir));
            }
            pidx++;
        }
    }
}


