//
// Created by Andi on 26.01.2022.
//

using namespace std;
#include "iostream"
#include "functions.h"
#include "binTree.h"
#include "vector"

void p5_aufgabe1(){
    print_test_result(1, check_double(1,1,0.01), "testtest1, must be success");
    print_test_result(2, check_double(1,1.1,0.01), "testtest2, must be fail");
    print_test_result(3, check_char('1', '1'), "testtest3, must be success");
    print_test_result(4, check_char('1', '2'), "testtest4, must be fail");

    BinTree bt;
    bt.insert('p');
    bt.insert('q');
    bt.insert('r');
    bt.insert('s');
    bt.insert('t');
    bt.insert('x');
    bt.insert('y');
    bt.insert('z');
    bt.insert('u');
    bt.insert('v');
    bt.insert('w');
    bt.insert('a');
    bt.insert('b');
    bt.insert('c');
    bt.insert('d');
    bt.insert('e');
    bt.insert('f');
    bt.insert('g');
    bt.insert('h');
    bt.insert('i');
    bt.insert('j');
    bt.insert('l');
    bt.insert('m');
    bt.insert('n');
    bt.insert('o');
    bt.insert('a');
    bt.insert('a');
    bt.insert('a');
    bt.in_order();
    bt.level_order();
    print_test_result(5, check_char('a', bt.find('a')->value), "checking find method1");
    print_test_result(6, check_char('b', bt.find('b')->value), "checking find method2");
    print_test_result(7, check_char('z', bt.find('z')->value), "checking find method3");
    print_test_result(8, check_int(4, bt.find('a')->count), "checking find method(count)1");
    print_test_result(9, check_int(1, bt.find('b')->count), "checking find method(count)2");
    print_test_result(10, check_int(25, bt.size()), "checking size of tree");
    print_test_result(11, check_int(bt.size(), bt.countNodes(bt.find('p'))), "checking size of subtree from root = size()");
    print_test_result(12, check_int(14, bt.countNodes(bt.getRoot()->left)), "checking size of subtree from spot1 (root-> left)");
    print_test_result(13, check_int(0, bt.countNodes(bt.getRoot()->left->left)), "checking size of subtree from spot1 (root-> left->left)");

    cout << "TEST: Some rotations around root" << endl;
    bt.level_order();
    bt.rotate_right(bt.getRoot());
    bt.level_order();
    bt.rotate_right(bt.getRoot());
    bt.level_order();
    bt.rotate_right(bt.getRoot());
    bt.level_order();
    bt.rotate_left(bt.getRoot());
    bt.level_order();
    bt.rotate_left(bt.getRoot());
    bt.level_order();
    bt.rotate_left(bt.getRoot());
    bt.level_order();
    bt.rotate_left(bt.getRoot());
    bt.level_order();
    bt.rotate_left(bt.getRoot());
    bt.level_order();
    bt.rotate_left(bt.getRoot());
    bt.level_order();
    bt.rotate_left(bt.getRoot());
    bt.level_order();
    bt.rotate_left(bt.getRoot());
    bt.level_order();
    bt.rotate_left(bt.getRoot());
    bt.level_order();
    bt.rotate_left(bt.getRoot());
    bt.level_order();
    bt.rotate_left(bt.getRoot());
    bt.level_order();

    cout << "TEST: Some rotations around other nodes" << endl;
    bt.rotate_left(bt.find('a'));
    bt.level_order();
    bt.rotate_left(bt.find('a'));
    bt.level_order();
    bt.rotate_left(bt.find('a'));
    bt.level_order();
    bt.rotate_right(bt.find('a'));
    bt.level_order();
    bt.rotate_right(bt.find('a'));
    bt.level_order();
    bt.rotate_right(bt.find('a'));
    bt.level_order();
    bt.rotate_right(bt.find('b'));
    bt.level_order();
    bt.rotate_left(bt.find('b'));
    bt.level_order();

    bt.insert_as_root('k');
    print_test_result(14, check_char('k', bt.getRoot()->value), "inserting k as root, checking if k is root");

    bt.insert_as_root('a');
    print_test_result(15, check_char('a', bt.getRoot()->value), "inserting a as root, checking if a is root");
    print_test_result(16, check_int(5, bt.getRoot()->count), "inserting k as root, checking if a counter has increased");

}


void p5_aufgabe2(){
    cout << "testvector<int>" << endl;
    vector<int> v = {1,2,3,4,1,2,3,5,7,2,4,6,5,3,45234,3,2345,234,1};
    printVector(v);
    quicksort(v, 0, v.size()-1);
    printVector(v);

    cout << "testvector<double>" << endl;
    vector<double> v2 = {1.32,2.2342,3.9,4,1,2,3,5,7,2,4,6,5,3,45234,3,2345,234.1,1};
    printVector(v2);
    quicksort(v2, 0, v2.size()-1);
    printVector(v2);

    cout << "testvector<int> mit 1 element" << endl;
    vector<int> v3 = {1};
    printVector(v3);
    quicksort(v3, 0, v3.size()-1);
    printVector(v3);


    cout << "testvector<int> leer" << endl;
    vector<int> v4 = {};
    printVector(v4);
    quicksort(v4, 0, v3.size()-1);
    printVector(v4);

}
