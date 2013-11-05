//
//  RenderSystem.cpp
//  entityComponentTestWithBoost
//
//  Created by Jim Fingal on 11/4/13.
//
//

#include "RenderSystem.h"
#include "System.h"
#include "Component.h"
#include "World.h"
#include "EntityManager.h"
#include "RenderComponent.h"
#include "TransformComponent.h"

namespace ecs {
    
    RenderSystem::RenderSystem(World * world) : System(world) { }
    
    void RenderSystem::draw() {
        
        EntityManager * em = this->world->getEntityManager();
        
        std::map<int, BaseComponent *> * render_components = em->getEntityComponents<RenderComponent>();
        
        if (render_components->size() > 0) {
            
            for (ComponentIterator iterator = render_components->begin();  iterator != render_components->end(); iterator++) {
                
                int id = iterator->first;
                RenderComponent * render = (RenderComponent *) iterator->second;
                
                TransformComponent * transform = em->getComponent<TransformComponent>(id);
                
                if (transform != NULL) {
                    render->draw(transform);
                }
            }
        }
        
    }
}