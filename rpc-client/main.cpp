#include <yarp/os/all.h>
#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace yarp::os;
using namespace std;

int main(int argc, char *argv[])
{
    Network yarp;
    RpcClient port;
    port.open("/rpcClient");
    Bottle cmd;

    int ct = 0;
    int k = 0;
    string operation[4] = {"Addition", "Multiplication", "Division", "Subtraction"};
    int values[100];

    for (ct = 0; ct <= 100; ct++)
    {
        if (port.getOutputCount() == 0)
        {
            printf("Trying to connect...\n");
            yarp.connect("/rpcClient", "/rpcServer");
        }
        else
        {
            values[ct - 1] = rand() % 100 + 1;
            cmd.addString(operation[rand() % 4]);
            cmd.addInt(ct);

            for (k = 0; k < ct; k++)
            {
                cmd.addInt(values[k]);
            }

            printf("Sending message: %s\n", cmd.toString().c_str());
            Bottle res;
            port.write(cmd, res);
            printf("Got response: %s\n", res.toString().c_str());

            cmd.clear();
        }
        Time::delay(1);
    }
}