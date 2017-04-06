#include <iostream>

// Função que apresenta o menu
void menu();

// Altera as letras minusculas para maiusculas
char *StrAlteraMinusMaius(char *s);

// Insere um espaço em branco entre cada caracter
char *StrInsereEsp(char *s);

// Insere uma string antes de outra
char *StrInsereStr(char *s1, char *s);

// Função principal
int main() {
    // Variáveis
    int sentenceLength = 100;
    int buffer = sizeof(char) * sentenceLength;

    int answer = -1;
    char *s = (char *) malloc(buffer);
    char *s1 = (char *) malloc(buffer);

    do {
        // Mostra o menu
        menu();

        // Pega entrada do usuário
        std::cin >> answer;
        std::cin.ignore();

        if(answer == 1) { // Opção para alterar letras para maiusculas
            std::cout << "Digite a frase: ";
            std::cin.getline(s, sentenceLength);

            std::cout << "Alterado de minusculas: " << s << "\n";

            s = StrAlteraMinusMaius(s);
            std::cout << "Para maiusculas: " << s << "\n";
        } else if(answer == 2) { // Opção para inserir espaço entre caracteres
            std::cout << "Digite a frase: ";
            std::cin.getline(s, sentenceLength);

            s = StrInsereEsp(s);
            std::cout << "Frase com espacos: " << s << "\n";
        } else if(answer == 3) { // Opção para inserir string antes de outra
            std::cout << "Digite a frase: ";
            std::cin.getline(s, sentenceLength);

            std::cout << "Digite o que deseja inserir: ";
            std::cin.getline(s1, sentenceLength);

            s = StrInsereStr(s1, s);

            std::cout << "Resultado da insercao: " << s << "\n";
        } else if(answer == 0) { // Opção para encerrar o programa
            // Sem implementação
        } else { // Opção inexistente
            std::cout << "O codigo digitado nao pertence a nenhuma funcao. Tente novamente!";
        }

        // Libera memória e realoca
        free(s);
        s = (char *) malloc(buffer);

        free(s1);
        s1 = (char *) malloc(buffer);

        std::cout << "\n\n\n\n";
    } while(answer != 0);

    return 0;
}

// Função que apresenta o menu
void menu() {
    // Print menu options
    std::cout << "1) Convertar minusculas em maiusculas\n";
    std::cout << "2) Adicionar espacos entre caracteres\n";
    std::cout << "3) Adicionar string no inicio da frase\n";
    std::cout << "0) Encerrar o programa\n";
    std::cout << "Digite o codigo da funcao: ";
}

// Altera as letras minusculas para maiusculas
char *StrAlteraMinusMaius(char *s) {
    // Variável
    int i;

    // Itera na string e verifica quais são minusculas
    for(i = 0; *(s + i) != '\0'; i++) {
        if(*(s + i) >= 'a' && *(s + i) <= 'z') {
            // Muda de minuscula para maiuscula
            // Na tabela ASCII a diferença entre minuscula e maiuscula é 32 unidades
            *(s + i) = *(s + i) - 32;
        }
    }

    return s;
}

// Insere um espaço em branco entre cada caracter
char *StrInsereEsp(char *s) {
    // Variáveis
    int i, sentenceLength = 0;
    char *aux;

    // Obtem a quantidade de caracteres da string
    for(i = 0; *(s + i) != '\0'; i++) {
        sentenceLength++;
    }

    // Cria um novo vetor para armazenar a string
    aux = (char *) malloc(sizeof(char) * sentenceLength * 2);

    // Itera a string e adiciona o espaçamento entre os caracteres
    for(i = 0; *(s + i) != '\0'; i++) {
        // Recebe o caracter da posição "i" e adiciona nas posições pares
        *(aux + i * 2) = *(s + i);
        // Adiciona um espaço nas posições ímpares
        *(aux + i * 2 + 1) = ' ';
    }

    // Libera memória
    free(s);

    return aux;
}

// Insere uma string antes de outra
char *StrInsereStr(char *s1, char *s) {
    // Variáveis
    int i, sLength = 0, s1Length = 0;
    char *aux;

    // Obtém o tamanho da string s
    for(i = 0; *(s + i) != '\0'; i++) {
        sLength++;
    }

    // Obtém o tamanho da string s1
    for(i = 0; *(s1 + i) != '\0'; i++) {
        s1Length++;
    }

    // Cria um novo vetor para armazenar a string
    aux = (char *) malloc(sizeof(char) * (sLength + s1Length));

    // Adiciona a string s1 ao vetor aux
    for(i = 0; *(s1 + i) != '\0'; i++) {
        *(aux + i) = *(s1 + i);
    }

    // Adiciona a string s ao vetor aux
    for(i = 0; *(s + i) != '\0'; i++) {
        *(aux + s1Length + i) = *(s + i);
    }

    // Libera a memória
    free(s);
    free(s1);

    return aux;
}

