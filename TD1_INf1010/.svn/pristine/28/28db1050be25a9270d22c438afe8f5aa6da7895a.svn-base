/********************************************
 * Titre: Travail pratique #1 - Medecin.cpp
 * Date: 
 * Auteur: 
 *******************************************/

#include"Medecin.h"
#include <iostream>
#include "Const.h"

Medecin::Medecin(const string& nom)
{
	nom_ = nom;
	specialite_ = nullptr;
	salaire_ = 0;
}

Medecin::Medecin(const string& nom,Specialite * uneSpecialite, float salaire)
{
	nom_ = nom;
	specialite_ = uneSpecialite;
	salaire_ = salaire;
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
	if (specialite_ == nullptr) {
		return salaire_;
	}
	return salaire_ * specialite_->getNiveau();
} 
ostream &Medecin::afficher(ostream &out) const
{  
	/*"Nom: DrOz\n"
		"Domaine: Chirurgie\n"
		"Niveau: 6\n"
		"Salaire: 540000 $\n";*/
	out << "Nom: " << nom_ << "\n" <<
		"Domaine: " << specialite_->getDomaine() << "\n" <<
		"Niveau: " << specialite_->getNiveau() << "\n" <<
		"Salaire: " << calculerSalaire() << " $\n";
	return out;
}

