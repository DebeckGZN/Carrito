#include <GL/glut.h>
#include "tinyxml.h"
#include <string>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <vector>
#include <cmath>


typedef struct{
        float xy[2];
        float rgb[3];
        float raio;
}circ;

typedef struct{
     float altura;
     float largura;
     float xy[2];
     float rgb[3];
}quad;

typedef struct{
        quad chassi;
        quad rodas[4];
	quad eixos[2];
        quad farois[4];
        quad canhao;
}car;

typedef struct{
	float x;
	float y;
	float angulo;
	float raio;
	float speed;
}tiro;
std::vector<tiro> tiros;

circ maior, menor, enm1, enm2, enm3, player;
car carrito;
quad rect;

float frlR;
float frlG;
float frlB;

float frltR;
float frltG;
float frltB;

float velTiro;

char pathsvg[300];

const char *corCirExt, *corCirInt, *corPlayer, *corLargada, *corEnm1, *corEnm2, *corEnm3;

bool teclas[256];

float dx = player.xy[0];
float dy = player.xy[1];

int angRoda = -90;
int angCarro = -90;
int angCan = -90;

int passo = 10;
int xIni = 0;

void init();
void display();
void desenhaEixo();

tiro novo_tiro(void);
void cria_tiro(void);
tiro novo_tiro(void);
void cria_tiro(void);
void remove_tiro(int i);
void parseSVG(char* argv);
void keyOperations (void);
void parseXML(char* argv);
void passiveMotion(int x, int y);
void keyUp (unsigned char key, int x, int y);
void mouse(int botao, int estado, int x, int y);
void keyPressed (unsigned char key, int x, int y);
void circuloSemCor(GLint x, GLint y, int linhas, int raio);
void criaTiro(int linha, int raio, float r, float g, float b);
void desenhaQuadrilatero(int altura, int largura, float r, float g, float b);
void desenhaCirculo(int x, int y, int raio, int pontos, float r, float g, float b);
