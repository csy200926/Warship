//
//  BackGroundLayer.h
//  HelloCpp
//
//  Created by 程 思源 on 13-11-17.
//
//

#ifndef __HelloCpp__BackGroundLayer__
#define __HelloCpp__BackGroundLayer__

#include <iostream>
#include "cocos2d.h"

class BackGroundLayer : public cocos2d::CCLayer
{
public:
    
    CREATE_FUNC(BackGroundLayer);
    
    virtual bool init();
    
    
    
};
#endif /* defined(__HelloCpp__BackGroundLayer__) */
