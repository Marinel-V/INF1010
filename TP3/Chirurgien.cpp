#include "Chirurgien.h"

// TODO: Constructeur de Chirurgien
// Le constructeur doit initialiser les attributs privés :
// - nbHeuresDeGarde_ avec le nombre d'heures de garde
// - nbOperations_ à 0 (par défaut, un chirurgien commence sans opérations)
Chirurgien::Chirurgien(const string& nom, unsigned nbHeuresGarde, unsigned int niveau): Medecin(nom, new Specialite("Chirurgie", niveau)), nbHeuresDeGarde_(nbHeuresGarde), nbOperations_(0){}

// TODO: Méthode getNbHeuresDeGarde
// Cette méthode doit retourner le nombre d'heures de garde effectuées par le chirurgien
unsigned Chirurgien::getNbHeuresDeGarde() const {
    return nbHeuresDeGarde_;
}

// TODO: Méthode setNbHeuresDeGarde
// Cette méthode doit modifier le nombre d'heures de garde du chirurgien
void Chirurgien::setNbHeuresDeGarde(int nbHeuresDeGarde) {
    nbHeuresDeGarde_ = nbHeuresDeGarde;
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
    nbOperations_ += nbOperations;
}

// TODO: Méthode opererPatient
// Cette méthode doit :
// 1. Incrémenter le nombre d'opérations du chirurgien
// 2. Assigner un patient au chirurgien (en utilisant setPatient)
// 3. Ajouter un antécédent médical pour le patient concernant l'opération (Opération chirurgicale effectuée par Dr X.")
// 4. Mettre à jour le type de soin du patient en TypeSoins::PAS_BESOIN
void Chirurgien::opererPatient(shared_ptr<Patient>& p) {
    ajouterNbOperations(1);
    setPatient(p);
    p->ajouterAntecedent("Opération chirurgicale effectuée par " + nom_+".");
    p->misAjourTypeSoin(static_cast<TypeSoins>(3));
}

// TODO: Méthode calculerSalaire
// Cette méthode doit calculer le salaire du chirurgien en fonction de
// Exemple : salaireBase * niveau + (nbHeuresDeGarde * 20) + (nbOperations * 50)
float Chirurgien::calculerSalaire() const {
    return salaireBase * specialite_->getNiveau() + (nbHeuresDeGarde_ * 20) + (nbOperations_ * 50);
}

// TODO: Méthode afficher (Voir les tests)
// vous devez réutiliser la methode afficher de medecin
// Cette méthode doit afficher les informations suivantes :
// - Appeler la méthode afficher() de la classe Medecin pour afficher les informations communes
// - Ajouter les informations suivantes :
//    - Heures de garde du chirurgien
//    - Nombre d'opérations effectuées par le chirurgien
ostream& Chirurgien::afficher(ostream& out) const {
    Medecin::afficher(out);
    out<<"Heures de garde: "<<nbHeuresDeGarde_<<"\n"
        "Opérations: "<<nbOperations_<<"\n";
    return out;
}
