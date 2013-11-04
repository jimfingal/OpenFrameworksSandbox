//
//  Poolable.h
//  particleTestJim
//
//  Created by Jim Fingal on 11/1/13.
//
//

#pragma once

class Poolable {
  
    public:
        virtual Poolable create(...);
        virtual void reset(Poolable reset_item, ...);
        virtual void recycle(Poolable recycled_item, ...);
    
};
