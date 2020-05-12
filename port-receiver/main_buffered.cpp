#include <yarp/os/all.h>
#include <iostream>
#include <yarp/sig/Vector.h>

using namespace yarp::os;
using namespace yarp::sig;
using namespace std;


int main(int argc, char *argv[]) {
    Network yarp;
    BufferedPort<Vector> port;
    Network::connect("/examples/port/sender","/examples/port/receiver");

    int i = 0;
    int count = 0;

    while(true){
        Vector* v = port.read(true); //con delay e read(true) prendo tutti i dati e mantiente l'alternanza pari/dispari
        if(v){                       //con read(false) spesso leggo un vettore vuoto, leggo troppo in fretta.
            int size = (*v).size();
            std::cout << size ": ";
            printf(*v);
            std::cout << std::endl;
        }else{
            std::cout<< "Nessun dato" << ", ";
            std::cout<< count <<std::endl;
        }
    }
port.close();
return 0;
}


    p.close();
    return 0;
}