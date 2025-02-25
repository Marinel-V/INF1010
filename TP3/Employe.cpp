#include "Employe.h"


Employe::Employe(const string& nom) : nom_(nom) {}


string Employe::getNom() const {
    return nom_;
}

void Employe::setNom(const string& nom) {
    nom_ = nom;
}

ostream& Employe::afficher(ostream &out) const {
    out << "Nom: " << nom_ << endl;
    return out;
}

ostream &operator<<(ostream &out, const Employe &e) {
    e.afficher(out);
    return out;
}