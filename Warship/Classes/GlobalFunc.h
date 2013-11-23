#pragma once

#include "cocos2d.h"

#define SCRHEIGHT 640
#define SCRWIDTH  960



// �����Լ��Ľ��ٶ�ת��Ŀ�귽��   Ҫ����update��
float rotateToVec2WithOmega(const cocos2d::CCPoint i_dr,const float i_omega,const float i_currentAngle);

// Ҫ��ǰ�ƶ��Ļ���ͨ�����������ȡ�´��ƶ���������  Ҫ����update��
cocos2d::CCPoint moveForward( const float i_rotation, const float i_speed, const cocos2d::CCPoint i_currentPosition);




// customed Rect.  Rotatable��
struct collisionRect
{

    cocos2d::CCPoint leftTop;
    cocos2d::CCPoint rightTop;
    cocos2d::CCPoint leftBottom;
    cocos2d::CCPoint rightBottom;
    
	bool collisionDetection( collisionRect i_Rect );

};