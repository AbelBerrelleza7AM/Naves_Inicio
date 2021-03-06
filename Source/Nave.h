#ifndef __NAVE_H__
#define __NAVE_H__
#include "Sprite.h"

class Nave{
	Sprite * sprite;
	int x;
	int y;
	int w;
	int h;
	bool autoMovimiento;
	int pasoActual;
	int pasoLimite;
	int module;//Modulo actual
public:
	void Mover(int posicion);
	Nave(SDL_Surface * screen, char * rutaImagen, int x, int y, int module);//Constructor
	void SetAutoMovimiento(bool autoMovimiento);
	void SetPasoLimite(int pasos);
	int ObtenerPasoActual();
	void IncrementarPasoActual();
	bool EstaColicionando(Nave* b);
	void Pintar();
	void Pintar(int module, int x, int y); 
	void Actualizar();
	int ObtenerX();
	int ObtenerY();
	int ObtenerW();
	int ObtenerH();
};

#endif
