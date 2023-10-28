#include "tricycle.hpp"

tricycle::tricycle(int initialSpeed){
    setSpeed(initialSpeed);
}

tricycle::~tricycle(){
    
}

void tricycle::setSpeed(int newSpeed){
    if(newSpeed>=0){
        speed = newSpeed;
    }
}

int main(){
    tricycle wichita(5);
    wichita.pedal();
    wichita.pedal();
    wichita.brake();
    wichita.brake();
    wichita.brake();
    return 0;
}