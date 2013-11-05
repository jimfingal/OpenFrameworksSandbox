//
//  EntityManager.h
//  particleTestJim
//
//  Created by Jim Fingal on 11/4/13.
//
//


#pragma once

#include "Component.h"
#include "map"
#include "tr1/memory"
#include "set"


namespace ecs {

    class World;
    class Entity;
    
    typedef std::map<Entity *, BaseComponent *>::iterator ComponentIterator;
    typedef std::pair<Entity *, BaseComponent *> ComponentPair;

    
    class EntityManager {
        
    private:
        int next_available_id = 0;

        std::map<const std::type_info *, std::map<Entity *, BaseComponent *> > component_stores;
        std::map<int, Entity *> entities;
        
        void initializeTypeKeyIfEmpty(const std::type_info * type_key);
        
        World * world;
        
    public:
        
        EntityManager(World * world);
        ~EntityManager();
        Entity * createEntity();
        
        template<typename N>
        N * getComponent(int entity_id) {
            
            N * component = NULL;
            
            const std::type_info * type_key = &typeid(N);
            
            Entity * entity_key = entities[entity_id];

            if (component_stores.count(type_key) > 0) {
                
                std::map<Entity *, BaseComponent *> * entity_component = &component_stores[type_key];
                
                if ((*entity_component).count(entity_key) > 0) {
                    component = (N *) (*entity_component)[entity_key];
                }
                
            }
            return component;
        }
        
        template<class N>
        N * addComponent(int entity_id, N * component) {
            
            const std::type_info * type_key = &typeid(N);
            Entity * entity_key = entities[entity_id];

            this->initializeTypeKeyIfEmpty(type_key);
            
            component_stores[type_key][entity_key] = component;
            
            return component;
        }
        
        template<class N>
        std::map<Entity *, BaseComponent *> * getEntityComponents() {
            
            const std::type_info * type_key = &typeid(N);

            this->initializeTypeKeyIfEmpty(type_key);
            
            return &component_stores[type_key];
            
            
        }
    };

}