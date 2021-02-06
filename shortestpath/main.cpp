#include <iostream>
#include <fstream>

using namespace std;

void nuskaitymasIsFailo(int mas[6][6])
{
    ifstream file ("mat.txt");
    for(int i=0; i<6; i++)
    {
        for(int j=0; j<6; j++)
        {
            file>>mas[i][j];
        }
    }
    file.close();
    cout<<"Sekmingai nuskaityta is failo!"<<endl;
}
void spausdinimas (int mas[6][6])
{

    for(int i=0; i<6; i++)
    {
        for(int j=0; j<6; j++)
        {

            cout<<mas[i][j]<<" ";

        }
        cout<<endl;
    }

}
void ivedimas(int mas[6][6])
{

    for(int i=0; i<6; i++)
    {
        for(int j=0; j<6; j++)
        {

            cout<<"Iveskite: "<<i<<" "<<j<<endl;
            cin>>mas[i][j];
        }
    }

}
int kelioIeskojimas(int P[],int galas,int pradzia,int sk, int kelias[6])
{
    sk++;
    if(P[galas-1]==pradzia)
    {
        //cout<<P[galas-1];
        kelias[sk]=P[galas-1];
        return P[galas-1];
    }
    else
    {
        kelias[sk]=P[galas-1];
    kelioIeskojimas(P,P[galas-1],pradzia,sk, kelias);

    }

}
int main()
{
    int sk=-1;
    int kelias[6];
    int mas[6][6];
    int pradzia;
    int galas;
    cout<<"Iveskite nuo kokios virsunes pradeti: ";
    cin>>pradzia;
    cout<<"Iveskite iki kokios virsunes eisite: ";
    cin>>galas;
    if(pradzia>0 && pradzia<=6 && galas>0 && galas<=6)
    {

    nuskaitymasIsFailo(mas);
    //spausdinimas(mas);
    bool arYraToks=false;
    int S[]= {pradzia,0,0,0,0,0};
    int D[6];
    int P[]= {pradzia,pradzia,pradzia,pradzia,pradzia,pradzia};

    for(int i=pradzia-1; i<pradzia; i++)
    {
        for(int j=0; j<6; j++)
        {
            D[j]=mas[i][j];
        }
    }


        for(int i=0; i<5; i++)
        {
            int minimumoPozicija=-1;
            bool arRadome = false;
            arYraToks = false;
            int poz = 0;
            int minimun = 999999;
            for(int a=0; a<6; a++)
            {

                if(a==5)
                {
                    arRadome=true;
                }

                if(D[a]>0)
                {

                    for(int j=0; j<6; j++)
                    {
                        if(a+1!=S[j])
                        {
                            arYraToks=false;

                        }
                        else
                        {
                            arYraToks=true;
                            break;
                        }



                    }
                    if(arYraToks==false)
                    {
                        for(int b=0; b<6; b++)
                        {
                            if(i==4)
                            {
                                minimun=D[a];
                                minimumoPozicija=a+1;
                            }
                            else if(D[a]<=D[b] && D[b]>0)
                            {
                                if(D[a]<minimun)
                                {
                                    minimun=D[a];
                                    minimumoPozicija=a+1;

                                }

                            }

                        }
                    }

                }

            }

            if(arRadome==true && minimun<999999)
            {

                //Jeigu radome minimuma ir tokio dar nera

                for(int i=0; i<6; i++)
                {
                    if(S[i]==0)
                    {
                        S[i]=minimumoPozicija;
                        break;
                    }
                }

                for(int i=minimumoPozicija-1; i<minimumoPozicija; i++)
                {
                    for(int j=0; j<6; j++)
                    {
                        if(mas[i][j]>0 && D[j]!=0)
                        {
                            if(D[j]<0 && mas[i][j]+minimun>0)
                            {
                                D[j]=mas[i][j]+minimun;
                                P[j]=minimumoPozicija;
                            }
                            else if(mas[i][j]+minimun<D[j])
                            {
                                D[j]=mas[i][j]+minimun;
                                P[j]=minimumoPozicija;
                            }
                        }
                    }
                }


            }

    }

    cout<<"Atstumu masyvas:"<<endl;
    for(int i=0; i<6; i++)
    {
        cout<<D[i]<<" ";
    }
    cout<<endl;
    cout<<"Keliu masyvas:"<<endl;
    for(int i=0; i<6; i++)
    {
        cout<<P[i]<<" ";
    }


    cout<<endl;

    if(D[galas-1]>0)
    {
        kelioIeskojimas(P,galas,pradzia,sk,kelias);
    cout<<"Maziausias atstumas iki jums norimos virsunes: "<<D[galas-1]<<endl;
    cout<<"Jums reikes eiti per: ";
    for(int i=6-1; i>=0; i--)
    {
        if(kelias[i]<1000 && kelias[i]>0)
        {
            cout<<kelias[i]<<" ";
        }

    }
    cout<<galas<<" ";

    cout<<endl;
    }
    else
    {
        cout<<"Nuo jusu: "<<pradzia<<" virsunes iki: "<<galas<<" virsunes, kelio nera!"<<endl;
    }

    }
    else
    {
        cout<<"Tokios virsunes nera, bandykite is naujo"<<endl;
    }


    return 0;
}

