#include "Employe.h"

// TODO: Implémenter le constructeur de Employe.
// - Initialiser le nom de l'employé avec la valeur passée en paramètre.
Employe::Employe(const string& nom) : nom_(nom) {}

// TODO: Implémenter la méthode getNom.
// - Retourner le nom de l'employé.
string Employe::getNom() const {
    return nom_;
}

// TODO: Implémenter la méthode setNom.
// - Mettre à jour le nom de l'employé avec la valeur passée en paramètre.
void Employe::setNom(const string& nom) {
    nom_ = nom;
}

ostream& Employe::afficher(ostream &out) const {
    out << "Nom: " << nom_ << endl;
    return out;
}

// TODO: Surcharger l'opérateur << pour afficher les informations de l'employé.
ostream &operator<<(ostream &out, const Employe &e) {
    e.afficher(out);
    return out;
}