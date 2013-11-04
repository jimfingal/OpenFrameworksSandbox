//
//  MotionComponent.h
//  entityComponentTest
//
//  Created by Jim Fingal on 11/4/13.
//
//

#pragma once

class MotionComponent : public ecs::BaseComponent {
    
public:
    float vx, vy;

    MotionComponent(float _vx, float _vy) : ecs::BaseComponent("MotionComponent") {
        vx = _vx;
        vy = _vy;
    }
    
    
};