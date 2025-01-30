/********************************************
 * Titre: Travail pratique #1 - Medecin.cpp
 * Date: 25 aout 2012
 * Auteur: 
 *******************************************/

#include"Medecin.h"
#include <iostream>

Medecin::Medecin(const string& nom):nom_(nom), salaire_(0),specialite_(nullptr)
{
}

Medecin::Medecin(const string& nom, float salaire, Specialite * uneSpecialite): 
nom_(nom), salaire_(salaire), specialite_(uneSpecialite)
{
}

string Medecin::getNom() const
{
	return nom_;
}

Specialite * Medecin::getSpecialite() const
{
	return specialite_;
}

void Medecin::setNom(const string& nom)
{
	nom_ = nom;
}
 
void Medecin::setSpecialite( Specialite * specialite)
{
	specialite_ = specialite;
}
float Medecin::calculerSalaire() const{
	  if  (specialite_ != nullptr) 
	 		return salaire_ * specialite_->getNiveau();
	   else
	       return salaire_;	
} 
ostream &Medecin::afficher(ostream &out) const
{  
	out << "Nom: " << nom_ << endl;
    if (specialite_ != nullptr) {
        specialite_->afficher(out);
    } else {
        out << "Specialite: Non assignee" << endl;
    }

    out << "Salaire: " << this->calculerSalaire() << " $" << endl;
	return out;
}
ostream& operator<<(ostream& out, const Medecin& b) {
	out << "Nom: " << b.nom_ << endl;
	if (b.specialite_ != nullptr) {
		b.specialite_->afficher(out);
	}
	else {
		out << "Specialite: Non assignee" << endl;
	}

	out << "Salaire: " << b.calculerSalaire() << " $" << endl;
	return out;
}

bool Medecin::operator==(const Medecin& rhs) const{
	return nom_ == rhs.nom_ &&
		salaire_ == rhs.salaire_ &&
		specialite_ == rhs.specialite_;
}

Medecin::Medecin(const Medecin& a) {
	nom_ = a.nom_;
	salaire_ = a.salaire_;
	specialite_ = a.specialite_;
}

