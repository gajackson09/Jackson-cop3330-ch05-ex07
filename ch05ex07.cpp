/*
 *  UCF COP3330 Fall 2021 Assignment 5 Solution
 *  Copyright 2021 Garielle Jackson
 */

#include <iostream>
#include "std_lib_facilities.h"
using namespace std;

double a,b,c;
bool checker;

//checker function
double found(double x){
    if (!checker)
        return x;
    else {
        const double epsilon = 1e-7;
        double e = a * x * x + b * x + c;
        if (e == 0) return x;
        if (0 < e && epsilon < e)
            cout << "Poor root; off by " << e << endl;
        else if (e < -epsilon)
            cout << "Poor root; off by " << e << endl;
        return x;
    }
}//end of checker function

// solves quadratic equation
void quadratic_equation(){
    while (cin>>a>>b>>c){
        if (a == 0) {
            if (b == 0)
                cout << "No root (x isn't used)\n";
            else
                cout << "x = " << found(-c/b) << endl;
        }
        else if (b == 0) {
            double ca = -c/a;
            if (ca == 0)
                cout << "x = 0\n";
            else if (ca < 0)
                cout << "No real roots\n";
            else
                cout << "Two real roots: x = " << found(sqrt(ca)) << " and " << found(-sqrt(ca)) << endl;
        }
        else {
            double delta = b*b - 4*a*c;
            if (delta == 0)
                cout << "One real root: " << found(-b/(2*a)) << endl;
            else if (delta < 0)
                cout << "No real roots\n";
            else
                cout << "Two real roots: " << found((-b + sqrt(delta))/(2*a)) << " and " << found((-b - sqrt(delta))/(2*a)) << endl;
        }
        cout << "Try again: ";
    }
}//end of quadratic equation

//main function
int main()
try {
    cout << "Should your solutions be checked?\n";
    char check = 0;
    cin >> check;
    if (check == 'y' || check == 'Y')
        checker = true;
    else if (check == 'n' || check == 'N')
        checker = false;
    else
        error("Answer not recognised (try 'y' or 'n')");
        cout << "Enter coefficients for quadratic equation a*x^2 + b*x + c = 0\n";
        quadratic_equation();
    return 0;
}
catch (exception& e) {
    cerr << "Error: " << e.what() << endl;
    keep_window_open();
    return 1;
}
catch (...) {
    cerr << "Unknown exception!\n";
    return 2;
}