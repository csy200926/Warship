//
//  HelloWorldScene.cpp
//  box2d
//
//  Created by 程 思源 on 13-10-18.
//  Copyright __MyCompanyName__ 2013年. All rights reserved.
//
#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "SneakyJoystick.h"
#include "SneakyJoystickSkinnedBase.h"
#include "GB2ShapeCache-x.h"
#include "MyContactListener.h"
#include "PhysicsSprite.h"
#include "Bullet.h"
#include "Weapon.h"


using namespace cocos2d;
using namespace CocosDenshion;

#define PTM_RATIO 32


enum
{
	kTagTileMap = 1,
	kTagSpriteManager = 1,
	kTagAnimation1 = 1,
};

static b2World *world = NULL;

static HelloWorld *hello = NULL;


b2World* HelloWorld::getWorld()
{
    
    return world;
}


HelloWorld* HelloWorld::sharedWorld()
{
    return hello;
}


void HelloWorld::initBG()
{
    CCSprite *bg = CCSprite::create("HelloWorld.png");
    bg->setPosition(ccp(480 * 2, 320 * 2));
    bg->setScale(4.0f);
    
    bgLayer = CCLayer::create();
    this->addChild(bgLayer);
    bgLayer->addChild(bg);

    

    
    
}


HelloWorld::HelloWorld()
{
    hello = this;
    // Define the gravity vector.
    b2Vec2 gravity;
    gravity.Set(0.0f, 0.0f);
    // Do we want to let bodies sleep?
    bool doSleep = true;
    
    // Construct a world object, which will hold and simulate the rigid bodies.
    world = new b2World(gravity);
    world->SetAllowSleeping(doSleep);
    world->SetContinuousPhysics(true);
    
    joyStick = new SneakyJoystick();
    joyStick->autorelease();
    joyStick->initWithRect(CCRectZero);
    joyStick->setAutoCenter(true);
    joyStick->setHasDeadzone(true);
    joyStick->setDeadRadius(10);
    
    SneakyJoystickSkinnedBase *joystickSkin = new SneakyJoystickSkinnedBase();
    joystickSkin->autorelease();
    joystickSkin->init();
    joystickSkin->setBackgroundSprite(CCSprite::create("button-default.png"));
    joystickSkin->setThumbSprite(CCSprite::create("button-disabled.png"));
    joystickSkin->getThumbSprite()->setScale(0.5f);
    joystickSkin->setPosition(ccp(50, 50));
    joystickSkin->setJoystick(joyStick);
    


    // load shapes
    GB2ShapeCache::sharedGB2ShapeCache()->addShapesWithFile("physicalTest.plist");
    
    setTouchEnabled(true);
    setAccelerometerEnabled( true );
    
    CCSize screenSize = CCDirector::sharedDirector()->getWinSize();
    

    
//    m_debugDraw = new GLESDebugDraw( PTM_RATIO );
//    world->SetDebugDraw(m_debugDraw);
//    
//    uint32 flags = 0;
//    flags += b2Draw::e_shapeBit;
//    flags += b2Draw::e_jointBit;
//    //        flags += b2Draw::e_aabbBit;
//    //        flags += b2Draw::e_pairBit;
//    //        flags += b2Draw::e_centerOfMassBit;
//    m_debugDraw->SetFlags(flags);
//    
    b2BodyDef groundBodyDef;
    groundBodyDef.position.Set(screenSize.width/2/PTM_RATIO, screenSize.height/2/PTM_RATIO);
    
    // Call the body factory which allocates memory for the ground body
	// from a pool and creates the ground box shape (also from a pool).
	// The body is also added to the world.
    b2Body *groundBody = world->CreateBody(&groundBodyDef);
    
    // Define the ground box shape.
    b2PolygonShape groundBox;
    
    /*
    // bottom
    groundBox.SetAsBox(screenSize.width/2/PTM_RATIO, 0, b2Vec2(0, -screenSize.height/2/PTM_RATIO), 0);
 	groundBody->CreateFixture(&groundBox, 0);
	
    // top
    groundBox.SetAsBox(screenSize.width/2/PTM_RATIO, 0, b2Vec2(0, screenSize.height/2/PTM_RATIO), 0);
    groundBody->CreateFixture(&groundBox, 0);
    
    // left
    groundBox.SetAsBox(0, screenSize.height/2/PTM_RATIO, b2Vec2(-screenSize.width/2/PTM_RATIO, 0), 0);
    groundBody->CreateFixture(&groundBox, 0);
    
    // right
    groundBox.SetAsBox(0, screenSize.height/2/PTM_RATIO, b2Vec2(screenSize.width/2/PTM_RATIO, 0), 0);
    groundBody->CreateFixture(&groundBox, 0);
    
*/
    //initBG
    initBG();
    
    PhysicsSprite *sprite = PhysicsSprite::create("missile", CCPointMake(screenSize.width/2/32, screenSize.height/2/32), world);
    sprite->setCollisionGroup(-10);
    
    sprite->setTag(1);
    playerBody = sprite->getBody();
    bgLayer->addChild(sprite);
    
    Weapon *gun = Weapon::create("SlienceBullet.png");
    sprite->addChild(gun);
    

    
    
    
    PhysicsSprite *sprite_2 = PhysicsSprite::create("missile", CCPointMake(screenSize.width/2/32, screenSize.height/2/32), world);
    sprite_2->setTag(2);
    bgLayer->addChild(sprite_2);
    

    //addNewSpriteWithCoords( CCPointMake(screenSize.width/2, screenSize.height/2) );
	//playerBody = addNewSpriteWithCoords( CCPointMake(screenSize.width/2, screenSize.height/2),"missile" ,1);
    //addNewSpriteWithCoords( CCPointMake(screenSize.width/2 + 100, screenSize.height/2),"missile",2 );

    CCFollow *follow = new CCFollow();
    follow->initWithTarget((CCSprite*)playerBody->GetUserData(),CCRectMake(0, 0, screenSize.width * 2, screenSize.height * 2));
    bgLayer->runAction(follow);
    bgLayer->setTag(100);
    follow->release();
   

    schedule(schedule_selector(HelloWorld::tick));
    scheduleUpdate();
    
    CCLayer *UI = CCLayer::create();
    this->addChild(UI);
    
    UI->addChild(joystickSkin);
    joystickSkin->setPosition(ccp(100, 100));
    
    speed = 0;
    
    
    // MyContactListener *_contactListener;
    _contactListener = new MyContactListener();
    world->SetContactListener(_contactListener);
}
#define MAX_SPEED 200

HelloWorld::~HelloWorld()
{
    delete world;
    world = NULL;

}
void HelloWorld::tick(float dt)
{

	//It is recommended that a fixed time step is used with Box2D for stability
	//of the simulation, however, we are using a variable time step here.
	//You need to make an informed choice, the following URL is useful
	//http://gafferongames.com/game-physics/fix-your-timestep/
	
	int velocityIterations = 80;
	int positionIterations = 10;
    
	// Instruct the world to perform a single step of simulation. It is
	// generally best to keep the time step and iterations fixed.
	world->Step(dt, velocityIterations, positionIterations);
    
	//Iterate over the bodies in the physics world
	for (b2Body* b = world->GetBodyList(); b; b = b->GetNext())
	{
        
		if (b->GetUserData() != NULL) {
			//Synchronize the AtlasSprites position and rotation with the corresponding body
			CCSprite* myActor = (CCSprite*)b->GetUserData();
			myActor->setPosition( CCPointMake( b->GetPosition().x * PTM_RATIO, b->GetPosition().y * PTM_RATIO) );
			myActor->setRotation( -1 * CC_RADIANS_TO_DEGREES(b->GetAngle()) );
		}
	}
    
    std::vector<b2Body *>toDestroy;
    std::vector<MyContact>::iterator pos;
    for(pos = _contactListener->_contacts.begin();
        pos != _contactListener->_contacts.end(); ++pos) {
        MyContact contact = *pos;
        

        
        b2Body *bodyA = contact.fixtureA->GetBody();
        b2Body *bodyB = contact.fixtureB->GetBody();
        if (bodyA->GetUserData() != NULL && bodyB->GetUserData() != NULL) {
            CCSprite *spriteA = (CCSprite *) bodyA->GetUserData();
            CCSprite *spriteB = (CCSprite *) bodyB->GetUserData();
            
            // Sprite A = ball, Sprite B = Block
            if (spriteA->getTag() == 1 && spriteB->getTag() == 2) {
                if (std::find(toDestroy.begin(), toDestroy.end(), bodyB)
                    == toDestroy.end()) {
                    toDestroy.push_back(bodyB);
                }
            }

            
            
            
        }
        

        
        
    }
    std::vector<b2Body *>::iterator pos2;
    for(pos2 = toDestroy.begin(); pos2 != toDestroy.end(); ++pos2) {
        b2Body *body = *pos2;
        if (body->GetUserData() != NULL) {
            CCSprite *sprite = (CCSprite *) body->GetUserData();
            bgLayer->removeChild(sprite, true);
        }
        world->DestroyBody(body);
    }

}

b2Body* HelloWorld::addNewSpriteWithCoords(CCPoint p,string nname,int tag)
{
    string name = nname;
    
    CCSprite* sprite = CCSprite::create((name+".png").c_str());
    sprite->setPosition(p);
    sprite->setTag(tag);
    
    bgLayer->addChild(sprite);
    
	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
    
	bodyDef.position.Set(p.x/PTM_RATIO, p.y/PTM_RATIO);
	bodyDef.userData = sprite;
    
	b2Body *body = world->CreateBody(&bodyDef);

    // add the fixture definitions to the body
    
    GB2ShapeCache *sc = GB2ShapeCache::sharedGB2ShapeCache();
    sc->addFixturesToBody(body, name.c_str());
    sprite->setAnchorPoint(sc->anchorPointForShape(name.c_str()));
    

    return body;
}

void HelloWorld::update(float dt)
{
    
    

    
    
    CCPoint velocity = joyStick->getVelocity(); // range  0-1
    if (velocity.x != 0 || velocity.y != 0) {
        
        if (speed < MAX_SPEED)
            speed += 50;
        
        
        // +y轴为起始轴 顺时针转  atan2范围是PI - 负PI  atan是 PI/2 - 负PI/2
        float c = atan2(velocity.x, velocity.y);
        
        c = c * 180/M_PI;
        
        // 度数为0 - 360.忘记了可以nslog下
        if (c <= 0)
            c += 360;
    
   
        float d = CC_RADIANS_TO_DEGREES(playerBody->GetAngle()),b;
        
        if (d <= 0) {
            d = -d;
            b =(int)d % 360;
        }else
            b =360 - abs((int)d) % 360;
        
        
        //CCLog("stickangle:%f,playerangle:%f   %f",c,b,CC_RADIANS_TO_DEGREES(playerBody->GetAngle()));
        float omega = 100.0f;
        if (abs(b - c) > 1.0f)
        {

            if (b > c) {
                if (b - c < 180)
                    omega = omega;
                else
                    omega = -omega;
            }else
            {
                if (c - b < 180)
                    omega = -omega;
                else
                    omega = omega;
            }
        
  
            
            playerBody->SetAngularVelocity(CC_DEGREES_TO_RADIANS(omega));
        }else
            playerBody->SetAngularVelocity(CC_DEGREES_TO_RADIANS(0.0f));
    }else
    {
        playerBody->SetAngularVelocity(CC_DEGREES_TO_RADIANS(0.0f));
    }
    
    if (speed > 0)
        speed -= 10;
    if (speed < 0) {
        speed = 0;
    }
    
    
    PhysicsSprite *player = (PhysicsSprite *)playerBody->GetUserData();
    float playerAngle = player->getRotation();
    
    b2Vec2 v2Linear;
    v2Linear.Set(sin(CC_DEGREES_TO_RADIANS(playerAngle)) * speed / PTM_RATIO,cos(CC_DEGREES_TO_RADIANS(playerAngle) )* speed / PTM_RATIO);
    playerBody->SetLinearVelocity(v2Linear);
}


CCScene* HelloWorld::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // add layer as a child to scene
    CCLayer* layer = new HelloWorld();
    scene->addChild(layer);
    layer->release();
    
    return scene;
}
