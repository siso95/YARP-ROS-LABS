#include <yarp/os/all.h>
#include <iostream>
#include <yarp/sig/Vector.h>

using namespace yarp::os;
using namespace yarp::sig;
using namespace std;

int main(int argc, char *argv[]) {
    Network yarp;
    int count = 0;
    BufferedPort<Vector> port;
    port.open("/examples/port/sender");
    while(true){
        yInfo() << "Invio dati";
        Vector& v = port.prepare();
        
        if(count % 2 == 0){ //EVEN
            v.resize(4);
            v[0] = count;
            v[1] = count + 1;
            v[2] = count + 2;
            v[3] = count + 3;
        }else{ //ODD
            v.resize(3);
            v[0] = count;
            v[1] = count + 1;
            v[2] = count + 2;
        }
        
        port.write();
        count++;
        if(count>2000) count=0;

        cout <<  v.size() << endl;
        Time::delay(1);
    }
    port.close();
    return 0;
}