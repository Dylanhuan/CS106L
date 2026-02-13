#pragma once  // Prevent repeated inclusion of header files

class CoffeeMug {

    private:
            
            int capacity;
            int temperature;
            bool hasMilk;


            void AdjustTemperature();


    public:
           
            //Constructor
            CoffeeMug();
            CoffeeMug( int cap, int temp, bool milk);

            //destructor
            ~CoffeeMug() = default;

            
            //Getter function
            int getCapacity() const;
            int getTemperature() const;
            bool getMilk() const;

            //Setter function
            void setMilk (bool& hasMilk);
            void setTemperature (int temp);


};