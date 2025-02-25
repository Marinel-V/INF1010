#include "HopitalPoly.h"


HopitalPoly::HopitalPoly(const string & nom) : nom_(nom), chambreLibre_(0) {}


HopitalPoly::HopitalPoly(const HopitalPoly &h) : nom_(h.nom_), chambreLibre_(h.chambreLibre_){
    employes_ += h.employes_;
}

string HopitalPoly::getNom() const {
    return nom_;
}

const Liste<shared_ptr<Employe>>& HopitalPoly::getEmployes() const {
	return employes_;
}

const Liste<shared_ptr<Patient>>& HopitalPoly::getPatients() const {
    return patients_;
}

void HopitalPoly::setNom(string nom) {
    nom_ = nom;
}

HopitalPoly& HopitalPoly::operator+=(const shared_ptr<Employe>& employe) {
    employes_ += employe;
    return *this;
}


HopitalPoly& HopitalPoly::operator+=(const HopitalPoly &h) {
    employes_ += h.employes_;
    return *this;
}


HopitalPoly& HopitalPoly::operator-=(const shared_ptr<Employe>& employe) {
    employes_ -= employe;
    return *this;
}


HopitalPoly& HopitalPoly::operator-=(const string &nomEmploye) {
    employes_ -= nomEmploye;
    return *this;
}

bool HopitalPoly::operator==(const HopitalPoly& rhs) const {
	return nom_ == rhs.nom_;
}


float HopitalPoly::coutSalarialTotal() const {
    float salaire = 0;
    for (unsigned i = 0; i < employes_.size(); i++){
        salaire += employes_[i]->calculerSalaire();
    }
    return salaire;
}


void HopitalPoly::accueillirPatient(shared_ptr<Patient>& patient) {
    if (patients_.chercher(patient) == -1)
    {
        patient->misAjourSalle(static_cast<int>(patients_.size()));
        patients_ += patient;
        chambreLibre_ += 1;
    }
    
    shared_ptr<Infirmier> infirmier = trouverEmployeLibre<Infirmier>();

    if (infirmier != nullptr)
    {
        infirmier->examinerPatient(patient);
        patient->assignerInfirmier(infirmier);
    }
}


void HopitalPoly::traiterPatients() {
    for (unsigned i = 0; i < patients_.size(); i++)
    {
        switch (patients_[i]->getTypeSoins()) {
        case TypeSoins::CARDIOLOGIE: {
            shared_ptr<Cardiologue>  medecin = trouverEmployeLibre<Cardiologue>();
            if (medecin != nullptr) {
                patients_[i]->assignerMedecin(medecin);
                medecin->opererCoeur(patients_[i]);
                patients_ -= patients_[i];
            }
            break;
        }
        case TypeSoins::CHIRURGICAL: {
            shared_ptr<Chirurgien> medecin = trouverEmployeLibre<Chirurgien>();
            if (medecin != nullptr) {
                patients_[i]->assignerMedecin(medecin);
                medecin->opererPatient(patients_[i]);
                patients_ -= patients_[i];
            }
            break;
        }
        case TypeSoins::PEDIATRIE: {
            shared_ptr<Pediatre> medecin = trouverEmployeLibre<Pediatre>();
            if (medecin != nullptr) {
                patients_[i]->assignerMedecin(medecin);
                medecin->examinerPatient(patients_[i]);
                patients_ -= patients_[i];
            }
            break;
        }
        default: break;
        }
    }
}


bool HopitalPoly::chercherEmploye(const shared_ptr<Employe>& employe) const {
    if (employes_.chercher(employe) != -1)
    {
        return  true;
    }
    return false;
}


bool HopitalPoly::chercherEmploye(const string& nomEmploye) const {
    if (employes_.chercher(nomEmploye) != -1){
        return true;
    }
    return false;
}


void HopitalPoly::afficherEmploye(ostream &out) const {
    for (unsigned i = 0; i < employes_.size(); i++)
    {
        out << *employes_[i]<<"\n";
    }
}


ostream& HopitalPoly::afficher(ostream &out) const {
    out << "Hôpital: " << nom_ << "\n"
        "Employés: \n";
    afficherEmploye(out);
    return out;
}


ostream &operator<<(ostream &o, const HopitalPoly &h) {
    h.afficher(o);
    return o;
}
