#pragma once
#include "Map.h"
#include "Cad.h"
#include "Personne.h"

namespace NS_Comp_Svc
{
	ref class CLservices
	{
	private:
		compData::Cad^ oCad;
		compMappage::Map^ oMappTB;
	public:
		CLservices(void);
		System::Data::DataSet^ selectionnerToutesLesPersonnes(System::String^);//a remove


		//CRUD Personnes
		System::Collections::ArrayList^ selectPersonnes();
		void update(Personne^ p);
		void add(Personne^ p);
		void deletePerso(int IdPersonne);

		//CRUD Adresse
		void update(Adresse^ p);
		void add(Adresse^ p);

		//CRUD Personnel
		void update(Personnel^ pl);
		void add(Personnel^ p);

		// ok donc pour moi, faut que tu continues dans cette direction, tu fais a chaque fois le add/update et essaye de r�fl�chir en avance pour pr�parer ce
		//que l'interface aura besoin
		//Tu peux donc ici commencer � cr�er au moins toutes tes entit�es (les classes qui seront des copies des tables)
		// et pr�parer tout les insert au minimum (car il te le faudra a un moment ou un autre)
		// Pour clients ect...
		//jte laisse la dessus, essaye de pr�parer les entit�es et les requ�tes (prends exemple sur ce que je t'ai fait)
		// pour le client, pense � mettre une System::Collections::ArrayList^ d'adresses dedans et a voir mais tu auras surement besoin soit
		// de mettre une System::Collections::ArrayList^ de commandes
		// soit dans la commande d'avoir l'entit� client
		// si tu trouves �a gal�re d'avoir des listes d'entit�es dans d'autres, rien ne t'mp�che de faire sans et tu peux faire des entit�es style
		// ClientAvecCommandes dans laquelle tu as un client et une System::Collections::ArrayList^ de commandes :) yes je vais faire avent gestion client et gestion stock

		//TODO le reste :D t'es parti en mode quasi-machine la ok bon je fait la meme pour insert
		//ah oui attends jte montre juste l'insert bien
	};
}