//
//  main.cpp
//  changeOfBase
//
//  Created by Bohan Liu & Yuhang Wang on 4/14/19.
//  Copyright © 2019 ECS 50 Homework. All rights reserved.
//

/*
 Please enter the number's base: 10
 Please enter the number: 25
 Please enter the new base: 2
 25 base 10 is 11001 base 2
*/

#include <iostream>
#include <vector>
#include <math.h>
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {
    
    // Get User Input: num, num_base, new_base. //
        // string num, int num_base, int new_base. //
    int num_base, new_base;
    string num;
    cout << "Please enter the number's base: ";
    cin >> num_base;
    cout << "Please enter the number: ";
    cin >> num;
    cout << "Please enter the new base: ";
    cin >> new_base;
    
    // Step1: Convert num to base 10. //
        // Finally, decimal_num is the num  base 10 //
    vector<int> digit;
    int exponent = 0;
    for(int i = (int)(num.size()) - 1; i >= 0; i--){
        int a = num[i];
        if(a >= 48 && a <= 57){ // if a is a number //
            a = (a - 48) * pow(num_base, exponent);
            digit.push_back(a);
            exponent += 1;
        }
        else if(a >= 65 && a <= 90){ // if a is a upper-letter //
            a = (a - 55) * pow(num_base, exponent);
            digit.push_back(a);
            exponent += 1;
        }
    }
    
    int decimal_num = 0;
    for(int i = 0; i < (int)digit.size(); i++){
        decimal_num = decimal_num + digit[i];
    }
    
    // Step2: Divison until the quotient equal to 0. //
        // If any digit bigger than 0, should be replaced by letter then. //
        // ATTENTION: the digit position of remainders_v is reverse to the new_number. //
    int remainder;
    int quotient = decimal_num;
    vector<int> remainders_v;
    while(quotient != 0){
        remainder = quotient % new_base;
        quotient = quotient / new_base;
        remainders_v.push_back(remainder);
    }
    
    // Step3: Write remenders from left to right. //
    /*
     int j = 0;
    vector<int> new_num_v;
    for(int i = (int)(remainders_v.size()) - 1; i >= 0; i--){
        new_num_v[j] = remainders_v[i];
        j += 1;
    }
    */
    string new_num;
    for(int i = (int)(remainders_v.size()) - 1; i >= 0; i-- ){
        if(remainders_v[i] >= 0 && remainders_v[i] <= 9){ // Keep this number, but convert to char type. //
            char c = remainders_v[i] + 48;
            new_num.push_back(c);
        }
        else{ // Convert to letter, and convert to char type. //
            char c = remainders_v[i] + 55;
            new_num.push_back(c);
        }
    }
    // Print out the result. //
    // EX: 25 base 10 is 11001 base 2 //
    cout << num << " base " << num_base << " is " << new_num << " base " << new_base << endl;

    return 0;
}
