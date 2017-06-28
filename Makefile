all:
	g++ final.cpp tinyxml.cpp tinystr.cpp tinyxmlparser.cpp tinyxmlerror.cpp -o trabalhocg -lGLU -lGL -lglut && ./trabalhocg /home/thaylo/Área\ de\ Trabalho/CG/carro/LeWildTrabReborn/

clear:
	rm trabalhocg
