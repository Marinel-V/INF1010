/********************************************
 * Titre: Travail pratique #1 - Medecin.h
 * Date:
 * Auteur: 
 *******************************************/

#pragma once

#include <string>
#include "Specialite.h"

using namespace std;

class Medecin 
{
public:
	// Constructeurs par defaut et par parametre
	Medecin(const string& nom);
	Medecin(const string& nom,Specialite * uneSpecialite, float salaire);

	// Methodes d'acces
	string getNom() const;
	Specialite * getSpecialite() const;
	
	// Methodes de modification
	void setNom(const string& nom);
	void setSpecialite(Specialite* specialite);
    float calculerSalaire() const;
	ostream &afficher(ostream &out) const;

private:
	// attributs prives
	string nom_;
	Specialite* specialite_;
	float salaire_;
};
