
#include "test_functions.h"
#include "p3/tests.h"



int main ()try {
    //a1();
    //a1_2();
    a2_2();
}
catch(exception &e){
    std::cout << e.what();
}
catch(...) {

    cout << "unknown error" << endl;
}

//test