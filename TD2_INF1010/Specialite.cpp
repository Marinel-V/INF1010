#include "Specialite.h"
#include <iostream>

Specialite::Specialite(): domaine_(""), niveau_(0)
{
}

Specialite::Specialite(const string & domaine, unsigned niveau):
            domaine_(domaine), niveau_(niveau)
{
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
	out << "Domaine: " << domaine_ << endl;
    out << "Niveau: " << niveau_ << endl;
	return out;
}

ostream& operator<<(ostream& out, const Specialite& b) {
	out << "Domaine: " << b.domaine_ << endl;
	out << "Niveau: " << b.niveau_ << endl;
	return out;
}

bool Specialite::operator==(const Specialite& rhs) const {
	return domaine_ == rhs.domaine_ &&
		niveau_ == rhs.niveau_;
}
Specialite::Specialite(const Specialite& a) {
	domaine_ = a.domaine_;
	niveau_ = a.niveau_;
}

