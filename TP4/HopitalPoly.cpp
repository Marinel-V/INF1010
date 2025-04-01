#include "HopitalPoly.h"
#include <algorithm>
#include <functional>
HopitalPoly::HopitalPoly(const string & nom) : nom_(nom), chambreLibre_(0) {}

string HopitalPoly::getNom() const {
    return nom_;
}

const vector<shared_ptr<Employe>>& HopitalPoly::getEmployes() const {
	return employes_;
}

const vector<shared_ptr<Patient>>& HopitalPoly::getPatients() const {
    return patients_;
}

void HopitalPoly::setNom(string nom) {
    nom_ = nom;
}

HopitalPoly& HopitalPoly::operator+=(const shared_ptr<Employe>& employe) {
	employes_.push_back(employe);
    return *this;
}

HopitalPoly& HopitalPoly::operator+=(const shared_ptr<Patient>& patient) {
	patients_.push_back(patient);
    return *this;
}

bool HopitalPoly::operator==(const HopitalPoly& rhs) const {
	return nom_ == rhs.nom_;
}


// TODO: compléter la méthode trouverPatientParTypeSoins pour qu'elle retourne un map de  patient par catégorie de type de soin, ne pas utiliser de for loop et utiliser les algorithmes de la STL
map<TypeSoins, vector<shared_ptr<Patient>>> HopitalPoly::trouverPatientParTypeSoins()
{
    map<TypeSoins, vector<shared_ptr<Patient>>> mapTypesSoins;
    for_each(patients_.begin(), patients_.end(), 
        [&mapTypesSoins](const shared_ptr<Patient>& patient)
        {
            TypeSoins cle = patient->getTypeSoins();
            mapTypesSoins[cle].push_back(patient);
        });
    return mapTypesSoins;
}

// TODO: compléter la méthode getMedecinParCritere pour qu'elle retourne un set de Medecin qui respecte le critère, ne pas utiliser de for loop et utiliser les algorithmes de la STL

set<shared_ptr<Medecin>, ComparerPersonne<Medecin>> HopitalPoly::getMedecinParCritere(function<bool(const shared_ptr<Medecin>&)> critere) const {
    set<shared_ptr<Medecin>, ComparerPersonne<Medecin>> setMedecins;
    copy_if(employes_.begin(), employes_.end(), inserter(setMedecins, setMedecins.begin()), dynamic_pointer_cast<Employe, Medecin>(&critere));
    return setMedecins;
}

// TODO: compléter la méthode listersi pour qu'elle retourne un pointeur sur le premier medecin qui respecte le critère
Medecin *HopitalPoly::listersi(const function<bool(const Employe &employe)> &critere) const
{
    return dynamic_cast<Medecin*>(find_if(employes_.begin(), employes_.end(), critere)->get());
}

// TODO: compléter la méthode ajouterPatientAuMedecin pour qu'elle ajoute un patient à un medecin dans la map medecinTousPatients_, ne pas utiliser de for loop et utiliser les algorithmes de la STL
void HopitalPoly::ajouterPatientAuMedecin(string &id,const shared_ptr<Patient> &patient){
    Medecin* med = listersi(([id](const Employe &employe) {return id == employe.getId(); }));
    medecinTousPatients_[med].emplace(patient);
}

unordered_map<Medecin *, set<shared_ptr<Patient>, ComparerPersonne<Patient>>, HashEmploye> HopitalPoly::getPatientsParMedecin()
{
	return medecinTousPatients_;
}

// TODO: compléter la méthode getSalaireTotal pour qu'elle retourne le salaire total dans l'hopital, ne pas utiliser de for loop et utiliser les algorithmes de la STL
float HopitalPoly::getSalaireTotal() const {
    return float(accumulate(employes_.begin(), employes_.end(), 0, [](const shared_ptr<Employe> &employe, int somme)
    {
            return employe->calculerSalaire() + somme;
    }));
}

// TODO: afficher les employes, ne pas utiliser de for loop et utiliser les algorithmes de la STL
void HopitalPoly::afficherEmploye(ostream& out) const {
    for_each(employes_.begin(), employes_.end(), [this, &out](const shared_ptr<Employe> &employe) {
        afficher(out);
        });
}

ostream& HopitalPoly::afficher(ostream &out) const {
    out << "Hopital: " << nom_ << endl;
    out << "Employes: " << endl;
    afficherEmploye(out);
    return out;
}

ostream &operator<<(ostream &o, const HopitalPoly &h) {
    return h.afficher(o);
}
