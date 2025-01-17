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
	// todo
}
string  HopitalPoly::getNom() const
{  // todo
}
vector<Medecin*> HopitalPoly:: getMedecins() const
{ // todo
}

vector<Infirmier*> HopitalPoly::getInfirmiers() const
{ // todo
}
void  HopitalPoly::setNom( string  nom)
{ // todo
}
	// Methodes publiques
bool HopitalPoly::chercherMedecin(const Medecin * unMedecin)const
{
	// todo	  
}

void HopitalPoly::ajouterMedecin( Medecin * unMedecin)
{
	// todo

}
void HopitalPoly::supprimerMedecin(const Medecin * unMedecin)
{
	 // todo
}

bool HopitalPoly::chercherInfirmier(const Infirmier * unInfirmier)const
{  // todo
}

void HopitalPoly::ajouterInfirmier(Infirmier * unInfirmier)
{
	// todo

}
void HopitalPoly::supprimerInfirmier(const Infirmier * unInfirmier)
{
	 // todo
}

void HopitalPoly:: afficherMedecins(ostream &out) const
{ 
	// todo 
}
void HopitalPoly::afficherInfirmiers(ostream &out) const
{
	 // todo
}
ostream &HopitalPoly::afficher(ostream &out) const{
	// todo
}