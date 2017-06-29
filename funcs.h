//#include "var.cpp"



void init()
{
	float left = maior.xy[0]-maior.raio;

	float right = maior.xy[0]+maior.raio;

	float roof = maior.xy[1]-maior.raio;

	float ceiling = maior.xy[1]+maior.raio;

    //Selecionar cor de fundo preto
    	glClearColor( 1, 1, 1, 0.0 );

    	gluOrtho2D(left,right,roof,ceiling);//2
        for (int i =0;i<256;i++)
        teclas[i]=0;
}


void display(){

	glClear( GL_COLOR_BUFFER_BIT );
	keyOperations();
	
////////circuito
	desenhaCirculo(maior.xy[0],maior.xy[1],360,maior.raio,maior.rgb[0],maior.rgb[1],maior.rgb[2]);
	desenhaCirculo(menor.xy[0],menor.xy[1],360,menor.raio,menor.rgb[0],menor.rgb[1],menor.rgb[2]);

////////linha de largada
	glPushMatrix();
		glTranslatef(rect.xy[0] + rect.largura/2,rect.xy[1],0 );
		desenhaQuadrilatero(rect.altura,rect.largura,rect.rgb[0],rect.rgb[1],rect.rgb[2]);
	glPopMatrix();

	

////////jogador
	glPushMatrix();

		glTranslatef(dx,dy,0);

		glTranslatef(player.xy[0],player.xy[1],0);

///////////colisao
		glPushMatrix();
			circuloSemCor(0,0,360,player.raio);
		glPopMatrix();

		glRotatef(angCarro,0,0,1);
		glRotatef(90,0,0,1);

//////////eixos

		glTranslatef(0,-player.raio/1.5,0);
		glPushMatrix();
			glTranslatef(0,carrito.chassi.altura*3/4,0);
			glTranslatef(0,-carrito.chassi.altura*1/8,0);
			desenhaQuadrilatero(carrito.eixos[0].altura,carrito.eixos[0].largura,0.3,0,0);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(0,carrito.chassi.altura*1/4,0);
			glTranslatef(0,-carrito.chassi.altura*1/8,0);
			desenhaQuadrilatero(carrito.eixos[1].altura,carrito.eixos[1].largura,0.3,0,0);
		glPopMatrix();

//////////farois

		glPushMatrix();
			glTranslatef(-player.raio/5,carrito.chassi.altura*15/16,0);
			desenhaQuadrilatero(carrito.farois[0].altura,carrito.farois[0].largura,frlR,frlG,frlB);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(player.raio/5,carrito.chassi.altura*15/16,0);
			desenhaQuadrilatero(carrito.farois[1].altura,carrito.farois[1].largura,frlR,frlG,frlB);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(-player.raio/5,-carrito.chassi.altura*1/16,0);
			desenhaQuadrilatero(carrito.farois[2].altura,carrito.farois[2].largura,frltR,frltG,frltB);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(player.raio/5,-carrito.chassi.altura*1/16,0);
			desenhaQuadrilatero(carrito.farois[3].altura,carrito.farois[3].largura,frltR,frltG,frltB);
		glPopMatrix();

//////////rodas
		glPushMatrix();
			glTranslatef(player.raio*2/3,carrito.chassi.altura*3/4,0);
			glRotatef(angRoda,0,0,1);
			glRotatef(90,0,0,1);
			glTranslatef(0,-carrito.rodas[0].altura/2,0);
			desenhaQuadrilatero(carrito.rodas[0].altura,carrito.rodas[0].largura,0.1,0.1,0.1);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(-player.raio*2/3,carrito.chassi.altura*3/4,0);
			glRotatef(angRoda,0,0,1);
			glRotatef(90,0,0,1);
			glTranslatef(0,-carrito.rodas[1].altura/2,0);
			desenhaQuadrilatero(carrito.rodas[1].altura,carrito.rodas[1].largura,0.1,0.1,0.1);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(player.raio*2/3,carrito.chassi.altura*1/4,0);
			glTranslatef(0,-carrito.rodas[2].altura/2,0);
			desenhaQuadrilatero(carrito.rodas[2].altura,carrito.rodas[2].largura,0.1,0.1,0.1);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(-player.raio*2/3,carrito.chassi.altura*1/4,0);
			glTranslatef(0,-carrito.rodas[3].altura/2,0);
			desenhaQuadrilatero(carrito.rodas[3].altura,carrito.rodas[3].largura,0.1,0.1,0.1);
		glPopMatrix();

//////////canhao
		glPushMatrix();
			glTranslatef(0,carrito.chassi.altura*0.9,0);
			glRotatef(angCan,0,0,1);
			glRotatef(90,0,0,1);
			desenhaQuadrilatero( carrito.canhao.altura, carrito.canhao.largura, 0.4, 0.4, 0.4);
		glPopMatrix();

///////////chassi
		glPushMatrix();
			desenhaQuadrilatero( carrito.chassi.altura, carrito.chassi.largura, 0, 1, 0);
		glPopMatrix();

//////////listra
		
		glPushMatrix();
			desenhaQuadrilatero( carrito.chassi.altura, carrito.chassi.largura/2, 0, 0, 0);
		glPopMatrix();


	glPopMatrix();
	cria_tiro();
////////"inimigos"
	desenhaCirculo(enm1.xy[0],enm1.xy[1],360,enm1.raio,enm1.rgb[0],enm1.rgb[1],enm1.rgb[2]);
	desenhaCirculo(enm2.xy[0],enm2.xy[1],360,enm2.raio,enm2.rgb[0],enm2.rgb[1],enm2.rgb[2]);
	desenhaCirculo(enm3.xy[0],enm3.xy[1],360,enm3.raio,enm3.rgb[0],enm3.rgb[1],enm3.rgb[2]);
	
	glutSwapBuffers();
}

void desenhaCirculo(GLint x, GLint y, int linhas, int raio, float r, float g, float b){
	int i = 0;
		glColor3f(r,g,b);
	float angulo;
	glBegin(GL_POLYGON);
		for(i=0;i<linhas;i++){
			angulo = 2*M_PI*i/linhas;
			glVertex2f(x + (cos(angulo)*raio),y + (sin(angulo)*raio));
		}
	glEnd();
}

void desenhaQuadrilatero(int altura, int largura, float r, float g, float b){

	glColor3f(r,g,b);
	glBegin( GL_QUADS );
		glVertex2f ( largura/2, 0 );
		glVertex2f ( -(largura/2), 0 );
		glVertex2f ( -(largura/2), altura );
		glVertex2f ( largura/2, altura );
	glEnd();

}

void circuloSemCor(GLint x, GLint y, int linhas, int raio){
	int i = 0;
	float angulo;
	glBegin(GL_LINE);
		for(i=0;i<linhas;i++){
			angulo = 2*M_PI*i/linhas;
			glVertex2f(x + (cos(angulo)*raio),y + (sin(angulo)*raio));
		}
	glEnd();
}



float distPlayer(int oxPlayer, int oyPlayer){
	return sqrt( (maior.xy[0] - (oxPlayer + dx))*(maior.xy[0] - (oxPlayer + dx)) + (maior.xy[1] - (oyPlayer+ dy))*(maior.xy[1] - (oyPlayer  + dy)) );
}

float enemyIsNear (int xInimigo, int yInimigo, int oxPlayer, int oyPlayer){
	return sqrt( (oxPlayer + dx - xInimigo )*(oxPlayer + dx - xInimigo ) +
                (oyPlayer + dy - yInimigo)*(oyPlayer + dy - yInimigo) );
}

//funcoes que alteram o flag no vetor de teclas
void keyPressed (unsigned char key, int x, int y) {
    teclas[key] = true; // altera pra true a posicao da tecla pressionada
    }
void keyUp (unsigned char key, int x, int y){
    teclas[key] = false;// altera pra false a posicao da tecla pressionada

}

void keyOperations (void) {

	float distMin = menor.raio + player.raio;
	float distMax = maior.raio - player.raio;
	float distEnemy = player.raio + enm1.raio;

	float dCos =cos(((angCarro*M_PI)/180.0));
	float dSin =sin(((angCarro*M_PI)/180.0));

	if (teclas['w']==true || teclas['W']==true){
		if(distPlayer(player.xy[0]-6*dCos,player.xy[1]-6*dSin) > distMin && distPlayer(player.xy[0]-6*dCos,player.xy[1]-6*dSin) < distMax
		&& enemyIsNear(enm1.xy[0],enm1.xy[1],player.xy[0]-6*dCos,player.xy[1]-6*dSin) > distEnemy
		&& enemyIsNear(enm2.xy[0],enm2.xy[1],player.xy[0]-6*dCos,player.xy[1]-6*dSin) > distEnemy
		&& enemyIsNear(enm3.xy[0],enm3.xy[1],player.xy[0]-6*dCos,player.xy[1]-6*dSin) > distEnemy){		
			dx-=6*dCos;
			dy-=6*dSin;
			if(angRoda > -90) angCarro+=5;
			if(angRoda < -90) angCarro-=5;
			frlR = 1;
			frlG = 1;
			frlB = 1;
		}
  }else if(teclas['s']==true || teclas['S']==true){
		if(distPlayer(player.xy[0]+2*dCos,player.xy[1]+2*dSin) > distMin && distPlayer(player.xy[0]+2*dCos,player.xy[1]+2*dSin) < distMax
		&& enemyIsNear(enm1.xy[0],enm1.xy[1],player.xy[0]+2*dCos,player.xy[1]+2*dSin) > distEnemy
		&& enemyIsNear(enm2.xy[0],enm2.xy[1],player.xy[0]+2*dCos,player.xy[1]+2*dSin) > distEnemy
		&& enemyIsNear(enm3.xy[0],enm3.xy[1],player.xy[0]+2*dCos,player.xy[1]+2*dSin) > distEnemy){
			dx+=2*dCos;
		  	dy+=2*dSin;
			if(angRoda < -90) angCarro+=3;
			if(angRoda > -90) angCarro-=3;
			frltR = 1;
			frltG = 0;
			frltB = 0;
		}
  }
	if(teclas['a']==true || teclas['A']==true){
		if(angRoda+passo < -45) angRoda+=passo;
		if(angRoda+passo >-45) angRoda = -45;
	}
	if(teclas['d']==true || teclas['D']==true){
		if(angRoda-passo > -135) angRoda-=passo;
		if(angRoda+passo <-135) angRoda = -135;
	}
	if((teclas['a']==false && teclas['A']==false)  && (teclas['d']==false && teclas['D']==false)) angRoda = -90;
	glutPostRedisplay();
	if(teclas['w'] == false && teclas['W'] == false){

			frlR = 0.7;
			frlG = 0.7;
			frlB = 0.7;
	}
	if(teclas['s'] == false && teclas['S'] == false){

			frltR = 0.7;
			frltG = 0.7;
			frltB = 0.7;
	}
	if(angCarro > 270) angCarro = -90;
	else if(angCarro > 360 || angCarro < -360) angCarro =0;
}

void passiveMotion(int x, int y){

	if(angCarro<0 && angCarro>-180){
		if(x<xIni){
			if(angCan < -45)angCan+=passo/5;
			if(angCan > -45)angCan = -45;
			xIni = x;
		}else{
			if(angCan > -135)angCan-=passo/5;
			if(angCan < -135)angCan = -135;
			xIni = x;
		}
	}
	else{
		if(x>xIni){
			if(angCan < -45)angCan+=2;
			if(angCan > -45)angCan = -45;
			xIni = x;
		}else{
			if(angCan > -135)angCan-=2;
			if(angCan < -135)angCan = -135;
			xIni = x;
		}
	}

	glutPostRedisplay();
}

tiro novo_tiro(void){
    tiro t;
		t.speed = velTiro;
		t.raio = player.raio*1/10;
    t.angulo = angCarro + (angCan)+270;
    t.x = dx - cos(angCarro*M_PI/180.0)*(carrito.chassi.altura/2) + cos((t.angulo)*M_PI/180.0)*carrito.canhao.altura;
    t.y = dy - sin(angCarro*M_PI/180.0)*(carrito.chassi.altura/2) + sin((t.angulo)*M_PI/180.0)*carrito.canhao.altura;
    return t;
}

void mouse(int botao, int estado, int x, int y)
{

	if(botao == GLUT_LEFT_BUTTON){
		switch(estado){
			case GLUT_DOWN:
				tiros.push_back(novo_tiro());
				break;
		}
	}
}

void cria_tiro(void){

    if(!tiros.empty()){
        for(int i = 0; i < tiros.size(); i++){
            glPushMatrix();
                glTranslatef(tiros[i].x, tiros[i].y, 0);
                desenhaCirculo(player.xy[0],player.xy[1],360,tiros[i].raio,0,1,0);
            glPopMatrix();
            //caminho que os tiros vao seguir
          	tiros[i].x += cos(tiros[i].angulo * M_PI / 180.0)*tiros[i].speed;
          	tiros[i].y += sin(tiros[i].angulo * M_PI / 180.0)*tiros[i].speed;

						remove_tiro(i);
        }
    }
    glutPostRedisplay();      
}

void remove_tiro(int i){

	float distMin = menor.raio + tiros[i].raio;
	float distMax = maior.raio - tiros[i].raio;
	float distEnemy = tiros[i].raio + enm1.raio;

	float dCos =cos((tiros[i].angulo*M_PI)/180.0);
	float dSin =sin((tiros[i].angulo*M_PI)/180.0);

	float tx = tiros[i].x+player.xy[0] -dx;
	float ty = tiros[i].y+player.xy[1]-dy;

	if(distPlayer(tx,ty) < distMin || distPlayer(tx,ty) > distMax
	|| enemyIsNear(enm1.xy[0],enm1.xy[1],tx,ty) < distEnemy
	|| enemyIsNear(enm2.xy[0],enm2.xy[1],tx,ty) < distEnemy
	|| enemyIsNear(enm3.xy[0],enm3.xy[1],tx,ty) < distEnemy){
		tiros.erase(tiros.begin()+i);
	}
}
