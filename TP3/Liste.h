#pragma once
#include <vector>
#include "Medecin.h"
#include <memory>
using namespace std;

template<typename T>
class Liste
{   
public:
    Liste(){};
    ~Liste() = default;

    
    Liste& operator+=(const T& obj) {
        for (T& element : listes_){
            if (element == obj) {
                return *this;
            }
        }
        listes_.push_back(obj);
        return *this;
    }

    
    Liste& operator+=(const Liste<T>& liste) {
        for (const T& elemAutre : liste.listes_) {
            for (T& elem : listes_) {
                if (elemAutre == elem) {
                    break;
                }
            }
            listes_.push_back(elemAutre);
        }
        return *this;
    }

    
    Liste& operator-=(const T& obj) {
        int index = chercher(obj);
        if (index != -1) {
            listes_.erase(listes_.begin() + index);
        }
        return *this;
    }

    
    Liste& operator-=(const string& nom) {
        int index = chercher(nom);
        if (index != -1) {
            listes_.erase(listes_.begin() + index);
        }
        return *this;
    }


    Liste& operator-=(const Liste<T>& liste) {
        if (liste.size() !=0)
        {
            for (T& elem : listes_) {
                if (chercher(elem) != -1)
                {
                    *this -= elem;
                }
            }
        }
        return *this;
    }


    const T& operator [](int index) const{
        return listes_[index];
    }

    T& operator [](int index) {
        return listes_[index];
    }


    int chercher(const string& nom) const {
        for (unsigned i = 0; i < listes_.size(); i++) {
            if (listes_[i]->getNom() == nom) {
                return i;
            }
        }
        return -1;
    }


    int chercher(const T& obj) const {
        for (unsigned i = 0; i < listes_.size(); i++) {
            if (listes_[i] == obj) {
                return i;
            }
        }
        return -1;
    }

    size_t size() const {
        return listes_.size();
    }

private:
    vector<T> listes_;
};