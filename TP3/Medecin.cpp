/********************************************
 * Titre: Travail pratique #1 - Medecin.cpp
 * Date: 25 aout 2012
 * Auteur: 
 *******************************************/

#include"Medecin.h"

Medecin::Medecin(const string& nom, Specialite * uneSpecialite): Employe(nom), specialite_(uneSpecialite){}

Specialite * Medecin::getSpecialite() const
{
	return specialite_;
}

const shared_ptr<Patient> Medecin::getPatient() const{
    return patient_;
}
 
void Medecin::setSpecialite(Specialite * specialite)
{
	specialite_ = specialite;
}

void Medecin::setPatient(const shared_ptr<Patient>& p){
    patient_ = p;
}

ostream &Medecin::afficher(ostream &out) const
{  
	Employe::afficher(out);
    if (specialite_ != nullptr) {
        specialite_->afficher(out);
    } else {
        out << "Specialite: Non assignee" << endl;
    }
	return out;
}

// TODO: Surcharger l'opérateur == pour comparer deux médecins.
// - Comparer les noms, les domaines et les niveaux des spécialités des médecins.
bool Medecin::operator==(const Medecin &rhs) const{
    
}