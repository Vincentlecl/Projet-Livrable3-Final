#include "Services.h"
#include "Personne.h"
using namespace System;

NS_Comp_Svc::CLservices::CLservices(void)
{
	this->oCad = gcnew compData::Cad();
	this->oMappTB = gcnew compMappage::Map();
}
System::Data::DataSet^ NS_Comp_Svc::CLservices::selectionnerToutesLesPersonnes(System::String^ dataTableName)
{
	System::String^ sql;

	sql = this->oMappTB->Select();
	return this->oCad->getRows(sql, dataTableName);
}
System::Collections::ArrayList^ NS_Comp_Svc::CLservices::selectPersonnes()
{
	System::Data::DataSet^ ds = this->oCad->getRows(this->oMappTB->Select(), "a");

	System::Collections::ArrayList^ l = gcnew System::Collections::ArrayList();
	for (int i = 0;i < ds->Tables["a"]->Rows->Count;i++) {
		Personne^ p = gcnew Personne();
		p->ID_Personne = (int)ds->Tables["a"]->Rows[i]->ItemArray[0];
		p->personnel = gcnew Personnel();
		p->personnel->ID_Personnel = (int)ds->Tables["a"]->Rows[i]->ItemArray[1];
		p->adresse = gcnew Adresse();
		p->adresse->ID_Adresse = (int)ds->Tables["a"]->Rows[i]->ItemArray[2];
		p->Nom = (String^) ds->Tables["a"]->Rows[i]->ItemArray[3];
		p->Prenom = (String^) ds->Tables["a"]->Rows[i]->ItemArray[4];
		
		p->personnel->DateEmbauche = (DateTime) ds->Tables["a"]->Rows[i]->ItemArray[5];
		if (ds->Tables["a"]->Rows[i]->IsNull(6))
			p->personnel->ID_Personnel_Superieur = 0;
		else
			p->personnel->ID_Personnel_Superieur = (int^) ds->Tables["a"]->Rows[i]->ItemArray[6];//donc ça marche bien c juste qu'ici ça peut être null du coup
		
		
		p->adresse->Ville = (String^)ds->Tables["a"]->Rows[i]->ItemArray[7];
		p->adresse->CP = (int^)ds->Tables["a"]->Rows[i]->ItemArray[8];
		p->adresse->Ligne = (String^)ds->Tables["a"]->Rows[i]->ItemArray[9];
		l->Add(p);
	}
	return l;
}


void NS_Comp_Svc::CLservices::update(Personne^ p) {

	System::String^ sql;
	sql = "UPDATE Personne SET nom = '" + p->Nom + "',prenom = '" + p->Prenom + "' WHERE Personne.ID_Personne = " + p->ID_Personne;
	this->oCad->actionRows(sql);

	//sql = "UPDATE Personnel set DateEmbauche = '" + p->Personnel->DateEmbauche + "', ID_Personnel_Superieur = " + p->Personnel->ID_Personnel_Superieur + " WHERE ID_Personnel = " + p->Personnel->ID_Personnel;
	//sql = "UPDATE Adresse set Ville = '" + this->Ville + "', CP = " + this->CP + ", Ligne = '" + this->Ligne + "' from Adresse join Habite on Habite.ID_Adresse = Adresse.ID_Adresse join Personnel on Personnel.ID_Personnel = Habite.ID_Personnel where Adresse.ID_Adresse = " + this->IdAdresse;
	
	//this->oCad->actionRows(sql);//ta commenté au dessus mais ta laissé une double exec de l'update la
	//attends du coup c voulu le commentaire sur le update en dessous ,
	this->update(p->personnel);//comme ça quand tu update une personne, tu update directement son personnel + son adresse yes
	this->update(p->adresse);
}


void NS_Comp_Svc::CLservices::add(Personne^ p)
{
	System::String^ sql;

	sql = "INSERT INTO Personne (nom, prenom,BoolSuppr) VALUES('" + p->Nom + "','" + p->Prenom + "','" + p->BoolSuppr + "');SELECT SCOPE_IDENTITY() AS 'Identity'";
	
	
	int idPersonne = this->oCad->insert(sql);
	p->ID_Personne = idPersonne;

	this->add(p->adresse);
	p->personnel->ID_Adresse = p->adresse->ID_Adresse;//qui sera rempli via le add juste avant
	p->personnel->ID_Personne = p->ID_Personne;
	this->add(p->personnel);
	
	//en fait la ta relation est mauvaise comme faut créer un habite faudrait limite passer un idPersonnel a l'add
	//normalement on devrait insert l'adresse, puis récup l'id géné après on en aurait besoin pour clients mais en 2min je peux modif la bdd
	//mhhh autant le faire ouais jpense, vire la table habite et met l'id adresse dans personnel ok mais ducoup je fait ca mais on auras le problem pour client
	//yes yes c pas un problme cc juste une façon de faire différente ok  ,n pour evité les dependence cyclique nan c dans l'autre sens le 1,1 1,
} 

void NS_Comp_Svc::CLservices::deletePerso(int IdPersonne){//pareil renome del (car delete est un mot clé reservé en c++)

	System::String^ sql;

	this->oMappTB->setId(IdPersonne);
	this->oMappTB->setBoolSuppr();
	sql = this->oMappTB->DeletePerso();

	this->oCad->actionRows(sql);

}

void NS_Comp_Svc::CLservices::update(Personnel^ pl) {//je transformer en ca

	System::String^ sql;
	sql = "UPDATE Personnel set DateEmbauche = '" + pl->DateEmbauche.ToString("yyyy/MM/dd hh:MM:ss") + "', ID_Personnel_Superieur = " + (pl->ID_Personnel_Superieur->Equals(0) ? "NULL" : System::Convert::ToString(pl->ID_Personnel_Superieur)) + " WHERE ID_Personnel = " + pl->ID_Personnel;
	this->oCad->actionRows(sql);
}

void NS_Comp_Svc::CLservices::add(Personnel^ p)
{
	System::String^ sql;
	//étrange mon ID_Personnel_Superieur devrait etre a 0 et ma condition ternaire devrait mettre soit null soit la val en fonction

	System::String^ noobmode;
	
	if(p->ID_Personnel_Superieur->Equals(0))//ça va me permettre de savoir si ma condition marche avec le debuuger
		noobmode =  "NULL";
	else
		noobmode = System::Convert::ToString(p->ID_Personnel_Superieur);//donc 0 != 0 jdeviens fou ?

	sql = "Insert into Personnel(DateEmbauche,ID_Personnel_Superieur,ID_Personne,ID_Adresse) VALUES('" + p->DateEmbauche.ToString("yyyy/MM/dd hh:MM:ss") + "'," +  noobmode + ","+p->ID_Personne+","+p->ID_Adresse+");SELECT SCOPE_IDENTITY() AS 'Identity'";


	int idPersonnel = this->oCad->insert(sql);
	p->ID_Personnel = idPersonnel;
}


void NS_Comp_Svc::CLservices::update(Adresse^ a) {

	System::String^ sql;
	sql = "UPDATE Adresse set Ville = '" + a->Ville + "', CP = " + a->CP + ", Ligne = '" + a->Ligne + "' where ID_Adresse = " + a->ID_Adresse;
	this->oCad->actionRows(sql);
}

void NS_Comp_Svc::CLservices::add(Adresse^ a)
{
	System::String^ sql;

	sql = "INSERT INTO Adresse(Ville,CP,Ligne,AdresseFact,AdresseLivr)values('" + a->Ville + "'," + a->CP + ",'" + a->Ligne + "','" + a->AdresseFact + "','" + a->AdresseLivr + "');SELECT SCOPE_IDENTITY() AS 'Identity'";

	
	int idAdrese = this->oCad->insert(sql);
	a->ID_Adresse = idAdrese;
	//INSERT INTO Personne (nom, prenom,BoolSuppr) VALUES('" + p->Nom + "','" + p->Prenom + "','" + p->BoolSuppr + "');Insert into Personnel(DateEmbauche,ID_Personnel_Superieur,ID_Personne) VALUES('" + p->personnel->DateEmbauche + "'," + p->personnel->ID_Personnel_Superieur + ",@@IDENTITY);Insert into Habite(ID_Personnel,ID_Adresse)values(@@IDENTITY,(select ID_Adresse from Adresse where convert(char(30),Ville) = '" + p->adresse->Ville + "' and CP = " + p->adresse->CP + " and convert(char(50),Ligne) = '" + p->adresse->Ligne + "' and AdresseFact = '" + p->adresse->AdresseFact + "' and AdresseLivr = '" + p->adresse->AdresseLivr + "'))";

	//TODO faire pareil que dans le add de Personnel
}