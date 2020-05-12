#include <yarp/os/all.h>
#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <string>

#define _USE_MATH_DEFINES
#include <math.h>

double pi = M_PI;

using namespace yarp::os;
using namespace std;

int main(int argc, char *argv[])
{
    Network yarp;
    RpcClient port;
    Port port2;
    port.open("/rpcClient");
    port2.open("/receiver");
    Bottle cmd;
    Bottle res;

    yarp.connect("/rpcClient", "/icubSim/head/rpc:i");
    yarp.connect("/icubSim/head/state:o", "/receiver");
    
    double pos;
    double sinpos;
    double aux = 0.1;
    double data;    
    
    while (true)
    {

        for (pos = -90; pos <= 90; pos = pos + aux)
        {
            port2.read(res, true);
            data = res.get(2).asDouble();
            cout << "Joint 2 position: " << data << endl;

            sinpos = 30 * sin(pos);

            cmd.addString("set");
            cmd.addString("pos");
            cmd.addInt(2);
            cmd.addInt(sinpos);

            printf("Sending message: %s\n", cmd.toString().c_str());
            port.write(cmd);

            if (pos >= 90)
                aux = -0.1;
            if (pos <= -90)
                aux = 0.1;

            cmd.clear();
            res.clear();
            Time::delay(1);
        }
    }
}
