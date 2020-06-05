#include "Material.h"

Material::Material()
{
    titulo="";
    idMaterial=0;
}

Material::Material(int idM,string title){
    setidMaterial(idM);
    setTitulo(title);
}

void Material::setidMaterial(int idM){
    idMaterial=idM;
}

int Material::getidMaterial(){
    return idMaterial;
}

void Material::setTitulo(string title){
    titulo=title;
}

string Material::getTitulo(){
    return titulo;
}


