//
//  Stepper.cpp
//  MVCGames
//
//  Created by Nikola Markovic on 4/29/15.
//
//

#include "Stepper.h"

namespace xd {

    Stepper::Stepper()  : _index(0){}
    
    Stepper::~Stepper(){
        _values.clear();
    }
    
    void Stepper::set(std::initializer_list<int> steps){
        // reset the index to 0
        reset();
        
        // clear the old values
        _values.clear();
        
        std::initializer_list<int>::iterator i = steps.begin();
        bool first = true;
        
        while(i != steps.end()){
            int beginValue = *i;
            i = i+1;
            if(i == steps.end()){
                return;
            }else{
                // firstIter is how we keep track of the first iteration
                // since we don't want to write the edge values twice
                bool firstIter = true;
                int endValue = *i;
                
                // step is direction we're iterating in
                int step = beginValue > endValue ? -1 : 1;
                while (beginValue!=endValue) {
                    if(!(firstIter && !first)){
                        _values.push_back(beginValue);
                    }
                    
                    beginValue += step;
                    
                    first = false;
                    firstIter = false;
                }
                _values.push_back(endValue);
            }
        }
    }
    
    void Stepper::reset(){
        _index = 0;
    }
    
    bool Stepper::hasNext(){
        return _index < _values.size();
    }
    
    int Stepper::next(){
        if(_index >= _values.size() || _index < 0){
            return -1;
        }
        int value = _values[_index];
        _index++;
        return value;
    }
}