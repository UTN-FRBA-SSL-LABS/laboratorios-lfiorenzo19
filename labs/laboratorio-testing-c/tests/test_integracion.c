#include <stdio.h>
#include "../src/carrito.h"
#include "minunit/minunit.h"

/*
 * Tests de integracion: verifican que las funciones trabajan bien
 * en combinacion, no de forma aislada.
 */

/* ═══════════════════════════════════════════════════════════════════════════
 *  PARTE D — Escribir el test guiado (ver README.md, Parte 8)
 * ═══════════════════════════════════════════════════════════════════════════ */

/* TODO: escribir test_compra_con_descuento() siguiendo la guia del .md */
void test_compra_con_descuento(){
    Carrito c;
    carrito_init(&c);
    Producto pan = {"Pan", 200,3};
    carrito_agregar(&c, pan);
    Producto leche = {"Leche", 350,2};
    carrito_agregar(&c, leche);
    int total =  carrito_total(&c);
    ASSERT_IGUAL(1300, total);
    int descuento = carrito_descuento(carrito_total(&c), 10);
    ASSERT_IGUAL(1170, descuento);
}
/* ═══════════════════════════════════════════════════════════════════════════
 *  PARTE E — Disenar un test propio (ver README.md, Parte 9)
 * ═══════════════════════════════════════════════════════════════════════════ */

/* TODO: escribir test_agregar_hasta_llenar()
*/
void test_agregar_hasta_llenar(){
    Carrito c;
    carrito_init(&c);
    for (int i = 0; i < MAX_ITEMS; i++) {
        Producto p = {"UnProducto", 500, 1};
        ASSERT_IGUAL(1, carrito_agregar(&c, p)); // agrego hasta el maximo permitido
    }
    Producto extra = {"UnProductoExtra", 250, 1};
    ASSERT_IGUAL(0, carrito_agregar(&c, extra)); // agrego un 5to producto
    
}



int main(void) {
    printf("=== Tests de integracion ===");
    /* Descomentar a medida que agregues las funciones: */
    test_compra_con_descuento();
    test_agregar_hasta_llenar();
    RESUMEN();
    return EXIT_CODE();
}
