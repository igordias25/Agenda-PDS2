#include <iostream>
#include <string>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include "ITENS.h"

/*
    Grupo:  
        Igor de Paiva Dias
        Lorena Brito Andrade
        Laura Soares Shakespeare Pereira
        
*/

//IMPLEMENTAÇAO ZIVIANI
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
int Vazia(TipoLista Lista){
    return (Lista.Primeiro == Lista.Ultimo);
}

void FLVazia(TipoLista *Lista){
    Lista -> Primeiro = (TipoCelula*) new(TipoCelula);
    Lista -> Ultimo = Lista -> Primeiro;
    Lista -> Primeiro -> Prox = NULL;
}

void Insere(TipoItem x, TipoLista *Lista){
    Lista -> Ultimo -> Prox = (TipoCelula*) new(TipoCelula);
    Lista -> Ultimo = Lista -> Ultimo -> Prox;
    Lista -> Ultimo -> Item = x;
    Lista -> Ultimo -> Prox = NULL;
}



void Retira(TipoApontador p, TipoLista *Lista, TipoItem *Item){
    TipoApontador q;
    if (Vazia(*Lista) || p == NULL || p -> Prox == NULL) {
        cout << "Erro Lista vazia ou posicao nao existe" << endl;
        return;
    }
    q = p -> Prox;
    *Item = q -> Item;
    p -> Prox = q -> Prox;
    if (p -> Prox == NULL)
        Lista -> Ultimo = p;
    free(q);
}

void Imprime(TipoLista Lista){
    TipoApontador Aux;
    Aux = Lista.Primeiro -> Prox;
    cout << "COMPROMISSO  DATA(DD/MM)  HORAS    LOCAL"<<endl;
    while (Aux != NULL) {
        cout << Aux -> Item.titulo<<" \t ";
        cout << Aux -> Item.dia<<"/";
        cout << Aux -> Item.mes<<"  \t";
        cout << Aux -> Item.hora<<" Horas\t";
        cout << Aux -> Item.local << endl;
        Aux = Aux -> Prox;
    }
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

void preencher_Atualiza_Arquivo(TipoLista Lista){
    TipoApontador Aux;
    Aux=Lista.Primeiro -> Prox;
    ofstream arq1;
    arq1.open ("agenda.txt", ios::ate);
    if (arq1.is_open()) {
        while(Aux != NULL){
            arq1 << Aux -> Item.titulo << endl;
            arq1 << Aux -> Item.dia << endl;
            arq1 << Aux -> Item.mes << endl;
            arq1 << Aux -> Item.hora << endl;
            arq1 << Aux -> Item.local << endl;
            Aux=Aux->Prox;

        }
        arq1.close();
    }
    else {
        cout << "ERRO: arquivo nao foi aberto ou nao existe" << endl;
    }
}




void deleta_compromisso(TipoLista Lista, TipoItem x){
    string titulo;
    cout<<"Digite o titulo para deletar o compromisso"<<endl;
    cin>>titulo;
    TipoApontador Aux, aponta, apontaaux;
    int existe=0,apontadorachado=0;
    Aux = Lista.Primeiro -> Prox;
    apontaaux=Lista.Primeiro;
    while (Aux != NULL) {
        if((Aux -> Item.titulo) == titulo){
            existe=1;
            apontadorachado=1;
        }
        if(apontadorachado==1){
            aponta=apontaaux;
            apontadorachado++;
        }
        apontaaux=Aux;
        Aux=Aux -> Prox;
    }
    if(existe!=1){
        cout<<"NAO HA COMPROMISSO"<<endl;
    }

    Retira(aponta, &Lista, &x);
}

void procurar_compromisso(TipoLista Lista){
    string titulo;
    cout<<"Digite o titulo para procurar o compromisso"<<endl;
    cin>>titulo;

    TipoApontador Aux, aponta;
    int existe=0;
    Aux = Lista.Primeiro -> Prox;

    while (Aux != NULL) {
        if((Aux -> Item.titulo) == titulo){
            existe=1;
            aponta=Aux;
        }
        Aux=Aux -> Prox;
    }
    if(existe!=1){
        cout<<"NAO HA COMPROMISSO"<<endl;
    }

    if(existe==1){
        cout << "COMPROMISSO  DATA(DD/MM)  HORAS    LOCAL"<<endl;
        cout << aponta -> Item.titulo<<" \t   ";
        cout << aponta -> Item.dia<<"  \t ";
        cout << aponta -> Item.mes<<"  \t";
        cout << aponta -> Item.hora<<" Horas\t";
        cout << aponta -> Item.local << endl;

    }



}


int main(){
    TipoLista lista;
    TipoApontador p;
    TipoItem item,z;
    FLVazia(&lista);


    //ABRIR ARQUIVO E PREENCHER LISTA
    string linha;
    int aux_arquivo=0;

    ifstream arq2 ("agenda.txt", ios::in);
    if (arq2.is_open()) {
        while (! arq2.eof() ) {
            getline (arq2, linha);
            if(aux_arquivo==0){
                item.titulo=linha;
            }
            if(aux_arquivo==1){
                item.dia=linha;
            }
            if(aux_arquivo==2){
                item.mes=linha;
            }
            if(aux_arquivo==3){
                item.hora=linha;
            }
            if(aux_arquivo==4){
                item.local=linha;
                aux_arquivo=0;
                Insere(item, &lista);
            }
            aux_arquivo++;
        }
    arq2.close();
    }
    else {
        cout << "ERRO: arquivo nao foi aberto ou nao existe" << endl;
    }

    //MENU

    int ope;
    do{
        cout<< "1. Inserir um novo compromisso" << endl;
        cout<< "2. Listar todos os compromissos" << endl;
        cout<< "3. Remover um dos compromissos da lista" << endl;
        cout<< "4. Localizar um determinado compromisso" << endl;
        cout<< "5. Para finalizar o programa" << endl;
        cin>>ope;
        switch(ope){
            case 1:
                {
                    fflush(stdin);
                    cout << "Digite o titulo: ";
                    getline(cin,item.titulo);
                    cout << "Digite o dia: ";
                    getline(cin,item.dia);
                    cout << "Digite o mes: ";
                    getline(cin,item.mes);
                    cout << "Digite a hora: ";
                    getline(cin,item.hora);
                    cout << "Digite o local do compromisso: ";
                    getline(cin,item.local);
                    fflush(stdin);
                    Insere(item, &lista);
                    preencher_Atualiza_Arquivo(lista);
                    system("pause");
                    system("cls");

                }

            break;
            case 2:
                {
                    Imprime(lista);
                    system("pause");
                    system("cls");

                }
            break;
            case 3:
                {
                    deleta_compromisso(lista,z);
                    preencher_Atualiza_Arquivo(lista);
                    system("pause");
                    system("cls");

                }
            break;
            case 4:
                {

                    procurar_compromisso(lista);
                    system("pause");
                    system("cls");

                }
            break;
            case 5:
                {
                    cout<<"Ate mais!" << endl;
                }
            break;

            default:
                {
                    cout<<"Entrada incorreta!" << endl;
                }
        }
    }while (ope!= 5);

     return 0;

}
