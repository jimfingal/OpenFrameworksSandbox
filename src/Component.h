//
//  Component.h
//  particleTestJim
//
//  Created by Jim Fingal on 11/4/13.
//
//


#pragma once

#include "string"

namespace ecs {

    class BaseComponent   {
        
        public:
        
            std::string name;
            
            BaseComponent(std::string _name) {
                name = _name;
            }
                
    };
}


