#include <yarp/os/all.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>

using namespace yarp::os;
using namespace std;

int main(int argc, char *argv[])
{
    Network yarp;
    RpcServer port;
    port.open("/rpcServer");
    Bottle cmd;
    Bottle res;

    while (true)
    {
        string operation;
        int items;
        float r;
        int i;

        printf("Waiting...\n");

        if (port.read(cmd, true))
        {
            printf("Received: %s\n", cmd.toString().c_str());
            operation = cmd.get(0).asString();
            items = cmd.get(1).asInt();
            r = 0;
        }
        else
        {
            printf("I can't read from the port...");
            return 0;
        }

        if (operation.compare("Multiplication") == 0)
        {
            for (int i = 2; i <= items; i++)
            {
                r = r + (cmd.get(i).asFloat32() * cmd.get(i + 1).asFloat32());
            }
        }
        else if (operation.compare("Division") == 0)
        {
            for (int i = 2; i <= items; i++)
            {
                r = r + (cmd.get(i).asFloat32() / cmd.get(i + 1).asFloat32());
            }
        }
        else if (operation.compare("Subtraction") == 0)
        {
            for (int i = 2; i <= items; i++)
            {
                r = r + (cmd.get(i).asFloat32() - cmd.get(i + 1).asFloat32());
            }
        }
        else if (operation.compare("Addition") == 0)
        {
            for (int i = 2; i <= items; i++)
            {
                r = r + (cmd.get(i).asFloat32() + cmd.get(i + 1).asFloat32());
            }
        }
        else
        {
            printf("Invalid operation");
        }

        res.addFloat32(r);
        printf("Sending: %s\n", res.toString().c_str());
        port.reply(res);

        cmd.clear();
        res.clear();
    }
}