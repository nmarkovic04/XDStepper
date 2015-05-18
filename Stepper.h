//
//  Stepper.h
//  MVCGames
//
//  Created by Nikola Markovic on 4/29/15.
//
//

#ifndef __MVCG__Stepper__
#define __MVCG__Stepper__

#include <stdio.h>
#include <initializer_list>
#include <vector>

namespace xd {
    class Stepper{
    private:
        std::vector<int> _values;
        std::vector<int>::iterator _i;
        int _index;
    public:
        Stepper();
        ~Stepper();

        /**
         * Sets the range of the stepper through an initializer list
         * e.g. stepper.set({1, 11, 5, 16})
         * Stepper will not iterate through the edge values multiple times
         * 1, 2, ... , 10, 11, 10, 9, 8, ... , 6, 5, 6, 7, 8, ... , 14, 15, 16
         */

        void set(std::initializer_list<int> steps);
        
        /**
         * Resets the stepper to the first index.
         */
        
        void reset();
        
        /**
         * Returns true if there are more values to iterate through.
         */
        bool hasNext();
        
        /**
         * Returns the next value
         */
        int next();
        
    };
}

#endif /* defined(__MVCG__Stepper__) */
