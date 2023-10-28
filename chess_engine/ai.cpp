#include "ai.h"
#include<random>
#include<algorithm>
#include<iostream>

namespace Chess{
    std::mt19937 mt(time(0));

    void moveorder(MoveSet& ms){
        std::random_shuffle(ms.begin(), ms.end());
    }
    
}