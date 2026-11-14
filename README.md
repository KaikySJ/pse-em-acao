# PSE em Ação

Sistema de Planejamento e Acompanhamento de Ações de Saúde na Escola, desenvolvido em linguagem C como Atividade de Estudo Programada (AEP) do 2º semestre de 2026 do curso de Análise e Desenvolvimento de Sistemas da Unicesumar.

## Sobre o projeto

A aplicação, executada em terminal, apoia uma equipe intersetorial do Programa Saúde na Escola (PSE) a cadastrar, listar, pesquisar e acompanhar ações coletivas de saúde nas escolas, gerando um resumo com ações planejadas, realizadas e canceladas e o percentual de participação em relação ao previsto.

O sistema trabalha apenas com dados fictícios e informações coletivas. Ele não armazena nome, diagnóstico, prontuário ou qualquer dado individual de estudantes, e não realiza diagnóstico, triagem ou recomendação de tratamento.

## Funcionalidades

1. Cadastrar ação (código, escola, tema, data prevista, público-alvo, responsável, quantidade prevista e situação)
2. Listar as ações cadastradas
3. Pesquisar ações por código, escola ou tema
4. Atualizar a situação da ação (planejada, realizada ou cancelada) e registrar a quantidade de participantes
5. Gerar resumo geral com os números consolidados
6. Validar as entradas (código repetido, quantidade negativa, campo em branco, data fora da faixa, situação inexistente e limite de armazenamento)

## Como compilar e executar

É necessário ter o compilador GCC instalado.

```bash
# Linux ou macOS
gcc src/main.c -o pse_em_acao
./pse_em_acao
```

```bash
# Windows
gcc src/main.c -o pse_em_acao.exe
pse_em_acao.exe
```

O programa também compila sem avisos com as opções de verificação:

```bash
gcc -Wall -Wextra -std=c99 -pedantic src/main.c -o pse_em_acao
```

Os dados ficam em memória durante a execução e são perdidos ao encerrar o programa.

## Integrantes

| Nome | RA |
|------|----|
| Kevin Caldonazo de Almeida | 26015183-2 |
| Kaiky de Souza Junqueira | 26012834-2 |
| Luan Pablos Sanches | 24150606-2 |

## Estrutura do repositório

```
pse-em-acao/
├── README.md
├── docs/
│   ├── etapa1/          documento da 1ª entrega (PDF)
│   ├── etapa2/          documento da 2ª entrega (PDF)
│   ├── fluxogramas/     imagens dos fluxogramas
│   └── casos-de-uso/    diagrama de casos de uso
└── src/
    └── main.c           código-fonte em linguagem C
```

## Status

- [x] Etapa 1: documento escrito (contextualização, requisitos, fluxogramas, pseudocódigos e planejamento das sprints)
- [x] Etapa 2: implementação em C, casos de uso, testes, manual do usuário e documento final
