/**************************************************
 * Titre: Travail pratique #1 - Main.cpp
 * // tests unitaires
**************************************************/

#include "Specialite.h"
#include "Medecin.h"
#include "Infirmier.h"
#include "HopitalPoly.h"
#include "ReseauHopital.h"
#include "TestSuite.h"
#include <string>
#include <iostream>
#include <sstream>


using namespace std;

int main()
{ 
	TestSuite testSuite;

	testSuite.require("Gestion des chambres", 0.5, [](){
		Infirmier i("Nightingale", "Florence", 15.0);
		Infirmier i2=i+"101";
		Infirmier i3=i2+"102";
		assert(i3.getChambre().size() == 2, "Erreur sur l'ajout de chambres");
		assert(i3.getChambre()[0] == "101", "Erreur: chambre 101 non trouvee");
		assert(i3.getChambre()[1] == "102", "Erreur: chambre 102 non trouvee");
	});

	testSuite.require("Suppression de chambres", 0.5, [](){
		Infirmier i("Nightingale", "Florence", 15.0);
		Infirmier i2=i+"101";
		Infirmier i3=i2+"102";
		Infirmier i4=i3-"101";
		assert(i4.getChambre().size() == 1, "Erreur sur la suppression de chambre");
		assert(i4.getChambre()[0] == "102", "Erreur: mauvaise chambre supprimee");
		i4-("103");
		assert(i4.getChambre().size() == 1, "Erreur: suppression d'une chambre inexistante");
	});

	testSuite.require("Egalite d'un infirmier", 0.5, [](){
        Infirmier i("Nightingale", "Florence", 15.0);
        Infirmier i2("Trump", "Donald", 20.0);
        assert((i == i2)== false, "Deux pilotes differents ne devraient pas être egaux.");
        assert(i == i, "Deux pilotes identiques devraient être pareil.");
        assert(i2 == i2, "Deux pilotes identiques devraient être pareil."); });

	testSuite.require("Affichage des details de l'infirmier", 1, []() {
		Infirmier i("Nightingale", "Florence", 15.0);
		i.ajouterHeuresTravaillees(5);
		Infirmier i2=i+("101");
		Infirmier i3=i2+("102");
		
		ostringstream oss;
		streambuf* oldCout = std::cout.rdbuf(oss.rdbuf());
		oss << i3;
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

	testSuite.require("Egalite d'une specialite", 0.5, [](){
        Specialite s("Pediatrie", 3);
        Specialite s2("Graissologie", 6);
        assert((s == s2)== false, "Deux specialites differents ne devraient pas être egaux.");
        assert(s == s, "Deux specialites identiques devraient être pareil.");
        assert(s2 == s2, "Deux specialites identiques devraient être pareil."); });

	testSuite.require("Affichage des details d'une specialite", 0.5, [](){
		Specialite s("Pediatrie", 3);
		ostringstream oss;
		streambuf* oldCout = cout.rdbuf(oss.rdbuf());
		oss << s;
		cout.rdbuf(oldCout);
		string output = oss.str();
		string expectedOutput =
			"Domaine: Pediatrie\n"
			"Niveau: 3\n";
    	assert(output == expectedOutput, "Erreur: le format de l'affichage de la specialite est incorrect");
	});

	testSuite.require("Egalite d'un medecin", 0.5, [](){
        Specialite s("Pediatrie", 3);
        Specialite s2("Graissologie", 6);
		Medecin m("DrOz", 90000.0, &s2);
		Medecin m2("DrHouse", 80000.0, &s);
        assert((m == m2)== false, "Deux medecins differents ne devraient pas être egaux.");
        assert(m == m, "Deux medecins identiques devraient être pareil.");
        assert(m2 == m2, "Deux medecins identiques devraient être pareil."); });

	testSuite.require("Affichage des details d'un medecin", 1, []() {
		Specialite s("Chirurgie", 6);
		Medecin m("DrOz", 90000.0, &s);
		
		ostringstream oss;
		streambuf* oldCout = cout.rdbuf(oss.rdbuf());
		oss << m;
		cout.rdbuf(oldCout);
		
		string output = oss.str();
		string expectedOutput =
			"Nom: DrOz\n"
			"Domaine: Chirurgie\n"
			"Niveau: 6\n"
			"Salaire: 540000 $\n";

		assert(output == expectedOutput, "Erreur: le format de l'affichage est incorrect");
	});

	testSuite.require("Ajout d'un medecin a l'hopital", 0.5, [](){
		HopitalPoly h("Hopital Sacre-Coeur");
		shared_ptr<Medecin> doctor= make_shared<Medecin>("Fauci");
		h+=doctor;
		assert(h.getMedecins().size() == 1, "Erreur: medecin non ajoute");
		h+=doctor;
		assert(h.getMedecins().size() == 1, "Erreur: medecin duplicat ajoute");
		assert(h.getMedecins()[0] ==doctor, "Erreur: mauvais medecin dans la liste");
	});

	testSuite.require("Suppression d'un medecin de l'hopital", 0.5, [](){
		HopitalPoly h("Hopital Maisonneuve-Rosemont");
		shared_ptr<Medecin> doctor= make_shared<Medecin>("Fauci");
		h+=doctor;
		h-=doctor;
		assert(h.getMedecins().empty(), "Erreur: medecin non supprime");
	});

	testSuite.require("Suppression d'un medecin de l'hopital (par nom)", 0.5, []() {
		HopitalPoly h("Hopital Maisonneuve-Rosemont");
		shared_ptr<Medecin> doctor1 = make_shared<Medecin>("Fauci");
		shared_ptr<Medecin> doctor2 = make_shared<Medecin>("DrHouse");
		h += doctor1;
		h += doctor2;

		string doctorToRemove = "Fauci";
		h -= doctorToRemove;

		assert(h.getMedecins().size() == 1, "Erreur: medecin non supprime (par nom)");
		assert(h.getMedecins()[0]->getNom() == "DrHouse", "Erreur: mauvais medecin supprime (par nom)");

		string invalidDoctor = "DrOz";
		h -= invalidDoctor;
		assert(h.getMedecins().size() == 1, "Erreur: suppression incorrecte d'un medecin inexistant (par nom)");
	});

	testSuite.require("Ajout d'un infirmier a l'hopital", 0.5, [](){
		HopitalPoly h("Hopital General Juif");
		shared_ptr<Infirmier> nurse= make_shared<Infirmier>("Florence", "Nightingale", 20.0);
		h+=nurse;
		assert(h.getInfirmiers().size() == 1, "Erreur: infirmier non ajoute");
		h+=nurse;
		assert(h.getInfirmiers().size() == 1, "Erreur: infirmier duplicat ajoute");
		assert(h.getInfirmiers()[0] == nurse, "Erreur: mauvais infirmier dans la liste");
	});

	testSuite.require("Suppression d'un infirmier de l'hopital", 0.5, [](){
		HopitalPoly h("Hopital de Montreal pour Enfants");
		Infirmier i("Florence", "Nightingale", 25.0);
		shared_ptr<Infirmier> nurse= make_shared<Infirmier>("Florence", "Nightingale", 20.0);
		h+=nurse;
		h-=nurse;
		assert(h.getInfirmiers().empty(), "Erreur: infirmier non supprime");
	});

	testSuite.require("Recherche d'un medecin dans l'hopital", 0.5, [](){
		HopitalPoly h("Hopital Charles-LeMoyne");
		shared_ptr<Medecin> doctor= make_shared<Medecin>("Fauci");
		h+=doctor;
		assert(h.chercherMedecin(doctor), "Erreur: medecin non trouve");
		shared_ptr<Medecin> invalid_doctor= make_shared<Medecin>("DrOz");
		assert(!h.chercherMedecin(invalid_doctor), "Erreur: faux positif pour medecin inexistant");
	});

	testSuite.require("Recherche d'un infirmier dans l'hopital", 0.5, [](){
		HopitalPoly h("Hopital de Verdun");
		shared_ptr<Infirmier> nurse= make_shared<Infirmier>("Florence", "Nightingale", 20.0);
		h+=nurse;
		assert(h.chercherInfirmier(nurse), "Erreur: infirmier non trouve");
		shared_ptr<Infirmier> invalid_nurse= make_shared<Infirmier>("Mary", "Sue", 30.0);
		assert(!h.chercherInfirmier(invalid_nurse), "Erreur: faux positif pour infirmier inexistant");
	});

	testSuite.require("Affichage de l'hopital", 2, []() {
		HopitalPoly h("Hopital Royal Victoria");
		Specialite s("Chirurgie", 6);
		shared_ptr<Medecin> doctor= make_shared<Medecin>("Fauci",90000.0,&s);
		Infirmier i=Infirmier("Nightingale", "Florence", 20.0);
		Infirmier i2=i+("101");
		Infirmier i3=i2+("102");
		shared_ptr<Infirmier> nurse= make_shared<Infirmier>(i3);
		nurse->ajouterHeuresTravaillees(5);
		h+=(doctor);
		h+=(nurse);

		ostringstream oss;
		streambuf* oldCout = std::cout.rdbuf(oss.rdbuf());
		oss << h;
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

	testSuite.require("Constructeur de copie d'un Infirmier", 0.5, [](){
		Infirmier i=Infirmier("Nightingale", "Florence", 20.0);
		i.ajouterHeuresTravaillees(5);
		Infirmier i3=i+("101");
		Infirmier i2(i3);
		assert(i2.getNom() == "Nightingale", "Erreur sur le nom");
		assert(i2.getPrenom() == "Florence", "Erreur sur le prenom");
		assert(i2.getTauxHoraire() == 20.0, "Erreur sur le taux horaire");
		assert(i2.getHeuresTravaillees() == 5, "Erreur sur les heures travaillees");
		assert(i2.getChambre()[0] == "101", "Erreur sur le numero de chambres");
	});

	testSuite.require("Constructeur de copie d'un Medecin", 0.5, [](){
        Specialite s2("Neurologie", 6);
		Medecin m("DrOz", 90000.0, &s2);
		Medecin m2(m);
		assert(m2.getNom() == "DrOz", "Erreur sur le nom");
		assert(*const_cast<Specialite*>(m2.getSpecialite()) == s2, "Erreur sur la specialite");
	});

	testSuite.require("Constructeur de copie d'une specialite", 0.5, [](){
        Specialite s2("Neurologie", 6);
		Specialite s(s2);
		assert(s.getDomaine() == "Neurologie", "Erreur sur le domaine");
		assert(s.getNiveau() == 6, "Erreur sur le niveau");
	});

	testSuite.require("Constructeur de copie d'un HopitalPoly", 1, [](){
		HopitalPoly original("Hopital General");
		
		Specialite chirurgie("Chirurgie", 6);
		shared_ptr<Medecin> doctor1 = make_shared<Medecin>("Fauci", 90000.0, &chirurgie);
		shared_ptr<Medecin> doctor2 = make_shared<Medecin>("DrHouse", 80000.0, &chirurgie);
		original += doctor1;
		original += doctor2;

		Infirmier nurse1("Nightingale", "Florence", 20.0);
		Infirmier nurse2("Doe", "John", 18.0);
		shared_ptr<Infirmier> sharedNurse1 = make_shared<Infirmier>(nurse1);
		shared_ptr<Infirmier> sharedNurse2 = make_shared<Infirmier>(nurse2);
		original += sharedNurse1;
		original += sharedNurse2;

		HopitalPoly copy(original);

		assert(copy.getNom() == "Hopital General", "Erreur: le nom de l'hopital n'est pas correctement copie");

		assert(copy.getMedecins().size() == 2, "Erreur: le nombre de medecins n'est pas correctement copie");
		assert(copy.getMedecins()[0] == doctor1, "Erreur: le premier medecin n'est pas correctement copie");
		assert(copy.getMedecins()[1] == doctor2, "Erreur: le deuxieme medecin n'est pas correctement copie");

		assert(copy.getInfirmiers().size() == 2, "Erreur: le nombre d'infirmiers n'est pas correctement copie");
		assert(copy.getInfirmiers()[0] == sharedNurse1, "Erreur: le premier infirmier n'est pas correctement copie");
		assert(copy.getInfirmiers()[1] == sharedNurse2, "Erreur: le deuxieme infirmier n'est pas correctement copie");
	});

	testSuite.require("Ajout d'un hopital a un autre - Medecins et Infirmiers", 1, [](){
		HopitalPoly h1("Hopital 1");
		HopitalPoly h2("Hopital 2");

		Specialite chirurgie("Chirurgie", 6);
		Specialite neurologie("Neurologie", 7);

		shared_ptr<Medecin> doctor1 = make_shared<Medecin>("Fauci", 90000.0, &chirurgie);
		shared_ptr<Medecin> doctor2 = make_shared<Medecin>("DrHouse", 80000.0, &neurologie);

		h1 += doctor1;
		h2 += doctor2;

		shared_ptr<Infirmier> nurse1 = make_shared<Infirmier>("Florence", "Nightingale", 25.0);
		shared_ptr<Infirmier> nurse2 = make_shared<Infirmier>("John", "Doe", 20.0);

		h1 += nurse1;

		h2 += nurse2;

		h1 += h2;

		assert(h1.getMedecins().size() == 2, "Erreur: le nombre total de medecins est incorrect apres l'ajout d'un hopital");
		assert(h1.chercherMedecin(doctor1), "Erreur: le medecin Fauci n'a pas ete trouve dans l'hopital apres l'ajout");
		assert(h1.chercherMedecin(doctor2), "Erreur: le medecin DrHouse n'a pas ete trouve dans l'hopital apres l'ajout");

		assert(h1.getInfirmiers().size() == 2, "Erreur: le nombre total d'infirmiers est incorrect apres l'ajout d'un hopital");
		assert(h1.chercherInfirmier(nurse1), "Erreur: l'infirmier Florence Nightingale n'a pas ete trouve dans l'hopital apres l'ajout");
		assert(h1.chercherInfirmier(nurse2), "Erreur: l'infirmier John Doe n'a pas ete trouve dans l'hopital apres l'ajout");
   });

   testSuite.require("Verification des doublons avec operator+= pour HopitalPoly", 0.5, [](){
		HopitalPoly h1("Hopital Principal");

		Specialite cardio("Cardiologie", 5);

		shared_ptr<Medecin> doctor = make_shared<Medecin>("Dube", 75000.0, &cardio);

		h1 += doctor;

		shared_ptr<Infirmier> nurse = make_shared<Infirmier>("Marie", "Curie", 30.0);
		h1 += nurse;

		HopitalPoly h2("Hopital Secondaire");
		h2 += doctor;
		h2 += nurse;

		h1 += h2;

		assert(h1.getMedecins().size() == 1, "Erreur: un doublon de medecin a ete ajoute apres la fusion des hopitaux");
		assert(h1.getInfirmiers().size() == 1, "Erreur: un doublon d'infirmier a ete ajoute apres la fusion des hopitaux");

		assert(h1.chercherMedecin(doctor), "Erreur: le medecin n'est pas trouve apres la fusion");
		assert(h1.chercherInfirmier(nurse), "Erreur: l'infirmier n'est pas trouve apres la fusion");
	});



	testSuite.require("Creation d'un reseau d'hopital", 0.5, []() {
        ReseauHopital reseau("Reseau Sante Montreal");
        assert(reseau.getNom() == "Reseau Sante Montreal", "Erreur: le nom du reseau n'est pas correctement initialise");
    });

    testSuite.require("Modification du nom du reseau d'hopital", 0.5, []() {
        ReseauHopital reseau("Reseau Original");
        reseau.setNom("Nouveau Reseau");
        assert(reseau.getNom() == "Nouveau Reseau", "Erreur: le nom du reseau n'a pas ete correctement modifie");
    });

    testSuite.require("Ajout d'un hopital au reseau", 0.5, []() {
        ReseauHopital reseau("Reseau Quebec");
		auto original = make_shared<HopitalPoly>("Hopital de Quebec");
        auto hopital = make_unique<HopitalPoly>("Hopital de Quebec");
        reseau += hopital;
        assert(reseau.chercherHopital(original.get()), "Erreur: l'hopital n'a pas ete correctement ajoute au reseau");
    });

	    testSuite.require("Suppression d'un hopital par nom", 0.5, []() {
        ReseauHopital reseau("Reseau Sante");
        unique_ptr<HopitalPoly> hopital1 = make_unique<HopitalPoly>("Hopital A");
        unique_ptr<HopitalPoly> hopital2 = make_unique<HopitalPoly>("Hopital B");
		auto originalA = make_shared<HopitalPoly>("Hopital A");
		auto originalB = make_shared<HopitalPoly>("Hopital B");
        reseau += hopital1;
        reseau += hopital2;

        string nomHopital = "Hopital A";
        reseau -= nomHopital;

        assert(!reseau.chercherHopital(originalA.get()), "Erreur: l'hopital n'a pas ete correctement supprime");
        assert(reseau.chercherHopital(originalB.get()), "Erreur: un mauvais hopital a ete supprime");
    });

    testSuite.require("Ajout d'un hopital duplicat au reseau", 0.5, []() {
        ReseauHopital reseau("Reseau Montreal");
        unique_ptr<HopitalPoly> hopital = make_unique<HopitalPoly>("Hopital General");
		auto original = make_shared<HopitalPoly>("Hopital General");
        reseau += hopital;

        unique_ptr<HopitalPoly> hopitalDuplicat = make_unique<HopitalPoly>("Hopital General");
        reseau += hopitalDuplicat;

        assert(reseau.chercherHopital(original.get()), "Erreur: l'hopital n'est pas trouve dans le reseau");
        assert(reseau.getNumbHospitals()==1, "Erreur: un hopital duplicat a ete ajoute au reseau");
    });

    testSuite.require("Suppression d'un hopital inexistant par nom", 0.5, []() {
        ReseauHopital reseau("Reseau Provincial");
        unique_ptr<HopitalPoly> hopital = make_unique<HopitalPoly>("Hopital Unique");
		auto original = make_shared<HopitalPoly>("Hopital Unique");
        reseau += hopital;

        string nomHopital = "Hopital Inexistant";
        reseau -= nomHopital;

        assert(reseau.chercherHopital(original.get()), "Erreur: un hopital existant a ete supprime par erreur");
    });

	testSuite.require("Affichage du reseau d'hopital", 1.0, []() {
		ReseauHopital reseau("Reseau Sante Quebec");
		HopitalPoly hopital("Hopital Royal Victoria");

		Specialite chirurgie("Chirurgie", 6);
		shared_ptr<Medecin> doctor = make_shared<Medecin>("Fauci", 90000.0, &chirurgie);
		hopital += doctor;

		Infirmier nurse("Nightingale", "Florence", 20.0);
		nurse.ajouterHeuresTravaillees(5);
		shared_ptr<Infirmier> sharedNurse = make_shared<Infirmier>(nurse);
		hopital += sharedNurse;
		unique_ptr<HopitalPoly> hopital1 = make_unique<HopitalPoly>(hopital);
		unique_ptr<HopitalPoly> hopital2 = make_unique<HopitalPoly>("Hopital B");

		reseau += hopital1;
		reseau += hopital2;

		ostringstream oss;
		streambuf* oldCout = std::cout.rdbuf(oss.rdbuf());
		oss << reseau;
		cout.rdbuf(oldCout);

		string output = oss.str();
		string expectedOutput =
			"Nom du reseau d'hopital: Reseau Sante Quebec\n"
			"Nom de l'Hopital: Hopital Royal Victoria\n"
			"Liste des infirmiers:\n"
			"Nom: Nightingale\n"
			"Prenom: Florence\n"
			"Taux horaire: 20 $/h\n"
			"Heures travaillees: 5 heures\n"
			"Total chambres gerees: 0\n"
			"Liste des chambres: Aucune chambre assignee.\n"
			"Liste des medecins:\n"
			"Nom: Fauci\n"
			"Domaine: Chirurgie\n"
			"Niveau: 6\n"
			"Salaire: 540000 $\n"   
			"Nom de l'Hopital: Hopital B\n"
			"Liste des infirmiers:\n"  
			"Liste des medecins:\n";   

		assert(output == expectedOutput, "Erreur: le format de l'affichage du reseau d'hopital est incorrect");
	});

	testSuite.showResults();
	return 0;
}