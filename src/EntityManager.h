//
//  EntityManager.h
//  particleTestJim
//
//  Created by Jim Fingal on 11/4/13.
//
//


#pragma once

#include "Entity.h"
#include "Component.h"
#include "map"
#include "tr1/memory"
#include "set"


namespace ecs {
    
    typedef std::map<int, BaseComponent *> EntityComponents;

    class World;
    
    class EntityManager {
        
    private:
        std::map<const std::type_info *, EntityComponents > component_stores;
        std::set<Entity> entities;
        int next_available_id = 0;
        World * w;
        
    public:
        
        EntityManager(World * _w) {
            w = _w;
        }
        
        ~EntityManager() {
            
            // Iterate through entities and delete
            
            // Iterate through component stores and delete
        }
        
        Entity createEntity() {
            
            Entity new_entity = Entity(new BaseEntity(++next_available_id));
            entities.insert(new_entity);
            return new_entity;
        }
        
        template<typename N>
        N * getComponent(int entity_id) {
            
            N * component = NULL;
            const std::type_info * type_key = &typeid(N);

            if (component_stores.count(type_key) > 0) {
                EntityComponents * entity_component = &component_stores[type_key];
                
                if ((*entity_component).count(entity_id) > 0) {
                    component = (*entity_component)[entity_id];
                }
                
            }
            return component;
        }
        
        template<class N>
        N * addComponent(int entity_id, N * component) {
            
            const std::type_info * type_key = &typeid(N);

            if (component_stores.count(type_key) == 0) {
                
                EntityComponents entity_component;
                
                component_stores[type_key] = entity_component;
                
            }
            
            component_stores[type_key][entity_id] = component;
            
            return component;
        }
        
        template<class N>
        EntityComponents * getEntityComponents() {
            
            const std::type_info * type_key = &typeid(N);

            if (component_stores.count(type_key) == 0) {
                return NULL;
            } else {
                return &component_stores[type_key];
            }
            
        }
        
        
    };

}