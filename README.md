# Atividade 4

### Descrição

Entrega da atividade 4 do curso de Sistemas Operacionais referente a parte 2 da atividade, na qual foram implementados três programas especificados nos itens a, b e c da atividade 04, o item 'a' implementa o jantar dos filósofos sem controle de impasse, o item 'b' implementa o jantar dos filósofos com controle de impasse e o item 'c' implementa o jantar dos filósofos usando threads com  uso paralelo de recursos

### Começando

Para rodar o programa localmente é necessario que tenha o compilador C instalado, para o Linux recomendo usar o GCC e para Windows utilize o MinGw.

### Executando nosso código

Para executarmos nosso codigo é necesário que tenhamos um editor de texto qualquer, recomendo o visual studio code, com o editor de texto ja escolhido vamos clonar o repositório para rodar o código localmente, para isso abra o git no diretório desejado e rode o seguinte comando:

```
git clone https://github.com/bigbatx1/Jantar_filosofos.git
```

Com o projeto em sua máquina, abra a atividade desejada e compile o codigo utilizado o seguinte comando:

```
gcc -o teste -lpthread main.c
```

Com o código já compilado, precisamos apenas executa-lo com o seguinte comando:

```
.\teste.exe
```
Ou, no linux:
```
./teste.out
```
