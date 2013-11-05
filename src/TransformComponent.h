//
//  TransformComponent.h
//  entityComponentTest
//
//  Created by Jim Fingal on 11/4/13.
//
//

#pragma once

class TransformComponent : public ecs::BaseComponent {
    
public:
    
    float x, y;
    
    TransformComponent(float _x, float _y) : ecs::BaseComponent("TransformComponent") {
        this->x = _x;
        this->y = _y;
    }
    
    
};