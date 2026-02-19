#include <filesystem>
#include <iostream>

void remover_pasta_repetida(const std::string &pasta_raiz, const std::string &pasta_remover);

int main() {
    setlocale(LC_ALL, ".UTF-8");
    std::cout << "Remove pasta repetida" << std::endl;
    std::cout << "Informe pasta raiz: ";;
    std::string pastaRaiz;
    std::getline(std::cin, pastaRaiz);
    if (!std::filesystem::exists(pastaRaiz)) {
        std::cout << "Pasta raiz não existe." << std::endl;
        return -1;
    }
    std::cout << "Pasta a remover: ";;
    std::string pastaRemover;
    std::getline(std::cin, pastaRemover);
    remover_pasta_repetida(pastaRaiz, pastaRemover);
    return 0;
}

void remover_pasta_repetida(const std::string &pasta_raiz, const std::string &pasta_remover) {
    for (const auto &entrada: std::filesystem::recursive_directory_iterator(pasta_raiz)) {
        if (entrada.is_directory() && entrada.path().filename() == pasta_remover) {
            std::error_code ec;
            std::filesystem::remove_all(entrada.path(), ec);
            if (ec) {
                std::cerr << "Erro ao remover pasta " << entrada.path().string() << ": " << ec.message() << std::endl;
            } else {
                std::cout << "Removida pasta: " << entrada.path().string() << std::endl;
            }
        }
    }
}
