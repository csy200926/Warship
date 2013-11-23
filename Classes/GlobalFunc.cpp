#include "GlobalFunc.h"

cocos2d::CCPoint moveForward( const float i_rotation, const float i_speed ,const cocos2d::CCPoint i_currentPosition)
{
    int offsetX = sin( CC_DEGREES_TO_RADIANS( i_rotation ) ) * i_speed;
    int offsetY = cos( CC_DEGREES_TO_RADIANS( i_rotation ) ) * i_speed;
    
    cocos2d::CCPoint newPosition = ccp(i_currentPosition.x + offsetX,i_currentPosition.y + offsetY);
    return newPosition;
    
}

float rotateToVec2WithOmega(const cocos2d::CCPoint i_dr,const float i_omega,const float i_currentAngle)
{
    
    float newAngle =  i_currentAngle;
    // +y��Ϊ��ʼ�� ˳ʱ��ת  atan2��Χ��PI - ��PI  atan�� PI/2 - ��PI/2
    float offset = atan2(i_dr.x,i_dr.y);
    
    offset = offset * 180/M_PI;// ��ǰ�Ǻ�Ŀ��ǶȲ�
    
    // ����Ϊ0 - 360.�����˿���nslog��  ####ȱ�ݾ���  Ŀ���Ϊ0  ��ǰ��Ϊ350ʱ  ������ת10�� ����ת350��
    if (offset <= 0)
        offset += 360;
    
    // ����㷨  ������Щʱ�����ֻת70�������290��
    if (newAngle > offset) {
        if (newAngle - offset < 180)
            newAngle -= i_omega;
        else
            newAngle += i_omega;
    }else
    {
        if (offset - newAngle < 180)
            newAngle += i_omega;
        else
            newAngle -= i_omega;
    }
    
    if (abs(newAngle - offset) <= i_omega) {
        newAngle = offset;
    }
    
    // �淶��Χ 0-360��
    if (newAngle > 360)
        newAngle = 0;
    if (newAngle < 0)
        newAngle = 360;
    
    return newAngle;
}

bool collisionRect::collisionDetection( collisionRect i_Rect )
    {
        // Compare every side to see if two rotated rects colliding....
        if( ccpSegmentIntersect(leftTop, rightTop, i_Rect.leftTop, i_Rect.rightTop) )
            return true;
        if( ccpSegmentIntersect(leftTop, rightTop, i_Rect.leftTop, i_Rect.leftBottom) )
            return true;
        if( ccpSegmentIntersect(leftTop, rightTop, i_Rect.rightTop, i_Rect.rightBottom) )
            return true;
        if( ccpSegmentIntersect(leftTop, rightTop, i_Rect.leftBottom, i_Rect.rightBottom) )
            return true;
        
        if( ccpSegmentIntersect(leftTop, leftBottom, i_Rect.leftTop, i_Rect.rightTop) )
            return true;
        if( ccpSegmentIntersect(leftTop, leftBottom, i_Rect.leftTop, i_Rect.leftBottom) )
            return true;
        if( ccpSegmentIntersect(leftTop, leftBottom, i_Rect.rightTop, i_Rect.rightBottom) )
            return true;
        if( ccpSegmentIntersect(leftTop, leftBottom, i_Rect.leftBottom, i_Rect.rightBottom) )
            return true;
        
        if( ccpSegmentIntersect(rightTop, rightBottom, i_Rect.leftTop, i_Rect.rightTop) )
            return true;
        if( ccpSegmentIntersect(leftTop, rightBottom, i_Rect.leftTop, i_Rect.leftBottom) )
            return true;
        if( ccpSegmentIntersect(leftTop, rightBottom, i_Rect.rightTop, i_Rect.rightBottom) )
            return true;
        if( ccpSegmentIntersect(leftTop, rightBottom, i_Rect.leftBottom, i_Rect.rightBottom) )
            return true;
        
        if( ccpSegmentIntersect(leftBottom, rightBottom, i_Rect.leftTop, i_Rect.rightTop) )
            return true;
        if( ccpSegmentIntersect(leftBottom, rightBottom, i_Rect.leftTop, i_Rect.leftBottom) )
            return true;
        if( ccpSegmentIntersect(leftBottom, rightBottom, i_Rect.rightTop, i_Rect.rightBottom) )
            return true;
        if( ccpSegmentIntersect(leftBottom, rightBottom, i_Rect.leftBottom, i_Rect.rightBottom) )
            return true;
        
        
        return false;
    }