#include "Agent.hh"
#include <chrono>
#include <ctime>

using namespace std;

Agent::Agent(string mat,string name,string surname,string type,string level,string department,int j,int m,int a){
    matricule = mat;
    nom = name;
    prenom = surname;
    genre = type;
    grade = level;
    departement = department;
    dateNaissance.j = j;
    dateNaissance.m = m;
    dateNaissance.a = a;
}

void Agent::afficherInfos(){
    cout<< matricule <<endl;
    cout<< nom << endl;
    cout<< prenom << endl;
    cout<< genre << endl;
    cout<< grade << endl;
    cout<< departement << endl;
    cout<< dateNaissance.a <<"/"<<dateNaissance.j<<"/"<<dateNaissance.m<<endl;

}

string Agent::getMatricule()const{
    return matricule;
}

int Agent::anneeAvRetraite(){
    return 60 - calculerAge();
}

void Agent::setDateNaiss(int j,int m,int a){
    dateNaissance.j = j;
    dateNaissance.m = m;
    dateNaissance.a = a;
}
int Agent::calculerAge(){
    auto now = chrono::system_clock::now();
    time_t now_time_t = chrono::system_clock::to_time_t(now);
    tm* now_tm = localtime(&now_time_t);
    int annee_a = now_tm->tm_year + 1900;
    return annee_a - dateNaissance.a;
}
string Agent::getGrade()const{
    return this->grade;
}

string Agent::getGenre()const{
    return this->genre;
}

string Agent::getPrenom()const{
    return this->prenom;
};

string Agent::getDepartment()const{
    return this->departement;
};

string Agent::getNom()const{
    return this->nom;
};

Date Agent::getDateNaiss(){
    return this->dateNaissance;
};



