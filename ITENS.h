#include <string>
using namespace std;
//IMPLEMENTA�AO ZIVIANI
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
typedef struct TipoItem {
    string titulo;
    string dia;
    string mes;
    string hora;
    string local;
} TipoItem;

typedef struct TipoCelula *TipoApontador;

typedef struct TipoCelula {
    TipoItem Item;
    TipoApontador Prox;
}TipoCelula;

typedef struct {
    TipoApontador Primeiro, Ultimo;
}TipoLista;

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
