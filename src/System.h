//
//  System.h
//  particleTestJim
//
//  Created by Jim Fingal on 11/4/13.
//
//


#pragma once

#include "World.h"

namespace ecs {
    
    class System  {
        
        protected:
            World * world;
        
        public:
            System(World * _w) {
                world = _w;
            }
        
    };

}