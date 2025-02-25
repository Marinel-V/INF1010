#include "HopitalPoly.h"

// TODO: Implémenter le constructeur de HopitalPoly.
// - Initialiser le nom de l'hôpital avec la valeur passée en paramètre.
// - Initialiser chambreLibre_ à 0.
HopitalPoly::HopitalPoly(const string & nom) : nom_(nom), chambreLibre_(0) {}

// TODO: Implémenter le constructeur de copie de HopitalPoly.
// - Copier le nom et chambreLibre_ de l'hôpital passé en paramètre.
// - Ajouter tous les employés de l'hôpital passé en paramètre.
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

// TODO: Surcharger l'opérateur += pour ajouter un employé à l'hôpital.
HopitalPoly& HopitalPoly::operator+=(const shared_ptr<Employe>& employe) {
    employes_ += employe;
    return *this;
}

// TODO: Surcharger l'opérateur += pour ajouter tous les employés d'un autre hôpital.
// - Vérifier que les employés n'existent pas déjà avant de les ajouter.
HopitalPoly& HopitalPoly::operator+=(const HopitalPoly &h) {
    employes_ += h.employes_;
    return *this;
}

// TODO: Surcharger l'opérateur -= pour retirer un employé de l'hôpital.
// - Retirer l'employé s'il existe dans la liste.
HopitalPoly& HopitalPoly::operator-=(const shared_ptr<Employe>& employe) {
    employes_ -= employe;
    return *this;
}

// TODO: Surcharger l'opérateur -= pour retirer un employé par son nom.
// - Retirer l'employé s'il existe dans la liste.
HopitalPoly& HopitalPoly::operator-=(const string &nomEmploye) {
    employes_ -= nomEmploye;
    return *this;
}

bool HopitalPoly::operator==(const HopitalPoly& rhs) const {
	return nom_ == rhs.nom_;
}

// TODO: Implémenter la méthode coutSalarialTotal.
// - Calculer le salaire total de tous les employés de l'hôpital.
float HopitalPoly::coutSalarialTotal() const {
    float salaire = 0;
    for (unsigned i = 0; i < employes_.size(); i++){
        salaire += employes_[i]->calculerSalaire();
    }
    return salaire;
}

// TODO: Implémenter la méthode accueillirPatient.
// - Vous devez utilisez la méthode générique trouverEmployeLibre
// Si le patient n'est pas dans la liste des patients
//      - Assigner une chambre au patient.
//      - l'ajouter dans la liste des patients
//      - incrementer chambreLibre
// - Chercher un infirmier libre
// - Si infirmier existe 
//      -Examiner le patient
//      - Assigner un infirmier au patient.
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

// TODO: Implémenter la méthode traiterPatients.
// - Vous devez utilisez la méthode générique trouverEmployeLibre
// - Traiter les patients en fonction de leur type de soins.
// - Assigner un médecin au patient en fonction du type de soins.
// - Retirer les patients traités de la liste des patients.
// indices: trouver un medecin libre selon le type de soins du patient et le traiter
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

// TODO: Implémenter la méthode chercherEmploye.
// - Rechercher un employé par objet dans la liste des employés.
bool HopitalPoly::chercherEmploye(const shared_ptr<Employe>& employe) const {
    if (employes_.chercher(employe) != -1)
    {
        return  true;
    }
    return false;
}

// TODO: Implémenter la méthode chercherEmploye.
// - Rechercher un employé par nom dans la liste des employés.
bool HopitalPoly::chercherEmploye(const string& nomEmploye) const {
    if (employes_.chercher(nomEmploye) != -1){
        return true;
    }
    return false;
}

// TODO: Implémenter la méthode afficherEmploye.
// - Afficher les informations de tous les employés de l'hôpital.
void HopitalPoly::afficherEmploye(ostream &out) const {
    for (unsigned i = 0; i < employes_.size(); i++)
    {
        out << *employes_[i]<<"\n";
    }
}

// TODO: Implémenter la méthode afficher.
// - Afficher les informations de l'hôpital, y compris la liste des employés.
ostream& HopitalPoly::afficher(ostream &out) const {
    out << "Hôpital: " << nom_ << "\n"
        "Employés: \n";
    afficherEmploye(out);
    return out;
}

// TODO: Surcharger l'opérateur << pour afficher les informations de l'hôpital.
ostream &operator<<(ostream &o, const HopitalPoly &h) {
    h.afficher(o);
    return o;
}
