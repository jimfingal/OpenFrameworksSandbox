//
//  Entity.h
//  particleTestJim
//
//  Created by Jim Fingal on 11/4/13.
//
//

#pragma once

#include "World.h"
#include "EntityManager.h"

namespace ecs {
    
    class EntityManager;

    class Entity  {
        
        private:
            World * world;
            
        public:
            int id;
            
            Entity(World * _w, int _id) {
                this->world = _w;
                this->id = _id;
            }
        
        
        template<typename N>
        N * getComponent() {
            return this->world->getEntityManager()->getComponent<N>(this->id);
        }
        
        friend bool operator<(const Entity& l, const Entity& r )
        {
            return l.id < r.id;
        }
    };

}
