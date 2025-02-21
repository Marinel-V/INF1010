#include "HopitalPoly.h"

// TODO: Implémenter le constructeur de HopitalPoly.
// - Initialiser le nom de l'hôpital avec la valeur passée en paramètre.
// - Initialiser chambreLibre_ à 0.
HopitalPoly::HopitalPoly(const string & nom) : {}

// TODO: Implémenter le constructeur de copie de HopitalPoly.
// - Copier le nom et chambreLibre_ de l'hôpital passé en paramètre.
// - Ajouter tous les employés de l'hôpital passé en paramètre.
HopitalPoly::HopitalPoly(const HopitalPoly &h) : {
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
    
}

// TODO: Surcharger l'opérateur += pour ajouter tous les employés d'un autre hôpital.
// - Vérifier que les employés n'existent pas déjà avant de les ajouter.
HopitalPoly& HopitalPoly::operator+=(const HopitalPoly &h) {
    
}

// TODO: Surcharger l'opérateur -= pour retirer un employé de l'hôpital.
// - Retirer l'employé s'il existe dans la liste.
HopitalPoly& HopitalPoly::operator-=(const shared_ptr<Employe>& employe) {
    
}

// TODO: Surcharger l'opérateur -= pour retirer un employé par son nom.
// - Retirer l'employé s'il existe dans la liste.
HopitalPoly& HopitalPoly::operator-=(const string &nomEmploye) {
    
}

bool HopitalPoly::operator==(const HopitalPoly& rhs) const {
	return nom_ == rhs.nom_;
}

// TODO: Implémenter la méthode coutSalarialTotal.
// - Calculer le salaire total de tous les employés de l'hôpital.
float HopitalPoly::coutSalarialTotal() const {
    
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
    
}

// TODO: Implémenter la méthode traiterPatients.
// - Vous devez utilisez la méthode générique trouverEmployeLibre
// - Traiter les patients en fonction de leur type de soins.
// - Assigner un médecin au patient en fonction du type de soins.
// - Retirer les patients traités de la liste des patients.
// indices: trouver un medecin libre selon le type de soins du patient et le traiter
void HopitalPoly::traiterPatients() {
}

// TODO: Implémenter la méthode chercherEmploye.
// - Rechercher un employé par objet dans la liste des employés.
bool HopitalPoly::chercherEmploye(const shared_ptr<Employe>& employe) const {
    return false;
}

// TODO: Implémenter la méthode chercherEmploye.
// - Rechercher un employé par nom dans la liste des employés.
bool HopitalPoly::chercherEmploye(const string& nomEmploye) const {
    
}

// TODO: Implémenter la méthode afficherEmploye.
// - Afficher les informations de tous les employés de l'hôpital.
void HopitalPoly::afficherEmploye(ostream &out) const {
}

// TODO: Implémenter la méthode afficher.
// - Afficher les informations de l'hôpital, y compris la liste des employés.
ostream& HopitalPoly::afficher(ostream &out) const {
    return out;
}

// TODO: Surcharger l'opérateur << pour afficher les informations de l'hôpital.
ostream &operator<<(ostream &o, const HopitalPoly &h) {
    return o;
}
