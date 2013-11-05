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
#include "Entity.h"
#include "EntityManager.h"
#include "RenderComponent.h"
#include "TransformComponent.h"

namespace ecs {
    
    RenderSystem::RenderSystem(World * world) : System(world) { }
    
    void render_entity(std::pair<Entity *, BaseComponent *> const & pair) {
        
        Entity * entity = pair.first;
        int id = entity->id;
        
        RenderComponent * render = (RenderComponent *) pair.second;
        
        TransformComponent * transform = entity->getComponent<TransformComponent>();
        
        if (transform != NULL) {
            render->draw(transform);
        }

    }
    
    void RenderSystem::draw() {
        
        EntityManager * em = this->world->getEntityManager();
        std::map<Entity *, BaseComponent *> * render_components = em->getEntityComponents<RenderComponent>();
        std::for_each(render_components->begin(), render_components->end(), render_entity);
        
    }
}