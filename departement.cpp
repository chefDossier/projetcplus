#include "Departement.hh"

using namespace std;

Departement::Departement(string name,vector<Agent> listeAgent){
    nom = name;
    for(Agent agent: listeAgent){
        this->listeAgent.push_back(agent);
    }
    //copy(listeAgent.begin(),listeAgent.end(),back_insert_iterator(this->listeAgent));
}

Departement::Departement(string nomD){
    nom=nomD;
};

Agent* Departement::searchAgent(string matricule){
    for (const Agent& agent : listeAgent){
        if(agent.getMatricule()==matricule){
            return const_cast<Agent*>(&agent);
            break;
        }
    }
    return nullptr;
}
void Departement::addAgents(Agent agent){
    if(searchAgent(agent.getMatricule())!=nullptr){
        cout<< "cet agent est deja enregistrer ou soit vous inserer un matricule deja emprunter"<<endl;
    }else{
        listeAgent.push_back(agent);
    }
};

void Departement::supprimerAgents(string matricule){
    for(auto it = listeAgent.begin();it != listeAgent.end();++it){
        if(it->getMatricule()==matricule){
            listeAgent.erase(it);
            cout<<"agent supprimer avec succes"<<endl;
            break;
        }
        cout<<"aucun agent ne correspond verifier vos entree"<<endl;
    }
};
void Departement::afficherAgents(){
    cout<< "liste des agents du departements: " << nom <<endl;

    for(Agent agent: listeAgent){
        cout<< agent.getMatricule() <<endl;
    }
}

int Departement::nombreTotalAgents(){
    return listeAgent.size();
}

int Departement::nombreAgProcheRet(){
    int t{};
    for(auto it = listeAgent.begin();it != listeAgent.end();++it){
        if(it->anneeAvRetraite() <= 3){
            ++t;
        }
    }
    return t;
}
string Departement::getNom()const{
    return this->nom;
}

vector<Agent> Departement::getListeAgent()const{
    return listeAgent;
}

