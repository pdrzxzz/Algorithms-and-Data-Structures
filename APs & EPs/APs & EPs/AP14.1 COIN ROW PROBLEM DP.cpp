#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void print(vector<int> v){
    for(auto n: v){
        cout << n << " ";
    }
    cout << endl;
}

int main()
{
    //--INPUT
    int num_cases;
    cin >> num_cases;
    for(int i=0; i<num_cases; i++){
         int num_moedas;
         cin >> num_moedas;
         vector<int> moedas;
         moedas.push_back(0);
         for(int j=0; j<num_moedas; j++){
            int moeda;
            cin >> moeda;
            moedas.push_back(moeda);
         }



        //calcular maior quantia
        vector<int> F;
        F.push_back(0);
        F.push_back(moedas[1]);
        for(int j=2; j<num_moedas+1; j++){
            F.push_back(max(moedas[j] + F[j-2], F[j-1]));
        }
        int maior_quantia = F[num_moedas];



        //calcular moedas coletadas
        vector<int> moedas_coletadas;
        for(int k=num_moedas; k>=1; k--){
            if(moedas[k] + F[k-2] > F[k-1]){ //se a moeda foi coletada
                moedas_coletadas.push_back(moedas[k]); //adiciona
                k--; //pula para o indice k - 2
            }
        }

        reverse(moedas_coletadas.begin(), moedas_coletadas.end());


        //--output--
        cout << maior_quantia << endl;
        print(moedas_coletadas);

    }
    return 0;
}


