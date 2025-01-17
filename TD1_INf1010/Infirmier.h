#pragma once
#include <string>
#include <vector>
using namespace std;
class Infirmier
{
public:
	Infirmier(const string& nom ="Inconnu", 
	          const string& prenom ="Inconnu", 
			  const float & tauxHoraire =0.0);

	string getNom() const;
	string getPrenom() const;
    float getTauxHoraire() const;
	int getTotalChambres() const;
	vector<string> getChambre() const;

	void setNom(const string& nom);
	void setPrenom(const string& prenom);
    void setTauxHoraire (const float & tauxHoraire);

	void ajouterChambre(const string & nbChambre);
	void retirerChambre (const string & nbChambre);
    bool chercherChambre (const string & nbChambre);
    
	unsigned getHeuresTravaillees() const;
	void ajouterHeuresTravaillees(unsigned heures);
  
    
	float  calculerSalaire();
	
	ostream& afficher(ostream &out) const;

private:
	string nom_;
	string prenom_;
	float tauxHoraire_;
	vector<string> listChambres_;
	unsigned totalChambres_;
	unsigned heuresTravaillees_;
};


