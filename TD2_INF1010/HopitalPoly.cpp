/**********************************************
 * Titre: Travail pratique #1 - HopitalPoly.cpp
 * Date: 10 janvier 2017
 * Auteur: 
 *********************************************/



#include "Medecin.h"
#include "Infirmier.h"
#include "HopitalPoly.h"
#include <iostream>
HopitalPoly::HopitalPoly(const string & nom):nom_(nom) {
}
string  HopitalPoly::getNom() const
{ return nom_;}
vector<shared_ptr<Medecin>> HopitalPoly:: getMedecins() const
{ return tableauMedecins_;}

vector<shared_ptr<Infirmier>> HopitalPoly::getInfirmiers() const
{ return tableauInfirmiers_;}
void  HopitalPoly::setNom( string  nom)
{ nom_ = nom;}
	// Methodes publiques
bool HopitalPoly::chercherMedecin(const shared_ptr<Medecin> &medecin)const
{
	 for ( auto med: tableauMedecins_)
	   if (*med == *medecin)
	      return true;
    return false;		  
}

HopitalPoly& HopitalPoly::operator+=(const shared_ptr<Medecin>& medecin) {
	if (!chercherMedecin(medecin)) {

		tableauMedecins_.push_back(medecin);
	}
	return *this;
}

HopitalPoly& HopitalPoly::operator+=(const shared_ptr<Infirmier>& infirmier) {
	if (!chercherInfirmier(infirmier)) {
		tableauInfirmiers_.push_back(infirmier);
	}
	return *this;
}

HopitalPoly& HopitalPoly::operator+=(const HopitalPoly& hopital) {
	for (shared_ptr<Infirmier> infirmier : hopital.tableauInfirmiers_) {
		*this += infirmier;
	}
	for (shared_ptr<Medecin> medecin : hopital.tableauMedecins_) {
		*this += medecin;
	}
	return *this;
}

HopitalPoly& HopitalPoly::operator-=(const shared_ptr<Medecin>& medecin) {
	for (int i = 0; i < tableauMedecins_.size(); i++) {
		if (tableauMedecins_[i] == medecin) {
			tableauMedecins_[i] = tableauMedecins_.back();
			tableauMedecins_.pop_back();
			return *this;
		}
	}
	return *this;
}

HopitalPoly& HopitalPoly::operator-=(const shared_ptr<Infirmier>& infirmier) {
	for (int i = 0; i < tableauInfirmiers_.size(); i++) {
		if (tableauInfirmiers_[i] == infirmier) {
			tableauInfirmiers_[i] = tableauInfirmiers_.back();
			tableauInfirmiers_.pop_back();
			return *this;
		}
	}
	return *this;
}

HopitalPoly& HopitalPoly::operator-=(string& medecin) {
	for (int i = 0; i < tableauMedecins_.size(); i++) {
		if (tableauMedecins_[i]->getNom() == medecin) {
			tableauMedecins_[i] = tableauMedecins_.back();
			tableauMedecins_.pop_back();
			return *this;
		}
	}
	return *this;
}

bool HopitalPoly::operator==(const HopitalPoly& rhs) const {
	return nom_ == rhs.nom_;
}

bool HopitalPoly::chercherInfirmier(const shared_ptr<Infirmier> &infirmier)const
{ 
	for ( auto med: tableauInfirmiers_)
	   if (*med == *infirmier)
	      return true;
    return false;	
}


void HopitalPoly:: afficherMedecins(ostream &out) const
{ 
	for (unsigned i = 0 ; i < tableauMedecins_.size(); i++){
		tableauMedecins_[i]->afficher(out);
	}
}
void HopitalPoly::afficherInfirmiers(ostream &out) const
{
	for ( unsigned i = 0 ; i < tableauInfirmiers_.size(); i++){
		tableauInfirmiers_[i]->afficher(out);
	}
}
ostream &HopitalPoly::afficher(ostream &out) const{
	out << "Nom de l'Hopital: " << nom_ << endl;
	out <<"Liste des infirmiers:"<< endl;
	this->afficherInfirmiers(out);
	out <<"Liste des medecins:"<< endl;
	this->afficherMedecins(out);
	return out;
}

ostream& operator<<(ostream& o, const HopitalPoly& c) {
	o << "Nom de l'Hopital: " << c.nom_ << endl;
	o << "Liste des infirmiers:" << endl;
	c.afficherInfirmiers(o);
	o << "Liste des medecins:" << endl;
	c.afficherMedecins(o);
	return o;
}

HopitalPoly::HopitalPoly(const HopitalPoly& h) {
	nom_ = h.nom_;
	for (shared_ptr<Infirmier> infirmier : h.tableauInfirmiers_) {
		tableauInfirmiers_.push_back(infirmier);
	}
	for (shared_ptr<Medecin> medecin : h.tableauMedecins_) {
		tableauMedecins_.push_back(medecin);
	}
}

