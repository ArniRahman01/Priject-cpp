#include<iostream>

using namespace std;


// Interface - pure abstrace class
class Interface {

    public:
    
        // Pure Virtual Function
        virtual void display() = 0;
};



// Base Class
class Temparature : public Interface{

    protected:
        float value; // Only accesible from derived class (Protected)
        float temp;  // Encapsulated access Modifier, does nothing

    public:

        // Default Constructor;
        Temparature(){}


        // Constructor
        Temparature(float data): value(data) {};

        // Destructor
        virtual ~Temparature() = default;


        // Get and Set Method does nothing
        // Get and Set Method for Private (Encapsulated Attribute).
        float getTemparature(){
            return temp;
            }
        void setTemparature(float data){
            temp = data;
        }
};


// Derived Class - Celcius
// Single Inheritance
class Celcius : public Temparature{
    
    public : 
        Celcius(float data):Temparature(data){}

        float celciusToFarenheight(){
            return value * 9.0/5.0 + 32;
        }

        void display() override {
            cout << "your Tempareture in Farenheight :" << celciusToFarenheight() << endl;
        }

};


// Derived Class - FarenHeight
// Single Inheritance
class FarenHeight : public Temparature{
    
    public : 
        FarenHeight(float data):Temparature(data){}

        float FarenheightToCelcius(){
            return (value - 32) * 5.0/9.0;
        }

        void display() override {
            cout << "your Tempareture in Celcius :" << FarenheightToCelcius() << endl;
        }

};



// Example Class 
// Example of Separation of Interface and Implementation
class  StudentDetails {
    public :
        void studentDetails(); // Declaration 
};

// Implimentation
void StudentDetails::studentDetails(){
    cout << endl;
    cout << "Name: Hafeza Rahman Arni" << endl;
    cout << "Student ID: \"41220300619\" "<< endl;
    cout << "Email: hafeza0130230@gmaiil.com" << endl;
    cout << "\n-----------------------------------------\n";

}



// function defined in c++;
int userOptionChoose(){

        int choose;
        
        cout << "please Choose your Option: "<<endl;
        cout << "1. Farenheight to Celcius" << endl;
        cout << "2. Celcius To Farenheight" << endl;

        cin >> choose;
        return choose;

}


int main(){

    int option;

    // calling demo class for showing the Implementaion of Separation of Interface.
    StudentDetails demo;
    demo.studentDetails();


    option = userOptionChoose();
    if(option == 2){
        cout << "Please choose your desire temparature in Celcius to convert in Farenheight: ";
        int temp ;
        cin>>temp;
        Celcius celcius(temp);   // Create object of Celcius
        celcius.display();
    }
    else if(option == 1){
        cout << "Please choose your desire temparature in Farenheight to convert in Celcius: ";
        int temp;
        cin>>temp;
        FarenHeight farenheight(temp); // Create object of Farenheight
        farenheight.display();
    }
    else{
        cout << " You have typped out other option ..... "<<endl;
        cout << "exiting the program........";
    }

   
}
