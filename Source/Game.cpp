#include <stdio.h>
#include <stdlib.h>
#include "Game.h"
#include "Config.h"
#include <SDL.h>
#include <SDL_image.h>

CGame::CGame(){
	tiempoFrameInicial = 0;
	estado=ESTADO_INICIANDO;
	//atexit(SDL_Quit);
}

// Con esta función eliminaremos todos los elementos en pantalla
void CGame::Finalize(){
	delete nave;
//	delete(keys);
	//delete enemigo;
	delete *enemigoArreglo;
	SDL_FreeSurface(screen);
	SDL_Quit();
}

void CGame::Iniciando(){
	if (SDL_Init( SDL_INIT_VIDEO )){
		printf("Error %s ", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	screen = SDL_SetVideoMode( WIDTH_SCREEN, HEIGHT_SCREEN, 24, SDL_HWSURFACE );
	if (screen == NULL)
	{
		printf("Error %s ", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	SDL_WM_SetCaption( "Mi primer Juego", NULL );
	atexit(SDL_Quit);
	nave = new Nave(screen,"../Data/minave.bmp",(WIDTH_SCREEN/2),(HEIGHT_SCREEN-80),MODULO_MINAVE_NAVE);
	menu = new Nave(screen,"../Data/menu2.bmp",0,0,MODULO_MENU2_FONDO);
	textos = new Nave(screen,"../Data/Texto.bmp",0,0,-1);
	
	for(int i=0;i<10;i++){
		enemigoArreglo[i] = new Nave(screen,"../Data/enemigo.bmp",i *60,0,MODULO_ENEMIGO_NAVE);
		enemigoArreglo[i]->SetAutoMovimiento(false);
		enemigoArreglo[i]->SetPasoLimite(4);

	}
	tick=0;
	opcionSeleccionada=MODULO_TEXTO_MENU_OPCION1;

	//-enemigo->SetPasoLimite(4);
	//-enemigo->SetAutoMovimiento();
	//delete nave;
}

bool CGame::Start()
{
	// Esta variable nos ayudara a controlar la salida del juego...
	int salirJuego = false;

	while (salirJuego == false){  
		//Maquina de estados
		switch(estado){
		case Estado::ESTADO_INICIANDO:
			Iniciando();
			estado = ESTADO_MENU;
			break;
		case Estado::ESTADO_MENU:
			menu->Pintar();
			textos->Pintar(MODULO_TEXTO_TITULO,100,50);
			textos->Pintar(MODULO_TEXTO_NOMBRE,150, 380);
			Menu();
			//estado=ESTADO_JUGANDO;
			break;
		case Estado::ESTADO_JUGANDO:
			for(int i=0;i<10;i++){
				enemigoArreglo[i]->Actualizar();
			}
			MoverEnemigo();
			SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format,0,0,0)); // Color de pantalla y velocidad
			keys = SDL_GetKeyState(NULL);
			if(keys[SDLK_RIGHT]){
				if(!EsLimitePantalla(nave, BORDE_DERECHO))
					nave->Mover(1);
			}
			if(keys[SDLK_LEFT]){
				nave->Mover(-10);
			}
			nave->Pintar();
			//-enemigo->Pintar();
			for(int i=0; i<10;i++)
			enemigoArreglo[i]->Pintar();
			break;
		case Estado::ESTADO_TERMINANDO:
			getchar();
			break;
		case Estado::ESTADO_FINALIZANDO:
			salirJuego = false;
			Finalize();
			break;
		}
		while(SDL_PollEvent(&event)) // aqui se creara una lista de events ocurridos
		{
			if(event.type == SDL_QUIT) {salirJuego = true;} // si se detecta una salida de SDL
			if(event.type == SDL_KEYDOWN) {  }
		}

		//Este codigo estara provicionalmente aqui.
		SDL_Flip(screen);

		//calculando FPS
		tiempoFrameFinal = SDL_GetTicks();
		while(tiempoFrameFinal < (tiempoFrameInicial+ FPS_DELAY)){
			tiempoFrameFinal=SDL_GetTicks();
			SDL_Delay(2);
		}
		printf("Frames:%d Tiempo:%d Tiempo Promedio:%f Tiempo por Frame:%d FPS:%f\n",tick,SDL_GetTicks(), (float)SDL_GetTicks()/tick, tiempoFrameFinal - tiempoFrameInicial, 1000.0f / (float)(tiempoFrameFinal - tiempoFrameInicial));
		tiempoFrameInicial = tiempoFrameFinal; //marcamos el inicio nuevamente
		tick++;
	}
	
	return true;
}
bool CGame::EsLimitePantalla(Nave * objeto, int bandera){
	if(bandera & BORDE_IZQUIERDO)
		if(objeto->ObtenerX() <= 0)
			return true;
	if(bandera & BORDE_SUPERIOR)
		if(objeto->ObtenerY() <= 0)
			return true;
	if(bandera & BORDE_DERECHO)
		if(objeto->ObtenerX() >= WIDTH_SCREEN - objeto->ObtenerW())
			return true;
	if(bandera & BORDE_INFERIOR)
		if(objeto->ObtenerY() >= HEIGHT_SCREEN - objeto->ObtenerH())
			return true;
	return false;
}

void CGame::MoverEnemigo(){
	/*if(enemigo->ObtenerPasoActual()==0)
		if(!EsLimitePantalla(enemigo,BORDE_DERECHO))
			enemigo->Mover(1);
		else{
			enemigo->IncrementarPasoActual();
			enemigo->IncrementarPasoActual();
		}
	if(enemigo->ObtenerPasoActual()==0)
		if(!EsLimitePantalla(enemigo,BORDE_IZQUIERDO))
			enemigo->Mover(1);
		else{
			enemigo->IncrementarPasoActual();
			enemigo->IncrementarPasoActual();
		}
		*/ //esto tambien es de enemigo


		for(int i=0;i<10;i++){
			

	if(enemigoArreglo[i]->ObtenerPasoActual()==0)
		if(!EsLimitePantalla(enemigoArreglo[i],BORDE_DERECHO))
			enemigoArreglo[i]->Mover(1);
		else{
			enemigoArreglo[i]->IncrementarPasoActual();
			enemigoArreglo[i]->IncrementarPasoActual();
		}

		//*****************************//
	if(enemigoArreglo[i]->ObtenerPasoActual()==2)
		if(!EsLimitePantalla(enemigoArreglo[i],BORDE_IZQUIERDO))
			enemigoArreglo[i]->Mover(-1);
		else{
			enemigoArreglo[i]->IncrementarPasoActual();
			enemigoArreglo[i]->IncrementarPasoActual();
		}
		}
}

void CGame:: Menu(){
	for(int i = MODULO_TEXTO_MENU_OPCION1, j=0; i <= MODULO_TEXTO_MENU_OPCION2; i++, j++)
	{
		if(i == opcionSeleccionada)
			textos->Pintar(i+2, 200, 180+(j*80));
		else
		textos->Pintar(i, 200, 180+(j*80));
	}
}