#include "Infirmier.h"
#include <iostream>

Infirmier::Infirmier(const string & nom, 
                    const std::string & prenom, 
					const float & tauxHoraire):
					 nom_(nom), prenom_(prenom), tauxHoraire_(tauxHoraire)
{  
    heuresTravaillees_  = 0;
}

string Infirmier::getNom() const
{
	return nom_;
}

string Infirmier::getPrenom() const
{
	return prenom_;
}

float Infirmier::getTauxHoraire() const{
	 return tauxHoraire_;
}

vector<string> Infirmier::getChambre() const
{ 
    return listChambres_;
}

void Infirmier::setNom(const string & nom)
{
	nom_ = nom;
}

void Infirmier::setPrenom (const string & prenom)
{
	prenom_ = prenom;
}

void Infirmier::setTauxHoraire (const float & taux)
{
	tauxHoraire_ = taux;
}

bool Infirmier::chercherChambre (const string & nbChambre) const{
   for (auto ch : listChambres_)
       if ( ch == nbChambre)
	       return true;
	return false;	   
}


unsigned Infirmier::getHeuresTravaillees() const{
 return heuresTravaillees_;
}
void Infirmier::ajouterHeuresTravaillees(unsigned heures){
  heuresTravaillees_+= heures;
}  
  
float  Infirmier::calculerSalaire() {
	float salaire = heuresTravaillees_ * tauxHoraire_ + listChambres_.size() * tauxHoraire_/20.0;
	heuresTravaillees_ = 0.0;
	return  salaire;
}

ostream &Infirmier::afficher(ostream &out) const
{
	out << "Nom: " << nom_ << endl;
    out << "Prenom: " << prenom_ << endl;
    out << "Taux horaire: " << tauxHoraire_ << " $/h" << endl;
    out << "Heures travaillees: " << heuresTravaillees_ << " heures" << endl;
    out << "Total chambres gerees: " << listChambres_.size() << endl;

    out << "Liste des chambres: ";
    if (listChambres_.empty()) {
        out << "Aucune chambre assignee.";
    } else {
        for (const auto& chambre : listChambres_) {
            out << chambre << " ";
        }
    }
    out << endl;
    return out;
}

    ostream& operator<<(ostream& out, const Infirmier& b) {
        out << "Nom: " << b.nom_ << endl;
        out << "Prenom: " << b.prenom_ << endl;
        out << "Taux horaire: " << b.tauxHoraire_ << " $/h" << endl;
        out << "Heures travaillees: " << b.heuresTravaillees_ << " heures" << endl;
        out << "Total chambres gerees: " << b.listChambres_.size() << endl;

        out << "Liste des chambres: ";
        if (b.listChambres_.empty()) {
            out << "Aucune chambre assignee.";
        }
        else {
            for (const auto& chambre : b.listChambres_) {
                out << chambre << " ";
            }
        }
        out << endl;
        return out;
    }

    Infirmier Infirmier::operator+(const string& nbChambre) const {
        Infirmier infirmier = *this;
        if (!chercherChambre(nbChambre)) {
            infirmier.listChambres_.push_back(nbChambre);
        }
        return infirmier;
    }

    Infirmier Infirmier::operator-(const string& nbChambre) const {
        Infirmier infirmier = *this;
        for (int i = 0; i < infirmier.listChambres_.size(); i++) {
            if (infirmier.listChambres_[i] == nbChambre) {
                infirmier.listChambres_[i] = infirmier.listChambres_.back();
                infirmier.listChambres_.pop_back();
                return infirmier;
            }
        }
        return infirmier;
    }

    bool Infirmier::operator==(const Infirmier& rhs) const {
        return nom_ == rhs.nom_ &&
            prenom_ == rhs.prenom_ &&
            tauxHoraire_ == rhs.tauxHoraire_ &&
            listChambres_ == rhs.listChambres_ &&
            heuresTravaillees_ == rhs.heuresTravaillees_;
    }

    Infirmier::Infirmier(const Infirmier& a) {
        nom_ = a.nom_;
        prenom_ = a.prenom_;
        tauxHoraire_ = a.tauxHoraire_;
        listChambres_ = a.listChambres_;
        heuresTravaillees_ = a.heuresTravaillees_;
    }



