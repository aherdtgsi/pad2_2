
#include "test_functions.h"
#include "p3/tests.h"
#include "myRangeVec.hpp"

#include "p4/mylist.hpp"
#include "p4/p4_tests.h"
#include "p5/tests.h"


int main() try {
    p5_aufgabe2();
}
catch (exception &e) {
    cerr << "Exception: " << e.what() << "\n";
}

catch (...) {
    cerr << "Unknown Exception \n";
}
