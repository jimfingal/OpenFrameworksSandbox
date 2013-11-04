//
//  SystemManager.h
//  particleTestJim
//
//  Created by Jim Fingal on 11/4/13.
//
//


#pragma once

class SystemManager {
    
private:
    
    std::map<const std::type_info *, System * > systems;
    
public:
    template<typename N>
    N * getSystem() {
        
        const type_info * type_key = &typeid(N);
        
        N * system = NULL;
        
        if (systems.count((type_key)) > 0) {
            system = systems[type_key]
            
        }
        
        return system;
    }
    
    template<class N>
    N * addSystem(N * system) {
        
        const type_info * type_key = &typeid(N);

        if (systems.count(type_key) > 0) {
            
            N * tmp = (N *) systems[type_key];
            delete tmp
        }
        
        systems[type_key] = system;
        
        return system;
        
    }
    
    
};