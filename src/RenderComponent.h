//
//  RenderComponent.h
//  entityComponentTestWithBoost
//
//  Created by Jim Fingal on 11/4/13.
//
//

#pragma once

#include "TransformComponent.h"
#include "ofGraphics.h"

class Renderer {
    
    public:
        virtual void draw(TransformComponent * transform) {}
    
};

class RenderComponent : public ecs::BaseComponent {
    
    private:
        
        Renderer * renderer;
        
    public:
        
        RenderComponent(Renderer  * _r) : ecs::BaseComponent("RenderComponent") {
            this->renderer = _r;
        }
        void draw(TransformComponent * transform) {
            this->renderer->draw(transform);
        };

};


class CircleRenderer : public Renderer {
    
    private:
        int radius;
        float r, g, b;
    
    public:
        
        CircleRenderer(int _radius, float r, float g, float b) {
            this->radius = _radius;
            this->r = r;
            this->g = g;
            this->b = b;
        }
    
        void draw(TransformComponent * transform) {
            ofPushStyle();
            ofSetColor(this->r, this->g, this->b);
            ofFill();
            ofCircle(transform->x, transform->y, this->radius);
            ofPopStyle();
        }

};