//
//  Entity.h
//  particleTestJim
//
//  Created by Jim Fingal on 11/4/13.
//
//

#pragma once

#include "tr1/memory"

class BaseEntity {
    
public:
    int id;
    
    BaseEntity(int _id) {
        id = _id;
    }
};

typedef std::tr1::shared_ptr<BaseEntity> Entity;

