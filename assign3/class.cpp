#include "class.h" // this must be the first line
#include <iostream>


// default constructor: a standard black coffee
CoffeeMug::CoffeeMug() {

    capacity = 350;
    temperature = 85;
    hasMilk = false;
    
    // private function
    AdjustTemperature();

}

//Parameterized constructor: User-defined coffee
CoffeeMug::CoffeeMug ( int cap, int temp, bool milk){

    this -> capacity = cap;
    this -> temperature = temp;
    this -> hasMilk = milk;

    AdjustTemperature();

}

//Implement of the private function
void CoffeeMug::AdjustTemperature(){

    if (temperature >= 85 ){

        std::cout << "The coffee is too hot, wait for cool..." << std::endl;
        temperature = 85;

    }

    else if ( temperature > 50 && temperature < 85 ){

        std::cout << "The temperature is just right!" << std::endl;

    }

    else{

        std::cout << "The coffee is too cold, please heat it..." << std::endl;
        setTemperature(85);

    }

}


//Getter( public function ), attention:const!
int CoffeeMug::getCapacity() const{

    return capacity;
}

int CoffeeMug::getTemperature() const{

    return temperature;
}

bool CoffeeMug::getMilk() const{

    return hasMilk;
}


//Setter( public function )
void CoffeeMug::setMilk (bool& hasMilk){

    hasMilk = true;

};

void CoffeeMug::setTemperature (int temp){

    temperature = temp;
}

//When define a class function (whether private or public), 
//don't forget to add the prefix of class name and two colons!!