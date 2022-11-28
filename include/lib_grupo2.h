#ifndef LIB_GRUPO2_H
#define LIB_GRUPO2_H

#include <iostream>
#include <string.h>
#include <unistd.h>
#include "tty_lib2.h"
using namespace std;

//aca se establece la clase a utilizar, con su parte 
class participantes {
	private:
		unsigned int  participante_id;
		string part_name;
		unsigned int num_pushed;
	public:
		participantes ();
		participantes (unsigned int participante_id, string part_name);
		
		void set_participantes();
		void set_pushed(unsigned int cant);

		unsigned int get_participante_id (unsigned int participante_id);
		string get_name(string part_name);
		unsigned int get_pushed(unsigned int num_pushed);
		
		unsigned int get_ImprimirInfo (unsigned int ImprimirInfo);

		//para imprimir info
		void ImprimirInfo();
		
	};

#endif