#include "Specialite.h"
#include <iostream>
#include "Const.h"

Specialite::Specialite()
{
	domaine_ = "";
	niveau_ = 0;
}

Specialite::Specialite(const string & domaine, unsigned niveau)
{ 
	domaine_ = domaine;
	niveau_ = niveau;
}

std::string Specialite::getDomaine() const
{
	return domaine_;
}

unsigned int Specialite::getNiveau() const
{
	return niveau_;
}

void Specialite::setDomaine(const std::string & domaine)
{
	domaine_ = domaine;
}

void Specialite::setNiveau(unsigned int niveau)
{
	niveau_ = niveau;
}

ostream &Specialite::afficher(ostream &out) const
{
	//  todo
}
