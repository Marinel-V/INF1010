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
	vector<string> getChambre() const;

	void setNom(const string& nom);
	void setPrenom(const string& prenom);
    void setTauxHoraire (const float & tauxHoraire);

    bool chercherChambre (const string & nbChambre) const;
    
	unsigned getHeuresTravaillees() const;
	void ajouterHeuresTravaillees(unsigned heures);
  
    
	float  calculerSalaire();
	
	ostream& afficher(ostream &out) const;

	friend ostream &operator<<(ostream &out, const Infirmier &b);
	Infirmier operator+(const string & nbChambre) const;
	Infirmier operator-(const string & nbChambre) const;
	bool operator==(const Infirmier &rhs) const;

	// Constructeur de copie
	Infirmier(const Infirmier &a);

private:
	string nom_;
	string prenom_;
	float tauxHoraire_;
	vector<string> listChambres_;
	unsigned heuresTravaillees_;
};


