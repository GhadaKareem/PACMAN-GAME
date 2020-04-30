#include "Renderer.h"

Renderer::Renderer()
{
    
}

Renderer::~Renderer()
{
    Cleanup();
}

void Renderer::Initialize()
{

	glGenVertexArrays(1, &vertexArrayID);
	glBindVertexArray(vertexArrayID);
	glClearColor(0.85, 0.60,80, 1.0f); 

	 GLfloat verts[] =
	{

		 -1.0f, -1.0f, 1.0f, // vertices
		 1.0f, 1.0f, 1.0f, //normal
		 1,1,		//uv data

		 1.0f, 1.0f, 1.0f,
		 1.0f, 1.0f, 1.0f, //color Blu
		 0,0,

		 -1.0f, 1.0f, 1.0f,
		 1.0f, 1.0f, 1.0f, //color Blu
		 1,0,


		 //Square Triangle front-down
		 1.0f, 1.0f, 1.0f, //vertex position left
		 1.0f, 1.0f, 1.0f, //color Blu
		 0,0,

		 -1.0f, -1.0f, 1.0f, //vertex position up
		 1.0f, 1.0f, 1.0f, //color Blu		
		 1,1,

		 1.0f, -1.0f, 1.0f, //vertex position Right tmam hyb2a m3waq kda mzboten tyb
		 1.0f, 1.0f, 1.0f, //color Blu	
		 0,1,
		 ///////////////////////second facce

		 //Square Triangle right side up
		 1.0f, -1.0f, 1.0f, //vertex position up
		 1.0f, 1.0f, 0.0f, //color Blu
		 1,1,

		 1.0f, 1.0f, 1.0f, //vertex position left
		 1.0f, 1.0f, 0.0f, //color Blu
		 1,0,

		 1.0f, 1.0f, -1.0f, //vertex position up 
		 1.0f, 1.0f, 0.0f, //color Blu
		 0,0,

		  //Square Triangle right side down
		 1.0f, -1.0f, 1.0f, //vertex position up
		 1.0f, 1.0f, 0.0f, //color Blu
		 1,1,

		 1.0f, -1.0f, -1.0f, //vertex position up 
		 1.0f, 1.0f, 0.0f, //color Blu
		 0,1,

		 1.0f, 1.0f, -1.0f, //vertex position up
		 1.0f, 1.0f, 0.0f, //color Blu
		 0,0,

		  //Square Triangle up square right
		 -1.0f, 1.0f, 1.0f, //vertex position up
		 0.0f, 1.0f, 0.0f, //color Blu
		 1,0,

		 1.0f, 1.0f, 1.0f, //vertex position up
		 0.0f, 1.0f, 0.0f, //color Blu
		 1,1,

		 1.0f, 1.0f, -1.0f, //vertex position up
		 0.0f, 1.0f, 0.0f, //color Blu
		 0,1,

		////Square Triangle up square left
		-1.0f, 1.0f, 1.0f, //vertex position up
		0.0f, 1.0f, 0.0f, //color Blu
		1,0,

		-1.0f, 1.0f, -1.0f, //vertex position up
		0.0f, 1.0f, 0.0f, //color Blu
		0,0,

		1.0f, 1.0f, -1.0f, //vertex position up
		0.0f, 1.0f, 0.0f, //color Blu
		0,1,

		////Square Triangle left side up
		-1.0f, 1.0f, 1.0f, //vertex position up
		1.0f, 1.0f, 0.0f, //color Blu
		0,0,

		-1.0f, 1.0f, -1.0f, //vertex position up
		1.0f, 1.0f, 0.0f, //color Blubac
		1,0,

		-1.0f, -1.0f, 1.0f, //vertex position up
		1.0f, 1.0f, 0.0f, //color Blu
		0,1,

		////Square Triangle left side down
		-1.0f, 1.0f, -1.0f, //vertex position up
		1.0f, 1.0f, 0.0f, //color Yellow
		1,0,

		  -1.0f, -1.0f, -1.0f, //vertex position up
		  1.0f, 1.0f, 0.0f, //color Red bac
		1, 1,
		
			 -1.0f, -1.0f, 1.0f, //vertex position up
		  1.0f, 1.0f, 0.0f, //color Blue
			 0, 1,

		  ///Square Triangle base down
		  1.0f, -1.0f, -1.0f, //vertex position up
		  0.0f, 1.0f, 1.0f, //color Yellow
			 0, 0,

		  1.0f, -1.0f, 1.0f, //vertex position up
		  0.0f, 1.0f, 1.0f, //color Red bac
			 1, 0,

		  -1.0f, -1.0f, 1.0f, //vertex position up
		  0.0f, 1.0f, 1.0f, //color Blue
			 1, 1,
				
		  ///Square Triangle base up
		  -1.0f, -1.0f, 1.0f, //vertex position up
		  0.0f, 1.0f, 1.0f, //color Yellow
			 1,1,

		  -1.0f, -1.0f, -1.0f, //vertex position up
		  0.0f, 1.0f, 1.0f, //color Red bac
			 0, 1,

		  1.0f, -1.0f, -1.0f, //vertex position up
		  0.0f, 1.0f, 1.0f, //color Blue
			  0, 0,

		  ///Square Triangle back up
		  -1.0f, 1.0f, -1.0f, //vertex position up
		  0.0f, 0.0f, 0.0f, //color Yellow
			  0, 0,

		  1.0f, 1.0f, -1.0f, //vertex position up
		  0.0f, 0.0f, 0.0f, //color Red bac
			  1, 0,

		  -1.0f, -1.0f, -1.0f, //vertex position up
		  0.0f, 0.0f, 0.0f, //color Blue
			  0, 1,


		  ///Square Triangle back down
		  1.0f, -1.0f, -1.0f, //vertex position up
		  1.0f, 1.0f, 1.0f, //color Yellow
			  1,1,

		  1.0f, 1.0f, -1.0f, //vertex position up
		  1.0f, 1.0f, 0.0f, //color Red bac
			  1, 0,

		  -1.0f, -1.0f, -1.0f, //vertex position up
		  1.0f, 1.0f, 0.0f, //color Blue
			  0, 1

	};
	
	////////////////////////////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////////////////////////////
	//shader
	 glGenBuffers(1, &vertexBufferID);
	 glBindBuffer(GL_ARRAY_BUFFER, vertexBufferID);
	 glBufferData(GL_ARRAY_BUFFER, sizeof(verts), verts, GL_STATIC_DRAW);
	 ProjectionMatrix = perspective(45.0f, 1024.0f / 768.0f, 0.1f, 1000.0f);
	programID = LoadShaders( "SimpleVertexShader.vertexshader", "SimpleFragmentShader.fragmentshader" );
	   MatrixID = glGetUniformLocation(programID, "MVP"); //to get ID of matrix(MVP)
	glUseProgram(programID);
	Maincamera = Camera(
		vec3(0,19, 1),// Camera Position
		vec3(0, 0, 0),  // Look at Point
		vec3(0, 1, 0)	// Up Vector
		);
	////////////////////////////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////////////////////////////
	//textures 
	t_UP = new Texture("orbital-element_up.tga", 0);
    t_DOWN = new Texture("orbital-element_dn.tga", 1);
	t_FRONT = new Texture("orbital-element_ft.tga", 2);
	t_BACK = new Texture("orbital-element_bk.tga", 3);
	t_RIGHT = new Texture("orbital-element_rt.tga", 4);
	t_LEFT = new Texture("orbital-element_lf.tga",5);
	mazetxt = new Texture("wood.jpg", 6);
	groundtxt = new Texture("Brown.jpg", 7);
	Enemy = new Texture("GamGom.jpg", 8);
	Hero = new Texture("Yellow.png", 9);
	Food = new Texture("Food.jpg", 10);

	////////////////////////////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////////////////////////////
	//player matrix for control
	player = translate(8.0f, -9.5f, 7.0f) * scale(0.7f, 0.7f, 0.7f);//8 f l z w 7 f l x
	enemy1 = translate(0.0f, -6.0f, 0.0f)*scale(0.9f, 0.9f, 0.9f);
	enemy2 = translate(-3.0f, -8.5f, -5.0f)*scale(0.9f, 0.9f, 0.9f);
	
		food1 = translate(-5.0f, -8.5f, -8.0f)*scale(0.2f, 0.2f, 0.2f);
		food2 = translate(5.0f, -8.5f, 5.0f)*scale(0.2f, 0.2f, 0.2f);
		food3 = translate(3.0f, -8.5f, 0.0f)*scale(0.2f, 0.2f, 0.2f);
		food4 = translate(-1.0f, -8.5f, 8.0f)*scale(0.2f, 0.2f, 0.2f);
		food5 = translate(-5.0f, -8.5f, 0.0f)*scale(0.2f, 0.2f, 0.2f);
	
	Maincamera.x = 8.0;
	Maincamera.z = 7.0;
	AmientColorID = glGetUniformLocation(programID, "AmbientColor");
	AmbientColor = vec3(1.0f, 1.0f, 1.0f);

	DiffuseLightID = glGetUniformLocation(programID, "DiffuseLight");
	DiffuseLight = vec3(1.0f, 1.0f, 1.0f);

	LightPoisitionID = glGetUniformLocation(programID, "LightPosition");
	LightPoisition = vec3(0.0f, -20.0f, -20.0f);
}

void Renderer::Draw()
{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glUseProgram(programID);
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(0,3,GL_FLOAT, GL_FALSE,8* sizeof(GLfloat),(void*)0);
	glVertexAttribPointer(1,3,GL_FLOAT,GL_FALSE,sizeof(GLfloat) * 8,(void*)(3 * sizeof(GLfloat)));
	glVertexAttribPointer(2,3, GL_FLOAT, GL_FALSE, 8* sizeof(GLfloat), (void*)(6 * sizeof(GLfloat)));
	ViewMatrix = Maincamera.GetViewMatrix();
	///////////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////skybox////////////////////////////////////////////////
	ModelMatrix1 = translate(0.0f, 0.0f, 0.0f) * scale(20.0f, 20.0f, 20.0f); 
	MVP_M2 = ProjectionMatrix * ViewMatrix * ModelMatrix1;//position l sybx 
	glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP_M2[0][0]); //3shan ya5od l qema w ywadeha ll vertex shader yersemha
	
	
	t_FRONT->Bind();
	glDrawArrays(GL_TRIANGLES, 0, 6);

	t_RIGHT->Bind();
	glDrawArrays(GL_TRIANGLES, 6, 6);

	t_UP->Bind();
	glDrawArrays(GL_TRIANGLES, 12, 6);


	t_LEFT->Bind();
	glDrawArrays(GL_TRIANGLES, 18, 6);
	
	t_DOWN->Bind();
	glDrawArrays(GL_TRIANGLES, 24, 6);
	
	t_BACK->Bind();
	glDrawArrays(GL_TRIANGLES, 30, 6);
	///////////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////
	ModelMatrix1 = translate(0.0f, 0.0f, 0.0f) * scale(10.0f, 10.0f, 10.0f);
	MVP_M2 = ProjectionMatrix * ViewMatrix * ModelMatrix1;
	glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP_M2[0][0]);
	groundtxt->Bind();
	glDrawArrays(GL_TRIANGLES, 24, 6);
	/////////////////////////////////////////////////////////////////////////////
	////////////////////////////////MAZE WALL LEFT////////////////////////////////////////////////
	maze1 = translate(0.0f, -9.5f, 10.0f) * scale(10.0f, 0.5f, 0.5f);
	MVP_M2 = ProjectionMatrix * ViewMatrix * maze1;
	glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP_M2[0][0]);

	mazetxt->Bind();
	glDrawArrays(GL_TRIANGLES, 0, 6);

	mazetxt->Bind();
	glDrawArrays(GL_TRIANGLES, 6, 6);

	mazetxt->Bind();
	glDrawArrays(GL_TRIANGLES, 12, 6);


	mazetxt->Bind();
	glDrawArrays(GL_TRIANGLES, 18, 6);

	mazetxt->Bind();
	glDrawArrays(GL_TRIANGLES, 24, 6);

	mazetxt->Bind();
	glDrawArrays(GL_TRIANGLES, 30, 6);
	/////////////////////////////////////////////////////////////////////////////
	////////////////////////////////MAZE WALL RIGHT////////////////////////////////////////////////
	maze1 = translate(0.0f, -9.5f, -10.0f) * scale(10.0f, 0.5f, 0.5f);
	MVP_M2 = ProjectionMatrix * ViewMatrix * maze1;
	glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP_M2[0][0]);

	mazetxt->Bind();
	glDrawArrays(GL_TRIANGLES, 0, 6);

	mazetxt->Bind();
	glDrawArrays(GL_TRIANGLES, 6, 6);

	mazetxt->Bind();
	glDrawArrays(GL_TRIANGLES, 12, 6);


	mazetxt->Bind();
	glDrawArrays(GL_TRIANGLES, 18, 6);

	mazetxt->Bind();
	glDrawArrays(GL_TRIANGLES, 24, 6);

	mazetxt->Bind();
	glDrawArrays(GL_TRIANGLES, 30, 6);
	/////////////////////////////////////////////////////////////////////////////
	////////////////////////////////MAZE WALL TOP////////////////////////////////////////////////
	maze1 = translate(-10.0f, -9.5f, 0.0f) * scale(0.5f, 0.5f, 10.0f);
	MVP_M2 = ProjectionMatrix * ViewMatrix * maze1;
	glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP_M2[0][0]);

	mazetxt->Bind();
	glDrawArrays(GL_TRIANGLES, 0, 6);

	mazetxt->Bind();
	glDrawArrays(GL_TRIANGLES, 6, 6);

	mazetxt->Bind();
	glDrawArrays(GL_TRIANGLES, 12, 6);


	mazetxt->Bind();
	glDrawArrays(GL_TRIANGLES, 18, 6);

	mazetxt->Bind();
	glDrawArrays(GL_TRIANGLES, 24, 6);

	mazetxt->Bind();
	glDrawArrays(GL_TRIANGLES, 30, 6);
	/////////////////////////////////////////////////////////////////////////////
	////////////////////////////////MAZE WALL down////////////////////////////////////////////////
	maze1 = translate(10.0f, -9.5f, 0.0f) * scale(0.5f, 0.5f, 10.0f);
	////es(texture s1, mat4 s2)
	MVP_M2 = ProjectionMatrix * ViewMatrix * maze1;
	glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP_M2[0][0]);

	mazetxt->Bind();
	glDrawArrays(GL_TRIANGLES, 0, 6);

	mazetxt->Bind();
	glDrawArrays(GL_TRIANGLES, 6, 6);

	mazetxt->Bind();
	glDrawArrays(GL_TRIANGLES, 12, 6);


	mazetxt->Bind();
	glDrawArrays(GL_TRIANGLES, 18, 6);

	mazetxt->Bind();
	glDrawArrays(GL_TRIANGLES, 24, 6);

	mazetxt->Bind();
	glDrawArrays(GL_TRIANGLES, 30, 6);
	/////////////////////////////////////////////////////////////////////////////
	////////////////////////////////MAZE WALL middel LEFT////////////////////////////////////////////////
	maze1 = translate(1.5f, -9.5f, 3.3f) * scale(8.0f, 0.5f, 0.5f);
	MVP_M2 = ProjectionMatrix * ViewMatrix * maze1;
	glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP_M2[0][0]);

	mazetxt->Bind();
	glDrawArrays(GL_TRIANGLES, 0, 6);

	mazetxt->Bind();
	glDrawArrays(GL_TRIANGLES, 6, 6);

	mazetxt->Bind();
	glDrawArrays(GL_TRIANGLES, 12, 6);


	mazetxt->Bind();
	glDrawArrays(GL_TRIANGLES, 18, 6);

	mazetxt->Bind();
	glDrawArrays(GL_TRIANGLES, 24, 6);

	mazetxt->Bind();
	glDrawArrays(GL_TRIANGLES, 30, 6);
	/////////////////////////////////////////////////////////////////////////////
	////////////////////////////////MAZE WALL middle RIGHT///////////////////////
	maze1 = translate(-1.5f, -9.5f, -3.3f) * scale(8.0f, 0.5f, 0.5f);
	MVP_M2 = ProjectionMatrix * ViewMatrix * maze1;
	glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP_M2[0][0]);

	mazetxt->Bind();
	glDrawArrays(GL_TRIANGLES, 0, 6);

	mazetxt->Bind();
	glDrawArrays(GL_TRIANGLES, 6, 6);

	mazetxt->Bind();
	glDrawArrays(GL_TRIANGLES, 12, 6);


	mazetxt->Bind();
	glDrawArrays(GL_TRIANGLES, 18, 6);

	mazetxt->Bind();
	glDrawArrays(GL_TRIANGLES, 24, 6);

	mazetxt->Bind();
	glDrawArrays(GL_TRIANGLES, 30, 6);
	/////////////////////////////////////////////////////////////////////////////
	////////////////////////////////player///////////////////////////////////////
	MVP_M2 = ProjectionMatrix * ViewMatrix * player;
	glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP_M2[0][0]);

	


	Hero->Bind();
	glDrawArrays(GL_TRIANGLES, 0, 6);

	Hero->Bind();
	glDrawArrays(GL_TRIANGLES, 6, 6);

	Hero->Bind();
	glDrawArrays(GL_TRIANGLES, 12, 6);


	Hero->Bind();
	glDrawArrays(GL_TRIANGLES, 18, 6);

	Hero->Bind();
	glDrawArrays(GL_TRIANGLES, 24, 6);

	Hero->Bind();
	glDrawArrays(GL_TRIANGLES, 30, 6);

	MVP_M3 = ProjectionMatrix * ViewMatrix * enemy1 *enemyRot;

	glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP_M3[0][0]);

	Enemy->Bind();
	glDrawArrays(GL_TRIANGLES, 0, 6);
	Enemy->Bind();
	glDrawArrays(GL_TRIANGLES, 6, 6);
	Enemy->Bind();
	glDrawArrays(GL_TRIANGLES, 12, 6);
	Enemy->Bind();
	glDrawArrays(GL_TRIANGLES, 18, 6);
	Enemy->Bind();
	glDrawArrays(GL_TRIANGLES, 24, 6);
	Enemy->Bind();
	glDrawArrays(GL_TRIANGLES, 30, 6);
	//////en 2
	MVP_M3 = ProjectionMatrix * ViewMatrix * enemy2 *enemyRot;

	glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP_M3[0][0]);
	Enemy->Bind();
	glDrawArrays(GL_TRIANGLES, 0, 6);
	Enemy->Bind();
	glDrawArrays(GL_TRIANGLES, 6, 6);
	Enemy->Bind();
	glDrawArrays(GL_TRIANGLES, 12, 6);
	Enemy->Bind();
	glDrawArrays(GL_TRIANGLES, 18, 6);
	Enemy->Bind();
	glDrawArrays(GL_TRIANGLES, 24, 6);
	Enemy->Bind();
	glDrawArrays(GL_TRIANGLES, 30, 6);
	
	MVP_M4 = ProjectionMatrix * ViewMatrix * food1 ;

	glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP_M4[0][0]);
	Food->Bind();
	glDrawArrays(GL_TRIANGLES, 0, 6);
	Food->Bind();
	glDrawArrays(GL_TRIANGLES, 6, 6);
	Food->Bind();
	glDrawArrays(GL_TRIANGLES, 12, 6);
	Food->Bind();
	glDrawArrays(GL_TRIANGLES, 18, 6);
	Food->Bind();
	glDrawArrays(GL_TRIANGLES, 24, 6);
	Food->Bind();
	glDrawArrays(GL_TRIANGLES, 30, 6);
	MVP_M4 = ProjectionMatrix * ViewMatrix * food2;

	glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP_M4[0][0]);
	Food->Bind();
	glDrawArrays(GL_TRIANGLES, 0, 6);
	Food->Bind();
	glDrawArrays(GL_TRIANGLES, 6, 6);
	Food->Bind();
	glDrawArrays(GL_TRIANGLES, 12, 6);
	Food->Bind();
	glDrawArrays(GL_TRIANGLES, 18, 6);
	Food->Bind();
	glDrawArrays(GL_TRIANGLES, 24, 6);
	Food->Bind();
	glDrawArrays(GL_TRIANGLES, 30, 6);
	MVP_M4 = ProjectionMatrix * ViewMatrix * food3;

	glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP_M4[0][0]);
	Food->Bind();
	glDrawArrays(GL_TRIANGLES, 0, 6);
	Food->Bind();
	glDrawArrays(GL_TRIANGLES, 6, 6);
	Food->Bind();
	glDrawArrays(GL_TRIANGLES, 12, 6);
	Food->Bind();
	glDrawArrays(GL_TRIANGLES, 18, 6);
	Food->Bind();
	glDrawArrays(GL_TRIANGLES, 24, 6);
	Food->Bind();
	glDrawArrays(GL_TRIANGLES, 30, 6);
	MVP_M4 = ProjectionMatrix * ViewMatrix * food4;

	glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP_M4[0][0]);
	Food->Bind();
	glDrawArrays(GL_TRIANGLES, 0, 6);
	Food->Bind();
	glDrawArrays(GL_TRIANGLES, 6, 6);
	Food->Bind();
	glDrawArrays(GL_TRIANGLES, 12, 6);
	Food->Bind();
	glDrawArrays(GL_TRIANGLES, 18, 6);
	Food->Bind();
	glDrawArrays(GL_TRIANGLES, 24, 6);
	Food->Bind();
	glDrawArrays(GL_TRIANGLES, 30, 6);
	MVP_M4 = ProjectionMatrix * ViewMatrix * food5;

	glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP_M4[0][0]);
	Food->Bind();
	glDrawArrays(GL_TRIANGLES, 0, 6);
	Food->Bind();
	glDrawArrays(GL_TRIANGLES, 6, 6);
	Food->Bind();
	glDrawArrays(GL_TRIANGLES, 12, 6);
	Food->Bind();
	glDrawArrays(GL_TRIANGLES, 18, 6);
	Food->Bind();
	glDrawArrays(GL_TRIANGLES, 24, 6);
	Food->Bind();
	glDrawArrays(GL_TRIANGLES, 30, 6);
	/////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////
	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(2);

	glUniform3fv(AmientColorID, 1, &AmbientColor[0]);
	glUniform3fv(LightPoisitionID, 1, &LightPoisition[0]);
	glUniform3fv(DiffuseLightID, 1, &DiffuseLight[0]);
}

void Renderer::Cleanup()
{
    glDeleteBuffers(1, &vertexBufferID);
    glDeleteVertexArrays(1, &vertexArrayID); //the one we didn't used (will be discussed later)
    glDeleteProgram(programID);
}


void Renderer::HandleKeyboardInput(int key)
{
	float stepsize = 1.0;
	printf("Renderer::KEY = %d \n", key);
	cout << "position 3al x   " << Maincamera.x << endl << "position 3al z  " << Maincamera.z << endl;

	
		if (key == GLFW_KEY_UP)
		{
			float aya = Maincamera.z - stepsize;

			if (((aya <= 3) && (aya >= 3) && (Maincamera.x <= 9 && Maincamera.x >= -7)) || (aya < -10))
			{
				cout << "Crash!" << endl;
			}
			else if (((aya == -3) && (Maincamera.x <= 6 && Maincamera.x >= -9)) || (aya < -10))
			{
				cout << "Crash!" << endl;
			}
			else if ((aya == 0) && (Maincamera.x <= 1 && Maincamera.x >= -2))
			{
				lifes--;
				cout << lifes << endl;
				player = translate(0.0f, 0.0f, -stepsize)*player;
				Maincamera.z -= stepsize;
				if (lifes == 0)
				{
					exit;
				}
			}
			
			else
			{
				player = translate(0.0f, 0.0f, -stepsize)*player;
				Maincamera.z -= stepsize;
			}
			Maincamera.setpz(Maincamera.z -= 0.04*stepsize);
		}

		else if (key == GLFW_KEY_DOWN)
		{
			float aya = Maincamera.z + stepsize;
			if (((aya == 3) && (Maincamera.x <= 9 && Maincamera.x >= -7)) || (aya > 10))
			{
				cout << "Crash!" << endl;
			}
			else if ((aya == -3) && (Maincamera.x >= -9 && Maincamera.x <= 6) || (aya > 10))
			{
				cout << "Crash!" << endl;

			}
			else if ((aya == 0) && (Maincamera.x <= 1 && Maincamera.x >= -3))
			{
				
				lifes--;
				cout << lifes << endl;
				player = translate(0.0f, 0.0f, stepsize)*player;
				Maincamera.z += stepsize;
				if (lifes == 0)
				{
					exit;
				}
			}
			else if ((aya == -6) && (Maincamera.x == -3))
			{
				lifes--;
				cout << lifes << endl;
				player = translate(0.0f, 0.0f, stepsize)*player;
				Maincamera.z += stepsize;
				if (lifes == 0)
				{
					exit;
				}
			}
			else
			{
				player = translate(0.0f, 0.0f, stepsize)*player;
				Maincamera.z += stepsize;
			}
			Maincamera.setpz(Maincamera.z += 0.04* stepsize);
		}


		else if (key == GLFW_KEY_RIGHT)
		{
			float aya = Maincamera.x + stepsize;

			if (Maincamera.x > 8)
			{
				cout << "Crash!" << endl;
			}
			else if ((aya == -1) && (Maincamera.z >= 0 && Maincamera.z <= 2))
			{
				lifes--;
				cout << lifes << endl;
				player = translate(stepsize, 0.0f, 0.0f)*player;
				Maincamera.x += stepsize;
				if (lifes == 0)
				{
					exit;
				}
			}
			else if ((aya == 0) && (Maincamera.z == -5))
			{
				lifes--;
				cout << lifes << endl;
				player = translate(stepsize, 0.0f, 0.0f)*player;
				Maincamera.x += stepsize;
				if (lifes == 0)
				{
					exit;
				}
			}
			else
			{
				player = translate(stepsize, 0.0f, 0.0f)*player;
				Maincamera.x += 0.04*stepsize;
			}
			Maincamera.setpx(Maincamera.x += stepsize);
		}
		else if (key == GLFW_KEY_LEFT)
		{
			float aya = Maincamera.x - stepsize;
			if (Maincamera.x < -8)
			{
				cout << "Crash!" << endl;
			}
			else if ((aya == 1) && (Maincamera.z <= 2 && Maincamera.z >= 0))
			{
				lifes--;
				cout << lifes << endl;
				player = translate(-stepsize, 0.0f, 0.0f)*player;
				Maincamera.x -= stepsize;
				if (lifes == 0)
				{
					exit;
				}
			}
			else if ((aya == -6) && (Maincamera.z == -5))
			{
				lifes--;
				cout << lifes << endl;
				player = translate(-stepsize, 0.0f, 0.0f)*player;
				Maincamera.x -= stepsize;
				if (lifes == 0)
				{
					exit;
				}
			}
			else
			{

				player = translate(-stepsize, 0.0f, 0.0f)*player;
				Maincamera.x -= stepsize;
			}
			Maincamera.setpx(Maincamera.x -= 0.04*stepsize);
		}
		else if (key == GLFW_KEY_D)
			Maincamera.strafe(0.1);

		else if (key == GLFW_KEY_A)
			Maincamera.strafe(-0.1);

		else if (key == GLFW_KEY_J)
			Maincamera.yaw(1.0f);


		else if (key == GLFW_KEY_L)
			Maincamera.yaw(-1.0f);

		else if (key == GLFW_KEY_W)
			Maincamera.walk(0.1f);

		else if (key == GLFW_KEY_S)
			Maincamera.walk(-0.1f);

		else if (key == GLFW_KEY_E)
			Maincamera.fly(0.1f);

		else if (key == GLFW_KEY_Q)
			Maincamera.fly(-0.1f);

		else if (key == GLFW_KEY_I)
			Maincamera.pitch(1.0f);

		else if (key == GLFW_KEY_K)
			Maincamera.pitch(-1.0f);

		else if (key == GLFW_KEY_U)
			Maincamera.roll(1.0f);

		else if (key == GLFW_KEY_O)
			Maincamera.roll(-1.0f);


	}

void Renderer::Update()
{
	double currentTime = glfwGetTime();
	//*1000 to convert from nanoseconds to seconds.
	double deltaTime = (currentTime - time) * 1000;
	time = currentTime;
	//[Your turn] do whatever you want with deltaTime

	double triangleRotationSpeed = 0.5;
	double triangleRoationAngle = triangleRotationSpeed;
	enemyRot= enemyRot*rotate((float)triangleRoationAngle, vec3(0.0, 0.0, 1.0));
}
void Renderer::HandleMouseClick(double xPos, double yPos)
{
	printf("Renderer::MOUSE = %f , %f \n", xPos, yPos);
}
int Renderer::Die()
{
	if (lifes==0)
		return 0;
}