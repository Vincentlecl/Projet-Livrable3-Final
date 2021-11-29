#include "Cad.h"

compData::Cad::Cad(void)
{
	this->sCnx = "Data Source=localHost;Initial Catalog=Projet-Groupe4;Persist Security Info=True;User ID=SA;Password=82RnAvRf3";

	this->sSql = "Rien";

	this->oCnx = gcnew System::Data::SqlClient::SqlConnection(this->sCnx);
	this->oCmd = gcnew System::Data::SqlClient::SqlCommand(this->sSql, this->oCnx);
	this->oDA = gcnew System::Data::SqlClient::SqlDataAdapter();
	this->oDs = gcnew System::Data::DataSet();

	this->oCmd->CommandType = System::Data::CommandType::Text;
	this->oCnx->Open();//on évite d'ouvrir / fermer la connexion a chaque req
}
System::Data::DataSet^ compData::Cad::getRows(System::String^ sSql, System::String^ sDataTableName)
{
	this->oDs->Clear();
	this->sSql = sSql;
	this->oCmd->CommandText = this->sSql;
	this->oDA->SelectCommand = this->oCmd;
	this->oDA->Fill(this->oDs, sDataTableName);
	return this->oDs;
}
void compData::Cad::actionRows(System::String^ sSql)
{
	this->sSql = sSql;
	this->oCmd->CommandText = this->sSql;
	this->oCmd->ExecuteNonQuery();
}
int compData::Cad::insert(System::String^ sSql)
{
	this->sSql = sSql;
	this->oCmd->CommandText = this->sSql;
	//this->oCmd->Prepare// ça serait la vraie bonne méthode mais trop complexe pr vous
	return System::Convert::ToInt32(this->oCmd->ExecuteScalar());
}