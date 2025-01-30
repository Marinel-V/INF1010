#pragma once
#include <string>
using namespace std;
class Specialite
{
public:
	Specialite();
	Specialite(const string & domaine, unsigned int niveau);

	string getDomaine() const;
	unsigned int getNiveau() const;

	void setDomaine(const string& domaine);
	void setNiveau(unsigned int niveau);

	ostream& afficher(ostream &out) const;

private:
	string domaine_;
	unsigned niveau_;
};
