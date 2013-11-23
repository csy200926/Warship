#pragma once

#include "cocos2d.h"

#define SCRHEIGHT 640
#define SCRWIDTH  960



// 根据自己的角速度转向目标方向   要放在update里
float rotateToVec2WithOmega(const cocos2d::CCPoint i_dr,const float i_omega,const float i_currentAngle);

// 要向前移动的话，通过这个函数获取下次移动到的坐标  要放在update里
cocos2d::CCPoint moveForward( const float i_rotation, const float i_speed, const cocos2d::CCPoint i_currentPosition);




// customed Rect.  Rotatable！
struct collisionRect
{

    cocos2d::CCPoint leftTop;
    cocos2d::CCPoint rightTop;
    cocos2d::CCPoint leftBottom;
    cocos2d::CCPoint rightBottom;
    
	bool collisionDetection( collisionRect i_Rect );

};