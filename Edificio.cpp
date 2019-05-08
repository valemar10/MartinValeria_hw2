#include <iostream>
#include <fstream>
#include <cmath>
#include <math.h>
using namespace std;
void leapfrog(float inicial, float finali, float dt, string archivo);
int main()
{
    leapfrog(0.0, 20.0, 0.1, "datoslp.dat");
    return(0); 
}

void leapfrog(float inicial, float finali, float dt, string archivo)
{
    float V1nuevo=0;
    float U1nuevo=0;
    float V2nuevo=0;
    float U2nuevo=0;
    float V3nuevo=0;
    float U3nuevo=0;
    float m=1000;
    float gamma=0;
    float k=2000;
    float omega= 1*sqrt(k/m);
    float V1viejo;
    float U1viejo;
    float V2viejo;
    float U2viejo;
    float V3viejo;
    float U3viejo;
    ofstream outfile;
    outfile.open(archivo);
    while (inicial<finali)
    {
        V1viejo=V1nuevo;
        U1viejo=U1nuevo;
        V2viejo=V2nuevo;
        U2viejo=U2nuevo;
        V3viejo=V3nuevo;
        U3viejo=U3nuevo;
        outfile << U1nuevo <<" "<< U2nuevo <<" "<< U3nuevo <<" "<< inicial <<endl;
        V1viejo= V1viejo-(dt/2)*(1/m)*((-gamma*V1viejo)-(2*k*U1viejo)+(k*U2viejo)+sin(omega*inicial));
        V1nuevo= V1viejo+dt*(1/m)*((-gamma*V1viejo)-(2*k*U1viejo)+(k*U2viejo)+sin(omega*inicial));
        U1nuevo= U1viejo+V1nuevo*dt;
        V2viejo= V2viejo-(dt/2)*(1/m)*((-gamma*V2viejo)+(k*U1viejo)-(2*k*U2viejo)+(k*U3viejo));
        V2nuevo=V2viejo+dt*(1/m)*((-gamma*V2viejo)+(k*U1viejo)-(2*k*U2viejo)+(k*U3viejo));
        U2nuevo=U2viejo+V2nuevo*dt;
        V3viejo= V3viejo-(dt/2)*(1/m)*((-gamma*V3viejo)+(k*U2viejo)-(k*U3viejo));
        V3nuevo= V3viejo+dt*(1/m)*((-gamma*V3viejo)+(k*U2viejo)-(k*U3viejo));
        U3nuevo=U3viejo+V3nuevo*dt;
        inicial= inicial+dt;
          
    }
    outfile.close();
    
}