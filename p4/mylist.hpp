#ifndef MYLIST_H
#define MYLIST_H

#include <iostream>
#include <exception>
using std::exception;
using std::cerr;
using std::cin;
using std::cout;
using std::endl;

template <class Elem> struct myNode { // "fuer alle Typen Elem"
    explicit myNode (const Elem& v = Elem{},
                     myNode<Elem>* p = nullptr,
                     myNode<Elem>* s = nullptr) // Standardkonstruktor
            : pre{p}, suc{s}, val{v}
    {}

    myNode<Elem>* pre; // Zeiger auf vorhergehenden Knoten (predecessor)
    myNode<Elem>* suc; // Zeiger auf nachfolgenden Knoten (successor)
    Elem val; // der Wert vom Typ Elem
};

template <class Elem> class myList {
public:
    myList (); // standardkonstruktor
    ~myList (); // destruktor

    void push_back (const Elem&);
    void pop_back ();
    void print();
    void printBackward ();
    long int getSize ();
    myNode <Elem>* ins ( const Elem&, myNode<Elem>* ); // vor Knoten p einfuegen // Rueckgabe: Adresse des neuen Knotens
    myNode <Elem>* rem ( myNode <Elem>* ); // Knoten p loeschen // Rueckgabe: Adresse des Knotens nach p
    void push_front( const Elem& ); // neuen Knoten am Anfang einfuegen
    void pop_front( ); // Knoten am Anfang loeschen

    class myIterator; // Vorabdeklaration: Typ myIterator, als "nested class"
    myIterator begin( ); // Methode, die myIterator auf erstes Element liefert
    myIterator end( ); // liefert myIterator auf "eins hinter letztem Element"
    myIterator find( const Elem&, myIterator , myIterator ) const; // finden
    myIterator insert( const Elem&, myIterator ); // einfuegen
    myIterator remove( myIterator ); // entfernen

private:
    long int sz; // Anzahl der Listenknoten
    myNode<Elem> head; // Waechterknoten: vor Listenanfang (im Stack)
    myNode<Elem> tail; // Waechterkonten: nach Listenende (im Stack)
};

template<class Elem> class myList<Elem>::myIterator {
public:
    myIterator( const myIterator& );
    explicit myIterator( myNode<Elem>* = nullptr );
    myNode<Elem>* get_curr( ) const { return curr; } // zum Debuggen

    // die Iterator-Operationen:
    myIterator& operator++( ); // ++it
    myIterator& operator--( ); // --it
    myIterator operator++( int ); // it++
    myIterator operator--( int ); // it--
    Elem& operator*( );
    bool operator==( const myIterator& ) const;
    bool operator!=( const myIterator& ) const;

private:
    myNode<Elem>* curr; // der aktuelle Knoten
};


template <class Elem>::myList<Elem>::myList ()
        : sz{0L}, head{}, tail{}
{
    head.suc = &tail;
    tail.pre = &head;
}

template <class Elem>::myList<Elem>::~myList<Elem> () {
    myNode<Elem>* dp { head.suc };
    myNode<Elem>* tmp { nullptr };
    while( dp != &tail ) {
        tmp = dp->suc;
        delete dp;
        dp = tmp;
    }
}

template <class Elem> void myList<Elem>::push_back (const Elem& v) {
    myNode<Elem>* nn { new myNode<Elem>{v} }; // neues Element aus dem Heap
    nn->suc = &tail;
    nn->pre = tail.pre;
    tail.pre->suc = nn;
    tail.pre = nn;
    ++sz;
}

template <class Elem> void myList<Elem>::pop_back () {
    if(tail.pre == &head) { // Liste ist schon leer
        cout << "Liste ist schon leer \n";
        return;
    }
    myNode<Elem>* tmp = tail.pre;
    tail.pre = tail.pre->pre;
    tail.pre->suc = &tail;
    delete tmp; // nicht mehr gebrauchter Speicher dem Heap zurueckgeben
    --sz;
}

template <class Elem> void myList <Elem>::print() {
    myNode<Elem>* current {head.suc};
    while (true){
        if(current == &tail)
            break;
        else
        {
            std::cout << current->val << " ";
            current = current->suc;
        }
    }
    std::cout << std::endl;
}

template <class Elem> void myList <Elem>::printBackward() {
    myNode<Elem>* current {tail.pre};
    while (true){
        if(current == &head)
            break;
        else
        {
            std::cout << current->val << " ";
            current = current->pre;
        }
    }
    std::cout << std::endl;
}

template <class Elem> long int myList<Elem>::getSize() {
    return sz;
}

template <class Elem> myNode<Elem>* myList<Elem>::ins(const Elem& e, myNode<Elem>* p ) {
    myNode<Elem>* n = new myNode<Elem> {e};
    myNode <Elem>* tmpPrv = p->pre; // p previous
    tmpPrv->suc = n;
    n->pre = tmpPrv;
    p->pre = n;
    n->suc = p;
    sz++;
    return n;
}

template <class Elem> myNode<Elem>* myList<Elem>::rem (myNode <Elem>* p ) {
    myNode<Elem>* tmpPrv = p->pre; // p previous
    myNode<Elem>* tmpNxt = p->suc; // p next
    if (p->pre != nullptr) {
        tmpPrv->suc = tmpNxt;
        tmpNxt->pre = tmpPrv;
        p = nullptr;
        delete p;
        sz--;

        return tmpNxt;
    }else {
        cout << "rem kann nicht durchgefuehrt werden, da Element nicht gueltig ist \n";
        return p;
    }
}

template <class Elem> void myList<Elem>::push_front (const Elem& e) {
    myNode<Elem>*n = new myNode<Elem> {e};

    n->pre = &head;
    n->suc = head.suc;

    head.suc->pre = n;
    head.suc = n;
    sz++;
}

template <class Elem> void myList<Elem>::pop_front () {
    myNode<Elem>* tmpBeg = head.suc; // begin
    myNode<Elem>* tmpSec = tmpBeg->suc; // zweites element

    head.suc = tmpSec;
    tmpSec->pre = &head;

    tmpBeg = nullptr;
    delete tmpBeg;
    sz--;
}

template<class Elem> typename myList<Elem>::myIterator myList<Elem>::begin () {
    return myIterator{ head.suc };
}

template<class Elem> typename myList<Elem>::myIterator myList<Elem>::end () {
    return myIterator{ tail.pre };
}

template<class Elem> typename myList<Elem>::myIterator myList<Elem>::find
        ( const Elem& v, myIterator p, myIterator q ) const {
    while( (p != q) && (*p != v) )
        ++p;
    return p;
}

template <class Elem> typename myList<Elem>::myIterator myList<Elem>::insert (const Elem& e, myIterator position) {
    myNode<Elem>* li = (this->head).suc;
    myIterator tst {this->begin()};

    while (position != tst) {
        tst++;
        li = li->suc;
    }
    this->ins(e,li);
    return position;
}

template <class Elem> typename myList<Elem>::myIterator myList<Elem>::remove (myIterator position ) {
    myNode<Elem>* li = (this->head).suc;
    myIterator tst {this->begin()};

    while (position != tst) {
        tst++;
        li = li->suc;
    }
    this->rem(li->pre);

    return position;
}

// Kopierkonstruktor
template<class Elem> myList<Elem>::myIterator::myIterator( const myIterator& other )
        : curr{ other.curr }
{}

// weiterer Konstruktor
template<class Elem> myList<Elem>::myIterator::myIterator( myNode<Elem>* p )
        : curr{ p }
{}

// ++it
template<class Elem> typename myList<Elem>::myIterator& myList<Elem>::myIterator::operator++( ) {
    curr = curr->suc;
    return *this;
}

// --it
template<class Elem> typename myList<Elem>::myIterator& myList<Elem>::myIterator::operator--( ) {
    curr = curr->pre;
    return *this;
}

// it++
template<class Elem> typename myList<Elem>::myIterator myList<Elem>::myIterator::operator++( int ) {
    const myIterator tmp{ *this };
    curr = curr->suc;
    return tmp;
}

// it--
template<class Elem> typename myList<Elem>::myIterator myList<Elem>::myIterator::operator--( int ) {
    const myIterator tmp{ *this };
    curr = curr->pre;
    return tmp;
}

// * // dereferenzieren
template<class Elem> Elem& myList<Elem>::myIterator::operator* () {
    return (this->curr)->val;
}

// ==
template<class Elem> bool myList<Elem>::myIterator::operator== ( const myList<Elem>::myIterator& other ) const {
    return curr == other.curr;
}

// !=
template<class Elem> bool myList<Elem>::myIterator::operator!=( const myList<Elem>::myIterator& other) const {
    return (curr != other.curr);
}

#endif // MYLIST_H
