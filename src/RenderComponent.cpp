//
//  RenderComponent.cpp
//  entityComponentTest
//
//  Created by Jim Fingal on 11/4/13.
//
//

#include "RenderComponent.h"

#include "TransformComponent.h"
#include "ofGraphics.h"


RenderComponent::RenderComponent(Renderer  * _r) : ecs::BaseComponent("RenderComponent") {
    this->renderer = _r;
}

void RenderComponent:: draw(TransformComponent * transform) {
    this->renderer->draw(transform);
};

CircleRenderer::CircleRenderer(int _radius, float r, float g, float b) {
    this->radius = _radius;
    this->r = r;
    this->g = g;
    this->b = b;
}

void CircleRenderer::draw(TransformComponent * transform) {
    ofPushStyle();
    ofSetColor(this->r, this->g, this->b);
    ofFill();
    ofCircle(transform->x, transform->y, this->radius);
    ofPopStyle();
}