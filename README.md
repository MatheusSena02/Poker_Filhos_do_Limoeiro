# Poker – Filhos do Limoeiro

> Poker Texas Hold’em no terminal — projeto semestral da disciplina **Algoritmos e Estruturas de Dados (AEDs)** da Universidade SENAI Cimatec.

![Menu principal](media_READMEmenu.gif)

## Visão geral
Este projeto demonstra como construir, em **C puro**, um jogo completo de poker que roda inteiramente no console, sem bibliotecas gráficas externas.  
Foi desenvolvido como trabalho final da disciplina, solidificando conceitos de **listas encadeadas**, **pilhas**, **filas** e algoritmos de ordenação/avaliação de mãos.

![Mesa em ação](media_READMEgameplay.gif)  
*Acima: distribuição de cartas no flop, turn e river.*

## Principais funcionalidades
- **Renderização ANSI 24-bit** para cartas, mesa e animações.  
- **Engine de estados** (menu, apostas, distribuição, showdown) sobre estruturas dinâmicas.  
- **Persistência** de perfil e partidas em `saves/`.  
- **Trilha sonora e efeitos** via `winmm` (Windows).  
- **Versão portátil** distribuída em `JogoPoker.exe`.  

## Controles
| Ação                           | Tecla       | Observação                                  |
|-------------------------------|------------|---------------------------------------------|
| Navegar menus / ajustar aposta| **W A S D**| Cima, esquerda, baixo, direita              |
| Confirmar / prosseguir        | **F**      | Apostar, virar cartas, etc.                 |
| Voltar / cancelar             | **X**      | Retorna ao menu ou etapa anterior           |

![Mesa estática](media_READMEmesa.png)

### Como jogar
1. Baixe a release ou compile o executável (veja abaixo).  
2. Abra o **cmd** ou *PowerShell* em janela, com fonte raster 8 × 12.  
3. Execute `JogoPoker.exe` e use as teclas acima.  

### Compilar a partir do código-fonte
Requisitos: **MinGW-w64** e `make`.

    git clone https://github.com/FilhosDoLimoeiro/Poker.git
    cd Poker
    gcc src/main.c src/*.c -Iinclude -lwinmm -o JogoPoker.exe

> Para Linux/macOS será necessário portar o áudio e remover dependências de `windows.h`.

## Avatares de vitória
Quando um jogador vence, um mascote aparece no canto do terminal:

| | | | | |
|---|---|---|---|---|
| ![](media_READMEgato-ganhador.png)<br/>**Gato** | ![](media_READMEesquilo-ganhador.png)<br/>**Esquilo** | ![](media_READMErato-vitorioso.png)<br/>**Rato** | ![](media_READMEsapo-vitorioso.png)<br/>**Sapo** | ![](media_READMEurso-ganhador.png)<br/>**Urso** |

## Créditos
| Papel                    | Integrantes                                                               |
|--------------------------|---------------------------------------------------------------------------|
| **Autores**              | Arthur Farias · Lucas Lima · Samara Souza · João Lessa · Matheus Sena     |
| **Professor-orientador** | Márcio Soussa                                                             |

## Sobre licenças
Ainda estamos definindo qual licença será adotada; enquanto isso, o código permanece **sem licença explícita**.

---

<sub>Coloque todos os arquivos de mídia em `media_README` ou ajuste os caminhos conforme necessário.</sub>
