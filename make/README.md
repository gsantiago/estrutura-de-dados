# introdução

Este diretório contem um exemplo de como usar make baseados [neste vídeo](https://www.youtube.com/watch?v=GExnnTaBELk).

Abaixo, algumas anotações também retiradas do vídeo e de outras fontes da internet.

## processo de compilação de um código c

As etapas são:

**1 - Pré-processador**, que cuida dos #includes e outros macros, além de eliminar comentários. A opção `-E` roda apenas o pré-processador.

**2 - Compilador**, traduz o código C pra assembly. A opção `-S` cospe o código assembly (`.s`).

**3 - Assembler**, traduz o código assembly para object files (`.o`). A opção `-c` cospe o arquivo `.o`.

**4 - Linker**, junta todos os object files (`.o`) e cospe um programa executável.

## make

`make` é um utilitário pra facilitar os processos de build.
Ele cria uma árvore de dependência e evita recompilações desnecessárias ao analisar a data de atualização dos arquivos e suas dependências.

Exemplo de Makefile:

```
target: dependency1 dependency2

dependency1:
    action1

dependency2:
    action2
```

Neste diretório, tem um exemplo de uso do make.
