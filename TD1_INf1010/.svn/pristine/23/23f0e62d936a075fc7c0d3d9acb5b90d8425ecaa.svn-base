#include "Infirmier.h"
#include <iostream>
#include "Const.h"
#include <vector>

Infirmier::Infirmier(const string& nom, const std::string& prenom, const float& tauxHoraire)
{
	nom_ = nom;
	prenom_ = prenom;
	tauxHoraire_ = tauxHoraire;
	totalChambres_ = 0;
	heuresTravaillees_ = 0;
}

string Infirmier::getNom() const
{
	return nom_;
}

string Infirmier::getPrenom() const
{
	return prenom_;
}

float Infirmier::getTauxHoraire() const {
	return tauxHoraire_;
}

int Infirmier::getTotalChambres() const {
	return listChambres_.size();
}

vector<string> Infirmier::getChambre() const
{
	return listChambres_;
}

void Infirmier::setNom(const string& nom)
{
	nom_ = nom;
}

void Infirmier::setPrenom(const string& prenom)
{
	prenom_ = prenom;
}

void Infirmier::setTauxHoraire(const float& taux)
{
	tauxHoraire_ = taux;
}

bool Infirmier::chercherChambre(const string& nbChambre) {
	for (string chambre : listChambres_) {
		if (chambre == nbChambre) {
			return false;
		}
	}
	return true;
}
void Infirmier::ajouterChambre(const string& nbChambre) {
	for (string chambre : listChambres_) {
		if (chambre == nbChambre) {
			return;
		}
	}
	listChambres_.push_back(nbChambre);
	totalChambres_++;
}

void Infirmier::retirerChambre(const string& nbChambre) {
	for (int i = 0; i < listChambres_.size(); i++) {
		if (listChambres_[i] == nbChambre) {
			listChambres_.erase(listChambres_.begin() + i);
			totalChambres_++;
		}
	}
}

unsigned Infirmier::getHeuresTravaillees() const {
	return heuresTravaillees_;
}
void Infirmier::ajouterHeuresTravaillees(unsigned heures) {
	heuresTravaillees_ += heures;
}

float  Infirmier::calculerSalaire() {
	float salaire = (heuresTravaillees_* tauxHoraire_ + (totalChambres_ * tauxHoraire_ / 20.0));
	heuresTravaillees_ = 0;
	return salaire;
}

ostream& Infirmier::afficher(ostream& out) const
{
	out << "Nom: " << nom_ << "\n" <<
		"Prenom: " << prenom_ << "\n" <<
		"Taux horaire: " << tauxHoraire_ << " $/h" << "\n" <<
		"Heures travaillees: " << heuresTravaillees_ << " heures" << "\n" <<
		"Total chambres gerees: " << totalChambres_ << "\n" <<
		"Liste des chambres: ";
	for (string chambre : listChambres_) {
		out << chambre << " ";
	}
	out << "\n";
	return out;
}