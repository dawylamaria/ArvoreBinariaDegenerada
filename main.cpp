#include <iostream>
using namespace std;

struct NoArvore {
    int data;
    NoArvore* esquerda;
    NoArvore* direita;
};

void preOrdem(NoArvore* raiz) {
    if (raiz != NULL) {
        cout << raiz->data << " ";
        preOrdem(raiz->esquerda);
        preOrdem(raiz->direita);
    }
}

bool arvoreDegenerada(NoArvore* raiz) {
    if (raiz == NULL) {
        return true;
    } else {
        if ((raiz->esquerda != NULL && raiz->direita == NULL) || (raiz->esquerda == NULL && raiz->direita != NULL)) {
    	return true;
	} else {
    	return arvoreDegenerada(raiz->esquerda) && arvoreDegenerada(raiz->direita);
}

    }
}

int main() {
    NoArvore* raiz = new NoArvore;
    raiz->data = 1;
    raiz->esquerda = NULL;
    raiz->direita = NULL;

    NoArvore* elementoEsquerda = new NoArvore;
    elementoEsquerda->data = 2;
    elementoEsquerda->esquerda = NULL;
    elementoEsquerda->direita = NULL;

    raiz->esquerda = elementoEsquerda;

    NoArvore* elementoEsquerda2 = new NoArvore;
    elementoEsquerda2->data = 4;
    elementoEsquerda2->esquerda = NULL;
    elementoEsquerda2->direita = NULL;

    elementoEsquerda->esquerda = elementoEsquerda2;

    NoArvore* elementoDireita = new NoArvore;
    elementoDireita->data = 3;
    elementoDireita->esquerda = NULL;
    elementoDireita->direita = NULL;

    raiz->direita = elementoDireita;


    cout << "Arvore degenerada: ";
    preOrdem(raiz);
    cout << endl;

    cout << "A arvore eh degenerada? " << arvoreDegenerada(raiz) << endl;

    delete raiz->direita->direita;
    delete raiz->direita;
    delete raiz;

    return 0;
}
