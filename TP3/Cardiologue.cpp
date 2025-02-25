#include "Cardiologue.h"

Cardiologue::Cardiologue(const string& nom, unsigned nbPatients, unsigned nbConsultations, unsigned int niveau)
    : Medecin(nom, new Specialite("Cardiologie", niveau)), nbPatients_(nbPatients), nbConferences_(nbConsultations), nbPublications_(0){}


unsigned int Cardiologue::getNbPatients() const {
    return nbPatients_;
}


void Cardiologue::setNbPatients(unsigned int nbPatients) {
    nbPatients_ = nbPatients;
}

unsigned int Cardiologue::getNbConferences() const {
    return nbConferences_;
}


void Cardiologue::setNbConferences(unsigned int nbConferences) {
    nbConferences_ = nbConferences;
}


unsigned int Cardiologue::getNbPublications() const {
    return nbPublications_;
}


void Cardiologue::ajouterPublications(unsigned int nbPublications) {
    nbPublications_ += nbPublications;
}


float Cardiologue::calculerSalaire() const {
    return salaireBase * specialite_->getNiveau() + (nbPatients_ * 30) + (nbConferences_ * 50) + (nbPublications_ * 200);
}


// - Mettre à jour le type de soins du patient.
void Cardiologue::opererCoeur(shared_ptr<Patient>& p) {
    nbPatients_ += 1;
    patient_ = p;
    p->ajouterAntecedent("Examen ou traitement cardiaque effectué par "+nom_+".");
    p->misAjourTypeSoin(static_cast<TypeSoins>(3));
}


ostream& Cardiologue::afficher(ostream& out) const {
    Medecin::afficher(out);
    out<< "Nombre de patients: "<<nbPatients_<<"\n"
        "Nombre de conférences: "<<nbConferences_<<"\n"
        "Nombre de publications: "<<nbPublications_<<"\n";
    return out;
}