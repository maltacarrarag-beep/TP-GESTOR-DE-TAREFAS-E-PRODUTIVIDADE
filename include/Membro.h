#ifndef MEMBRO_H
#define MEMBRO_H

#include <string>

/**
 * @brief Representa um membro da equipe no sistema.
 *
 * Controla a carga de trabalho do membro, impedindo que ele receba
 * mais tarefas do que o limite definido (LIMITE_CARGA).
 */
class Membro {
public:

    /**
     * @brief Constrói um membro com carga inicial zero.
     * @param nome Nome do membro da equipe.
     */
    Membro(const std::string& nome);

    /// @brief Retorna o nome do membro.
    std::string getNome() const;

    /// @brief Retorna a carga atual (numero de tarefas atribuidas).
    int getCarga() const;

    /// @brief Incrementa a carga do membro em 1.
    void incrementarCarga();

    /// @brief Decrementa a carga do membro em 1. Nao permite valor negativo.
    void decrementarCarga();

    /**
     * @brief Verifica se o membro esta sobrecarregado.
     * @return true se a carga ultrapassar LIMITE_CARGA.
     */
    bool estaSobrecarregado() const;

    /// @brief Exibe os dados do membro no terminal.
    void exibir() const;

private:
    std::string nome;       ///< Nome do membro.
    int carga;              ///< Numero de tarefas atribuidas atualmente.

    /// @brief Limite maximo de tarefas antes de considerar o membro sobrecarregado.
    static const int LIMITE_CARGA = 3;
};

#endif // MEMBRO_H