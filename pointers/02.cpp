#include <iostream>

// Função para ordenar alfabeticamente
void sortByName(char ***products, float **prices, int qntProducts);

// Função para inflacionar o preço dos produtos menores do que 100
void inflate(float **prices, int qntProducts);

// Função principal
int main() {
    // Variaveis
    int i, answer = -1;
    int qntProducts, productsLength = 100;

    // Verifica a quantidade de produtos que serão inseridos
    std::cout << "Digite a quantidade de produtos que deseja adicionar: ";
    std::cin >> qntProducts;
    std::cin.ignore();

    // Cria o vetor de preços e a matriz de produtos
    float *prices = (float *) malloc(sizeof(float) * qntProducts);
    char **products = (char **) malloc(sizeof(char *) * qntProducts);

    for(i = 0; i < qntProducts; i++) {
        *(products + i) = (char *) malloc(sizeof(char) * productsLength);
    }

    std::cout << "\n";

    // Insere os produtos e preços
    for(i = 0; i < qntProducts; i++) {
        std::cout << "Digite o nome do produto: ";
        std::cin.getline(*(products + i), productsLength);
        
        std::cout << "Digite o preco do produto: ";
        std::cin >> *(prices + i);
        std::cin.ignore();

        std::cout << "\n";
    }

    std::cout << "\n\n";

    // Menu com as funções
    while(answer != 0) {
        std::cout << "\n1) Ordenar os produtos por ordem alfabetica.";
        std::cout << "\n2) Inflacionar os precos dos produtos inferiores a 100 reais.";
        std::cout << "\n0) Encerrar o programa.";
        std::cout << "\nDigite o codigo da opcao desejada: ";
        std::cin >> answer;
        std::cin.ignore();

        switch(answer) {
            case 1:
                // Ordena
                sortByName(&products, &prices, qntProducts);

                // Imprime os produtos e preços
                for(i = 0; i < qntProducts; i++) {
                    std::cout << "Produto: " << *(products + i) << ", " << *(prices + i) << "\n";
                }

                break;
            case 2:
                // Inflaciona
                inflate(&prices, qntProducts);

                // Imprime os produtos e preços
                for(i = 0; i < qntProducts; i++) {
                    std::cout << "Produto: " << *(products + i) << ", " << *(prices + i) << "\n";
                }

                break;

            case 0:
                break;

            default:
                std::cout << "Opcao inexistente! Tente novamente.";

                break;
        }

        std::cout << "\n\n";
    }

    // Libera a memória
    for(i = 0; i < qntProducts; i++) {
        free(*(products + i));
    }

    free(products);
    free(prices);

    return 0;
}

// Função para ordenar alfabeticamente
void sortByName(char ***products, float **prices, int qntProducts) {
    int i, isSwaping = 1;
    
    char *product;
    float price;

    // Enquanto houver trocas mantém o loop
    while(isSwaping) {
        isSwaping = 0;

        // Itera sobre os produtos e troca (caso haja necessidade)
        for(i = 0; i < (qntProducts - 1); i++) {
            if(strcmp(*((*products) + i), *((*products) + i + 1)) > 0) {
                // Troca produtos
                product = *((*products) + i);
                *((*products) + i) = *((*products) + i + 1);
                *((*products) + i + 1) = product;

                // Troca preços
                price = *((*prices) + i);
                *((*prices) + i) = *((*prices) + i + 1);
                *((*prices) + i + 1) = price;

                isSwaping = 1;
            }
        }

        qntProducts--;
    }
}

// Função para inflacionar o preço dos produtos menores do que 100
void inflate(float **prices, int qntProducts) {
    int i;

    // Itera sobre os preços e inflaciona (caso haja necessidade)
    for(i = 0; i < qntProducts; i++) {
        if(*((*prices) + i) < 100) {
            *((*prices) + i) = *((*prices) + i) * 1.05f;
        }
    }
}