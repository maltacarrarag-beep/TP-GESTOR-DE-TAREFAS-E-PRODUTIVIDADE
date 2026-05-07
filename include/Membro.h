#ifndef MEMBRO_H
#define MEMBRO_H

#include <string>

class Membro {
public:
    Membro(const std::string& nome);

    std::string getNome() const;
    int getCarga() const;

    void incrementarCarga();
    void decrementarCarga();
    bool estaSobrecarregado() const;
    void exibir() const;

private:
    std::string nome;
    int carga;
    static const int LIMITE_CARGA = 3;
};

#endif // MEMBRO_H