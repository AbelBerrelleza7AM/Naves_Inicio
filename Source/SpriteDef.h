#ifndef __SPRITEDEF_H__
#define __SPRITEDEF_H__

class SpriteDef{
	struct Modulos{
		int id;
		int x;
		int y;
		int w;
		int h;
	};
public:
	Modulos modulos [9];// numeros de modulos
	SpriteDef();
};

#endif
