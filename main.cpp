#include <iostream>
#include <math.h>
#include <assert.h> //to include the assert library to make sure dynamic memory allocation worked
using namespace std; // so that I dont have to put std in front of every operation like cout, cin


double addNum(double &a, double &b) { //function for addition
    return a + b; //anonymous object
} 

double subNum(double a, double b) { //function for subtraction 
    return a - b; //anonymous object
}

double multNum(double a, double b) { //function for multiplication
    return a * b; //anonymous object
}

double divNum(double a, double b) { //function for division
    if (b == 0) { //error checking
        cout << "Nonexistent. Cannot divide by 0" << endl; //if user chooses second number as 0, then terminate because cannot divide by 0 in math
    }
    
    return a/b; //anonymous object
}

double modNum(double a, double b) { //function for modulo operation
    if (b == 0) { //error checking
        cout << "Nonexistent. Cannot modulo by 0" << endl; // if user choose second number as 0, then terminate because cannot divide by 0 in math
    }
    
    return fmod(a,b); //anonymous object and function to use modulo operator because c++ does not allow % between doubles
}

int main(void) { //main function
    char continueornah; //the only regular variable
    double *num1 = new(nothrow) double; //assigns new chunk of memory which is 8 bytes to pointer num1 
    double *num2 = new(nothrow) double; //allocates new memory 8 bytes to pointer num2
    int *selection = new(nothrow) int; //assigns new memory of 4 bytes to pointer selection
    
do {   
    
    
    assert(num1 != 0); //double checks to see if any new memory was put into num1
    assert(num2 != 0); //double checks to see if dynamic memory allocation happened
    assert(selection != 0); //double checks to see if memory was stored in pointer
  
    cout << "This is a standard calculator" << endl;
    cout << "Choose the first number that you would like to operate on" << endl;
        if (!(cin >> *num1)) { //error checking: makes sure user does not enter non-numbers https://stackoverflow.com/questions/5131647/why-would-we-call-cin-clear-and-cin-ignore-after-reading-input
            cout << "Please enter numbers only." << endl;
            cin.clear();
            cin.ignore(10000,'\n'); //It takes out 10000 characters from the buffer but stops if it encounters a newline (\n). The 10000 is just a generic large value
      
            cout << "Choose the first number that you would like to operate on" << endl;
            cin >>  *num1;
    }
    
    cout << "Choose the second number that you would like to operate on" << endl;
        if (!(cin >> *num2)) { //error checking
            cout << "Please enter numbers only." << endl;
            cin.clear();
            cin.ignore(10000,'\n');
      
            cout << "Choose the second number that you would like to operate on" << endl;
            cin >> *num2;
    }
    
    cout << "Here are the 2 numbers you put in: " << *num1 << " and " << *num2 << endl;
    
    cout << "what would you like to do with the numbers? \n";
    cout << "Select 1 to add(+) the first number to the second number\n" ; 
    cout << "Select 2 to subtract(-) the first number from the second number\n";
    cout << "Select 3 to multiply(*) the first number from the second number\n";
    cout << "Select 4 to divide(/) the first number from the second number\n";
    cout << "Select 5 to modulo operate(%) the first number from the second number\n";
    cin >> *selection;
    
        if (*selection <= 0) { //error checking: if user does not enter one of the options
            cout << "Invalid Input." << endl;
            cin.clear();
            cin.ignore(10000,'\n');
      
            cout << "Let's try this again! What would you like to do with the numbers? \n";
            cout << "Select 1 to add(+) the first number to the second number\n" ; 
            cout << "Select 2 to subtract(-) the first number from the second number\n";
            cout << "Select 3 to multiply(*) the first number from the second number\n";
            cout << "Select 4 to divide(/) the first number from the second number\n";
            cout << "Select 5 to modulo operate(%) the first number from the second number\n";
            cin >> *selection;
        }
        else if (*selection >= 6) { //error checking: if user does not enter one of the options
            cout << "Invalid Input." << endl;
            cin.clear();
            cin.ignore(10000,'\n');
      
            cout << "Let's try this again! What would you like to do with the numbers? \n";
            cout << "Select 1 to add(+) the first number to the second number\n" ; 
            cout << "Select 2 to subtract(-) the first number from the second number\n";
            cout << "Select 3 to multiply(*) the first number from the second number\n";
            cout << "Select 4 to divide(/) the first number from the second number\n";
            cout << "Select 5 to modulo operate(%) the first number from the second number\n";
            cin >> *selection;
        }
    
    switch (*selection) { //switch cases for when user inputs selections
      
        case 1:
        cout << "The sum is: " << addNum(*num1, *num2) << endl;
        break;
        case 2:
        cout << "The difference is " << subNum(*num1, *num2) << endl;
        break;
        case 3:
        cout << "The product is " << multNum(*num1, *num2) << endl;
        break;
        case 4:
        cout << "The dividend is " << divNum(*num1, *num2) << endl;
        break;
        case 5: 
        cout << "The modulo is " << modNum(*num1, *num2) << endl;
        break;
    }
    
    
    
    cout << "Do you want to continue? (y or n)" << endl; //asking user if they want to continue
    cin >> continueornah;
}
 while (continueornah == 'y'); //the loop will continue as long as user selects 'y'
  
    delete[] num1; //to prevent memory leak
    delete[] num2; //to prevent memory leak
    delete[] selection; //to prevent memory leak
    
   cout << "Thank you for your time! Goodbye!" << endl; //as soon as user inputs 'n', do-while exits and program says goodbye
   return 0;
}
