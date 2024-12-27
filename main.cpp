#include <iostream>
#include "agent.cpp"
#include "departement.cpp"
#include "region.cpp"
#include <fstream>

using namespace std;

void enregistreRegion(const Region& region,string nomR,const string& nomFichier){
    ofstream fichier(nomFichier);
    if(fichier.is_open()){
        fichier<<nomR<<endl;
        fichier<< "liste des departements:" <<endl;
        for(const Departement& departement : region.getDepartment()){
            fichier<<"- "<<departement.getNom()<<endl;
            fichier<< "\t  liste: des agents: " <<endl;
            for(Agent& agent: departement.getListeAgent()){
                fichier<<" \t* nom de l'agent: "<<agent.getNom()<<endl;
                fichier<<" \t* prenom de l'agent: "<<agent.getPrenom()<<endl;
                fichier<<" \t* date de naissance: "<<agent.getDateNaiss().a<<"/"<<agent.getDateNaiss().m<<"/"<<agent.getDateNaiss().j<<endl;
                fichier<<" \t* genre: "<<agent.getGenre()<<endl;
                fichier<<" \t* grade: "<<agent.getGrade()<<endl;
                fichier<<" \t* matricule: "<<agent.getMatricule()<<endl;
                fichier<<" \t* departement: "<<agent.getDepartment()<<endl;
            }

        }

        fichier.close();
    }
}

int main()
{
    cout<< "menu des operations" <<endl;
    cout<< "1- creer une nouvelle region"<<endl;
    cout<< "2- MODIFIER LES INFOS D'UN AGENT"<<endl;
    cout<< "3- rechercher un agent"<<endl;
    cout<< "4- afficher les AGENTS D'UN DEPARTEMENT SPECIFIQUE"<<endl;
    cout<< "5- GENERER LES RAPPORTS SUR UN DEPARTEMENT"<<endl;
    cout<< "6- afficher les statistiques globales"<<endl;
    cout<< "7- AFFICHER LES AGENTS PROCHE DE LA RETRAIT POUR TOUT LA REGION"<<endl;


    int choix;
    cout<< "selectionnez l'operation a performer"<<endl;
    cin>>choix;

    switch(choix){
        case 1:
            string nomR;
           cout<< "entrez le nom de la region :"<<endl;
           cin.ignore();
           getline(cin,nomR);
           cout<< "la region du :" <<nomR <<" a ete creer avec succes."<<endl;
           cout<< "lui ajouter des departement? '1' pour continuer et '0' pour arreter"<<endl;
           int c;
           cin>>c;
           vector<Departement> departements;
           while(c== 1){
            string nomD;
            cout<<"entrez le nom du departement"<<endl;

            cin.ignore();
            getline(cin,nomD);

            cout<< "lui ajouter des agents? '1' pour continuer et '0' pour arreter"<<endl;
            int a;
            cin>>a;
            vector<Agent> agents;
            while(a==1){
                string name,mat,genre,grade,dpartment,prenom;
                int anais,jnais,mnais;

                cin.ignore();
                cout<<"enter son nom"<<endl;
                getline(cin,name);
                cout<<"enter son prenom"<<endl;
                getline(cin,prenom);
                cout<<"entrer son matricule"<<endl;
                getline(cin,mat);
                cout<<"entrer son genre"<<endl;
                getline(cin,genre);
                cout<<"entrer son grade"<<endl;
                getline(cin,grade);
                cout<< "entrer son departement "<<endl;
                getline(cin,dpartment);
                cout<<"entrer son anne de naissance"<<endl;
                cin>>anais;
                cout<<"entrer son mois de naissance"<<endl;
                cin>>mnais;
                cout<<"entrer son jour de naissance"<<endl;
                cin>>jnais;
                Agent agent(mat,name,prenom,genre,grade,dpartment,jnais,mnais,anais);
                agents.push_back(agent);
                cout<< "ajouter un autre agents ? '1' pour continuer '0' pour arreter"<<endl;
                cin>>a;

            }
            Departement departement(nomD,agents);
            departements.push_back(departement);
            cout<< "lui ajouter encore des departement? '1' pour continuer et '0' pour arreter"<<endl;
            cin>>c;
           }
           Region nom(departements);
           nom.afficherStatGlobale();
           enregistreRegion(nom,nomR,"region.txt");
        }
    return 0;
}
