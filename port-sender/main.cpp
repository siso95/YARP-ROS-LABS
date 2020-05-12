#include <yarp/os/all.h>
#include <iostream>
#include <string>

using namespace yarp::os;

int main(int argc, char *argv[]) {
    Network yarp;
    Port p;
    bool ok  = p.open("/examples/port/sender");
    if (!ok) {
        std::cerr << "Failed to open port" << std::endl;
        return 1;
    }
    yarp.waitConnection("/examples/port/sender", "/examples/port/receiver");
    int max=100;
    for(int i=0; i<=max; i++){
            Bottle b;
            b.addInt32(i);
            std::cout << "Inviato: " + std::to_string(i) << std::endl;
            p.write(b);
            Time::delay(1);
    }
    p.close();
    return 0;
}
