//
// Created by Andi on 26.01.2022.
//

using namespace std;
#include "iostream"
#include "functions.h"
#include "binTree.h"

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
    bt.insert('u');
    bt.insert('v');
    bt.insert('w');
    bt.insert('x');
    bt.insert('y');
    bt.insert('z');
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
    bt.insert('k');
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
    print_test_result(10, check_int(26, bt.size()), "checking size of tree");
    print_test_result(11, check_int(bt.size(), bt.countNodes(bt.find('p'))), "checking size of subtree from root = size()");
    print_test_result(12, check_int(15, bt.countNodes(bt.getRoot()->left)), "checking size of subtree from spot1 (root-> left)");
    print_test_result(13, check_int(0, bt.countNodes(bt.getRoot()->left->left)), "checking size of subtree from spot1 (root-> left->left)");



}

