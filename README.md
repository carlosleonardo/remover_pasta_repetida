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
    ```bash 
      git clone https://github.com/carlosleonardo/remover_pasta_repetida.git
    ```
- Navegar até o diretório onde foi clonado o projeto
  e executar o comando:
  ```bash 
  cmake -B build -S . 
  ```

- Em seguida, execute o comando:
    ```bash 
    cmake --build build
    ```

- O executável gerado estará na pasta build, e pode ser executado com o comando:
  ```bash
  
    ./build/remover_pasta_repetida
    ```

Caso queira usar uma IDE, basta abrir o projeto com a IDE de sua preferência e configurar o CMake para gerar os arquivos
de build, como mostrado acima. Depois disso, basta compilar e executar o projeto normalmente.
Se ocorrer algum erro, verifique se o CMake e o compilador estão corretamente instalados e configurados no seu sistema.
Tente mudar o gerador do CMake para o Visual Studio, caso esteja usando o Windows, ou para o Makefiles, caso esteja
usando o Linux ou MacOS. Você pode fazer isso adicionando a opção -G ao comando cmake, como mostrado abaixo:

```bash
cmake -B build -S . -G "Visual Studio 16 2019"
```

ou

```bash
cmake -B build -S . -G "Unix Makefiles"
``` 

Você também pode usar o Ninja como gerador, caso esteja usando o Windows, Linux ou MacOS, adicionando a opção -G "Ninja"
ao comando cmake:

```bash
cmake -B build -S . -G "Ninja"
```

Certifique-se de ter o Ninja instalado no seu sistema para usar esse gerador.