//
// Created by Andi on 13.01.2022.
//

#ifndef PAD2_2_P4_TESTS_H
#define PAD2_2_P4_TESTS_H

#include "mylist.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "map"
#include "iterator"

using std::cout;

void p4_aufgabe1(){
    // myList standardkonstruktor + pushback test
    cout << "myList standardkonstruktor, pushback test, push front test, print und print rueckwertz test \n";
    myList<char> l1;
    l1.push_back('a');
    l1.push_back('b');
    l1.push_back('c');
    l1.push_back('d');
    l1.push_back('e');
    l1.push_back('f');
    l1.push_back('g');
    cout << "Print Test \n";
    l1.print();
    cout << "\n";
    cout << "Print rueckwertz test \n";
    l1.printBackward();
    cout << "Size Lists ist: " << l1.getSize() << "\n";

    cout << "\n\n";
    cout << "push front test \n";
    cout << "push front 'j', danach 'k' \n";
    l1.push_front('j');
    l1.push_front('k');
    l1.print();
    l1.printBackward();
    cout << "Size Lists ist: " << l1.getSize() << "\n\n";

    // myList pop_back test
    cout << "myList pop_back test \n";
    cout << "pop_back wird einmal aufgeruefen \n";
    l1.pop_back();
    l1.print();
    l1.printBackward();
    cout << "Size Lists ist: " << l1.getSize() << "\n\n";

    // myList ins, rem und myIterator tests
    cout << "myList ins, rem und myIterator tests \n";
    cout << "myIterator wird hergestellt, er zeigt auf list anfang \n";
    l1.print();
    myList<char>::myIterator it {l1.begin()};
    cout << "Iterator zeigt auf: ";
    cout << it.get_curr()->val << "\n";
    cout << "Iterator wird inkrementiert mit it++ operator um eine Stelle \n";
    it.operator++(0);
    cout << "Iterator zeigt auf: ";
    cout << it.get_curr()->val << "\n";
    cout << "Iterator wird inkrementiert mit ++it operator um eine Stelle \n";
    it.operator++();
    cout << "Iterator zeigt auf: ";
    cout << it.get_curr()->val << "\n";
    cout << "\n\n";
    l1.print();
    cout << "Iterator wird dekrementiert mit it-- operator um eine Stelle \n";
    it.operator--();
    cout << "Iterator zeigt auf: ";
    cout << it.get_curr()->val << "\n";
    cout << "Iterator wird dekrementiert mit --it operator um eine Stelle \n";
    it.operator--(2);
    cout << "Iterator zeigt auf: ";
    cout << it.get_curr()->val << "\n";
    cout << "\n\n";
    l1.print();
    cout << "Iterator wird wieder inkrementiert und danach wird die * Operator fuer dereferenzierung verwendet um value Elements auszudruecken \n";
    it.operator++();
    cout << "Iterator zeigt auf: " << it.operator*() << "\n";
    cout << "Iterator == test \n";
    cout << "Noch einen Iterator wird hergestellt und er wird am ende Lists zeigen \n";
    myList<char>::myIterator it2 {l1.end()};
    cout << "Iterator 1 zeigt auf: " << it.operator*() << "\n";
    cout << "Iterator 2 zeigt auf: " << it2.operator*() << "\n";

    if (it.operator==(it2)) {
        cout << "Operatoren zeigen auf das selbe Element (==) \n";
    }else
        cout << "Operatoren zeigen nicht auf dasselbe Element (==) \n";
    cout << "\n\n";
    l1.print();

    cout << "Iterator != test \n";

    if (it.operator!=(it2)) {
        cout << "Operatoren zeigen nicht auf dasselbe Element (!=) \n";
    }else
        cout << "Operatoren zeigen auf dasselbe Element (!=) \n";
    cout << "Iterator zuweisungsoperator = test \n";
    cout << "Iterator 1 = Iterator 2 \n";
    it.operator=(it2);
    cout << "Iterator 1 zeigt auf: " << it.operator*() << "\n";
    cout << "Iterator 2 zeigt auf: " << it2.operator*() << "\n";
    if (it.operator==(it2)) {
        cout << "Operatoren zeigen auf dasselbe Element (==) \n";
    }else
        cout << "Operatoren zeigen nicht auf dasselbe Element (==) \n";
    cout << "\n\n";
    l1.print();
    cout << "Size Lists ist: " << l1.getSize() << "\n";
    cout << "ins und rem test \n";
    cout << "ins 'h' wird verwendet mithilfe von iterator 1 \n";
    myNode<char>* n1 = it.get_curr();
    l1.ins('h',n1);
    l1.print();
    l1.printBackward();
    cout << "Size Lists ist: " << l1.getSize() << "\n";
    cout << "\n\n";
    cout << "Iterator 1 zeigt auf: " << it.operator*() << "\n";
    cout << "Iterator 2 zeigt auf: " << it2.operator*() << "\n";
    cout << "Iterator wird um 3 stellen dekrementiert und wird verwendet fuer methode rem \n";
    it2.operator--();
    it2.operator--();
    it2.operator--();
    myNode<char>* n2 = it2.get_curr();
    cout << "Iterator 2 zeigt auf: " << it2.operator*() << "\n";
    l1.rem(n2);
    l1.print();
    l1.printBackward();
    cout << "Size Lists ist: " << l1.getSize() << "\n";

    // Methode find test
    cout << "\n\n";
    cout << "Methode find test \n";
    cout << "Iterators 1 und 2 zeigen auf Anfang bzw. Ende der Liste \n";
    cout << "Elemente es wird nach Elemente a, b und p gesucht \n";
    it.operator=(l1.begin());
    it2.operator=(l1.end());
    l1.print();
    char z1 ('a');
    if (l1.find(z1,it,it2).get_curr()->val == z1) {
        cout << "Gefunden " << z1 << "\n";
    }else
        cout << "Nicht gefunden " << z1 << "\n";

    char z2 ('b');
    if (l1.find(z2,it,it2).get_curr()->val == z2) {
        cout << "Gefunden " << z2 << "\n";
    }else
        cout << "Nicht gefunden " << z2 << "\n";

    char z3 ('p');
    if (l1.find(z3,it,it2).get_curr()->val == z3) {
        cout << "Gefunden " << z3 << "\n";
    }else
        cout << "Nicht gefunden " << z3 << "\n";
    cout << "\n\n";

    //Methode insert und Methode remove test
    cout << "Methode insert und Methode remove test \n";
    it.operator=(l1.begin());
    cout << "Iterator 1 zeigt auf: " << it.operator*() << "\n";
    cout << "Iterator 2 zeigt auf: " << it2.operator*() << "\n";
    cout << "Element 'p' wird mithilfe von insert eingefuegt und iterator zwei wird die rueckgabe der Methode insert uebernehmen \n";
    cout << "Danach wird Methode remove mit Iterator 2 als argument aufgeruefen \n\n";
    l1.print();
    cout << "Insert:.. \n";
    it2.operator=( l1.insert(z3, it));
    cout << "Iterator 1 zeigt auf: " << it.operator*() << "\n";
    cout << "Iterator 2 zeigt auf: " << it2.operator*() << "\n";
    l1.print();
    cout << "Size Lists ist: " << l1.getSize() << "\n";
    cout << "Methode remove wird aufgeruefen mit Iterator 2 als argument \n\n";
    cout << "Remove:.. \n";
    l1.remove(it2);
    cout << "Iterator 1 zeigt auf: " << it.operator*() << "\n";
    cout << "Iterator 2 zeigt auf: " << it2.operator*() << "\n";
    l1.print();
    cout << "Size Lists ist: " << l1.getSize() << "\n\n";

    cout << "Iterator 1 wird zweimal inkrementiert und danach wird die Methode remove wieder verwendet mit ihm als argument \n";
    it.operator++();
    it.operator++();
    cout << "Iterator 1 zeigt auf: " << it.operator*() << "\n\n";
    cout << "Remove:.. \n";
    l1.remove(it);
    cout << "Iterator 1 zeigt auf: " << it.operator*() << "\n";
    l1.print();
    cout << "Size Lists ist: " << l1.getSize() << "\n\n";

    cout << "Jetz wird: l1.remove(l1.insert('m',it)) durchgefuehrt \n";
    l1.remove(l1.insert('m',it));
    cout << "Iterator 1 zeigt auf: " << it.operator*() << "\n";
    cout << "Iterator 2 zeigt auf: " << it2.operator*() << "\n";
    l1.print();
    cout << "Size Lists ist: " << l1.getSize() << "\n\n";

    cout << "Jetz wird: l1.insert('o',l1.remove(it)) durchgefuehrt \n";
    l1.insert('o',l1.remove(it));
    cout << "Iterator 1 zeigt auf: " << it.operator*() << "\n";
    l1.print();
    cout << "Size Lists ist: " << l1.getSize() << "\n";

}

void p4_aufgabe2_A() {
    string from{R"(C:\Users\Andi\CLionProjects\pad2_2\p4\bible.txt)"};
    string to{R"(C:\Users\Andi\CLionProjects\pad2_2\p4\p4a2.txt)"};

    std::ifstream input_stream{from.c_str()};
    std::ofstream os{to.c_str()};

    if (!input_stream) {
        throw runtime_error("No Input Stream");
    }
    if (!os) {
        throw runtime_error("No Output Stream");
    }


    std::map<string, int> words{};
    string s{};
    while ((input_stream >> s) && (!input_stream.eof())) {
        ++words[s];
    }

    //prints the map
    //for (auto it = words.begin(); it != words.end(); it++)
    for (auto &word: words) {
        cout << word.first << " " << word.second << endl;
    }


    //copy map into vector of pairs
    std::vector<std::pair<string, int>> pairs;
    pairs.reserve(words.size());
    for (auto &word: words)
        pairs.emplace_back(word);

    //sort the vector
    std::sort(pairs.begin(), pairs.end(),
              [](const auto &x, const auto &y) { return x.second > y.second; });

    //print sorted vector
    for (auto &pair: pairs) {
        cout << pair.first << " " << pair.second << endl;
    }
/* why does this not work
    std::map<string, int> words2{};
    for (auto &pair: pairs) {
        words2.emplace(pair.first,pair.second);
    }

    for (auto &word: words2) {
        cout << word.first << " " << word.second << endl;
    }
*/

    //write into file
    for (auto &pair: pairs) {
        os << pair.first << " " << pair.second << endl;
    }

    input_stream.close();
    os.close();
}
void p4_aufgabe2_B() {
    string from{R"(C:\Users\Andi\CLionProjects\pad2_2\p4\p4a2.txt)"};
    std::ifstream input_stream{from.c_str()};
    //read data into a map
    std::map<string, int> words{};
    string s{};
    istream_iterator<string> my_it(input_stream);
    for (; my_it != istream_iterator<string>(); my_it++){
        string word = *my_it;
        my_it++;
        int frequency = std::stoi(*my_it);
        words.insert(make_pair(word, frequency));
    }
    for (auto &word: words) {
        cout << word.first << " " << word.second << endl;
    }

    cout << "Frequency the: "  << words.find("the")->second << endl;
    cout << "Frequency 1: "  << words.find("1")->second << endl;
    cout << "Frequency zeal: "  << words.find("zeal")->second << endl;
}
#endif //PAD2_2_P4_TESTS_H
