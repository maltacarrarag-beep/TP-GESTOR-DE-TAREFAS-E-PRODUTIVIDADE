#include "membro.h"
#include <iostream>

using namespace std;

Membro::Membro(const string& nome)
    : nome(nome), carga(0) {
}

string Membro::getNome() const {
    return nome;
}

int Membro::getCarga() const {
    return carga;
}

void Membro::incrementarCarga() {
    carga++;
}

void Membro::decrementarCarga() {
    if (carga > 0) {
        carga--;
    }
}

bool Membro::estaSobrecarregado() const {
    return carga > LIMITE_CARGA;
}

void Membro::exibir() const {
    cout << "Membro: " << nome
         << " | Carga: " << carga;

    if (estaSobrecarregado()) {
        cout << " (SOBRECARREGADO)";
    }

    cout << endl;
}