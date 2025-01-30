/**********************************************
 * Titre: Travail pratique #1 - HopitalPoly.cpp
 * Date: 
 * Auteur: 
 *********************************************/



#include "Medecin.h"
#include "Infirmier.h"
#include "HopitalPoly.h"
#include <iostream>
#include "Const.h"
HopitalPoly::HopitalPoly(const string & nom) {
	nom_ = nom;
}
string  HopitalPoly::getNom() const
{  
	return nom_;
}
vector<Medecin*> HopitalPoly:: getMedecins() const
{ 
	return tableauMedecins_;
}

vector<Infirmier*> HopitalPoly::getInfirmiers() const
{ 
	return tableauInfirmiers_;
}
void  HopitalPoly::setNom( string  nom)
{ 
	nom_ = nom;
}
	// Methodes publiques
bool HopitalPoly::chercherMedecin(const Medecin * unMedecin)const
{
	for (Medecin* medecin : tableauMedecins_) {
		if (medecin->getNom() == unMedecin->getNom()) {
			return true;
		}
	}
	return false;
}

void HopitalPoly::ajouterMedecin( Medecin * unMedecin)
{
	for(Medecin* medecin : tableauMedecins_)
		if (medecin->getNom() == unMedecin->getNom()) {
			return;
	}
	tableauMedecins_.push_back(unMedecin);
}
void HopitalPoly::supprimerMedecin(const Medecin * unMedecin)
{
	for (int i = 0; i < tableauMedecins_.size(); i++) {
		if (tableauMedecins_[i]->getNom() == unMedecin->getNom()) {
			tableauMedecins_.erase(tableauMedecins_.begin() + i);
			return;
		}
	}
}

bool HopitalPoly::chercherInfirmier(const Infirmier * unInfirmier)const
{ 
	for (Infirmier* infirmier: tableauInfirmiers_) {
		if (infirmier->getNom() == unInfirmier->getNom()) {
			return true;
		}
	}
	return false;
}

void HopitalPoly::ajouterInfirmier(Infirmier * unInfirmier)
{
	for (Infirmier* infirmier : tableauInfirmiers_) {
		if (infirmier->getNom() == unInfirmier->getNom()) {
			return;
		}
	}
	tableauInfirmiers_.push_back(unInfirmier);
}
void HopitalPoly::supprimerInfirmier(const Infirmier * unInfirmier)
{
	for (int i = 0; i < tableauInfirmiers_.size(); i++) {
		if (tableauInfirmiers_[i]->getNom() == unInfirmier->getNom()) {
			tableauInfirmiers_.erase(tableauInfirmiers_.begin() + i);
			return;
		}
	}
}

void HopitalPoly:: afficherMedecins(ostream &out) const
{ 
	for (Medecin* medecin : tableauMedecins_) {
		medecin->afficher(out);
	}
}
void HopitalPoly::afficherInfirmiers(ostream &out) const
{
	for (Infirmier *infirmier : tableauInfirmiers_) {
		infirmier->afficher(out);
	}
}
ostream &HopitalPoly::afficher(ostream &out) const{
	out << "Nom de l'Hopital: " << nom_ << "\n" <<
		"Liste des infirmiers:\n";
	afficherInfirmiers(out);
	out << "Liste des medecins:\n";
	afficherMedecins(out);
	return out;
}