//
//  RenderSystem.h
//  entityComponentTestWithBoost
//
//  Created by Jim Fingal on 11/4/13.
//
//

#pragma once

#include "System.h"
#include "World.h"
#include "Component.h"

namespace ecs {
    
    class RenderSystem : public System {
        
        public:
            RenderSystem(World * world);
            void draw();
    };
}
