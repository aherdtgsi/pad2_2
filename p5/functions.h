//
// Created by Andi on 26.01.2022.
//

#ifndef PAD2_2_FUNCTIONS_H
#define PAD2_2_FUNCTIONS_H

using namespace std;
#include "iostream"
#include <string>
#include <cstdlib>


bool check_double( const double& exp, const double& act, const double& precision){
    const double difference { ( act < exp ) ?
                              ( exp-act ) : ( act-exp ) };
    const bool result{ difference <= precision };
    return result;
}

bool check_char( const char exp, const char act){
    const bool result{ exp == act };
    return result;
}

bool check_int( const int exp, const int act){
    const bool result{ exp == act };
    return result;
}

bool check_string( const std::string& exp, const std::string& act){
    const bool result{ exp == act };
    return result;
}

void print_test_result(int test_number, bool test_result, const string& test_name){

    if(test_result){
        cout << "Test " << test_number << ": " << "SUCCESSFUL" << "(" << test_name << ")"<< endl;
        return;
    }
    cout << "Test " << test_number << ": " <<"FAILED" << "(" << test_name << ")"<< endl;
}

#endif //PAD2_2_FUNCTIONS_H
