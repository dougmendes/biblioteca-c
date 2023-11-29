#include <stdio.h>
#include <stdlib.h>
//AUTOR//
typedef struct autor
{
    char nome[200];
    char instituicao[200];
    struct autor *proximo;
} Autor;

typedef struct
{
    Autor *inicio;
} ListaAutor;

//USUARIO//
typedef struct usuario
{
    int id;
    char nome[100];
    char endereco[400];
    long telefone;
    struct usuario *proximo;

} Usuario;



typedef struct
{
    Usuario *inicio;
    int tam;

} Lista;

void inserirUsuario(Usuario **lista)
{
    Usuario *remover, *novo = malloc(sizeof(Usuario));
    if (novo)
    {
        printf("Nome:");
        getchar();
        gets(novo->nome);
        printf("Endereco:");
        gets(novo->endereco);
        printf("Telefone:");
        scanf("%ld", &novo->telefone);

        // Encontre o id mais alto na lista
        int max_id = 0;
        Usuario *atual = *lista;
        while (atual != NULL)
        {
            if (atual->id > max_id)
            {
                max_id = atual->id;
            }
            atual = atual->proximo;
        }

        // Defina o id do novo usuário como o id mais alto encontrado mais um
        novo->id = max_id + 1;

        novo->proximo = *lista;
        *lista = novo;
    }
    else
    {
        printf("erro ao alocar memoria \n");
    }
}

void imprimir(Usuario *usuario)
{

    while (usuario)
    {
        printf("\n\nid:");
        printf("%d\n", usuario->id);
        printf("Nome:");
        printf("%s\n", usuario->nome);
        printf("Endereco:");
        printf("%s\n", usuario->endereco);
        printf("Telefone:");
        printf("%ld\n", usuario->telefone);
        usuario = usuario->proximo;
    }
    printf("\n\n");
}

Usuario *remover(Usuario **lista, int id)
{
    Usuario *aux, *remover = NULL;
    if (*lista != NULL)
    {
        if ((*lista)->id == id)
        {
            remover = *lista;
            *lista = remover->proximo;
        }
        else
        {
            aux = *lista;
            while (aux->proximo && aux->proximo->id != id)
            {
                aux = aux->proximo;
            }
            if (aux->proximo)
            {
                remover = aux->proximo;
                aux->proximo = remover->proximo;
            }
        }
    }
    return remover;

}


void alterarUsuario(Usuario *usuario)
{
    int opcao;

    do
    {
        printf("O que voce deseja alterar?\n");
        printf("1. Nome\n");
        printf("2. Endereco\n");
        printf("3. Telefone\n");
        printf("4. Sair\n");

        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Digite o novo nome: ");
            getchar();
            gets(usuario->nome);
            break;
        case 2:
            printf("Digite o novo endereco: ");
            getchar();
            gets(usuario->endereco);
            break;
        case 3:
            printf("Digite o novo telefone: ");
            scanf("%ld", &usuario->telefone);
            break;
        case 4:

            break;
        default:
            printf("Opcao invalida. digite outra opcao.\n");
        }

    }
    while (opcao != 4);
}
Usuario *buscarUsuario(Usuario *lista, int id)
{
    Usuario *atual = lista;
    while (atual != NULL)
    {
        if (atual->id == id)
        {
            return atual;
        }
        atual = atual->proximo;
    }
    return NULL; // Retorna NULL se o usuário não for encontrado
}

// ESTRUTURAS DOS LIVROS //
typedef struct livro
{
    int id;
    char titulo[200];
    int ano;
    int edicao;
    char editora[150];
    Autor *autores;
    struct livro *proximo;
} Livro;

typedef struct
{
    Livro *inicio;
} Listalivros;

// INSERIR LIVROS//
void inserirLivro(Livro **listaLivros)
{
    Livro *remover, *novo = malloc(sizeof(Livro));
    if (novo)
    {
        printf("Titulo:");
        getchar();
        gets(novo->titulo);
        printf("Ano:");
        scanf("%d", &novo->ano);
        getchar(); // Consumir o caractere de nova linha
        printf("Edicao:");
        scanf("%d", &novo->edicao);
        getchar(); // Consumir o caractere de nova linha
        printf("Editora:");
        getchar(); // Consumir o caractere de nova linha
        gets(novo->editora);
        
        novo->autores = NULL;
        // Encontre o id mais alto na lista
        int max_id = 0;
        Livro *atual = *listaLivros;
        while (atual != NULL)
        {
            if (atual->id > max_id)
            {
                max_id = atual->id;
            }
            atual = atual->proximo;
        }

        // Defina o id do novo usuário como o id mais alto encontrado mais um
        novo->id = max_id + 1;

        novo->proximo = *listaLivros;
        *listaLivros = novo;
    }
    else
    {
        printf("erro ao alocar memoria \n");
    }
}
// REMOVER LIVROS//
Livro *removerLivro(Livro **listaLivros, int id)
{
    Livro *aux, *remover = NULL;
    if (*listaLivros != NULL)
    {
        if ((*listaLivros)->id == id)
        {
            remover = *listaLivros;
            *listaLivros = remover->proximo;
        }
        else
        {
            aux = *listaLivros;
            while (aux->proximo && aux->proximo->id != id)
            {
                aux = aux->proximo;
            }
            if (aux->proximo)
            {
                remover = aux->proximo;
                aux->proximo = remover->proximo;
            }
        }
    }
    return remover;
}

//IMPRIMIR LIVRO//
void imprimirLivro(Livro *livro)
{

    while (livro)
    {
        printf("\n\nid:");
        printf("%d\n", livro->id);
        printf("Titulo:");
        printf("%s\n", livro->titulo);
        printf("Ano:");
        printf("%d\n", livro->ano);
        printf("Edicao:");
        printf("%d\n", livro->edicao);
        printf("Editora:");
        printf("%s\n",livro->editora);
        livro = livro->proximo;
    }
    printf("\n\n");
}


void inserirAutor(Livro *livro)
{
    Autor *novoAutor = malloc(sizeof(Autor));
    if (novoAutor)
    {
        printf("Nome do autor:");
        getchar();
        gets(novoAutor->nome);
        printf("Instituicao do autor:");
        gets(novoAutor->instituicao);

        // Adicione o novo autor ao início da lista de autores do livro
        novoAutor->proximo = livro->autores;
        livro->autores = novoAutor;
    }
    else
    {
        printf("Erro ao alocar memoria\n");
    }
}
int main()
{
    Lista lista = {NULL, 0};
    Listalivros listaLivros = {NULL, 0};
    ListaAutor listaAutor = {NULL};

    int opcao;

    do
    {
        printf("Escolha o que deseja gerenciar:\n");
        printf("1 - Usuários\n");
        printf("2 - Livros\n");
        printf("3 - Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1: // Gerenciar usuários
            do
            {
                printf("1 - Inserir usuário\n");
                printf("2 - Remover usuário\n");
                printf("3 - Alterar usuário\n");
                printf("4 - Imprimir usuário\n");
                printf("5 - Sair\n");
                printf("Opção: ");
                scanf("%d", &opcao);

                switch (opcao)
                {
                case 1:
                    inserirUsuario(&lista.inicio);
                    lista.tam++;
                    break;
                case 2:
                    printf("Digite o ID do usuário a ser removido: ");
                    int id;
                    scanf("%d", &id);
                    Usuario *usuario = remover(&lista.inicio, id);
                    if (usuario)
                    {
                        printf("Usuário removido:\n");
                        printf("Nome: %s\n", usuario->nome);
                        printf("Endereço: %s\n", usuario->endereco);
                        printf("Telefone: %ld\n", usuario->telefone);
                        free(usuario);
                        lista.tam--;
                    }
                    else
                    {
                        printf("Usuário não encontrado.\n");
                    }
                    break;
                case 3:
                    printf("Digite o ID do usuário que você deseja alterar: ");
                    scanf("%d", &id);
                    Usuario *usuario_alterar = buscarUsuario(lista.inicio, id);
                    if (usuario_alterar)
                    {
                        alterarUsuario(usuario_alterar);
                    }
                    else
                    {
                        printf("Usuário não encontrado.\n");
                    }
                    break;
                case 4:
                    imprimir(lista.inicio);
                    break;
                case 5:
                    printf("Saindo...\n");
                    break;
                default:
                    printf("Opção inválida.\n");
                    break;
                }
            } while (opcao != 5);
            break;
        case 2: // Gerenciar livros
            do
            {
                printf("1 - Inserir Livro\n");
                printf("2 - Remover Livro\n");
                printf("3 - Alterar Livro\n");
                printf("4 - Imprimir livro\n");
                printf("5 - Sair\n");
                printf("Opção: ");
                scanf("%d", &opcao);

                switch (opcao)
                {
                case 1:
                    // Inicialize a lista de livros como NULL antes de inserir se não fizer isso pode levar a acessos inválidos de memória.
                    listaLivros.inicio = NULL;
                    inserirLivro(&listaLivros.inicio);
                    inserirAutor(&listaAutor.inicio);
                    break;
                case 2:
                    printf("Digite o ID do livro a ser removido: ");
                    int id_livro;
                    scanf("%d", &id_livro);
                    Livro *livro_remover = removerLivro(&listaLivros.inicio, id_livro);
                    if (livro_remover)
                    {
                        printf("Livro removido:\n");
                        printf("Título: %s\n", livro_remover->titulo);
                        printf("Ano: %d\n", livro_remover->ano);
                        printf("Editora: %s\n", livro_remover->editora);
                        free(livro_remover);
                    }
                    else
                    {
                        printf("Livro não encontrado.\n");
                    }
                    break;
                case 4:
                    imprimirLivro(listaLivros.inicio);
                    break;
                case 5:
                    printf("Saindo...\n");
                    break;
                default:
                    printf("Opção inválida.\n");
                    break;
                }
            } while (opcao != 5);
            break;
        case 3:
            printf("Saindo...\n");
            break;
        default:
            printf("Opção inválida.\n");
            break;
        }
    } while (opcao != 3);

    return 0;
}
