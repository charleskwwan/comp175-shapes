## osx
build:
	g++ -Wall -Wextra Assignment1.cpp -framework OpenGL -framework GLUT -lglui -o Assignment1

linux:
	g++ -Wall -Wextra Assignment1.cpp -lglut -lglui -lGL -lGLU -o Assignment1

