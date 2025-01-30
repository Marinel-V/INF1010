/**************************************************
 * Titre: Travail pratique #1 - Main.cpp
 * // tests unitaires
**************************************************/

#include "Specialite.h"
#include "Medecin.h"
#include "Infirmier.h"
#include "HopitalPoly.h"
#include "TestSuite.h"
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

int main()
{ 
	TestSuite testSuite;

  	testSuite.require("Creation d'un infirmier", 0.5, [](){
		Infirmier i("Nightingale", "Florence", 10.0);
		assert(i.getNom() == "Nightingale", "Erreur sur le nom");
		assert(i.getPrenom() == "Florence", "Erreur sur le prenom");
		assert(i.getTauxHoraire() == 10.0, "Erreur sur la taux horaire"); });
	
	testSuite.require("Modification des attributs d'un infirmier", 0.5, [](){
		Infirmier i("Doe", "John", 15.0);
		i.setNom("Nightingale");
		i.setPrenom("Florence");
		i.setTauxHoraire(20.0);
		assert(i.getNom() == "Nightingale", "Erreur sur la modification du nom");
		assert(i.getPrenom() == "Florence", "Erreur sur la modification du prenom");
		assert(i.getTauxHoraire() == 20.0, "Erreur sur la modification du taux horaire");
	});

	testSuite.require("Gestion des chambres", 0.5, [](){
		Infirmier i("Nightingale", "Florence", 15.0);
		i.ajouterChambre("101");
		i.ajouterChambre("102");
		assert(i.getTotalChambres()==2, "Erreur sur l'ajout de chambres");
		assert(i.getChambre().size() == 2, "Erreur sur l'ajout de chambres");
		assert(i.getChambre()[0] == "101", "Erreur: chambre 101 non trouvee");
		assert(i.getChambre()[1] == "102", "Erreur: chambre 102 non trouvee");
	});

	testSuite.require("Suppression de chambres", 0.5, [](){
		Infirmier i("Nightingale", "Florence", 15.0);
		i.ajouterChambre("101");
		i.ajouterChambre("102");
		i.retirerChambre("101");
		assert(i.getTotalChambres()==1, "Erreur sur l'ajout de chambres");
		assert(i.getChambre().size() == 1, "Erreur sur la suppression de chambre");
		assert(i.getChambre()[0] == "102", "Erreur: mauvaise chambre supprimee");
		i.retirerChambre("103");
		assert(i.getChambre().size() == 1, "Erreur: suppression d'une chambre inexistante");
	});

	testSuite.require("Gestion des heures travaillees", 0.5, [](){
		Infirmier i("Nightingale", "Florence", 15.0);
		i.ajouterHeuresTravaillees(5);
		assert(i.getHeuresTravaillees() == 5, "Erreur sur l'ajout des heures travaillees");
		i.ajouterHeuresTravaillees(3);
		assert(i.getHeuresTravaillees() == 8, "Erreur sur l'ajout cumule des heures travaillees");
	});

	testSuite.require("Calcul du salaire", 0.5, [](){
		Infirmier i("Nightingale", "Florence", 15.0);
		i.ajouterHeuresTravaillees(10);
		i.ajouterChambre("101");
		i.ajouterChambre("102");
		float salaire = i.calculerSalaire();
		assert(salaire == (10 * 15.0 + (2 * 15.0 / 20.0)), "Erreur sur le calcul du salaire");
		assert(i.getHeuresTravaillees() == 0, "Erreur: heures travaillees non reinitialisees après le calcul du salaire");
	});

	testSuite.require("Affichage des details de l'infirmier", 1, []() {
		Infirmier i("Nightingale", "Florence", 15.0);
		i.ajouterHeuresTravaillees(5);
		i.ajouterChambre("101");
		i.ajouterChambre("102");
		
		ostringstream oss;
		streambuf* oldCout = std::cout.rdbuf(oss.rdbuf());
		i.afficher(oss);
		cout.rdbuf(oldCout);
		
		string output = oss.str();
		string expectedOutput = 
			"Nom: Nightingale\n"
			"Prenom: Florence\n"
			"Taux horaire: 15 $/h\n"
			"Heures travaillees: 5 heures\n"
			"Total chambres gerees: 2\n"
			"Liste des chambres: 101 102 \n";
		
		assert(output == expectedOutput, "Erreur: le format de l'affichage de l'infirmier est incorrect");
	});


	testSuite.require("Creation d'une specialite par defaut", 0.5, [](){
		Specialite s;
		assert(s.getDomaine() == "", "Erreur: domaine par defaut incorrect");
		assert(s.getNiveau() == 0, "Erreur: niveau par defaut incorrect");
	});
	
	testSuite.require("Creation d'une specialite avec paramètres", 0.5, [](){
		Specialite s("Cardiologie", 5);
		assert(s.getDomaine() == "Cardiologie", "Erreur sur le domaine");
		assert(s.getNiveau() == 5, "Erreur sur le niveau");
	});

	testSuite.require("Modification des attributs d'une specialite", 0.5, [](){
		Specialite s;
		s.setDomaine("Neurologie");
		s.setNiveau(7);
		assert(s.getDomaine() == "Neurologie", "Erreur sur la modification du domaine");
		assert(s.getNiveau() == 7, "Erreur sur la modification du niveau");
	});

	testSuite.require("Affichage des details d'une specialite", 0.5, [](){
		Specialite s("Pediatrie", 3);
		ostringstream oss;
		streambuf* oldCout = cout.rdbuf(oss.rdbuf());
		s.afficher(oss);
		cout.rdbuf(oldCout);
		string output = oss.str();
		string expectedOutput =
			"Domaine: Pediatrie\n"
			"Niveau: 3\n";
    	assert(output == expectedOutput, "Erreur: le format de l'affichage de la specialite est incorrect");
	});

	testSuite.require("Creation d'un medecin avec nom uniquement", 0.5, [](){
		Medecin m("Fauci");
		assert(m.getNom() == "Fauci", "Erreur: nom incorrect");
		assert(m.getSpecialite() == nullptr, "Erreur: specialite initiale non nulle");
	});

	testSuite.require("Creation d'un medecin avec parametres", 0.5, [](){
		Specialite s("Immunologie",5);
		Medecin m("Fauci", &s, 100000);
		assert(m.getNom() == "Fauci", "Erreur sur le nom");
		assert(m.getSpecialite() == &s, "Erreur sur la specialite"); 
		assert(m.calculerSalaire() == 500000.0, "Erreur: calcul du salaire incorrect"); });

	testSuite.require("Modification des attributs d'un medecin", 0.5, [](){
		Medecin m("Dupont",  nullptr, 100000.0);
		Specialite s("Neurologie", 4);
		m.setNom("Fauci");
		m.setSpecialite(&s);
		assert(m.getNom() == "Fauci", "Erreur: modification du nom");
		assert(m.getSpecialite() == &s, "Erreur: modification de la specialite");
	});	

	testSuite.require("Calcul du salaire sans specialite", 0.5, [](){
		Medecin m("Fauci", nullptr, 120000.0 );
		assert(m.calculerSalaire() == 120000.0, "Erreur: calcul du salaire sans specialite incorrect");
	});

	testSuite.require("Calcul du salaire avec specialite", 0.5, [](){
		Specialite s("Pediatrie", 3);
		Medecin m("Fauci", &s, 80000.0);
		assert(m.calculerSalaire() == 240000.0, "Erreur: calcul du salaire avec specialite incorrect");
	});

	testSuite.require("Affichage des details d'un medecin", 1, []() {
		Specialite s("Chirurgie", 6);
		Medecin m("DrOz", &s, 90000.0);
		
		ostringstream oss;
		streambuf* oldCout = cout.rdbuf(oss.rdbuf());
		m.afficher(oss);
		cout.rdbuf(oldCout);
		
		string output = oss.str();
		string expectedOutput =
			"Nom: DrOz\n"
			"Domaine: Chirurgie\n"
			"Niveau: 6\n"
			"Salaire: 540000 $\n";

		assert(output == expectedOutput, "Erreur: le format de l'affichage est incorrect");
	});

	testSuite.require("Creation d'un hopital avec un nom", 0.5, [](){
		HopitalPoly h("Hopital Sainte-Justine");
		assert(h.getNom() == "Hopital Sainte-Justine", "Erreur: nom incorrect");
		assert(h.getMedecins().empty(), "Erreur: liste de medecins non vide a la creation");
		assert(h.getInfirmiers().empty(), "Erreur: liste d'infirmiers non vide a la creation");
	});

	testSuite.require("Ajout d'un medecin a l'hopital", 0.5, [](){
		HopitalPoly h("Hopital Sacre-Coeur");
		Medecin m("Fauci");
		h.ajouterMedecin(&m);
		assert(h.getMedecins().size() == 1, "Erreur: medecin non ajoute");
		assert(h.getMedecins()[0] == &m, "Erreur: mauvais medecin dans la liste");
	});

	testSuite.require("Suppression d'un medecin de l'hopital", 0.5, [](){
		HopitalPoly h("Hopital Maisonneuve-Rosemont");
		Medecin m("House");
		h.ajouterMedecin(&m);
		h.supprimerMedecin(&m);
		assert(h.getMedecins().empty(), "Erreur: medecin non supprime");
	});

	testSuite.require("Ajout d'un infirmier a l'hopital", 0.5, [](){
		HopitalPoly h("Hopital General Juif");
		Infirmier i("Florence", "Nightingale", 20.0);
		h.ajouterInfirmier(&i);
		assert(h.getInfirmiers().size() == 1, "Erreur: infirmier non ajoute");
		assert(h.getInfirmiers()[0] == &i, "Erreur: mauvais infirmier dans la liste");
	});

	testSuite.require("Suppression d'un infirmier de l'hopital", 0.5, [](){
		HopitalPoly h("Hopital de Montreal pour Enfants");
		Infirmier i("Florence", "Nightingale", 25.0);
		h.ajouterInfirmier(&i);
		h.supprimerInfirmier(&i);
		assert(h.getInfirmiers().empty(), "Erreur: infirmier non supprime");
	});

	testSuite.require("Recherche d'un medecin dans l'hopital", 0.5, [](){
		HopitalPoly h("Hopital Charles-LeMoyne");
		Medecin m("Smith");
		h.ajouterMedecin(&m);
		assert(h.chercherMedecin(&m), "Erreur: medecin non trouve");
		Medecin m2("Johnson");
		assert(!h.chercherMedecin(&m2), "Erreur: faux positif pour medecin inexistant");
	});

	testSuite.require("Recherche d'un infirmier dans l'hopital", 0.5, [](){
		HopitalPoly h("Hopital de Verdun");
		Infirmier i("Florence", "Nightingale", 30.0);
		h.ajouterInfirmier(&i);
		assert(h.chercherInfirmier(&i), "Erreur: infirmier non trouve");
		Infirmier i2("Mary", "Seacole", 30.0);
		assert(!h.chercherInfirmier(&i2), "Erreur: faux positif pour infirmier inexistant");
	});

	testSuite.require("Affichage de l'hopital", 2, []() {
		HopitalPoly h("Hopital Royal Victoria");
		Specialite s("Chirurgie", 6);
		Medecin m("Fauci", &s, 90000);
		Infirmier i("Nightingale", "Florence", 20.0);
		i.ajouterChambre("101");
		i.ajouterChambre("102");
		i.ajouterHeuresTravaillees(5);
		h.ajouterMedecin(&m);
		h.ajouterInfirmier(&i);

		ostringstream oss;
		streambuf* oldCout = std::cout.rdbuf(oss.rdbuf());
		h.afficher(oss);
		cout.rdbuf(oldCout);

		string output = oss.str();
		string expectedOutput = 
			"Nom de l'Hopital: Hopital Royal Victoria\n"
			"Liste des infirmiers:\n"
			"Nom: Nightingale\n"
			"Prenom: Florence\n"
			"Taux horaire: 20 $/h\n"
			"Heures travaillees: 5 heures\n"
			"Total chambres gerees: 2\n"
			"Liste des chambres: 101 102 \n"
			"Liste des medecins:\n"
			"Nom: Fauci\n"
			"Domaine: Chirurgie\n"
			"Niveau: 6\n"
			"Salaire: 540000 $\n";
		assert(output == expectedOutput, "Erreur: le format de l'affichage de l'hopital est incorrect");
	});

	testSuite.showResults();
	return 0;
}