//
//  World.cpp
//  entityComponentTest
//
//  Created by Jim Fingal on 11/4/13.
//
//

#include "World.h"
#include "EntityManager.h"
#include "SystemManager.h"


namespace ecs {
   
    World::World() {
        this->entity_manager = new EntityManager(this);
        this->system_manager = new SystemManager(this);
    }
        
    EntityManager * World::getEntityManager() {
        return this->entity_manager;
    }
    
    SystemManager * World::getSystemManager() {
        return this->system_manager;
    }
    
    World::~World() {
        
        delete entity_manager;
        delete system_manager;
        
    }

}

