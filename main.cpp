#include <stdio.h>
#include <math.h>
#include <fstream>
#include <iostream>
#include <conio.h>
#include <time.h>
#include <windows.h>

using namespace std;
typedef unsigned long long int Number;

Number isPrimeNumber(Number);
Number nwd(Number,Number);

int main() {
   srand(time(NULL));
   bool isPrime;
   Number tab1[102];

   Number k=1;
   for(Number n = 3; n < 10000000; n+=2)
   {
       if(isPrimeNumber(n)&&n>1000000&&k<=100)
          {
             tab1[k]=n;
             k++;

          }

   }
   Number p=0,q=0,x0=4,blum=8;
   while(nwd(x0,blum)!=1)
   {
   p=tab1[rand()%99+1];
   q=tab1[rand()%99+1];
   x0=tab1[rand()%99+1];
   blum=p*q;
   }
   cout<<"x^2: "<<x0*x0<<endl;
   cout<<"blum: "<<blum<<endl;
   cout<<"NWD: "<<nwd(x0,blum)<<endl;
   Number x[20001];
   Number u[20001];
   x[0]=(x0*x0)%blum;
   cout<<"x[0]: "<<x[0]<<endl;
   Number jedynki=0;
   Number zera=0;
   //obliczamy bluma dla ka¿dego miejsca w tablicy
   for(Number i=1;i<=20000;i++)
   {
    x[i]=(x[i-1]*x[i-1])%blum;
   }
   //wypelniamy zerami i jedynkami
   for(Number i=0;i<=20000;i++)
   {
       if(x[i]%2==0)
       {
           u[i]=0;
           zera++;
       }
       else
       {
           u[i]=1;
           jedynki++;
       }
   }
   cout<<endl<<"Test pojedynczych bitow"<<endl<<"jedynki "<<jedynki<<" zera "<<zera<<endl;
   if(jedynki>9725&&jedynki<10275)
    cout<<"Test pojedynczych bitow zaliczony"<<endl;
    else
    cout<<"Test pojedynczych bitow nie zaliczony"<<endl;
   Number seria=0,dluga_seria=0;
   Number serie[30];
   cout<<endl<<"Test serii"<<endl<<"serie: "<<endl;
      for(Number i=1;i<30;i++)
   {
       serie[i]=0;
   }
    for(Number i=0;i<20000;i++)
   {
    if(u[i]==u[i+1]&&seria<26)
    {
        seria++;
    }
    else if(seria<26)
    {
        if(seria<=5)
        {
        serie[seria]+=1;
        seria=0;
        }
        else
        {
        serie[6]+=1;
        seria=0;
        }
    }
    else{
        dluga_seria++;
    }
   }
      for(Number i=1;i<7;i++)
   {
       if(i<6)
       cout<<i<<"  "<<serie[i]<<endl;
       else
       cout<<i<<"+ "<<serie[i]<<endl;
   }
if(serie[1]>2315&&serie[1]<2685&&serie[2]>1114&&serie[2]<1386&&serie[3]>527&&serie[3]<723&&serie[4]>240&&serie[4]<384&&serie[5]>103&&serie[5]<209&&serie[6]>103&&serie[6]<209)
{
 cout<<"Test serii zaliczony"<<endl;
}
else
{cout<<"Test serii nie zaliczony"<<endl;}

cout<<endl<<"Test dlugiej serii"<<endl;
if(dluga_seria==0)
   {
     cout<<"Test dlugiej serii zaliczony, ilosc dlugich serii "<<dluga_seria<<endl;
   }
else
    cout<<"Test dlugiej serii nie zaliczony, ilosc dlugich serii "<<dluga_seria<<endl;
cout<<endl<<"Test Pokerowy"<<endl;
   Number b=8,c=0;
   double tpokerowy[16];
   for(Number i=0;i<16;i++)
   {
       tpokerowy[i]=0;
   }
    for(Number i=0;i<20000;i=i+4)
    {
        for(Number j=0;j<4;j++)
           {
               c+=u[i+j]*b;
               b/=2;
           }
        tpokerowy[c]+=1;
        b=8;
        c=0;
    }
    double sumpoker=0;
    double sumpokerv2=0;
    for(Number i=0;i<16;i++)
    {
        sumpoker+=(tpokerowy[i]*tpokerowy[i]);
        sumpokerv2+=tpokerowy[i];
        cout <<i<< " is " << tpokerowy[i]<<endl;
    }
double test_pokerowy =0.0032*sumpoker-5000;
if(test_pokerowy>2,16&&test_pokerowy<46,17)
cout<<"Test pokerowy zaliczony z wartoscia: "<<test_pokerowy<<endl;
else
cout<<"Test pokerowy nie zaliczony: "<<test_pokerowy<<endl;

   cout<<"done";
   return 0;
}

// funkcja liczby pierwsze
Number isPrimeNumber(Number n) {
   bool isPrime = true;

   for(Number i = 3; i*i <= n; i+=2) {
      if (n%i == 0 || n%4!=3)
      {
         isPrime = false;
         break;
      }
   }
   return isPrime;
}

Number nwd(Number a,Number b){
while( a != b ){
    if( a < b ){ b -= a;} else {a -= b;}
  }
  return a;
}
