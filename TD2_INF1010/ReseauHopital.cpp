#include "HopitalPoly.h"
#include <iostream>
#include "ReseauHopital.h"

ReseauHopital::ReseauHopital(const string & nom):nom_(nom) {
}

string  ReseauHopital::getNom() const
{ return nom_;}

void  ReseauHopital::setNom(const string & nom)
{ nom_ = nom;}

size_t  ReseauHopital::getNumbHospitals()
{ return tableauHopitaux_.size();}

ostream& ReseauHopital::afficher(ostream& out) const {
	out << "Nom du reseau d'hopital: " << nom_ << endl;
	for (int i = 0; i < tableauHopitaux_.size(); i++) {
		tableauHopitaux_[i]->afficher(out);
	}
	return out;
}

bool ReseauHopital::chercherHopital(const HopitalPoly* hopital) const {
	for (auto &temp : tableauHopitaux_) {
		if (*temp == *hopital) {
			return true;
		}
	}
	return false;
}

ReseauHopital& ReseauHopital::operator+=(unique_ptr<HopitalPoly>& hopital) {
	if (!chercherHopital(hopital.get())) {
		tableauHopitaux_.push_back(move(hopital));
	}
	return *this;
}

ReseauHopital& ReseauHopital::operator-=(string& nomHopital) {
	for (int i = 0; i < tableauHopitaux_.size(); i++) {
		if (tableauHopitaux_[i]->getNom() == nomHopital) {
			tableauHopitaux_[i] = move(tableauHopitaux_.back());
			tableauHopitaux_.pop_back();
			return *this;
		}
	}
	return *this;
}

ostream& operator<<(ostream& o, const ReseauHopital& c) {
	return c.afficher(o);
}

