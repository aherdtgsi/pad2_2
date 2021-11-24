//
// Created by Andi on 24.11.2021.
//

#ifndef UNTITLED1_PARKPLATZ_H
#define UNTITLED1_PARKPLATZ_H
#include "string"
using std::string;


class parkplatz {
public:
    parkplatz(unsigned int id);
    void belegen();
    void freigeben();
    void dauerparkplatz_belegen(string name);
    void dauerparkplatz_freigeben();
    bool isIstBelegt() const;
    void setIstBelegt(bool istBelegt);
    bool isIstDauerparkplatz() const;
    void setIstDauerparkplatz(bool istDauerparkplatz);
    unsigned int getId() const;
    void setId(unsigned int id);
    const string &getName() const;
    void setName(const string &name);

private:
    bool ist_belegt;
    bool ist_dauerparkplatz;
    unsigned int id;
    std::string name;

};


#endif //UNTITLED1_PARKPLATZ_H
