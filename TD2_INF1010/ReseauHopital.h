#pragma once
#include <string>
#include <vector>
#include "HopitalPoly.h"
#include <memory>
using namespace std;
class ReseauHopital
{
public:
	ReseauHopital(const string& nom ="Inconnu");
	string getNom() const;
	void setNom(const string& nom);

    size_t getNumbHospitals();

    ostream& afficher(ostream &out) const;
    bool chercherHopital(const HopitalPoly* hopital) const;
	ReseauHopital &operator+=(unique_ptr<HopitalPoly> &hopital);
	ReseauHopital &operator-=(string &nomHopital);
    friend ostream & operator<<(ostream &o, const ReseauHopital &c);
private:
    string nom_;
	vector<unique_ptr<HopitalPoly>> tableauHopitaux_;
};
