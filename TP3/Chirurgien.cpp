#include "Chirurgien.h"


Chirurgien::Chirurgien(const string& nom, unsigned nbHeuresGarde, unsigned int niveau): Medecin(nom, new Specialite("Chirurgie", niveau)), nbHeuresDeGarde_(nbHeuresGarde), nbOperations_(0){}


unsigned Chirurgien::getNbHeuresDeGarde() const {
    return nbHeuresDeGarde_;
}


void Chirurgien::setNbHeuresDeGarde(int nbHeuresDeGarde) {
    nbHeuresDeGarde_ = nbHeuresDeGarde;
}


unsigned Chirurgien::getNbOperations() const {
    return nbOperations_;
}


void Chirurgien::ajouterNbOperations(unsigned nbOperations) {
    nbOperations_ += nbOperations;
}


void Chirurgien::opererPatient(shared_ptr<Patient>& p) {
    ajouterNbOperations(1);
    setPatient(p);
    p->ajouterAntecedent("Opération chirurgicale effectuée par " + nom_+".");
    p->misAjourTypeSoin(static_cast<TypeSoins>(3));
}


float Chirurgien::calculerSalaire() const {
    return salaireBase * specialite_->getNiveau() + (nbHeuresDeGarde_ * 20) + (nbOperations_ * 50);
}


ostream& Chirurgien::afficher(ostream& out) const {
    Medecin::afficher(out);
    out<<"Heures de garde: "<<nbHeuresDeGarde_<<"\n"
        "Opérations: "<<nbOperations_<<"\n";
    return out;
}
