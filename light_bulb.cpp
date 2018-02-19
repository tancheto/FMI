#include<iostream>
using namespace std;

int main()
{
    int n,m,i,j,counter=1;

    cout<<"Razmernost:";cin>>n;
    cout<<"Bulbs:";cin>>m;

    if(m<=n*n)
    {

    int matr_in[n][n];

cout<<"Vuvedete matricata element po element:"<<endl;

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cin>>matr_in[i][j];
        }
    }

    cout<<"Gotova matrica:"<<endl;

       for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cout<<matr_in[i][j];
        }
        cout<<endl;
    }
    cout<<endl;

    bool matr_out[n][n];

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            matr_out[i][j]=0;
        }
    }

     for(i=0;i<n;i++)
                {
                for(j=0;j<n;j++)
                {
                cout<<matr_out[i][j];
                }
                cout<<endl;
                }
                cout<<endl;
while(counter<=m)
{
        for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(counter==matr_in[i][j])
                {  counter++;
                 if(j!=0){matr_out[i][j-1]=(!matr_out[i][j-1]);}
                 if(j!=n-1){matr_out[i][j+1]=(!matr_out[i][j+1]);}
                 if(i!=0){matr_out[i-1][j]=(!matr_out[i-1][j]);}
                 if(i!=n-1){matr_out[i+1][j]=(!matr_out[i+1][j]);}

                 for(i=0;i<n;i++)
                {
                for(j=0;j<n;j++)
                {
                cout<<matr_out[i][j];
                }
                cout<<endl;
                }
                cout<<endl;
                }

            else{continue;}

        }
    }


}
}
}
