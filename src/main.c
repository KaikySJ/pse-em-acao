#include <stdio.h>
#include <string.h>

#define MAX 100

struct Acao {
	int codigo;
	char escola[40];
	char tema[40];
	int dia;
	int mes;
	int ano;
	char publico[40];
	char responsavel[40];
	int previsto;
	int efetivo;
	int situacao;
};

struct Acao acoes[MAX];
int total = 0;

void limparBuffer();
int lerInteiro();
void lerTexto(char destino[], int tamanho);
int buscarCodigo(int codigo);
void mostrarAcao(int i);
void cadastrarAcao();
void listarAcoes();
void pesquisarAcoes();
void atualizarSituacao();
void gerarResumo();

int main (){

	int opcao;

	do {
		printf("\n===MENU PRINCIPAL===\n");
		printf(" 1 - Cadastrar acao\n");
		printf(" 2 - Listar acoes\n");
		printf(" 3 - Pesquisar acoes\n");
		printf(" 4 - Atualizar situacao\n");
		printf(" 5 - Gerar resumo\n");
		printf(" 0 - Sair\n");
		printf("Escolha uma opcao: ");
		opcao = lerInteiro();

		switch (opcao) {
			case 1:
				cadastrarAcao();
				break;

			case 2:
				listarAcoes();
				break;

			case 3:
				pesquisarAcoes();
				break;

			case 4:
				atualizarSituacao();
				break;

			case 5:
				gerarResumo();
				break;

			case 0:
				printf("Obrigado por usar o PSE em Acao!\n");
				break;
                
			default:
				printf("Opcao invalida! Digite um numero de 0 a 5.\n");
				break;
		}
	}
	while (opcao != 0);

	return 0;
}

void limparBuffer(){

	int c;

	do {
		c = getchar();
	}
	while (c != '\n' && c != EOF);
}

int lerInteiro(){

	int valor;

	if (scanf("%d", &valor) != 1) {
		valor = -1;
	}
	limparBuffer();

	return valor;
}

void lerTexto(char destino[], int tamanho){

	int i;
	int achou = 0;

	fgets(destino, tamanho, stdin);

	for (i = 0; destino[i] != '\0'; i++) {
		if (destino[i] == '\n') {
			destino[i] = '\0';
			achou = 1;
			break;
		}
	}
	if (achou == 0) {
		limparBuffer();
	}
}

int buscarCodigo(int codigo){

	int i;

	for (i = 0; i < total; i++) {
		if (acoes[i].codigo == codigo) {
			return i;
		}
	}

	return -1;
}

void mostrarAcao(int i){

	printf("Codigo: %d\n", acoes[i].codigo);
	printf("Escola: %s\n", acoes[i].escola);
	printf("Tema: %s\n", acoes[i].tema);
	printf("Data prevista: %02d/%02d/%d\n", acoes[i].dia, acoes[i].mes, acoes[i].ano);
	printf("Publico-alvo: %s\n", acoes[i].publico);
	printf("Responsavel: %s\n", acoes[i].responsavel);
	printf("Participantes previstos: %d\n", acoes[i].previsto);

	switch (acoes[i].situacao) {
		case 1:
			printf("Situacao: Planejada\n");
			break;

		case 2:
			printf("Situacao: Realizada\n");
			printf("Participantes que foram: %d\n", acoes[i].efetivo);
			break;

		case 3:
			printf("Situacao: Cancelada\n");
			break;
	}
	printf("--------------------------------\n");
}

void cadastrarAcao(){

	struct Acao nova;
	int valido = 1;

	if (total >= MAX) {
		printf("Erro: o sistema ja tem %d acoes cadastradas!\n", MAX);
		return;
	}

	printf("\n===CADASTRO DE ACAO===\n");

	printf("Digite o codigo da acao: ");
	nova.codigo = lerInteiro();

	printf("Digite o nome da escola: ");
	lerTexto(nova.escola, 40);

	printf("Digite o tema (ex: Saude bucal): ");
	lerTexto(nova.tema, 40);

	printf("Digite o dia: ");
	nova.dia = lerInteiro();

	printf("Digite o mes: ");
	nova.mes = lerInteiro();

	printf("Digite o ano: ");
	nova.ano = lerInteiro();

	printf("Digite o publico-alvo (ex: 5 ano A): ");
	lerTexto(nova.publico, 40);

	printf("Digite o responsavel: ");
	lerTexto(nova.responsavel, 40);

	printf("Digite a quantidade prevista: ");
	nova.previsto = lerInteiro();

	printf("Situacao (1-Planejada, 2-Realizada, 3-Cancelada): ");
	nova.situacao = lerInteiro();

	nova.efetivo = 0;

	if (nova.situacao == 2) {
		printf("Quantos participantes foram? ");
		nova.efetivo = lerInteiro();
	}

	if (nova.codigo <= 0) {
		printf("Erro: o codigo tem que ser maior que zero!\n");
		valido = 0;
	}
	else {
		if (buscarCodigo(nova.codigo) != -1) {
			printf("Erro: ja existe uma acao com esse codigo!\n");
			valido = 0;
		}
	}

	if (strlen(nova.escola) == 0 || strlen(nova.tema) == 0 ||
		strlen(nova.publico) == 0 || strlen(nova.responsavel) == 0) {
		printf("Erro: os campos de texto nao podem ficar em branco!\n");
		valido = 0;
	}

	if (nova.previsto <= 0 || nova.efetivo < 0) {
		printf("Erro: quantidade invalida!\n");
		valido = 0;
	}

	if (nova.situacao < 1 || nova.situacao > 3) {
		printf("Erro: situacao invalida!\n");
		valido = 0;
	}

	if (nova.dia < 1 || nova.dia > 31 || nova.mes < 1 || nova.mes > 12 || nova.ano < 2026) {
		printf("Erro: data invalida!\n");
		valido = 0;
	}

	if (valido == 1) {
		acoes[total] = nova;
		total = total + 1;
		printf("Acao cadastrada com sucesso!\n");
	}
	else {
		printf("A acao nao foi cadastrada.\n");
	}
}

void listarAcoes(){

	int i;

	if (total == 0) {
		printf("Nenhuma acao cadastrada!\n");
		return;
	}

	printf("\n===ACOES CADASTRADAS: %d===\n", total);

	for (i = 0; i < total; i++) {
		mostrarAcao(i);
	}
}

void pesquisarAcoes(){

	int i;
	int tipo;
	int codigo;
	int encontrados = 0;
	char termo[40];

	if (total == 0) {
		printf("Nenhuma acao cadastrada para pesquisar!\n");
		return;
	}

	printf("\n===PESQUISA===\n");
	printf(" 1 - Codigo\n");
	printf(" 2 - Escola\n");
	printf(" 3 - Tema\n");
	printf("Escolha uma opcao: ");
	tipo = lerInteiro();

	if (tipo < 1 || tipo > 3) {
		printf("Erro: opcao invalida!\n");
		return;
	}

	if (tipo == 1) {
		printf("Digite o codigo: ");
		codigo = lerInteiro();

		for (i = 0; i < total; i++) {
			if (acoes[i].codigo == codigo) {
				mostrarAcao(i);
				encontrados = encontrados + 1;
			}
		}
	}
	else {
		printf("Digite o texto que quer procurar: ");
		lerTexto(termo, 40);

		for (i = 0; i < total; i++) {
			if (tipo == 2 && strcmp(acoes[i].escola, termo) == 0) {
				mostrarAcao(i);
				encontrados = encontrados + 1;
			}
			if (tipo == 3 && strcmp(acoes[i].tema, termo) == 0) {
				mostrarAcao(i);
				encontrados = encontrados + 1;
			}
		}
	}

	if (encontrados == 0) {
		printf("Nenhuma acao encontrada!\n");
	}
	else {
		printf("%d acao(oes) encontrada(s).\n", encontrados);
	}
}

void atualizarSituacao(){

	int codigo;
	int pos;
	int nova_situacao;
	int efetivo;

	if (total == 0) {
		printf("Nenhuma acao cadastrada!\n");
		return;
	}

	printf("\n===ATUALIZAR SITUACAO===\n");
	printf("Digite o codigo da acao: ");
	codigo = lerInteiro();

	pos = buscarCodigo(codigo);

	if (pos == -1) {
		printf("Erro: acao nao encontrada!\n");
		return;
	}

	mostrarAcao(pos);

	printf("Nova situacao (1-Planejada, 2-Realizada, 3-Cancelada): ");
	nova_situacao = lerInteiro();

	if (nova_situacao < 1 || nova_situacao > 3) {
		printf("Erro: situacao invalida!\n");
		return;
	}

	acoes[pos].situacao = nova_situacao;
	acoes[pos].efetivo = 0;

	if (nova_situacao == 2) {
		printf("Quantos participantes foram? ");
		efetivo = lerInteiro();

		if (efetivo < 0) {
			printf("Erro: valor negativo! Foi gravado zero.\n");
			efetivo = 0;
		}
		acoes[pos].efetivo = efetivo;
	}

	printf("Situacao atualizada com sucesso!\n");
}

void gerarResumo(){

	int i;
	int planejadas = 0;
	int realizadas = 0;
	int canceladas = 0;
	int participantes = 0;
	int previsto = 0;
	float percentual = 0;

	for (i = 0; i < total; i++) {
		switch (acoes[i].situacao) {
			case 1:
				planejadas = planejadas + 1;
				break;

			case 2:
				realizadas = realizadas + 1;
				participantes = participantes + acoes[i].efetivo;
				previsto = previsto + acoes[i].previsto;
				break;

			case 3:
				canceladas = canceladas + 1;
				break;
		}
	}

	if (previsto > 0) {
		percentual = ((float) participantes * 100) / previsto;
	}

	printf("\n===RESUMO GERAL===\n");
	printf("Total de acoes cadastradas: %d\n", total);
	printf("Planejadas: %d\n", planejadas);
	printf("Realizadas: %d\n", realizadas);
	printf("Canceladas: %d\n", canceladas);
	printf("Total de participantes: %d\n", participantes);
	printf("Percentual de participacao: %.2f%%\n", percentual);
}
