#pragma once;
#include "Nave.h"

class CGame
{
public:
	bool Start();
	static CGame instanceGame;

	enum Estado{
		ESTADO_INICIANDO,
		ESTADO_MENU,
		ESTADO_JUGANDO,
		ESTADO_TERMINANDO,
		ESTADO_FINALIZANDO
	};
	CGame();
	void Finalize();

private:
	void Iniciando();
	void Menu();
	void MoverEnemigo();
	bool EsLimitePantalla(Nave * objeto, int bandera);

	int opcionSeleccionada;
	Uint8 * keys; // esta variable nos servira para ver si determinadas teclas estan o no pulsando
	SDL_Event event; //nos servira para movilizar el

	// 
	SDL_Surface * screen;
	Nave * nave;
	//Nave * enemigo;
	Nave * enemigoArreglo [10];

	int tick;
	int tiempoFrameInicial;
	int tiempoFrameFinal;
	//int SDL_Geticks; ///]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]
	Nave *menu;//fondomenu
	Nave *textos;

	Estado estado; 
};
