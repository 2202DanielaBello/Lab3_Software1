#include "lib_grupo2.h"
//#include <string>
//#include <istream>

using namespace std;
/**declaracion de los constructores
 * inicialcilzacion de las variables y funciones para la clase participantes
 * */

participantes :: participantes():participante_id(0),part_name(" "),num_pushed(0){}
participantes :: participantes(unsigned int id,string name):participante_id(id),part_name(name),num_pushed(0){}		 
void participantes:: set_participantes(){
    cout << "ingrese el id del partcipantes" << endl;
    cin >> participante_id;

    cout << "ingrese el nombre del participante:"<< endl;
    cin  >> part_name;
}
void participantes:: set_pushed(unsigned int cant){
    num_pushed =cant;
}

unsigned int participantes :: get_participante_id (unsigned int participante_id){
    return participante_id;
}
string participantes :: get_name(string part_name){
    return part_name;
}

unsigned int participantes :: get_pushed(unsigned int num_pushed){
    return num_pushed;
}

//Impresion de los datos
void participantes :: ImprimirInfo()
{
    cout <<"-----------------------------------------"<<'\n';
    cout <<"El nombre del participante es: "<<part_name<<'\n';
	cout <<"El ID participante es: "<< participante_id<<'\n';
	cout <<"El # de pulsaciones que tuvo es: "<<num_pushed <<'\n'; 
    cout <<"-----------------------------------------"<<'\n';
}