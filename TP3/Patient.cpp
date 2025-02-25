#include "Patient.h"


Patient::Patient(std::string nom, int age)
    : nom_(nom), age_(age), typeSoins_(static_cast<TypeSoins>(3)), infirmier_(nullptr), medecin_(nullptr) {}

void Patient::setNom(const string& nom) {
    nom_ = nom;
}

const string& Patient::getNom() const {
    return nom_;
}

int Patient::getSalle() const {
    return numeroSalle_;
}

const TypeSoins& Patient::getTypeSoins() const {
    return typeSoins_;
}

shared_ptr<Infirmier> Patient::getInfirmier() const {
    return infirmier_;
}

shared_ptr<Medecin>  Patient::getMedecin() const {
    return medecin_;
}

vector<string> Patient::getAntecedentsMedicaux() const {
    return antecedentsMedicaux_;
}

void Patient::ajouterAntecedent(const std::string& antecedent) {
    antecedentsMedicaux_.push_back(antecedent);
}

void Patient::misAjourTypeSoin(const TypeSoins& typeSoin) {
    typeSoins_ = typeSoin;
}

void Patient::misAjourSalle(int nSalle) {
    numeroSalle_ = nSalle;
}

void Patient::assignerInfirmier(const shared_ptr<Infirmier>& i){
    infirmier_ = i;
}

void Patient::assignerMedecin(const shared_ptr<Medecin>& m){
    medecin_ = m;
}


void Patient::afficher(ostream& out) const {
    string typeSoinsStr = "";
	switch (typeSoins_)
	{
    case TypeSoins::CARDIOLOGIE: { typeSoinsStr = "Cardiologie"; break; }
    case TypeSoins::CHIRURGICAL: { typeSoinsStr = "Chirurgical";break; }
    case TypeSoins::PEDIATRIE: { typeSoinsStr = "Pediatrie";break; }
    case TypeSoins::PAS_BESOIN: { typeSoinsStr = "Pas Besoin";break; }
	}
    out<<"Nom: "<<nom_<<"\n"
        "Âge: "<<age_<<" ans\n"
        "Numéro de salle: "<<numeroSalle_<<"\n"
        "Type de soins requis: "<<typeSoinsStr<<"\n"
        "Antécédents médicaux:\n";
    for (auto& elem : antecedentsMedicaux_)
    {
        out<<" > " <<elem << "\n";
    }
}


ostream& operator<<(ostream& out, const Patient& p) {
    p.afficher(out);
    return out;
}