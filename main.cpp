
#include "test_functions.h"
#include "p3/tests.h"

int main ()try {
    //a1();
    a1_2();
}
catch(out_of_range &e){
    std::cout << e.what();
}
catch(...) {
    cout << "unknown error" << endl;
}

//test