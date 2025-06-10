#include <stdio.h>
#include <string.h>
#include "libro.h"

int main() {
    struct libro libros[MAX_LIBROS];
    int contador = 0;
    int opcion, idBuscado;
    char tituloBuscado[101];

    do {
        printf("\nMenú de Biblioteca\n");
        printf("1. Registrar libro\n");
        printf("2. Listar libros\n");
        printf("3. Buscar libro por ID\n");
        printf("4. Actualizar estado de libro\n");
        printf("5. Eliminar libro\n");
        printf("6. Salir\n");
        printf("Seleccione una opción: ");
        
        if (scanf("%d", &opcion) != 1) {
            printf("Opción inválida.\n");
            fflush(stdin);
            continue;
        }

        switch (opcion) {
            case 1:
                registrarLibro(libros, &contador);
                break;
            case 2:
                listarLibros(libros, contador);
                break;
            case 3:
                printf("Ingrese el ID a buscar: ");
                scanf("%d", &idBuscado);
                buscarLibroPorID(libros, contador, idBuscado);
                break;
            case 4:
                printf("Ingrese el ID del libro a actualizar: ");
                scanf("%d", &idBuscado);
                actualizarEstadoLibro(libros, contador, idBuscado);
                break;
            case 5:
                printf("Ingrese el ID del libro a eliminar: ");
                scanf("%d", &idBuscado);
                eliminarLibro(libros, &contador, idBuscado);
                break;
            case 6:
                printf("¡Hasta luego!\n");
                break;
            default:
                printf("Opción inválida.\n");
        }
    } while (opcion != 7);

    return 0;
}
