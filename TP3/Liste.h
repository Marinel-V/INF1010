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

    // TODO: Surcharger l'opérateur += pour ajouter un élément à la liste.
    // Vérifier que l'élément n'existe pas déjà avant de l'ajouter.
    Liste& operator+=(const T& obj) {
        // TODO: Implémenter la logique d'ajout d'un élément.
        for (T& element : listes_){
            if (element == obj) {
                return *this;
            }
        }
        listes_.push_back(obj);
        return *this;
    }

    // TODO: Surcharger l'opérateur += pour ajouter tous les éléments d'une autre liste.
    // Vérifier que les éléments n'existent pas déjà avant de les ajouter.
    Liste& operator+=(const Liste<T>& liste) {
        // TODO: Implémenter la logique d'ajout d'une liste.
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

    // TODO: Surcharger l'opérateur -= pour retirer un élément de la liste.
    // Utiliser la méthode chercher pour trouver l'élément à retirer.
    Liste& operator-=(const T& obj) {
        // TODO: Implémenter la logique de suppression d'un élément.
        int index = chercher(obj);
        if (index != -1) {
            listes_.erase(listes_.begin() + index);
        }
        return *this;
    }

    // TODO: Surcharger l'opérateur -= pour retirer un élément par son nom.
    // Utiliser la méthode chercher pour trouver l'élément à retirer.
    Liste& operator-=(const string& nom) {
        // TODO: Implémenter la logique de suppression par nom.
        int index = chercher(nom);
        if (index != -1) {
            listes_.erase(listes_.begin() + index);
        }
        return *this;
    }

    // TODO: Surcharger l'opérateur -= pour retirer tous les éléments d'une autre liste.
    // Utiliser la méthode chercher pour vérifier l'existence des éléments.
    Liste& operator-=(const Liste<T>& liste) {
        // TODO: Implémenter la logique de suppression d'une liste.
        if (liste.size() !=0)
        {
            for (T& elem : listes_) {
                *this -= elem;
            }
        }
    	
        return *this;
    }

    // TODO: Surcharger l'opérateur [] pour accéder à un élément de la liste par index.
    // Retourner une référence constante à l'élément.
    const T& operator [](int index) const{
        return listes_[index];
    }

    // TODO: Surcharger l'opérateur [] pour accéder à un élément de la liste par index.
    // Retourner une référence modifiable à l'élément.
    T& operator [](int index) {
        return listes_[index];
    }

    // TODO: Implémenter la méthode chercher pour trouver un élément par son nom.
    // Retourner l'index de l'élément s'il est trouvé, sinon retourner -1.
    int chercher(const string& nom) const {
        // TODO: Implémenter la recherche par nom.
        for (unsigned i = 0; i < listes_.size(); i++) {
            if (listes_[i]->getNom() == nom) {
                return i;
            }
        }
        return -1;
    }

    // TODO: Implémenter la méthode chercher pour trouver un élément par comparaison directe.
    // Retourner l'index de l'élément s'il est trouvé, sinon retourner -1.
    int chercher(const T& obj) const {
        for (unsigned i = 0; i < listes_.size(); i++) {
            if (listes_[i] == obj) {
                return i;
            }
        }
        return -1;
    }

    // TODO: Implémenter la méthode size pour retourner la taille de la liste.
    size_t size() const {
        return listes_.size();
    }

private:
    vector<T> listes_;
};