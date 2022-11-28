#include "lib_grupo2.h"

int main (int argc,char *argv[])
{
    int tiempo_preparacion;
    int tiempo_lectura;
    unsigned int read_buf;
    int num_bytes;
    int cont;
    int cont2;
    struct termios tty;
    int serial_port;
    
    int num_part;

//esto permite conectar el arduino a este programa solo se configura la salida
//arduino y la velocidad de transmision de datos
    cout << "Ingrese la cantidad de participantes: "<< endl;
    cin >>num_part;
    participantes participante[num_part];
    //write (serial_port,"S",sizeof(char));
    //sleep(10);


//funcion para que el tiempo de preparacion y tiempo de lectura este muerto mientras transcurre
    for (cont=0; cont < num_part; cont ++)
    { 
        config_tty ("/dev/ttyS0",&tty,B9600,&serial_port);
        
        participante[cont].set_participantes();
        tiempo_preparacion=stoi(argv[1]); //prende el amarillo
        tiempo_lectura=stoi(argv[2]);    //prende el verde

        sleep(2);
        write (serial_port,"s",sizeof(char));
        
        cout << "¡PREPARATE!"  <<endl ;
        sleep(tiempo_preparacion);
        write (serial_port,"r",sizeof(char));
        cout << "¡EMPIEZA A PULSAR!" <<endl;
        sleep(tiempo_lectura);
    
        if (num_bytes > 0) {
            cout << num_bytes << endl;
        }

        write (serial_port,"S",sizeof(char));
        num_bytes = read(serial_port,&read_buf,sizeof(read_buf));
        cout <<"llego hasta aqui:"<< read_buf <<"  en  "<<argv[2]<<" segundos"<< endl;
        participante[cont].set_pushed((char)read_buf);

        //cout << "su puntaje Bytes: "<< read_buf << endl;
        //cout << "Su puntaje es: "<< num_bytes << endl;
        printf ("\n %d\n ",(char) read_buf);
        close (serial_port);
  

    }
    for (cont2 = 0; cont2 < num_part; cont2 ++)
    {
        //Impresion de los datos
        participante[cont2].ImprimirInfo();
    } 
    return 0;
}