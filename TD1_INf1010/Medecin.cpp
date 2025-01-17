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
	//check si dois initialiser specialiste
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
	return salaire_ * specialite_->getNiveau();
} 
ostream &Medecin::afficher(ostream &out) const
{  
	out << "";
}

