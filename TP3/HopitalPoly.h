/**********************************************
 * Titre: Travail pratique #1 - HopitalPoly.h
 * Date:
 * Auteur: 
 *********************************************/

#pragma once

#include <string>
#include <vector>
#include "Employe.h"
#include "Medecin.h"
#include "Pediatre.h"
#include "Chirurgien.h"
#include "Cardiologue.h"
#include "Liste.h"
#include "Infirmier.h"
#include "Patient.h"
#include <memory>
#include <iostream>
using namespace std;

class HopitalPoly
{
public:
	HopitalPoly(const string & nom);
	// Constructeur de copie
	HopitalPoly(const HopitalPoly &h);
	
	string  getNom() const;
	const Liste<shared_ptr<Employe>>& getEmployes() const;
	const Liste<shared_ptr<Patient>>& getPatients() const;
    void  setNom( string  nom);

	HopitalPoly &operator+=(const shared_ptr<Employe>& employe);
	HopitalPoly &operator+=(const HopitalPoly &);
	
	HopitalPoly &operator-=(const shared_ptr<Employe>& employe);
	HopitalPoly &operator-=(const string &nomEmploye);
	bool operator==(const HopitalPoly &rhs) const;


	// TODO: Parcourir la liste des employés pour trouver un employé disponible du type T.
    // - Utiliser dynamic_pointer_cast pour vérifier si l'employé est du type T.
    // - Vérifier si l'employé n'a pas de patient assigné.
    // - Retourner un shared_ptr vers l'employé trouvé.
    // - Si aucun employé disponible n'est trouvé, retourner nullptr.
	template<typename T>
	shared_ptr<T> trouverEmployeLibre() {
		return nullptr;
	}

	float coutSalarialTotal() const;

	void accueillirPatient(shared_ptr<Patient>& patient);
	void traiterPatients();

    bool chercherEmploye(const shared_ptr<Employe>& employe)const;
	bool chercherEmploye(const string& nomEmploye) const;

    void afficherEmploye(ostream &out) const;
	ostream& afficher(ostream &out) const;

	friend ostream &operator<<(ostream &o, const HopitalPoly &c);

private:
	// attributs prives
    string nom_;
	int chambreLibre_;
	Liste<shared_ptr<Employe>> employes_;
	Liste<shared_ptr<Patient>> patients_;
};
