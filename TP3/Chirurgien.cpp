#include "Chirurgien.h"

// TODO: Constructeur de Chirurgien
// Le constructeur doit initialiser les attributs privés :
// - nbHeuresDeGarde_ avec le nombre d'heures de garde
// - nbOperations_ à 0 (par défaut, un chirurgien commence sans opérations)
Chirurgien::Chirurgien(const string& nom, unsigned nbHeuresGarde, unsigned int niveau): {}

// TODO: Méthode getNbHeuresDeGarde
// Cette méthode doit retourner le nombre d'heures de garde effectuées par le chirurgien
unsigned Chirurgien::getNbHeuresDeGarde() const {
}

// TODO: Méthode setNbHeuresDeGarde
// Cette méthode doit modifier le nombre d'heures de garde du chirurgien
void Chirurgien::setNbHeuresDeGarde(int nbHeuresDeGarde) {
}

// TODO: Méthode getNbOperations
// Cette méthode doit retourner le nombre d'opérations effectuées par le chirurgien
unsigned Chirurgien::getNbOperations() const {
    return nbOperations_;
}

// TODO: Méthode ajouterNbOperations
// Cette méthode doit ajouter un certain nombre d'opérations au chirurgien.
// Exemple : si nbOperations = 3, alors nbOperations_ doit augmenter de 3
void Chirurgien::ajouterNbOperations(unsigned nbOperations) {
}

// TODO: Méthode opererPatient
// Cette méthode doit :
// 1. Incrémenter le nombre d'opérations du chirurgien
// 2. Assigner un patient au chirurgien (en utilisant setPatient)
// 3. Ajouter un antécédent médical pour le patient concernant l'opération (Opération chirurgicale effectuée par Dr X.")
// 4. Mettre à jour le type de soin du patient en TypeSoins::PAS_BESOIN
void Chirurgien::opererPatient(shared_ptr<Patient>& p) {
}

// TODO: Méthode calculerSalaire
// Cette méthode doit calculer le salaire du chirurgien en fonction de
// Exemple : salaireBase * niveau + (nbHeuresDeGarde * 20) + (nbOperations * 50)
float Chirurgien::calculerSalaire() const {
    return 0.0f; // TODO: Remplacer par le calcul du salaire
}

// TODO: Méthode afficher (Voir les tests)
// vous devez réutiliser la methode afficher de medecin
// Cette méthode doit afficher les informations suivantes :
// - Appeler la méthode afficher() de la classe Medecin pour afficher les informations communes
// - Ajouter les informations suivantes :
//    - Heures de garde du chirurgien
//    - Nombre d'opérations effectuées par le chirurgien
ostream& Chirurgien::afficher(ostream& out) const {
    return out;
}
