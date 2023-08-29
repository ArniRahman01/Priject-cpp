#include<iostream>

using namespace std;


class Interface {

    public:
        virtual void display() = 0;
};


class Temparature : public Interface{

    protected:
        float value;

    public:

        Temparature(float data): value(data) {};

        float getTemparature(){
            return value;
            }
        void setTemparature(float data){
            value = data;
        }
};

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
    cout << "Student ID: \" ..... \" "<< endl;
    cout << "Email: hafeza0130230@gmaiil.com" << endl;
    cout << "\n-----------------------------------------\n";

}



// function defined in c++;
int userOptionChoose(){

        int choose;
        
        cout << "please Choose your Option: "<<endl;
        cout << "1. Celcius To Farenheight" << endl;
        cout << "2. Farenheight to Celcius" << endl;

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
        cout << "Please choose your desire temparature to convert in Celcius: ";
        int temp ;
        cin>>temp;
        Celcius celcius(temp);
        celcius.display();
    }
    else if(option == 1){
        cout << "Please choose your desire temparature to convert in FarenHeight: ";
        int temp;
        cin>>temp;
        FarenHeight farenheight(temp);
        farenheight.display();
    }
    else{
        cout << " You have typped out other option ..... "<<endl;
        cout << "exiting the program........";
    }

   
}
