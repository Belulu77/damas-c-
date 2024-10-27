
#include <iostream>
#include <windows.h>
#include <stdio.h> 

int pausa, opc;

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

	void mostrarTablero(char tablero[10][10]);
	void ingresarNombres(char jugador1[50], char jugador2[50]);
	void procesarTurnos(char jugador1[50], char jugador2[50], char tablero[10][10]);

void volverAtras(){
	printf("\nPresione cualquier nro para volver atras..\n"); scanf("%d", &pausa);
}


void mostrarMenu() {
    system("cls");
    printf("***** MENU PRINCIPAL *****\n");
    printf("'P' para jugar.\n");
    printf("2. Creditos\n");
    printf("3. Iniciar juego\n");
    printf("4. Salir\n");
    
    scanf(" %c", &opc);

    if (opc == 'P' || opc == 'p') {
		iniciarJuego();
    } else if (opc == 'S' || opc == 's') {
        printf("Saliendo del programa.\n");
       	exit(0);
	} else {
 		printf("Opcion no valida. Por favor, ingrese 'P' para jugar o 'S' para salir.\n");
   	}
}

void mostrarReglas() {
    system("cls");
   	printf("**************************************************************************************************************\n");
    printf("***** REGLAS DEL JUEGO *****\n");
    printf("1. El juego se juega en un tablero 10x10.\n");
    printf("2. Los jugadores mueven por coordenadas (fila, columna).\n");
    printf("3. Para seleccionar una pieza, primero ingrese las coordenadas de origen (fila columna).\n");
    printf("4. Luego, ingrese las coordenadas de destino (fila columna) a donde desea mover la pieza.\n");
    printf("5. Las filas y columnas comienzan desde 0 hasta 9. Por ejemplo, la esquina superior izquierda es (0,0).\n");
    printf("6. Los movimientos son diagonales. El jugador 'X' mueve hacia adelante y el jugador 'O' hacia atrás.\n");
    printf("7. El jugador con más piezas capturadas al final del juego gana.\n");
   	printf("**************************************************************************************************************\n");
   	printf("Presione cualquier numero para continuar...\n");
	volverAtras();


    scanf("%d", &pausa);

}

void mostrarCreditos() {
    system("cls");
	printf("**************************************************************************************************************\n");
    printf("***** CREDITOS *****\n");
    printf("Desarrolladores: \n");
    printf("1. Belen Ruiz Diaz\n");
    printf("2. Vasquez Felipe\n");
    printf("3. Julian Sosa\n");
    printf("Presione cualquier numero para continuar...\n");
  	printf("**************************************************************************************************************\n");

    scanf("%d", &pausa);

}

iniciarJuego() {
    char jugador1[50], jugador2[50];
    char tablero[10][10] = {{' ', 'X', ' ', 'X', ' ', 'X', ' ', 'X', ' ', 'X'},
                            {'X', ' ', 'X', ' ', 'X', ' ', 'X', ' ', 'X', ' '},
                            {' ', 'X', ' ', 'X', ' ', 'X', ' ', 'X', ' ', 'X'},
                            {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                            {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                            {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                            {'O', ' ', 'O', ' ', 'O', ' ', 'O', ' ', 'O', ' '},
                            {' ', 'O', ' ', 'O', ' ', 'O', ' ', 'O', ' ', 'O'},
                            {'O', ' ', 'O', ' ', 'O', ' ', 'O', ' ', 'O', ' '},
                            {' ', 'O', ' ', 'O', ' ', 'O', ' ', 'O', ' ', 'O'}};
    
    ingresarNombres(jugador1, jugador2);
    procesarTurnos(jugador1, jugador2, tablero);
    volverAtras();
}

void ingresarNombres(char jugador1[50], char jugador2[50]) {
    system("cls");
    printf("Ingrese el nombre del Jugador 1 (X): ");
    scanf("%s", jugador1);
    printf("Ingrese el nombre del Jugador 2 (O): ");
    scanf("%s", jugador2);
}

void mostrarTablero(char tablero[10][10]) {
    system("cls"); 
    printf("    0 1 2 3 4 5 6 7 8 9\n");
    printf(" _______________________\n");
    
    for (int i = 0; i < 10; i++) {
        printf("%d | ", i);
        for (int j = 0; j < 10; j++) {
            printf("%c ", tablero[i][j]);
        }
        printf("\n");
    }
}

void procesarTurnos(char jugador1[50], char jugador2[50], char tablero[10][10]) {
    int movimientos = 0;
    int turnoJugador1 = 1;
    
    while (movimientos < 50) {
        mostrarTablero(tablero);
        int x1, y1, x2, y2;
        
        if (turnoJugador1) {
            printf("Turno de %s (X)\n", jugador1);
        } else {
            printf("Turno de %s (O)\n", jugador2);
        }
        
        printf("Ingrese la coordenada de origen (fila columna): ");
        scanf("%d %d", &x1, &y1);
        printf("Ingrese la coordenada de destino (fila columna): ");
        scanf("%d %d", &x2, &y2);

        if (x1 >= 0 && x1 < 10 && y1 >= 0 && y1 < 10 && x2 >= 0 && x2 < 10 && y2 >= 0 && y2 < 10) {
            // actualizamos el tablero 
            tablero[x2][y2] = tablero[x1][y1];
            tablero[x1][y1] = ' ';
            movimientos++;
            turnoJugador1 = 1 - turnoJugador1; // jugardor turno
        } else {
            printf("Movimiento invalido. Intente de nuevo.\n");
        }
    }

    printf("***** FIN DEL JUEGO *****\n");
    printf("Presione cualquier numero para continuar...\n");
    int pausa;
    scanf("%d", &pausa);
}

int main() {
	


	void mostrarTablero(char tablero[10][10]);
	void ingresarNombres(char jugador1[50], char jugador2[50]);
	void procesarTurnos(char jugador1[50], char jugador2[50], char tablero[10][10]);
    return 0;
}
