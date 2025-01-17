/**********************************************
 * Titre: Travail pratique #1 - HopitalPoly.h
 * Date:
 * Auteur: 
 *********************************************/

#pragma once

#include <string>
#include <vector>
#include "Medecin.h"
#include "Infirmier.h"
using namespace std;

class HopitalPoly
{
public:
	// Constructeur par defaut
	HopitalPoly(const string & nom);
	
	string  getNom() const;
	vector<Medecin*>  getMedecins() const;
	vector<Infirmier*> getInfirmiers() const;
    void  setNom( string  nom);
	// Methodes publiques
	bool chercherMedecin(const Medecin * unMedecin)const;
	void ajouterMedecin(Medecin * unMedecin);
	void supprimerMedecin(const Medecin * unMedecin);

    bool chercherInfirmier(const Infirmier * unInfirmier)const;
	void ajouterInfirmier(Infirmier * unInfirmier);
	void supprimerInfirmier(const Infirmier * unInfirmier);

    void afficherMedecins(ostream &out) const;
    void afficherInfirmiers(ostream &out) const;
	ostream& afficher(ostream &out) const;
	
private:
	// attributs prives
    string nom_;	
	vector<Medecin*>   tableauMedecins_;
	vector<Infirmier*> tableauInfirmiers_;
};
