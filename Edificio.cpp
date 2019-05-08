#include <iostream>
#include <fstream>
#include <cmath>
#include <math.h>
using namespace std;
void leapfrog(float inicial, float finali, float dt);

void otro(float inicial, float finali, float dt, float omega, string archivo);
int main()
{
    float omega2=0.402837;
    float omega1=4.04266;
    float omega3= 3.92266;
    float omega4=2.32274;
    leapfrog(0.0, 20.0, 0.1);
    otro(0.0, 20.0, 0.1, omega1, "datoslp1.dat");
    otro(0.0, 20.0, 0.1, omega2, "datoslp2.dat");
    otro(0.0, 20.0, 0.1, omega3, "datoslp3.dat");
    otro(0.0, 20.0, 0.1, omega4, "datoslp4.dat");
    return(0); 
}

void leapfrog(float inicial, float finali, float dt)
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
    outfile.open("datoslp.dat");
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
    // arreglo de omegas
    float contador=0;
    float omegas[100];
    float arreglo[100];
    float valor_inicial=0.2;
    arreglo[0]=0.2;
    float valor=0; 
    float espacio=((3-0.2)/(99));
    for(int i=1; i<100; i++)
    {
        valor=valor_inicial+(espacio);
        arreglo[i]=valor;
        valor_inicial=valor;
        
        
        
    }
    
    for(int i=0;i<100;i++)
    {
        omegas[i]=arreglo[i]*sqrt(k/m);
    }
    float posicion1[100];
    float posicion2[100];
    float posicion3[100];
    int j=0;
    int contador2=0;
    while(j<9900)  
        {
            if(j%100==0)
            {
                contador2=contador2+1;
            }


                V1viejo=V1nuevo;
                U1viejo=U1nuevo;
                V2viejo=V2nuevo;
                U2viejo=U2nuevo;
                V3viejo=V3nuevo;
                U3viejo=U3nuevo;
                V1viejo= V1viejo-(dt/2)*(1/m)*((-gamma*V1viejo)-(2*k*U1viejo)+(k*U2viejo)+sin(omegas[contador2]*inicial));
                V1nuevo= V1viejo+dt*(1/m)*((-gamma*V1viejo)-(2*k*U1viejo)+(k*U2viejo)+sin(omegas[contador2]*inicial));
                U1nuevo= U1viejo+V1nuevo*dt;
                if(abs(U1nuevo)>U1viejo)
                {
                    posicion1[contador2]=abs(U1nuevo);
                }
                else
                {
                    posicion1[contador2]=abs(U1viejo);
                }
                V2viejo= V2viejo-(dt/2)*(1/m)*((-gamma*V2viejo)+(k*U1viejo)-(2*k*U2viejo)+(k*U3viejo));
                V2nuevo=V2viejo+dt*(1/m)*((-gamma*V2viejo)+(k*U1viejo)-(2*k*U2viejo)+(k*U3viejo));
                U2nuevo=U2viejo+V2nuevo*dt;
                if(abs(U2nuevo)>U2viejo)
                {
                    posicion2[contador2]=abs(U2nuevo);
                }
                else
                {
                    posicion2[contador2]=abs(U2viejo);
                }
                V3viejo= V3viejo-(dt/2)*(1/m)*((-gamma*V3viejo)+(k*U2viejo)-(k*U3viejo));
                V3nuevo= V3viejo+dt*(1/m)*((-gamma*V3viejo)+(k*U2viejo)-(k*U3viejo));
                U3nuevo=U3viejo+V3nuevo*dt;
                if(abs(U3nuevo)>U3viejo)
                {
                    posicion3[contador2]=abs(U3nuevo);
                }
                else
                {
                    posicion3[contador2]=abs(U3viejo);
                }

                j=j+1;
            }
            
           
        
        
    outfile.open("datos_omega.dat");
    for(int i=0; i<100; i++)
    {
          outfile <<posicion1[i] <<" "<< posicion2[i] <<" "<< posicion3[i] <<" "<< omegas[i] <<endl;   
    }
    outfile.close();

}

void otro(float inicial, float finali, float dt, float omega, string archivo)
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