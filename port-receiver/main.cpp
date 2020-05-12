#include <yarp/os/all.h>
#include <stdio.h>
#include <yarp/sig/Vector.h>

using namespace yarp::os;
using namespace yarp::sig;

int main(int argc, char *argv[]) {
    Network yarp;
    Port p;
    p.open("/examples/port/receiver");
    Network::connect("/examples/port/sender","/examples/port/receiver");

    for(int i=0; i<=100; i++){
        Bottle b;
        p.read(b);
        printf("Ricevuto: %s\n", b.toString().c_str());
    }

    p.close();
    return 0;
}