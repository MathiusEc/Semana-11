#ifndef LIBRO_H
#define LIBRO_H

#define MAX_LIBROS 10

struct libro {
    int id;
    char titulo[101];
    char autor[51];
    int anio_publicacion;
    char estado[11];
};

int esIDUnico(struct libro libros[], int contador, int id);
void leerCadena(char *cadena, int num);
void registrarLibro(struct libro libros[], int *contador);  
void listarLibros(struct libro libros[], int contador);
void buscarLibroPorID(struct libro libros[], int contador, int idBuscado);
void actualizarEstadoLibro(struct libro libros[], int contador, int idBuscado);
void eliminarLibro(struct libro libros[], int *contador, int idBuscado);

#endif
