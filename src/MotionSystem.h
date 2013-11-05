//
//  MotionSystem.h
//  entityComponentTest
//
//  Created by Jim Fingal on 11/4/13.
//
//

#pragma once
#include "World.h"
#include "System.h"
#include "Component.h"

namespace ecs {
    
    class MotionSystem : public System {
        
        public:
            MotionSystem(World * world);
            void update(double dt);
    };
}

