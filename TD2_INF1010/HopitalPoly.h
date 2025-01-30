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
#include <memory>
using namespace std;

class HopitalPoly
{
public:
	// Constructeur par defaut
	HopitalPoly(const string & nom);
	
	string  getNom() const;
	vector<shared_ptr<Medecin>>  getMedecins() const;
	vector<shared_ptr<Infirmier>> getInfirmiers() const;
    void  setNom( string  nom);
	// Methodes publiques
	bool chercherMedecin(const shared_ptr<Medecin> &medecin)const;
	HopitalPoly &operator+=(const shared_ptr<Medecin> &medecin);
	HopitalPoly &operator+=(const shared_ptr<Infirmier> &infirmier);
	HopitalPoly &operator+=(const HopitalPoly &);
	HopitalPoly &operator-=(const shared_ptr<Medecin> &medecin);
	HopitalPoly &operator-=(const shared_ptr<Infirmier> &infirmier);
	HopitalPoly &operator-=(string &medecin);
	bool operator==(const HopitalPoly &rhs) const;
    bool chercherInfirmier(const shared_ptr<Infirmier> &infirmier)const;

    void afficherMedecins(ostream &out) const;
    void afficherInfirmiers(ostream &out) const;
	ostream& afficher(ostream &out) const;

	friend ostream &operator<<(ostream &o, const HopitalPoly &c);
	// Constructeur de copie
	HopitalPoly(const HopitalPoly &h);


private:
	// attributs prives
    string nom_;
	vector<shared_ptr<Infirmier>> tableauInfirmiers_;	
	vector<shared_ptr<Medecin>>   tableauMedecins_;
};
