//
//  RenderComponent.h
//  entityComponentTestWithBoost
//
//  Created by Jim Fingal on 11/4/13.
//
//

#pragma once

#include "TransformComponent.h"
#include "Component.h"

class Renderer {
    
    public:
        virtual void draw(TransformComponent * transform) {}
    
};

class RenderComponent : public ecs::BaseComponent {
    
    private:
        
        Renderer * renderer;
        
    public:
        
        RenderComponent(Renderer  * _r);
        void draw(TransformComponent * transform);

};


class CircleRenderer : public Renderer {
    
    private:
    
        int radius;
        float r, g, b;
    
    public:
    
        CircleRenderer(int _radius, float r, float g, float b);
        void draw(TransformComponent * transform);

};