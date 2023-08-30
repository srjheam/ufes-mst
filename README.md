<div align="center">
  <h3 align="center">MST</h3>
</div>

## Sobre

MST foi o primeiro trabalho desenvolvido ao longo da disciplina de Técnicas de Busca e Ordenação, ministrada pelo professor Giovanni.

## Começando

### Pré-requisitos

- Linux (sem suporte pro windows, sra. microsoft)
- [GNU Compiler Collection](https://gcc.gnu.org/)

### Instalando

1. Clone o repositório

   ```sh
   git clone https://github.com/srjheam/ufes-mst.git
   ```

2. Dirija-se ao seu diretório

   ```sh
   cd ufes-mst/
   ```

3. Compile o código-fonte

   ```sh
   make
   ```

#### Python

A fim de rodar o tsp_plot e as análises com Jupyter Notebook. Novos requisitos são adicionados:

- [Python 3](https://www.python.org/)
- [pip](https://pypi.org/project/pip/)

1. Crie um venv

    ```sh
    python3 -m venv ufes-mst
    ```

2. Ative o venv

    ```sh
    source ufes-mst/bin/activate
    ```

3. Instale os pacotes

    ```sh
    pip install -r requirements.txt
    ```

    3.1. Atualize o requirements.txt ao adicionar ou remover algum pacote

        ```sh
        pip freeze > requirements.txt
        ```

4. Garanta que o Jupyter Notebook está com o kernel conectado ao venv ufes-mst

5. Por fim, saia do venv. Opcional.

    ```sh
    deactivate
    ```

Caso tenha problemas com esse que é o pior gerenciador de pacotes e ambientes do mundo todo:

- [ppa](https://packaging.python.org/en/latest/guides/installing-using-pip-and-virtual-environments/)
- [Google](https://www.google.com/)
- [Chat GPT](https://chat.openai.com/)
- [Pressione o labgrad a adicionar o Anaconda aos PCs do Lab](mailto:monitores@inf.ufes.br)

## Usando

Intruções de uso para o giovanni.

### Giovanni

giovanni.

```sh
./trab1 <tsp_file>
```

Onde,

- `tsp_file` - é uma instância do TSP.

## Contribuindo

Este projeto está configurado e integrado com o Visual Studio Code.

### Valgrind

Há uma regra no [Makefile](./Makefile) para lançar rapidamente o Valgrind. O resultado será salvo em [valgrind-out.txt](./valgrind-out.txt).

```sh
make valgrind VALARGS=<args>
```

Onde,

- `args` - são os argumentos para passar ao programa. Opcional.

## To-do

- [ ] Giovanni-minify
    Transpilador que pega a base de código ~bem~ mal organizada e combina tudo em um único giovanni.c provando que é possível fazer o trabalho com <1000 linhas.
- [ ] Chuu de LOONA jumpscare
- [ ] O trabalho. (opcional)

## Suporte

Esse programa não funciona em ambientes não-POSIX e pode até mesmo não funcionar em sistemas não-Linux.

Isso se deve ao fato de usar APIs que são extensões do POSIX e não fazem parte do padrão C.

## Licença

Licenciado sob [Unlicense](./LICENSE).
