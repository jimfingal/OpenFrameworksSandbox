//
//  MotionSystem.cpp
//  entityComponentTestWithBoost
//
//  Created by Jim Fingal on 11/4/13.
//
//

#include "MotionSystem.h"
#include "System.h"
#include "Component.h"
#include "World.h"
#include "Entity.h"
#include "EntityManager.h"
#include "TransformComponent.h"
#include "MotionComponent.h"

namespace ecs {
    
    MotionSystem::MotionSystem(World * world) : System(world) { }
    
    // Functor for moving an entity
    struct move_entity {

        move_entity(double dt) : dt(dt) { }
        
        int operator()(std::pair<Entity *, BaseComponent *> const & pair) {
        
            Entity * entity = pair.first;
            int id = entity->id;
            
            MotionComponent * motion = (MotionComponent *) pair.second;
            
            TransformComponent * transform = entity->getComponent<TransformComponent>();
            

            if (transform != NULL) {
                
                transform->x = transform->x + (motion->vx * dt);
                
                if (transform->x < 0) {
                    transform->x = 0;
                    motion->vx = motion->vx * -1;
                }
                
                
                if (transform->x > 1024) {
                    transform->x = 1024;
                    motion->vx = motion->vx * -1;
                }
                
                transform->y = transform->y + (motion->vy * dt);
                
                if (transform->y < 0) {
                    transform->y = 0;
                    motion->vy = motion->vy * -1;
                }
                
                
                if (transform->y > 768) {
                    transform->y = 768;
                    motion->vy = motion->vy * -1;
                }
                
            }
        }

        private:
            double dt;

    };
  

    void MotionSystem::update(double dt) {
        
        EntityManager * em = this->world->getEntityManager();
        
        std::map<Entity *, BaseComponent *> * motion_components = em->getEntityComponents<MotionComponent>();
    
        std::for_each(motion_components->begin(), motion_components->end(), ecs::move_entity(dt));
                      
    }
}