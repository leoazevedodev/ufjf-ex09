#include <iostream>
#include "PilhaEncad.h"
#include "FilaEncad.h"

using namespace std;

FilaEncad* concatena(FilaEncad *f1,FilaEncad *f2)
{
    FilaEncad *filaResult = new FilaEncad();
    while(true != f1->vazia())
    {
        int val = f1->desenfileira();
        filaResult->enfileira(val);
    }

    while(true != f2->vazia())
    {
        int val = f2->desenfileira();
        filaResult->enfileira(val);
    }

    return filaResult;
}

void removeDaPilha(PilhaEncad *p, int x)
{
    PilhaEncad * pAux = new PilhaEncad();
    while(true != p->vazia())
    {
        int val = p->desempilha();
        if(val != x)
        {
            pAux->empilha(val);
        }
    }

    while(true != pAux->vazia())
    {
        int val = pAux->desempilha();
        p->empilha(val);
    }
}

int main()
{
    /// TESTE COM PILHA
    PilhaEncad p;

    for(int i = 0; i < 5; i++) p.empilha(i);
    cout << "Pilha apos inserir 5 valores" << endl;
    p.imprime();

    for(int i = 6; i < 10; i++) p.empilha(i);
    cout << "Pilha apos inserir mais 5 valores" << endl;
    p.imprime();

    /// TESTE COM FILA

    FilaEncad f;
    for(int i=0; i<5; i++) f.enfileira(i);
    cout << "Fila apos inserir 5 valores" << endl;
    f.imprime();

    for(int i = 6; i < 10; i++) f.enfileira(i);
    cout << "Fila apos inserir mais 5 valores" << endl;
    f.imprime();

    cout << "O tamanho da pilha e: " << p.tamaho() << endl;

    FilaEncad * fc1 = new FilaEncad();
    for(int i=0; i<5; i++) fc1->enfileira(i);

    FilaEncad * fc2 = new FilaEncad();
    for(int i=6; i<10; i++) fc2->enfileira(i);

    FilaEncad* x = concatena(fc1, fc2);

    PilhaEncad * pilha = new PilhaEncad();
    for(int i=0; i<5; i++) pilha->empilha(i);

    removeDaPilha(pilha, 2);
    removeDaPilha(pilha,1);
    cout << "Nova pilha removendo o caractere: ";
    pilha->imprime();

    delete pilha;
    delete fc1;
    delete fc2;


    return 0;
}
