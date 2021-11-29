#include "Services.h"
#include "Personnel.h"
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
System::Collections::ArrayList^ NS_Comp_Svc::CLservices::select()
{
	System::Data::DataSet^ ds = this->oCad->getRows(this->oMappTB->Select(), "a");

	System::Collections::ArrayList^ l = gcnew System::Collections::ArrayList();
	for (int i = 0;i < ds->Tables["a"]->Rows->Count;i++) {
		Personnel^ p = gcnew Personnel();
		p->ID_Personne = (int)ds->Tables["a"]->Rows[i]->ItemArray[0];
		p->ID_Personnel = (int)ds->Tables["a"]->Rows[i]->ItemArray[1];
		p->ID_Adresse = (int)ds->Tables["a"]->Rows[i]->ItemArray[2];
		p->Nom = (String^) ds->Tables["a"]->Rows[i]->ItemArray[3];
		p->Prenom = (String^) ds->Tables["a"]->Rows[i]->ItemArray[4];
		p->DateEmbauche = (DateTime^) ds->Tables["a"]->Rows[i]->ItemArray[5];
		p->ID_Personnel_Superieur = (int^) ds->Tables["a"]->Rows[i]->ItemArray[6];
		p->Ville = (String^)ds->Tables["a"]->Rows[i]->ItemArray[7];
		p->CP = (int^)ds->Tables["a"]->Rows[i]->ItemArray[8];
		p->Ligne = (String^)ds->Tables["a"]->Rows[i]->ItemArray[9];
		l->Add(p);
	}
	return l;
}
void NS_Comp_Svc::CLservices::update(int IdPersonne,int IdAdresse, System::String^ nom, System::String^ prenom, System::DateTime^ DateEmbauche, int IdSuperieur, System::String^ Ville, int CP, System::String^ Ligne) {

	System::String^ sql;

	this->oMappTB->setId(IdPersonne);
	this->oMappTB->setIdAdresse(IdAdresse);
	this->oMappTB->setNom(nom);
	this->oMappTB->setPrenom(prenom);
	this->oMappTB->setDateEmbauche(DateEmbauche);
	this->oMappTB->setIdSuperieur(IdSuperieur);
	this->oMappTB->setVille(Ville);
	this->oMappTB->setCP(CP);
	this->oMappTB->setLigne(Ligne);
	sql = this->oMappTB->Update();

	this->oCad->actionRows(sql);

}
void NS_Comp_Svc::CLservices::ajouterUnPersonnel(System::String^ nom, System::String^ prenom, System::DateTime^ DateEmbauche,int IdSuperieur,System::String^ Ville,int CP,System::String^ Ligne)
{
	System::String^ sql;

	this->oMappTB->setNom(nom);
	this->oMappTB->setPrenom(prenom);
	this->oMappTB->setDateEmbauche(DateEmbauche);
	this->oMappTB->setIdSuperieur(IdSuperieur);
	this->oMappTB->setVille(Ville);
	this->oMappTB->setCP(CP);
	this->oMappTB->setLigne(Ligne);
	sql = this->oMappTB->Insert();

	this->oCad->actionRows(sql);
}
void NS_Comp_Svc::CLservices::deletePerso(int IdPersonne){

	System::String^ sql;

	this->oMappTB->setId(IdPersonne);
	this->oMappTB->setBoolSuppr();
	sql = this->oMappTB->DeletePerso();

	this->oCad->actionRows(sql);

}