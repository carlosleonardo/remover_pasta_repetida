# Removedor de Pastas Repetidas

## Objetivos
Remover uma pasta que aparece repetida numa hierarquia, como em Projetos Node, com a pasta node_modules

## Construindo
### Requisitos
- CMake
- Git(para clonar ou baixar o zip)
- Compilador C++ que implemente pelo menos o C++20(gcc, clang, etc.)
- CLion ou VS Code(opcional)

### Próximos passos
- Baixar do repositório com Git, ou se preferir, baixar o Zip do projeto no mesmo local do repositório GitHub:
'''bash git clone https://github.com/carlosleonardo/remover_pasta_repetida.git '''
- Navegar até o diretório onde foi clonado o projeto
- Executar o comando:
- '''bash
- cmake -B build -S . -G Ninja'''
- '''bash
- cmake --build build

  
