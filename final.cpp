#include "parser.cpp"
#include "funcs.h"


int main(int argc, char *argv[])
{

        parseXML(argv[1]);
        glutInit( &argc, argv );
    	glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGB );
    	glutInitWindowSize( maior.raio*2, maior.raio*2 );
    	glutInitWindowPosition( 70, 75 );
    	glutCreateWindow("circuito");

    	init();
  		glutDisplayFunc( display );
        glutKeyboardFunc(keyPressed);
        glutKeyboardUpFunc(keyUp);
        glutPassiveMotionFunc( passiveMotion );
        glutTimerFunc(800,Timer,1);
        glutMouseFunc( mouse );

    	glutMainLoop();
    	return 0;
}



