#ifdef USUARIO_H
#define USUARIO_H

typedef struct usuario Usuario;
typedef struct lista Lista;

void inserirUsuario(Lista *lista);
void imprimirUsuario(Usuario *usuario);
Usuario *removerUsuario(Lista *lista, int id);
Usuario *buscarUsuario(Lista *lista, int id);

#endif