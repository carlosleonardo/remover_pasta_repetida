#include <filesystem>
#include <iostream>
#include <vector>

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
    std::vector<std::filesystem::path> pastas_para_remover;
    for (const auto &entrada: std::filesystem::recursive_directory_iterator(
             pasta_raiz, std::filesystem::directory_options::skip_permission_denied)) {
        if (entrada.is_directory() && entrada.path().filename() == pasta_remover) {
            pastas_para_remover.push_back(entrada.path());
        }
    }

    for (const auto &pasta: pastas_para_remover) {
        std::error_code ec;
        std::filesystem::remove_all(pasta, ec);
        if (ec) {
            std::cerr << "Erro ao remover pasta " << pasta.string() << ": " << ec.message() << std::endl;
        } else {
            std::cout << "Removida pasta: " << pasta.string() << std::endl;
        }
    }
}
