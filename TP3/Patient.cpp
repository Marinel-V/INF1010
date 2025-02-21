#include "Patient.h"

// TODO: Implémenter le constructeur de Patient.
// - Initialiser le nom et l'âge du patient.
// - Initialiser typeSoins_ à PAS_BESOIN.
// - Initialiser infirmier_ et medecin_ à nullptr.
Patient::Patient(std::string nom, int age)
    :  {}

void Patient::setNom(const string& nom) {
    nom_ = nom;
}

const string& Patient::getNom() const {
    return nom_;
}

int Patient::getSalle() const {
    return numeroSalle_;
}

const TypeSoins& Patient::getTypeSoins() const {
    return typeSoins_;
}

shared_ptr<Infirmier> Patient::getInfirmier() const {
    return infirmier_;
}

shared_ptr<Medecin>  Patient::getMedecin() const {
    return medecin_;
}

vector<string> Patient::getAntecedentsMedicaux() const {
    return antecedentsMedicaux_;
}

void Patient::ajouterAntecedent(const std::string& antecedent) {
    antecedentsMedicaux_.push_back(antecedent);
}

void Patient::misAjourTypeSoin(const TypeSoins& typeSoin) {
    typeSoins_ = typeSoin;
}

void Patient::misAjourSalle(int nSalle) {
    numeroSalle_ = nSalle;
}

void Patient::assignerInfirmier(const shared_ptr<Infirmier>& i){
    infirmier_ = i;
}

void Patient::assignerMedecin(const shared_ptr<Medecin>& m){
    medecin_ = m;
}

// TODO: Implémenter la méthode afficher.
// - Afficher les informations du patient, y compris le nom, l'âge, le numéro de salle, le type de soins et les antécédents médicaux.
void Patient::afficher(ostream& out) const {
}

// TODO: Surcharger l'opérateur << pour afficher les informations du patient.
ostream& operator<<(ostream& out, const Patient& p) {
    // TODO: Utiliser la méthode afficher pour afficher les informations du patient.
    return out;
}