//
//  World.h
//  particleTestJim
//
//  Created by Jim Fingal on 11/4/13.
//
//

#pragma once
#include "tr1/memory"
#include "EntityManager.h"

namespace ecs {

    class EntityManager;
    class SystemManager;

    class World  {
        
        private:

            EntityManager * entity_manager;
            SystemManager * system_manager;
            
        public:
            
            World();
            ~World();
            
            EntityManager * getEntityManager();
            SystemManager * getSystemManager();
    
        
    };
    

}



