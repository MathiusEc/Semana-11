#include <stdio.h>
#include <string.h>
#include "libro.h"

int esIDUnico(struct libro libros[], int contador, int id) {
    for (int i = 0; i < contador; i++) {
        if (libros[i].id == id) return 0;
    }
    return 1;
}

void leerCadena(char *cadena, int num) {
    fflush(stdin);
    fgets(cadena, num, stdin);
    int len = strlen(cadena);
    if (len > 0 && cadena[len-1] == '\n') {
        cadena[len-1] = '\0';
    }
}

void registrarLibro(struct libro libros[], int *contador) {
    if (*contador >= MAX_LIBROS) {
        printf("La biblioteca está llena. No se pueden agregar más libros.\n");
        return;
    }

    struct libro nuevoLibro;
    int idValido;
    
    do {
        printf("Ingrese el ID del libro: ");
        scanf("%d", &nuevoLibro.id);
        if (!esIDUnico(libros, *contador, nuevoLibro.id)) {
            printf("Error: El ID ya existe. Ingrese uno diferente.\n");
            idValido = 0;
        } else {
            idValido = 1;
        }
    } while (!idValido);

    getchar(); // Limpiar buffer
    
    printf("Ingrese el título del libro: ");
    leerCadena(nuevoLibro.titulo, 101);
    
    printf("Ingrese el autor del libro: ");
    leerCadena(nuevoLibro.autor, 51);
    
    printf("Ingrese el año de publicación: ");
    scanf("%d", &nuevoLibro.anio_publicacion);
    getchar(); // Limpiar buffer
    
    strcpy(nuevoLibro.estado, "Disponible");

    libros[*contador] = nuevoLibro;
    (*contador)++;
    printf("Libro registrado exitosamente.\n");
}

void listarLibros(struct libro libros[], int contador) {
    if (contador == 0) {
        printf("No hay libros registrados.\n");
        return;
    }

    printf("\nLista de Libros:\n");
    printf("%-5s %-30s %-20s %-6s %-10s\n", "ID", "Título", "Autor", "Año", "Estado");
    printf("--------------------------------------------------------\n");
    
    for (int i = 0; i < contador; i++) {
        printf("%-5d %-30s %-20s %-6d %-10s\n", 
            libros[i].id, 
            libros[i].titulo, 
            libros[i].autor, 
            libros[i].anio_publicacion, 
            libros[i].estado);
    }
}

void buscarLibroPorID(struct libro libros[], int contador, int idBuscado) {
    for (int i = 0; i < contador; i++) {
        if (libros[i].id == idBuscado) {
            printf("\nLibro encontrado:\n");
            printf("ID: %d\n", libros[i].id);
            printf("Título: %s\n", libros[i].titulo);
            printf("Autor: %s\n", libros[i].autor);
            printf("Año: %d\n", libros[i].anio_publicacion);
            printf("Estado: %s\n", libros[i].estado);
            return;
        }
    }
    printf("No se encontró ningún libro con ID %d.\n", idBuscado);
}

void actualizarEstadoLibro(struct libro libros[], int contador, int idBuscado) {
    for (int i = 0; i < contador; i++) {
        if (libros[i].id == idBuscado) {
            if (strcmp(libros[i].estado, "Disponible") == 0) {
                strcpy(libros[i].estado, "Prestado");
            } else {
                strcpy(libros[i].estado, "Disponible");
            }
            printf("Estado del libro actualizado exitosamente.\n");
            return;
        }
    }
    printf("No se encontró ningún libro con ID %d.\n", idBuscado);
}

void eliminarLibro(struct libro libros[], int *contador, int idBuscado) {
    for (int i = 0; i < *contador; i++) {
        if (libros[i].id == idBuscado) {
            for (int j = i; j < *contador - 1; j++) {
                libros[j] = libros[j + 1];
            }
            (*contador)--;
            printf("Libro eliminado exitosamente.\n");
            return;
        }
    }
    printf("No se encontró ningún libro con ID %d.\n", idBuscado);
}
