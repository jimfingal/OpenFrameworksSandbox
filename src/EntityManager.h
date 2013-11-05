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
    
    class World;
    
    typedef std::map<int, BaseComponent *>::iterator ComponentIterator;

    class EntityManager {
        
    private:
        int next_available_id = 0;

        World * w;

        std::map<const std::type_info *, std::map<int, BaseComponent *> > component_stores;
        std::set<Entity *> entities;
        
        void initializeTypeKeyIfEmpty(const std::type_info * type_key);
        
        
    public:
        
        EntityManager(World * _w);
        ~EntityManager();
        Entity * createEntity();
        
        template<typename N>
        N * getComponent(int entity_id) {
            
            N * component = NULL;
            
            const std::type_info * type_key = &typeid(N);

            if (component_stores.count(type_key) > 0) {
                
                std::map<int, BaseComponent *> * entity_component = &component_stores[type_key];
                
                if ((*entity_component).count(entity_id) > 0) {
                    component = (N *) (*entity_component)[entity_id];
                }
                
            }
            return component;
        }
        
        template<class N>
        N * addComponent(int entity_id, N * component) {
            
            const std::type_info * type_key = &typeid(N);

            this->initializeTypeKeyIfEmpty(type_key);
            
            component_stores[type_key][entity_id] = component;
            
            return component;
        }
        
        template<class N>
        std::map<int, BaseComponent *> * getEntityComponents() {
            
            const std::type_info * type_key = &typeid(N);

            this->initializeTypeKeyIfEmpty(type_key);
            
            return &component_stores[type_key];
            
            
        }
    };

}