#include <iostream>

using namespace std;
//Define exception class
class OverSpeed : public exception {
    int speed1;
public:
    //overwrite the method which is written in this exception class
     const char* what(){
        return "You are in the car not in the airplane";
    }

    void setSpeed(int nSpeed){
        speed1 = nSpeed;
    }
};

class Car{
    int speed;
    OverSpeed s;
public:
    Car(){
        speed = 0;
        cout << "Speed of the car is 0" << endl;
    }
    //loop without condition
   void accelarate(){
        for(;;){
           speed += 10;
            cout << " Speed is:  " << speed << endl;
            if(speed >= 250){
                s.setSpeed(speed);
                throw s;// s -> the object of OverSpeed 
            }}
        }
};

int main() {
    try {
        Car car1;

        car1.accelarate();
    }catch (OverSpeed s){
     cout <<  s.what() << endl;
    }
    return 0;
}