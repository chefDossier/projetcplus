#include <iostream>
#include "Region.hh"

using namespace std;

Region::Region(vector<Departement> listedepartements){
    for(Departement departement: listedepartements){
        this->listedepartements.push_back(departement);
    }
}

vector<Departement> Region::getDepartment()const{
    return listedepartements;
}

void Region::ajouterDepartements(Departement departement){
    listedepartements.push_back(departement);
};

void Region::afficherStatGlobale(){
    int totalAgent{};
    for(Departement departement: listedepartements){
        cout<<"le departement:"<<departement.getNom()<<" compte: "<<departement.nombreTotalAgents() <<" agents"<<endl;
        cout<<"le nombre total d'agent proche de la retraite est : "<<departement.nombreAgProcheRet()<<endl;
        totalAgent += departement.nombreTotalAgents();
        int a1{};
        int a2{};
        int b1{};
        int f{};
        int h{};

        for(Agent agent : departement.getListeAgent()){
            a1 += (agent.getGrade() == "a1" ) ? 1 : 0;
            a2 += (agent.getGrade() == "a2" ) ? 1 : 0;
            b1 += (agent.getGrade() == "b1" ) ? 1 : 0;
            f += (agent.getGenre() == "f" ) ? 1 : 0;
            h += (agent.getGenre() == "h" ) ? 1 : 0;

        }
        cout << "nombres de femmes: "<<f<<endl;
        cout << "nombres d'hommes: "<<h<<endl;

        cout<< "agent de grade a1: "<< a1 <<endl;
        cout<< "agent de grade a2: "<< a2 <<endl;
        cout<< "agent de grade b1: "<< b1 <<endl;


    }
};
