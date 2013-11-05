//
//  EntityManager.cpp
//  entityComponentTest
//
//  Created by Jim Fingal on 11/4/13.
//
//

#include "EntityManager.h"
#include "Entity.h"
#include "Component.h"
#include "map"
#include "tr1/memory"
#include "set"
#include "EntityManager.h"
#include "World.h"

namespace ecs {
    
        EntityManager::EntityManager(World * world) {
            this->world =  world;
        }
        
        EntityManager::~EntityManager() {
            
            // component_stores.clear();
            entities.clear();
            
        }
        
        Entity * EntityManager::createEntity() {
            
            Entity * new_entity = new Entity(this->world, ++next_available_id);
            entities[new_entity->id] = new_entity;
            return new_entity;
            
        }

        void EntityManager::initializeTypeKeyIfEmpty(const std::type_info * type_key) {
            
            if (component_stores.count(type_key) == 0) {
                std::map<Entity *, BaseComponent *> entity_component;
                component_stores[type_key] = entity_component;
            }
        }
        
    
}