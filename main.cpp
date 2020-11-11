/************************************************************************************************/
/*** Topic: Hodgkin–Huxley model               Ali-Seif                                       ***/
/*** Version Release 17.12 rev 11256                                                          ***/
/*** Date: 1397/3/1                                                                           ***/
/*** Code implemented in CodeBlocks C++ compiler (v. 17.12),                                  ***/
/*** MSI: PX60 6QD/ DDR4                                                                      ***/
/*** Run under a Intel® Core™ i7-6700HQ CPU @ 2.60GHz × 64 based processor with 16 GB RAM     ***/
/************************************************************************************************/
#include <iostream>
#include <math.h>

using namespace std;



double alphaN(double v){
    return 0.01*(v+50)/(1-exp(-(v+50)/10));
}
double betaN(double v){
    return 0.125*exp(-(v+60)/80);
}
double alphaM(double v){
    return 0.1*(v+35)/(1-exp(-(v+35)/10));
}
double betaM(double v){
    return 4.0*exp(-0.0556*(v+60));
}
double alphaH(double v){
    return 0.07*exp(-0.05*(v+60));
}
double betaH(double v){
    return 1/(1+exp(-(0.1)*(v+30)));
}


int main()
{
        int   step=         15000;
    float v[step] =    { 0.0 };
    float h[step] =    { 0.0 };
    float n[step] =    { 0.0 };
    float m[step] =    { 0.0 };
    float dt=            0.025;



//__________Define the parameters____________/



    float I =        7;
    float Cm =         1.0;        //microFarad

    int   ENa=         50;         //miliVolt
    int   EK=          -77;        //miliVolt
    int   El=          -54.4;        //miliVolt

    int   g_Na=         120;         //mScm-2
    int   g_K=          36;          //mScm-2
    float g_l=          0.03;        //mScm-2

//=============First neurons===========


    float INa1=         0.0;
    float IK1=          0.0;
    float Il1=          0.0;

//_____________Fixed values___________________/




    v[0]=-65;
    m[0] = alphaM(v[0])/(alphaM(v[0])+betaM(v[0]));
    n[0] = alphaN(v[0])/(alphaN(v[0])+betaN(v[0]));
    h[0] = alphaH(v[0])/(alphaH(v[0])+betaH(v[0]));





    float k1;
    float k2;
    float k3;
    float k4;



    float gNa ;
    float gK ;
    float gl ;
    float INa ;
    float IK ;
    float Il ;

    k1 = dt*((alphaN(v[0]))*(1-(n[0]))-(betaN(v[0]))*(n[0]));
  cout<<'\t'<<k1<<endl;

for(int  i=1; i<=step; i++) {


    k1 = dt*((alphaN(v[i-1]))*(1-(n[i-1]))-(betaN(v[i-1]))*(n[i-1]));
    k2 = dt*(alphaN(v[i-1])*(1-(n[i-1])+0.5*k1)-betaN(v[i-1])*(n[i-1]+0.5*k1));
    k3 = dt*(alphaN(v[i-1])*(1-(n[i-1])+0.5*k2)-betaN(v[i-1])*(n[i-1]+0.5*k2));
    k4 = dt*(alphaN(v[i-1])*(1-(n[i-1])+k3)-betaN(v[i-1])*(n[i-1]+k3));
    n[i]=(n[i-1] + (1/6)*(k1 + 2*k2 + 2*k3 + k4));

    k1 = dt*(alphaM(v[i-1])*(1-(m[i-1]))-betaM(v[i-1])*(m[i-1]));
    k2 = dt*(alphaM(v[i-1])*(1-(m[i-1])+0.5*k1)-betaM(v[i-1])*(m[i-1]+0.5*k1));
    k3 = dt*(alphaM(v[i-1])*(1-(m[i-1])+0.5*k2)-betaM(v[i-1])*(m[i-1]+0.5*k2));
    k4 = dt*(alphaM(v[i-1])*(1-(m[i-1])+k3)-betaM(v[i-1])*(m[i-1]+k3));
    m[i]=(m[i-1] + (1/6)*(k1 + 2*k2 + 2*k3 + k4));

    k1 = dt*(alphaH(v[i-1])*(1-(h[i-1]))-betaH(v[i-1])*(h[i-1]));
    k2 = dt*(alphaH(v[i-1])*(1-(h[i-1])+0.5*k1)-betaH(v[i-1])*(h[i-1]+0.5*k1));
    k3 = dt*(alphaH(v[i-1])*(1-(h[i-1])+0.5*k2)-betaH(v[i-1])*(h[i-1]+0.5*k2));
    k4 = dt*(alphaH(v[i-1])*(1-(h[i-1])+k3)-betaH(v[i-1])*(h[i-1]+k3));
    h[i]=(h[i-1] + (1/6)*(k1 + 2*k2 + 2*k3 + k4)) ;

    gNa = g_Na*h[i-1]*pow(m[i-1],3);
    gK = g_K*pow(n[i-1],4);
    gl = g_l;
    INa = gNa*(v[i-1]-ENa);
    IK = gK*(v[i-1]-EK);
    Il = gl*(v[i-1]-El);

    k1 = dt*((1/Cm)*(I-(INa+IK+Il)));
    k2 = dt*((1/Cm)*((I-(INa+IK+Il)) + (0.5*k1)));
    k3 = dt*((1/Cm)*(I-(INa+IK+Il) + (0.5*k2)));
    k4 = dt*((1/Cm)*(I-(INa+IK+Il) + (k3)));
    v[i]=(v[i-1] + (1/6)*(k1 + 2*k2 + 2*k3 + k4));




}

    return 0;
}
