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
#include "EntityManager.h"
#include "TransformComponent.h"
#include "MotionComponent.h"

namespace ecs {
    
    MotionSystem::MotionSystem(World * world) : System(world) { }
    
    void MotionSystem::update(double dt) {
        
        EntityManager * em = this->world->getEntityManager();
        
        std::map<int, BaseComponent *> * motion_components = em->getEntityComponents<MotionComponent>();
        
        if (motion_components->size() > 0) {
            
            for (ComponentIterator iterator = motion_components->begin();  iterator != motion_components->end(); iterator++) {
                
                int id = iterator->first;
                MotionComponent * motion = (MotionComponent *) iterator->second;
                
                TransformComponent * transform = em->getComponent<TransformComponent>(id);
                
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
        }
        
    }
}