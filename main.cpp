
#include "test_functions.h"
#include "p3/tests.h"
#include "myRangeVec.hpp"


int main ()try {
    /*
    //geraden:
    frame frm = frame();
    line geradeNachOben{ 25, 25, 25, 50 };
    line geradeNachRechts{ 25, 25, 50, 25 };
    line geradeNachLinks{ 25, 25, 5, 25 };
    line geradeNachUnten{ 25, 25, 25, 5 };

//45* schrägen:
    line RechtsOben{25, 25, 50, 50};
    line RechtsUnten{25, 25, 45, 5};
    line LinksOben{25, 25, 5, 45};
    line LinksUnten{25, 25, 5, 5};

//<45* schrägen:
    line RechtsObenSteil{ 25, 25, 35, 50 };
    line RechtsObenFlach{25, 25, 50, 35};
    line RechtsUntenSteil{ 25, 25, 35, 5 };
    line RechtsUntenFlach{ 25, 25, 45, 15 };
    line LinksObenSteil{ 25, 25, 15, 45 };
    line LinksObenFlach{ 25, 25, 5, 35 };
    line LinksUntenSteil{ 25, 25, 15, 5 };
    line LinksUntenFlach{ 25, 25, 5, 15 };


    RechtsOben.draw(&frm);
    RechtsUnten.draw(&frm);
    LinksOben.draw(&frm);
    LinksUnten.draw(&frm);

    RechtsObenSteil.draw(&frm);
    RechtsObenFlach.draw(&frm);
    RechtsUntenSteil.draw(&frm);
    RechtsUntenFlach.draw(&frm);
    LinksObenSteil.draw(&frm);
    LinksObenFlach.draw(&frm);
    LinksUntenSteil.draw(&frm);
    LinksUntenFlach.draw(&frm);
    geradeNachOben.draw(&frm);
    geradeNachRechts.draw(&frm);
    geradeNachLinks.draw(&frm);
    geradeNachUnten.draw(&frm);
    frm.show();
     */
    //a1();
    //a1_2();
    a2_2();
    //a3_2();
    return 0;
}
catch(exception &e){
    std::cout << e.what();
}
catch(...) {

    cout << "unknown error" << endl;
}

//test