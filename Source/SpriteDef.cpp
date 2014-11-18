#include "SpriteDef.h"
#include "Config.h"

SpriteDef::SpriteDef(){
	modulos[0].id = MODULO_MINAVE_NAVE;
	modulos[0].x = 0;
	modulos[0].y = 0;
	modulos[0].w = 64;
	modulos[0].h = 64;

	modulos[1].id = MODULO_MENU2_FONDO;
	modulos[1].x = 0;
	modulos[1].y = 0;
	modulos[1].w = WIDTH_SCREEN;
	modulos[1].h = HEIGHT_SCREEN;
	
	modulos[2].id = MODULO_ENEMIGO_NAVE;
	modulos[2].x = 0;
	modulos[2].y = 0;
	modulos[2].w = 54;
	modulos[2].h = 61;

	modulos[3].id = MODULO_TEXTO_TITULO;
	modulos[3].x = 71;
	modulos[3].y = 19;
	modulos[3].w = 477;
	modulos[3].h = 54;
	
	modulos[4].id = MODULO_TEXTO_NOMBRE;
	modulos[4].x = 63;
	modulos[4].y = 82;
	modulos[4].w = 365;
	modulos[4].h = 48;

	modulos[5].id = MODULO_TEXTO_MENU_OPCION1;
	modulos[5].x = 28;
	modulos[5].y = 145;
	modulos[5].w = 204;
	modulos[5].h = 57;

	modulos[6].id = MODULO_TEXTO_MENU_OPCION2;
	modulos[6].x = 276;
	modulos[6].y = 149;
	modulos[6].w = 142;
	modulos[6].h = 52;

	modulos[7].id = MODULO_TEXTO_MENU_OPCION1_SELECCIONADO;
	modulos[7].x = 38;
	modulos[7].y = 202;
	modulos[7].w = 192;
	modulos[7].h = 59;

	modulos[8].id = MODULO_TEXTO_MENU_OPCION2_SELECCIONADO;
	modulos[8].x = 271;
	modulos[8].y = 208;
	modulos[8].w = 153;
	modulos[8].h = 55;
	
}

