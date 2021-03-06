// PlantillaOpenGL.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h" //ayuda a que compile mas rapido
#include <stdio.h> // esta cosa para librerias incluidas en c#
#include <stdlib.h>

#define GLEW_STATIC 

#include "GL/glew.h" //comillas para librerias personalizadas
#include "GLFW/glfw3.h"

#include <iostream>

#include "Shader.h"
#include "Vertice.h"

using namespace std; //aqui esta lo de c++

Shader *shader;
GLuint posicionID;
GLuint colorID;

//el vertice necesita saber como va a empezar a leer y donde


vector<Vertice> cuerpo;
GLuint vertexArrayCuerpoID;
GLuint bufferCuerpoID;

vector <Vertice> cara;
GLuint vertexArrayCaraID;
GLuint bufferCaraID;

vector <Vertice> barba;
GLuint vertexArrayBarbaID;
GLuint bufferBarbaID;

vector <Vertice> brazos;
GLuint vertexArrayBrazosID;
GLuint bufferBrazosID;

vector <Vertice> manos;
GLuint vertexArrayManosID;
GLuint bufferManosID;


vector <Vertice> base;
GLuint vertexArrayBaseID;
GLuint bufferBaseID;

vector <Vertice> piso;
GLuint vertexArrayPisoID;
GLuint bufferPisoID;

vector <Vertice> cabello;
GLuint vertexArrayCabelloID;
GLuint bufferCabelloID;

void inicializarCuerpo()
{
	Vertice v1 = { vec3(0.15, 0.6, 0.0), vec4(0.5, 0.5, 0.5, 1.0) };
	Vertice v2 = { vec3(0.15, -0.6, 0.0), vec4(0.5, 0.5, 0.5, 1.0) };
	Vertice v3 = { vec3(-0.15, -0.6, 0.0), vec4(0.5, 0.5, 0.5, 1.0) };
	Vertice v4 = { vec3(-0.15, 0.6, 0.0), vec4(0.5, 0.5, 0.5, 1.0) };

	cuerpo.push_back(v1);
	cuerpo.push_back(v2);
	cuerpo.push_back(v3);
	cuerpo.push_back(v4);

}

void inicializarCara()
{
	Vertice v1 = { vec3(0.1, 0.8, 0.0), vec4(0.5, 0.5, 0.5, 1.0) };
	Vertice v2 = { vec3(0.1, 0.6, 0.0), vec4(0.5, 0.5, 0.5, 1.0) };
	Vertice v3 = { vec3(-0.1, 0.6, 0.0), vec4(0.5, 0.5, 0.5, 1.0) };
	Vertice v4 = { vec3(-0.1, 0.8, 0.0), vec4(0.5, 0.5, 0.5, 1.0) };

	cara.push_back(v1);
	cara.push_back(v2);
	cara.push_back(v3);
	cara.push_back(v4);

}


void inicializarBarba()
{
	Vertice v1 = { vec3(0.05, 0.45, 0.0), vec4(0.6, 0.6, 0.6, 1.0) };
	Vertice v2 = { vec3(0.1, 0.6, 0.0), vec4(0.6, 0.6, 0.6, 1.0) };
	Vertice v3 = { vec3(-0.1, 0.6, 0.0), vec4(0.6, 0.6, 0.6, 1.0) };
	Vertice v4 = { vec3(-0.05, 0.45, 0.0), vec4(0.6, 0.6, 0.6, 1.0) };

	cara.push_back(v1);
	cara.push_back(v2);
	cara.push_back(v3);
	cara.push_back(v4);

}



void inicializarBrazos()
{
	Vertice v1 = { vec3(0.4, 0.6, 0.0), vec4(0.5, 0.5, 0.5, 1.0) };
	Vertice v2 = { vec3(0.4, 0.4, 0.0), vec4(0.5, 0.5, 0.5, 1.0) };
	Vertice v3 = { vec3(-0.4, 0.4, 0.0), vec4(0.5, 0.5, 0.5, 1.0) };
	Vertice v4 = { vec3(-0.4, 0.6, 0.0), vec4(0.5, 0.5, 0.5, 1.0) };

	cuerpo.push_back(v1);
	cuerpo.push_back(v2);
	cuerpo.push_back(v3);
	cuerpo.push_back(v4);

}

void inicializarManos()
{
	Vertice v1 = { vec3(0.5, 0.55, 0.0), vec4(0.5, 0.5, 0.5, 1.0) };
	Vertice v2 = { vec3(0.5, 0.45, 0.0), vec4(0.5, 0.5, 0.5, 1.0) };
	Vertice v3 = { vec3(-0.5, 0.45, 0.0), vec4(0.5, 0.5, 0.5, 1.0) };
	Vertice v4 = { vec3(-0.5, 0.55, 0.0), vec4(0.5, 0.5, 0.5, 1.0) };

	cuerpo.push_back(v1);
	cuerpo.push_back(v2);
	cuerpo.push_back(v3);
	cuerpo.push_back(v4);

}


void inicializarBase()
{
	Vertice v1 = { vec3(0.2, -0.9, 0.0), vec4(0.5, 0.5, 0.5, 1.0) };
	Vertice v2 = { vec3(0.2, -0.6, 0.0), vec4(0.5, 0.5, 0.5, 1.0) };
	Vertice v3 = { vec3(-0.2, -0.6, 0.0), vec4(0.5, 0.5, 0.5, 1.0) };
	Vertice v4 = { vec3(-0.2, -0.9, 0.0), vec4(0.5, 0.5, 0.5, 1.0) };

	base.push_back(v1);
	base.push_back(v2);
	base.push_back(v3);
	base.push_back(v4);

}


void inicializarPiso()
{
	Vertice v1 = { vec3(1, -1, 0.0), vec4(0.0, 0.9, 0.0, 1.0) };
	Vertice v2 = { vec3(1, -0.9, 0.0), vec4(0.0, 0.9, 0.0, 1.0) };
	Vertice v3 = { vec3(-1, -0.9, 0.0), vec4(0.0, 0.9, 0.0, 1.0) };
	Vertice v4 = { vec3(-1, -1, 0.0), vec4(0.0, 0.9, 0.0, 1.0) };

	base.push_back(v1);
	base.push_back(v2);
	base.push_back(v3);
	base.push_back(v4);

}


void inicializarCabello()
{
	Vertice v1 = { vec3(0.15, 0.85, 0.0), vec4(0.6, 0.6, 0.6, 1.0) };
	Vertice v2 = { vec3(0.15, 0.6, 0.0), vec4(0.6, 0.6, 0.6, 1.0) };
	Vertice v3 = { vec3(-0.15, 0.6, 0.0), vec4(0.6, 0.6, 0.6, 1.0) };
	Vertice v4 = { vec3(-0.15, 0.85, 0.0), vec4(0.6, 0.6, 0.6, 1.0) };

	cara.push_back(v1);
	cara.push_back(v2);
	cara.push_back(v3);
	cara.push_back(v4);

}


void dibujar()
{
	//Elegir el shader
	shader->enlazar();
	//Elegir un vertex array
	glBindVertexArray(vertexArrayCuerpoID);
	//Dibujar
	//toma de parametro el tipo de primitivas que va a dibujar,despues si va a tener un desface y el numero de vertices
	glDrawArrays(GL_QUADS, 0, cuerpo.size());
	


	glBindVertexArray(vertexArrayCaraID);
	glDrawArrays(GL_QUADS, 0, cara.size());
	
	glBindVertexArray(vertexArrayBrazosID);
	glDrawArrays(GL_QUADS, 0, brazos.size());

	glBindVertexArray(vertexArrayManosID);
	glDrawArrays(GL_QUADS, 0, manos.size());

	glBindVertexArray(vertexArrayBaseID);
	glDrawArrays(GL_QUADS, 0, base.size());
	
	glBindVertexArray(vertexArrayPisoID);
	glDrawArrays(GL_QUADS, 0, piso.size());


	//soltar el vertex array
	glBindVertexArray(0);
	//soltar el shader
	shader->desenlazar();
}

void actualizar() {

}

int main()
{
	//Declaramos apuntador de ventana

	GLFWwindow *window;

	//Si no se pudo iniciar glfw terminamos ejecución

	if (!glfwInit()) {
		exit(EXIT_FAILURE);
	}

	//Si se pudo iniciar GLFW entonces inicializamos la ventana

	window = glfwCreateWindow(1024, 768, "Ventana", NULL, NULL);

	//Si no podemos iniciar la ventana entonces terminamos la ejecución
	if (!window) {
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	//establecemos el contexto
	glfwMakeContextCurrent(window);

	//Una vez establecido e contexto activamos funciones modernas
	glewExperimental = true; //permite trabajar con gpu y cpu al mismo tiempo,solo va a funcionar si ya esta establecido el contexto

	//en caso de haber error se guarda en la variable errorGlew que es tipo GLenum 
	GLenum errorGlew = glewInit(); //inicializa glew

	if (errorGlew != GLEW_OK) {
		cout << glewGetErrorString(errorGlew);
	}

	//se obtiene la version de OpenGL y se imprime
	const GLubyte *versionGL = glGetString(GL_VERSION); 
	cout << "Version OpenGL: " << versionGL; 

	inicializarCabello();
	inicializarCuerpo();
	inicializarCara();
	inicializarBrazos();
	inicializarManos();
	inicializarBase();
	inicializarPiso();
	inicializarBarba();

	const char *rutaVertex = "VertexShader.shader";
	const char *rutaFragment = "FragmentShader.shader";

	//Se crea una nueva instancia de la clase
	shader = new Shader(rutaVertex, rutaFragment);

	//Mapeo de atributos
	//lleva 2 atributos el id del programa y la variable que va a obtener
	//aqui se estan guardando las entradas del vertex
	posicionID = glGetAttribLocation(shader -> getID(),"posicion");

	colorID = glGetAttribLocation(shader->getID(), "color");

	//Desenlazar el shader
	shader -> desenlazar();

	/*-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
	//Vertex array y buffer para un cuadrado

	//Crear un vertex array (los vertex array son el conjunto de vertices)
	//pide cuantos arreglos se haran, la direccion de memoria donde se va a guardar
	glGenVertexArrays(1, &vertexArrayCuerpoID);
	//con este se le dice que todas las acciones referentes a los vertex array estan vinculadas al que acabamos de crear
	glBindVertexArray(vertexArrayCuerpoID);

	//crear vertex buffer
	//aqui es cantidad y direccion de memoria
	glGenBuffers(1, &bufferCuerpoID);
	//Se dice que todas las acciones de buffer se hacen a este que acabamos de hacer
	//se le dice que tipo de buffer es y la direccion
	glBindBuffer(GL_ARRAY_BUFFER, bufferCuerpoID);

	//llenar el buffer
	//se le dice que tipo de buffer es, cuanto es el tamaño en bits de lo que le queremos mandar, el espacio de memoria donde va a empezar a leer y para que lo vas a utilizar
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertice) * cuerpo.size(), cuerpo.data(), GL_STATIC_DRAW);

	//habilitar atributos del shader
	glEnableVertexAttribArray(posicionID);
	glEnableVertexAttribArray(colorID);

	//Especificar a OpenGL como se van a comunicar
	//el primer atributo es cual se va a comunicar, el segundo es el tamaño de lo que se tiene que mandar(en este caso 3 flotantes), el tipo de dato de lo que estas mandando,si esta normalizado,el stride es que se van a leer 3 valores y que tanto espacio va a dejar pasar para tomar otros 3 valores, se le pasa el tamaño del vertice incluyendo los 3 que ya se tomaron en cuenta
	glVertexAttribPointer(posicionID, 3, GL_FLOAT, GL_FALSE, sizeof(Vertice), 0);
	glVertexAttribPointer(colorID, 4, GL_FLOAT, GL_FALSE, sizeof(Vertice), (void*) sizeof(vec3));

	/*-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
	//Vertex array y buffer para un cuadrado

	//Crear un vertex array (los vertex array son el conjunto de vertices)
	//pide cuantos arreglos se haran, la direccion de memoria donde se va a guardar
	glGenVertexArrays(1, &vertexArrayCaraID);
	//con este se le dice que todas las acciones referentes a los vertex array estan vinculadas al que acabamos de crear
	glBindVertexArray(vertexArrayCaraID);

	//crear vertex buffer
	//aqui es cantidad y direccion de memoria
	glGenBuffers(1, &bufferCaraID);
	//Se dice que todas las acciones de buffer se hacen a este que acabamos de hacer
	//se le dice que tipo de buffer es y la direccion
	glBindBuffer(GL_ARRAY_BUFFER, bufferCaraID);

	//llenar el buffer
	//se le dice que tipo de buffer es, cuanto es el tamaño en bits de lo que le queremos mandar, el espacio de memoria donde va a empezar a leer y para que lo vas a utilizar
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertice) * cara.size(), cara.data(), GL_STATIC_DRAW);

	//habilitar atributos del shader
	glEnableVertexAttribArray(posicionID);
	glEnableVertexAttribArray(colorID);

	//Especificar a OpenGL como se van a comunicar
	//el primer atributo es cual se va a comunicar, el segundo es el tamaño de lo que se tiene que mandar(en este caso 3 flotantes), el tipo de dato de lo que estas mandando,si esta normalizado,el stride es que se van a leer 3 valores y que tanto espacio va a dejar pasar para tomar otros 3 valores, se le pasa el tamaño del vertice incluyendo los 3 que ya se tomaron en cuenta
	glVertexAttribPointer(posicionID, 3, GL_FLOAT, GL_FALSE, sizeof(Vertice), 0);
	glVertexAttribPointer(colorID, 4, GL_FLOAT, GL_FALSE, sizeof(Vertice), (void*) sizeof(vec3));

	/*-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/


	/*-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
	//Vertex array y buffer para un cuadrado

	//Crear un vertex array (los vertex array son el conjunto de vertices)
	//pide cuantos arreglos se haran, la direccion de memoria donde se va a guardar
	glGenVertexArrays(1, &vertexArrayBrazosID);
	//con este se le dice que todas las acciones referentes a los vertex array estan vinculadas al que acabamos de crear
	glBindVertexArray(vertexArrayBrazosID);

	//crear vertex buffer
	//aqui es cantidad y direccion de memoria
	glGenBuffers(1, &bufferBrazosID);
	//Se dice que todas las acciones de buffer se hacen a este que acabamos de hacer
	//se le dice que tipo de buffer es y la direccion
	glBindBuffer(GL_ARRAY_BUFFER, bufferBrazosID);

	//llenar el buffer
	//se le dice que tipo de buffer es, cuanto es el tamaño en bits de lo que le queremos mandar, el espacio de memoria donde va a empezar a leer y para que lo vas a utilizar
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertice) * brazos.size(), brazos.data(), GL_STATIC_DRAW);

	//habilitar atributos del shader
	glEnableVertexAttribArray(posicionID);
	glEnableVertexAttribArray(colorID);

	//Especificar a OpenGL como se van a comunicar
	//el primer atributo es cual se va a comunicar, el segundo es el tamaño de lo que se tiene que mandar(en este caso 3 flotantes), el tipo de dato de lo que estas mandando,si esta normalizado,el stride es que se van a leer 3 valores y que tanto espacio va a dejar pasar para tomar otros 3 valores, se le pasa el tamaño del vertice incluyendo los 3 que ya se tomaron en cuenta
	glVertexAttribPointer(posicionID, 3, GL_FLOAT, GL_FALSE, sizeof(Vertice), 0);
	glVertexAttribPointer(colorID, 4, GL_FLOAT, GL_FALSE, sizeof(Vertice), (void*) sizeof(vec3));

	/*-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/


	/*-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
	//Vertex array y buffer para un cuadrado

	//Crear un vertex array (los vertex array son el conjunto de vertices)
	//pide cuantos arreglos se haran, la direccion de memoria donde se va a guardar
	glGenVertexArrays(1, &vertexArrayManosID);
	//con este se le dice que todas las acciones referentes a los vertex array estan vinculadas al que acabamos de crear
	glBindVertexArray(vertexArrayManosID);

	//crear vertex buffer
	//aqui es cantidad y direccion de memoria
	glGenBuffers(1, &bufferManosID);
	//Se dice que todas las acciones de buffer se hacen a este que acabamos de hacer
	//se le dice que tipo de buffer es y la direccion
	glBindBuffer(GL_ARRAY_BUFFER, bufferManosID);

	//llenar el buffer
	//se le dice que tipo de buffer es, cuanto es el tamaño en bits de lo que le queremos mandar, el espacio de memoria donde va a empezar a leer y para que lo vas a utilizar
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertice) * manos.size(), manos.data(), GL_STATIC_DRAW);

	//habilitar atributos del shader
	glEnableVertexAttribArray(posicionID);
	glEnableVertexAttribArray(colorID);

	//Especificar a OpenGL como se van a comunicar
	//el primer atributo es cual se va a comunicar, el segundo es el tamaño de lo que se tiene que mandar(en este caso 3 flotantes), el tipo de dato de lo que estas mandando,si esta normalizado,el stride es que se van a leer 3 valores y que tanto espacio va a dejar pasar para tomar otros 3 valores, se le pasa el tamaño del vertice incluyendo los 3 que ya se tomaron en cuenta
	glVertexAttribPointer(posicionID, 3, GL_FLOAT, GL_FALSE, sizeof(Vertice), 0);
	glVertexAttribPointer(colorID, 4, GL_FLOAT, GL_FALSE, sizeof(Vertice), (void*) sizeof(vec3));

	/*-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/


	/*-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
	//Vertex array y buffer para un cuadrado

	//Crear un vertex array (los vertex array son el conjunto de vertices)
	//pide cuantos arreglos se haran, la direccion de memoria donde se va a guardar
	glGenVertexArrays(1, &vertexArrayBaseID);
	//con este se le dice que todas las acciones referentes a los vertex array estan vinculadas al que acabamos de crear
	glBindVertexArray(vertexArrayBaseID);

	//crear vertex buffer
	//aqui es cantidad y direccion de memoria
	glGenBuffers(1, &bufferBaseID);
	//Se dice que todas las acciones de buffer se hacen a este que acabamos de hacer
	//se le dice que tipo de buffer es y la direccion
	glBindBuffer(GL_ARRAY_BUFFER, bufferBaseID);

	//llenar el buffer
	//se le dice que tipo de buffer es, cuanto es el tamaño en bits de lo que le queremos mandar, el espacio de memoria donde va a empezar a leer y para que lo vas a utilizar
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertice) * base.size(), base.data(), GL_STATIC_DRAW);

	//habilitar atributos del shader
	glEnableVertexAttribArray(posicionID);
	glEnableVertexAttribArray(colorID);

	//Especificar a OpenGL como se van a comunicar
	//el primer atributo es cual se va a comunicar, el segundo es el tamaño de lo que se tiene que mandar(en este caso 3 flotantes), el tipo de dato de lo que estas mandando,si esta normalizado,el stride es que se van a leer 3 valores y que tanto espacio va a dejar pasar para tomar otros 3 valores, se le pasa el tamaño del vertice incluyendo los 3 que ya se tomaron en cuenta
	glVertexAttribPointer(posicionID, 3, GL_FLOAT, GL_FALSE, sizeof(Vertice), 0);
	glVertexAttribPointer(colorID, 4, GL_FLOAT, GL_FALSE, sizeof(Vertice), (void*) sizeof(vec3));

	/*-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

	/*-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
	//Vertex array y buffer para un cuadrado

	//Crear un vertex array (los vertex array son el conjunto de vertices)
	//pide cuantos arreglos se haran, la direccion de memoria donde se va a guardar
	glGenVertexArrays(1, &vertexArrayPisoID);
	//con este se le dice que todas las acciones referentes a los vertex array estan vinculadas al que acabamos de crear
	glBindVertexArray(vertexArrayPisoID);

	//crear vertex buffer
	//aqui es cantidad y direccion de memoria
	glGenBuffers(1, &bufferPisoID);
	//Se dice que todas las acciones de buffer se hacen a este que acabamos de hacer
	//se le dice que tipo de buffer es y la direccion
	glBindBuffer(GL_ARRAY_BUFFER, bufferPisoID);

	//llenar el buffer
	//se le dice que tipo de buffer es, cuanto es el tamaño en bits de lo que le queremos mandar, el espacio de memoria donde va a empezar a leer y para que lo vas a utilizar
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertice) * piso.size(), piso.data(), GL_STATIC_DRAW);

	//habilitar atributos del shader
	glEnableVertexAttribArray(posicionID);
	glEnableVertexAttribArray(colorID);

	//Especificar a OpenGL como se van a comunicar
	//el primer atributo es cual se va a comunicar, el segundo es el tamaño de lo que se tiene que mandar(en este caso 3 flotantes), el tipo de dato de lo que estas mandando,si esta normalizado,el stride es que se van a leer 3 valores y que tanto espacio va a dejar pasar para tomar otros 3 valores, se le pasa el tamaño del vertice incluyendo los 3 que ya se tomaron en cuenta
	glVertexAttribPointer(posicionID, 3, GL_FLOAT, GL_FALSE, sizeof(Vertice), 0);
	glVertexAttribPointer(colorID, 4, GL_FLOAT, GL_FALSE, sizeof(Vertice), (void*) sizeof(vec3));

	/*-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

		/*-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
	//Vertex array y buffer para un cuadrado

	//Crear un vertex array (los vertex array son el conjunto de vertices)
	//pide cuantos arreglos se haran, la direccion de memoria donde se va a guardar
	glGenVertexArrays(1, &vertexArrayBarbaID);
	//con este se le dice que todas las acciones referentes a los vertex array estan vinculadas al que acabamos de crear
	glBindVertexArray(vertexArrayBarbaID);

	//crear vertex buffer
	//aqui es cantidad y direccion de memoria
	glGenBuffers(1, &bufferBarbaID);
	//Se dice que todas las acciones de buffer se hacen a este que acabamos de hacer
	//se le dice que tipo de buffer es y la direccion
	glBindBuffer(GL_ARRAY_BUFFER, bufferBarbaID);

	//llenar el buffer
	//se le dice que tipo de buffer es, cuanto es el tamaño en bits de lo que le queremos mandar, el espacio de memoria donde va a empezar a leer y para que lo vas a utilizar
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertice) * barba.size(), barba.data(), GL_STATIC_DRAW);

	//habilitar atributos del shader
	glEnableVertexAttribArray(posicionID);
	glEnableVertexAttribArray(colorID);

	//Especificar a OpenGL como se van a comunicar
	//el primer atributo es cual se va a comunicar, el segundo es el tamaño de lo que se tiene que mandar(en este caso 3 flotantes), el tipo de dato de lo que estas mandando,si esta normalizado,el stride es que se van a leer 3 valores y que tanto espacio va a dejar pasar para tomar otros 3 valores, se le pasa el tamaño del vertice incluyendo los 3 que ya se tomaron en cuenta
	glVertexAttribPointer(posicionID, 3, GL_FLOAT, GL_FALSE, sizeof(Vertice), 0);
	glVertexAttribPointer(colorID, 4, GL_FLOAT, GL_FALSE, sizeof(Vertice), (void*) sizeof(vec3));

	/*-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/



		/*-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
	//Vertex array y buffer para un cuadrado

	//Crear un vertex array (los vertex array son el conjunto de vertices)
	//pide cuantos arreglos se haran, la direccion de memoria donde se va a guardar
	glGenVertexArrays(1, &vertexArrayCabelloID);
	//con este se le dice que todas las acciones referentes a los vertex array estan vinculadas al que acabamos de crear
	glBindVertexArray(vertexArrayCabelloID);

	//crear vertex buffer
	//aqui es cantidad y direccion de memoria
	glGenBuffers(1, &bufferCabelloID);
	//Se dice que todas las acciones de buffer se hacen a este que acabamos de hacer
	//se le dice que tipo de buffer es y la direccion
	glBindBuffer(GL_ARRAY_BUFFER, bufferCabelloID);

	//llenar el buffer
	//se le dice que tipo de buffer es, cuanto es el tamaño en bits de lo que le queremos mandar, el espacio de memoria donde va a empezar a leer y para que lo vas a utilizar
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertice) * cabello.size(), cabello.data(), GL_STATIC_DRAW);

	//habilitar atributos del shader
	glEnableVertexAttribArray(posicionID);
	glEnableVertexAttribArray(colorID);

	//Especificar a OpenGL como se van a comunicar
	//el primer atributo es cual se va a comunicar, el segundo es el tamaño de lo que se tiene que mandar(en este caso 3 flotantes), el tipo de dato de lo que estas mandando,si esta normalizado,el stride es que se van a leer 3 valores y que tanto espacio va a dejar pasar para tomar otros 3 valores, se le pasa el tamaño del vertice incluyendo los 3 que ya se tomaron en cuenta
	glVertexAttribPointer(posicionID, 3, GL_FLOAT, GL_FALSE, sizeof(Vertice), 0);
	glVertexAttribPointer(colorID, 4, GL_FLOAT, GL_FALSE, sizeof(Vertice), (void*) sizeof(vec3));

	/*-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/









	//soltar vertex array y buffer
	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	//ciclo de dibujo (draw loop)
	while (!glfwWindowShouldClose(window)) {
		//Establecer region de dibujo
		glViewport(0, 0, 1024, 768); //dice donde va a empezar a renderear y donde va a terminar
		//Establecer color de borrado
		glClearColor(0.0f, 0.0f, 0.8f, 1.0f);
		//Borramos
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//Rutina de dibujo
		dibujar();
		actualizar();

		//Cambiar los buffer
		glfwSwapBuffers(window); //cambia el buffer de la pantalla por el otro que se lleno
		//reconocer si hay entradas
		glfwPollEvents();

	}

	glfwDestroyWindow(window); //terminamos los procesos y eliminamos la ventana
	glfwTerminate();
	return 0;
}



