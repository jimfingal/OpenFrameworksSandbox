//
//  Entity.h
//  particleTestJim
//
//  Created by Jim Fingal on 11/4/13.
//
//

#pragma once

namespace ecs {

    class Entity  {
        
        public:
            int id;
            
            Entity(int _id) {
                id = _id;
            }
        
        friend bool operator<(const Entity& l, const Entity& r )
        {
            return l.id < r.id;
        }
    };

}
