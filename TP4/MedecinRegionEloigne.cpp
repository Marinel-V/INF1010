#include "MedecinRegionEloigne.h"
// TODO: Implémentez le constructeur de MedecinRegionEloigne
//       - Initialisez le nom, l'ID et le nombre de voyages en hélicoptère.
//       - Appelez les constructeurs des classes parentes avec des valeurs appropriées.
MedecinRegionEloigne::MedecinRegionEloigne(const string& nom, const string& id, unsigned nbVoyagesEnHelicopteres, unsigned int niveau) :
    Pediatre(nom, id, 0, niveau), Chirurgien(nom, id, 0, niveau), Cardiologue(nom, id, 0, 0, niveau), nbVoyagesEnHelicopteres_(nbVoyagesEnHelicopteres)
{
}
 // TODO: Retournez le nombre de voyages effectués en hélicoptère.
unsigned MedecinRegionEloigne::getNbVoyagesEnHelicopteres(){
    return nbVoyagesEnHelicopteres_;
}

// TODO: Implémentez le calcul du salaire en prenant en compte :
    //       - Le salaire de base multiplié par le niveau de spécialité du chirurgien.
    //       - Une prime de 500 pour chaque voyage en hélicoptère.
    //       - Une prime de 30 pour chaque opération chirurgicale effectuée.
    //       - Une prime de 50 pour chaque enfant soigné en tant que pédiatre.
    //       - Une prime de 20 pour chaque patient soigné en tant que cardiologue.
float MedecinRegionEloigne::calculerSalaire() const
{
    return (salaireBase * Cardiologue::specialite_->getNiveau()) + (nbVoyagesEnHelicopteres_ * 500) + (Chirurgien::getNbOperations() * 30) + (Pediatre::getNbNbEnfantsSoignes() * 50) + (Cardiologue::getNbPatients() * 20);
}
// TODO: Incrémentez le nombre de voyages en hélicoptère.
// TODO: Ajoutez un antécédent médical au patient indiquant le transport par hélicoptère.
void MedecinRegionEloigne::visiterPatientEnHelicoptere(shared_ptr<Patient>& p)
{
    nbVoyagesEnHelicopteres_++;
    p->ajouterAntecedent("Transport par helicoptere");
}
// TODO: Affichez les informations du médecin en appelant l'affichage de la classe de base.
// TODO: Affichez le niveau des différentes spécialités (chirurgie, cardiologie, pédiatrie).
// TODO: Affichez le nombre de voyages en hélicoptère et le salaire calculé.
ostream& MedecinRegionEloigne::afficher(ostream& out) const
{
    return out << "Nom: " << Cardiologue::getNom() <<
        "\nId: " << Cardiologue::getId() <<
        "\nNiveau: " << Cardiologue::specialite_->getNiveau() <<
        "\nNiveau de Chirurgie: " << Chirurgien::specialite_->getNiveau() <<
        "\nNiveau de Cardiologue: " << Cardiologue::specialite_->getNiveau() <<
        "\nNiveau de Pediatre: " << Pediatre::specialite_->getNiveau() <<
        "\nNombre de voyages en helicoptere: " << nbVoyagesEnHelicopteres_ <<
        "\nSalaire: " << calculerSalaire() << "\n";
}