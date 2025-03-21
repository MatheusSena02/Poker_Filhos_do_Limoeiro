#ifndef ARQ_H
#define ARQ_H
#include <stdio.h>
#include <time.h>

int str_iniciaCom(char stringA[],char stringB[]) {
// Função que compara se stringA inicia com stringB e retorna 1 caso seja verdade;
// EXEMPLO: str_iniciaCom("TesteEscrito","Teste")
    if(strncmp(stringA, stringB, strlen(stringB)) == 0 ) return 1; 
    else return 0;
    
}

int arq_gerar(char principal[], char arqmontado[],int modo) {
// A partir de um nome, arq_gerar gera o nome de arquivo em "arquivo.txt"
// arq_gerar (string contendo o nome, string que receberá o nome de arquivo, modo de operação, modo de debug)
// Modos de operação:
// 1 -> gera o nome do arquivo sem nenhuma mudança
// 2 -> gera o nome do arquivo considerando se o arquivo já existe. Se já existir o arquivo "exemplo.txt" será criado "exemplo1.txt"
    
    // Modo 1
    if (modo==1) {
        sprintf(arqmontado,"%s.txt",principal);
        return 1;
    }
    
    // Modo 2
    else if (modo==2) {
        int cont=0; char scont[20];
        
        do {
            strcpy(arqmontado,principal);
            
            if (cont>0) strcat(arqmontado,scont);
            
            strcat(arqmontado,".txt");
            
            cont++;
            sprintf(scont,"%d",cont);
            
        } while ((fopen(arqmontado,"r") != NULL));
		return 1;
    }
    
    else return 0;
    
}

int arq_ler(int limite, char arq_nome[]) {
// Função que lê todo um arquivo txt linha por linha
// Recebe uma string que armazenará o conteúdo até o caractere [limite] da linha atual, do arquivo arq_nome.
    
    char linha[limite+1];
    FILE *arquivo;
    arquivo=fopen(arq_nome,"r");
    
    if (arquivo) {
        while  (fgets(linha, limite, arquivo) ) printf("%s",linha); 
        fclose(arquivo); 
        return 1;
        
    } else return 0;
    
}

void arq_obterData(char arq_nome[]) {
    time_t agora = time(NULL);
    struct tm infoTempo;
    char buffer[20];  // Espaço para "DD-MM-YYYY-HH-MM-SS" + '\0'

    #ifdef _WIN32
        // No windows, usa gmtime_s e ajusta para GMT-3.
        gmtime_s(&infoTempo, &agora);
        infoTempo.tm_hour -= 3;
        // Normaliza se necessário (mktime ajusta os campos)
        mktime(&infoTempo);
    #else
        // No linux (gdb e replit), configura o fuso p "America/Sao_Paulo"
        setenv("TZ", "America/Sao_Paulo", 1);
        tzset();
        localtime_r(&agora, &infoTempo);
    #endif

    strftime(buffer, sizeof(buffer), "%d-%m-%Y-%H-%M-%S", &infoTempo);
    strcpy(arq_nome, buffer);
}


int arq_gerarcData(char arq_nome[]) {
//Função que coloca na string "arq_nome" uma string no formato DD-MM-YYYY-HH-MM-SS.txt e gera esse arquivo
    
    arq_obterData(arq_nome);
    arq_gerar(arq_nome,arq_nome,1);
    
    FILE *arquivo;
    arquivo=fopen(arq_nome,"a");
    if (arquivo) fclose(arquivo);
    else return 0;
    if (strcmp(arq_nome,".txt") == 0) {
        printf("\x1b[1;91m// ERRO // ERRO // ERRO // ERRO //\n");
        printf("-> Erro na geração de arquivo para salvamento de histórico.\n");
        printf("-> O programa ainda funcionará.\n");
        printf("-> Caso o problema persista:\n");
        printf("-> Troque 'ModoDeSalvamento' para '0' em 'opcoes.txt'\x1b[22;39m\n");
        return 0;
    }
    return 1;
}

int arq_gerarCopia(char arq_nome[], char arq_nomeCopia[]) {
// Função que copia arq_nome para o arq_nomeCopia, que é criado no modo write
// Debug: caso debug seja 1, printfs de aviso e visualização dos resultados serão mostrados
    
    int limite=300;
    char linha[limite+1];
    
    FILE *arquivo;
    FILE *arquivo2;
    arquivo=fopen(arq_nome,"r");
    arquivo2=fopen(arq_nomeCopia,"w");
    
    if (arquivo) {
        if (arquivo2) {
            
            while  (fgets(linha, limite, arquivo) ) fprintf(arquivo2,"%s",linha); 
            fclose(arquivo); 
            fclose(arquivo2); 
            
        } else return 0;
        
    } else return 0;
    
    return 1;
}

void arq_criarOpcoes () {
// Função para gerar o conteudo de opcoes.txt
    FILE *arq;
    arq=fopen("opcoes.txt","w");
    if (arq) {
        fprintf(arq,"--- Opções ---\n\n");
        fprintf(arq,"// Estilo de Carta ( 1 = Carta Branca [Padrão] / 0 = Carta Preta )\n");
        fprintf(arq,"EstiloCarta = 1\n\n");
        fprintf(arq,"//Modo de debug ( 0 = Desativado [Padrão] / 1 = Simples )\n");
        fprintf(arq,"// Simples -> prinfs de avisos e monitoramento\n");
        fprintf(arq,"debug = 0\n\n");
        fprintf(arq,"// Seleciona como será formatado o .txt que salva o histórico cada partida ( 1 = Data e Hora [Padrão] / 0 = partida.txt )\n");
        fprintf(arq,"// Recomendação:  Windows / OnlineGDB = 1 / Replit = 0\n");
        fprintf(arq,"ModoDeSalvamento = 1\n\n");
        fprintf(arq,"\n\n\n\n\n\n//-->Esse código foi feito para rodar em sistemas Windows e é onde funciona normalmente\n");
        fprintf(arq,"//-->Em sites que rodam Linux, algumas funções são diferentes, o que causa erro na função de obtenção de Data e Hora\n");
        fclose(arq);
    }
}

int arq_lerOpcoes (int *variavel, char scan[], char formato[]){
// Função para obter valores para uma variável cujos valores estão dentro deu um opcoes.txt
// Parametros: end.de memória da variável cujo valor será obtido / string a ser comparada com a linha escaneada / formatação da string q a variável tá inserida
// EXEMPLO DE USO: arq_lerOpcoes(&modoJogo,"Modo_de_Jogo =","Modo de Jogo = %d");
    FILE *arq;
    char linha[100];
    arq=fopen("opcoes.txt","r");
    if (arq) {
        while((fgets(linha,100,arq) != NULL)) {
            if (str_iniciaCom(linha,scan)) {
                sscanf(linha,formato,variavel);
                break;
            }
        }
    } else {
        printf("Erro na abertura de arquivo\n");
        return 1;
    }
    return 0;
}

int arq_verificarOpcoes () {
//Função que verifica se opcoes.txt já foi criado. Se sim, retorna 0, se não, retorna 1
    FILE *arq;
    arq=fopen("opcoes.txt","r");
    if (arq);
    else {
        printf(" - Gerando arquivos necessários - \n");
        arq_criarOpcoes();
        printf(" Geração concluida, rode o programa novamente");
        return 0;
    }
    return 1;
}

#endif