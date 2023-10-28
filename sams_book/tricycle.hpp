#include<iostream>

class tricycle{
    public:
        tricycle(int initialSpeed);
        ~tricycle();
        int getSpeed() const { return speed; }
        void setSpeed(int speed);
        void pedal(){
            setSpeed(speed + 1);
            std::cout << "\nPedalling " << getSpeed() << " mph\n";
        }
        void brake(){
            setSpeed(speed - 1);
            std::cout << "\nPedalling " << getSpeed() << " mph\n";
        }

    private:
        int speed;
};