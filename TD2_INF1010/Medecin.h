/********************************************
 * Titre: Travail pratique #1 - Medecin.h
 * Date:
 * Auteur: 
 *******************************************/

#pragma once

#include <string>
#include "Specialite.h"

using namespace std;

//const unsigned int NB_MEDECIN = 6;

class Medecin 
{
public:
	// Constructeurs par defaut et par parametre
	Medecin(const string& nom);
	Medecin(const string& nom, float salaire, Specialite* uneSpecialite);

	// Methodes d'acces
	string getNom() const;
	Specialite * getSpecialite() const;
	
	// Methodes de modification
	void setNom(const string& nom);
	void setSpecialite(Specialite* specialite);
    float calculerSalaire() const;
	ostream &afficher(ostream &out) const;

	friend ostream &operator<<(ostream &out, const Medecin &b);
	bool operator==(const Medecin &rhs) const;

	// Constructeur de copie
	Medecin(const Medecin &a);

private:
	// attributs prives
	string nom_;
	float salaire_;
	Specialite* specialite_;
};
