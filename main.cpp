//include lets compiler know how to use things in different c++ files
//This includes the iostream library in my project
#include <iostream>
//This includes the "function.h" file I made in my main.
#include "function.h"

void addTwoNumbers(int a, int b)
{
    std::cout << "Running addTwoNumbers: " << std::endl;
    /*std:endl ends the line so the next print goes on the next line,
    but it also clears the buffer, which slows down further output*/
    int c (a+b);
    std::cout << a << " + " << b << " = " << a+b << '\n';
}

bool isEqualToSeven(int num)
{
    if (num == 7)
    {
        return true;
    } else
    {
        return false;
    }
}

int main(int, char**){
    //variables abt amnt of memory they take up
    int speed = 3;
    short accel = 4;
    long gravity = 10;
    char gear = '4';
    bool aboutToCrash = false;


    //float topSpeed = 400.29348399;
    double speedOfLight = 38928849938302;

    std::cout << "Enter number to add to 3: ";
    int numberInput;
    //std::cin takes input 
    std::cin >> numberInput;
    
    addTwoNumbers(3, numberInput);

    for(int i = 0; i < 4; i++)
    {
        std::cout << i << '\n';
    }

    std::cout << "Hi Kyle! " <<"Here's more I have to say. " << "And this is the end of my sentence.";
    /*\n is the preferred way to start a new line for output, since it is faster and doesnt clear the buffer*/
    std::cout << '\n' << "Gravity is: " << gravity;

    int x;
    //Pointers pass memory addresses, which is faster
    int *xer = nullptr;
    //null pointer so that random value isn't assigned instead
    //Pointers are very unsafe, random piece of memory
    int& ref = x; //Reference to x. 
    

    return 0;
}
