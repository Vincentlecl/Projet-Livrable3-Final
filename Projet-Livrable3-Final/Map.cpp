#include "Map.h"

System::String^ compMappage::Map::Select(void)
{
	System::String^ str = "";
	str += "select Personne.ID_Personne,Personnel.ID_Personnel,Adresse.ID_Adresse,Nom,Prenom,DateEmbauche,ID_Personnel_Superieur,Ville,CP,Ligne";
	str +=" from Personne";
	str += " join Personnel on Personne.ID_Personne = Personnel.ID_Personne";
	str += " join Adresse on Personnel.ID_Adresse = Adresse.ID_Adresse";
	str += " where BoolSuppr = 'False'";//PROPRE NEST-CE PAS ? oui bien plus
	return str;
}
System::String^ compMappage::Map::Insert(void)
{
	return "INSERT INTO Adresse(Ville,CP,Ligne,AdresseFact,AdresseLivr)values('" + this->Ville + "'," + this->CP + ",'" + this->Ligne + "','" + this->AdresseFact + "','" + this->AdresseLivr + "');INSERT INTO Personne (nom, prenom,BoolSuppr) VALUES('" + this->nom + "','" + this->prenom + "','" + this->BoolSuppr + "');Insert into Personnel(DateEmbauche,ID_Personnel_Superieur,ID_Personne) VALUES('" + this->DateEmbauche + "'," + this->IdSuperieur +",@@IDENTITY);Insert into Habite(ID_Personnel,ID_Adresse)values(@@IDENTITY,(select ID_Adresse from Adresse where convert(char(30),Ville) = '" + this->Ville + "' and CP = " + this->CP + " and convert(char(50),Ligne) = '" + this->Ligne + "' and AdresseFact = '" + this->AdresseFact + "' and AdresseLivr = '" + this->AdresseLivr + "'))";
}
System::String^ compMappage::Map::DeletePerso(void)
{
	return "Update Personne set BoolSuppr = '" + this->BoolSuppr + "' WHERE Personne.ID_Personne = " + this->IdPersonne + ";";
}
System::String^ compMappage::Map::Update(void)
{
	return "UPDATE Personne SET nom = '" + this->nom + "',prenom = '" + this->prenom + "' from Personne join Personnel on Personne.ID_Personne = Personnel.ID_Personne  WHERE Personne.ID_Personne = " + this->IdPersonne + "; UPDATE Personnel set DateEmbauche = '" + this->DateEmbauche + "',ID_Personnel_Superieur = " + this->IdSuperieur + "From Personnel join Personne on Personnel.ID_Personne = Personne.ID_Personne join Habite on Personnel.ID_Personnel = Habite.ID_Personnel WHERE Personne.ID_Personne = " + this->IdPersonne + ";UPDATE Adresse set Ville = '" + this->Ville + "', CP = " + this->CP + ", Ligne = '" + this->Ligne + "' from Adresse join Habite on Habite.ID_Adresse = Adresse.ID_Adresse join Personnel on Personnel.ID_Personnel = Habite.ID_Personnel where Adresse.ID_Adresse = " + this->IdAdresse + ";";
}
void compMappage::Map::setId(int IdPersonne)
{
	this->IdPersonne = IdPersonne;
}
void compMappage::Map::setNom(System::String^ nom)
{
	this->nom = nom;
}
void compMappage::Map::setPrenom(System::String^ prenom)
{
	this->prenom = prenom;
}
void compMappage::Map::setDateEmbauche(System::DateTime^ DateEmbauche)
{
	this->DateEmbauche = DateEmbauche;
}
void compMappage::Map::setIdSuperieur(System::Int32^ IdSuperieur)
{
	this->IdSuperieur = IdSuperieur;
}
void compMappage::Map::setBoolSuppr(){

	this->BoolSuppr = true;
}
void compMappage::Map::setVille(System::String^ Ville) {

	this->Ville = Ville;
}
void compMappage::Map::setCP(System::Int32^ CP) {

	this->CP = CP;
}
void compMappage::Map::setLigne(System::String^ Ligne) {

	this->Ligne = Ligne;

}
void compMappage::Map::setIdAdresse(int IdAdresse) {

	this->IdAdresse = IdAdresse;

}



int compMappage::Map::getId(void) { return this->IdPersonne; }
System::String^ compMappage::Map::getNom(void) { return this->nom; }
System::String^ compMappage::Map::getPrenom(void) { return this->prenom; }