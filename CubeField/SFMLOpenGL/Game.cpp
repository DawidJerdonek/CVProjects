#include <Game.h>
#include <Cube.h>
#include <Easing.h>

// Helper to convert Number to String for HUD
template <typename T>
string toString(T number)
{
	ostringstream oss;
	oss << number;
	return oss.str();
}

GLuint	vsid,		// Vertex Shader ID
		fsid,		// Fragment Shader ID
		progID,		// Program ID
		vao = 0,	// Vertex Array ID
		vbo,		// Vertex Buffer ID
		vib,		// Vertex Index Buffer
		to[1];		// Texture ID
GLint	positionID,	// Position ID
		colorID,	// Color ID
		textureID,	// Texture ID
		uvID,		// UV ID
		mvpID,		// Model View Projection ID
		x_offsetID, // X offset ID
		y_offsetID,	// Y offset ID
		z_offsetID;	// Z offset ID

GLenum	error;		// OpenGL Error Code


//Please see .//Assets//Textures// for more textures
const string filename = ".//Assets//Textures//grid.tga";

int width;						// Width of texture
int height;						// Height of texture
int comp_count;					// Component of texture

unsigned char* img_data;		// image data

mat4 mvp, projection, 
		view, model;			// Model View Projection

Font font;						// Game font

float x_offset, y_offset, z_offset; // offset on screen (Vertex Shader)

Game::Game() : 
	window(VideoMode(800, 600), 
	"Introduction to OpenGL Texturing")
{
}

Game::Game(sf::ContextSettings settings) :
	window(VideoMode(800, 600),
		"Introduction to OpenGL Texturing",
		sf::Style::Default,
		settings)
{

	game_object[0] = new GameObject();
	game_object[0]->setPosition(vec3(0.0f, 0.5f, -0.5f));

	game_object[1] = new GameObject();
	game_object[1]->setPosition(vec3(-5.0f, 0.5f, -5.5f));

	game_object[2] = new GameObject();
	game_object[2]->setPosition(vec3(-9.0f, 0.5f, -8.0f));

	game_object[3] = new GameObject();
	game_object[3]->setPosition(vec3(9.0f, 0.5f, -8.0f));

	game_object[4] = new GameObject();
	game_object[4]->setPosition(vec3(-7.0f, 0.5f, -11.0f));

	game_object[5] = new GameObject();
	game_object[5]->setPosition(vec3(7.0f, 0.5f, -11.0f));

	game_object[6] = new GameObject();
	game_object[6]->setPosition(vec3(-2.5f, 0.5f, -15.0f));

	game_object[7] = new GameObject();
	game_object[7]->setPosition(vec3(2.5f, 0.5f, -15.0f));

	game_object[8] = new GameObject();
	game_object[8]->setPosition(vec3(7.0f, 0.5f, -21.5f));

	game_object[9] = new GameObject();
	game_object[9]->setPosition(vec3(-7.0f, 0.5f, -21.5f));

	game_object[10] = new GameObject();
	game_object[10]->setPosition(vec3(5.0f, 0.5f, -5.5f));

	game_object[11] = new GameObject();
	game_object[11]->setPosition(vec3(0.0f, 0.5f, -30.5f));

	game_object[12] = new GameObject();
	game_object[12]->setPosition(vec3(1.0f, 0.5f, -31.5f));

	game_object[13] = new GameObject();
	game_object[13]->setPosition(vec3(-1.0f, 0.5f, -31.5f));

	game_object[14] = new GameObject();
	game_object[14]->setPosition(vec3(0.0f, 0.5f, -32.5f));

	game_object[15] = new GameObject();
	game_object[15]->setPosition(vec3(9.0f, 0.5f, -38.5f));

	game_object[16] = new GameObject();
	game_object[16]->setPosition(vec3(-9.0f, 0.5f, -38.5f));

	game_object[17] = new GameObject();
	game_object[17]->setPosition(vec3(7.0f, 0.5f, -40.5f));

	game_object[18] = new GameObject();
	game_object[18]->setPosition(vec3(-7.0f, 0.5f, -40.5f));

	game_object[19] = new GameObject();
	game_object[19]->setPosition(vec3(-5.0f, 0.5f, -42.5f));

	game_object[20] = new GameObject();
	game_object[20]->setPosition(vec3(5.0f, 0.5f, -42.5f));

	game_object[21] = new GameObject();
	game_object[21]->setPosition(vec3(-3.0f, 0.5f, -44.5f));

	game_object[22] = new GameObject();
	game_object[22]->setPosition(vec3(3.0f, 0.5f, -44.5f));

	game_object[23] = new GameObject();
	game_object[23]->setPosition(vec3(-3.0f, 0.5f, -46.5f));

	game_object[24] = new GameObject();
	game_object[24]->setPosition(vec3(3.0f, 0.5f, -46.5f));

	game_object[25] = new GameObject();
	game_object[25]->setPosition(vec3(-3.0f, 0.5f, -48.5f));

	game_object[26] = new GameObject();
	game_object[26]->setPosition(vec3(3.0f, 0.5f, -48.5f));

	game_object[27] = new GameObject();
	game_object[27]->setPosition(vec3(5.0f, 0.5f, -50.5f));

	game_object[28] = new GameObject();
	game_object[28]->setPosition(vec3(-5.0f, 0.5f, -50.5f));

	game_object[29] = new GameObject();
	game_object[29]->setPosition(vec3(7.0f, 0.5f, -52.5f));

	game_object[30] = new GameObject();
	game_object[30]->setPosition(vec3(-7.0f, 0.5f, -52.5f));

	game_object[31] = new GameObject();
	game_object[31]->setPosition(vec3(9.0f, 0.5f, -54.5f));

	game_object[32] = new GameObject();
	game_object[32]->setPosition(vec3(-9.0f, 0.5f, -54.5f));

	game_object[33] = new GameObject();
	game_object[33]->setPosition(vec3(9.0f, 0.5f, -56.5f));

	game_object[34] = new GameObject();
	game_object[34]->setPosition(vec3(-9.0f, 0.5f, -56.5f));

	game_object[35] = new GameObject();
	game_object[35]->setPosition(vec3(9.0f, 0.5f, -58.5f));

	game_object[36] = new GameObject();
	game_object[36]->setPosition(vec3(-9.0f, 0.5f, -58.5f));

	game_object[37] = new GameObject();
	game_object[37]->setPosition(vec3(9.0f, 0.5f, -60.5f));

	game_object[38] = new GameObject();
	game_object[38]->setPosition(vec3(-9.0f, 0.5f, -60.5f));

	game_object[39] = new GameObject();
	game_object[39]->setPosition(vec3(9.0f, 0.5f, -62.5f));

	game_object[40] = new GameObject();
	game_object[40]->setPosition(vec3(-9.0f, 0.5f, -62.5f));

	game_object[41] = new GameObject();
	game_object[41]->setPosition(vec3(9.0f, 0.5f, -64.5f));

	game_object[42] = new GameObject();
	game_object[42]->setPosition(vec3(-9.0f, 0.5f, -64.5f));

	game_object[43] = new GameObject();
	game_object[43]->setPosition(vec3(9.0f, 0.5f, -66.5f));

	game_object[44] = new GameObject();
	game_object[44]->setPosition(vec3(-9.0f, 0.5f, -66.5f));

	game_object[45] = new GameObject();
	game_object[45]->setPosition(vec3(9.0f, 0.5f, -68.5f));

	game_object[46] = new GameObject();
	game_object[46]->setPosition(vec3(-9.0f, 0.5f, -68.5f));

	game_object[47] = new GameObject();
	game_object[47]->setPosition(vec3(9.0f, 0.5f, -70.5f));

	game_object[48] = new GameObject();
	game_object[48]->setPosition(vec3(-9.0f, 0.5f, -70.5f));

	game_object[49] = new GameObject();
	game_object[49]->setPosition(vec3(7.0f, 0.5f, -72.5f));

	game_object[50] = new GameObject();
	game_object[50]->setPosition(vec3(-7.0f, 0.5f, -72.5f));

	game_object[51] = new GameObject();
	game_object[51]->setPosition(vec3(5.0f, 0.5f, -74.5f));

	game_object[52] = new GameObject();
	game_object[52]->setPosition(vec3(-5.0f, 0.5f, -74.5f));

	game_object[53] = new GameObject();
	game_object[53]->setPosition(vec3(3.0f, 0.5f, -76.5f));

	game_object[54] = new GameObject();
	game_object[54]->setPosition(vec3(-3.0f, 0.5f, -76.5f));

	game_object[55] = new GameObject();
	game_object[55]->setPosition(vec3(1.0f, 0.5f, -90.5f));

	game_object[56] = new GameObject();
	game_object[56]->setPosition(vec3(-1.0f, 0.5f, -90.5f));

	game_object[57] = new GameObject();
	game_object[57]->setPosition(vec3(3.0f, 0.5f, -94.5f));

	game_object[58] = new GameObject();
	game_object[58]->setPosition(vec3(-3.0f, 0.5f, -94.5f));

	game_object[59] = new GameObject();
	game_object[59]->setPosition(vec3(5.0f, 0.5f, -98.5f));

	game_object[60] = new GameObject();
	game_object[60]->setPosition(vec3(-5.0f, 0.5f, -98.5f));

	game_object[61] = new GameObject();
	game_object[61]->setPosition(vec3(8.0f, 0.5f, -115.5f));

	game_object[62] = new GameObject();
	game_object[62]->setPosition(vec3(-8.0f, 0.5f, -115.5f));

	game_object[63] = new GameObject();
	game_object[63]->setPosition(vec3(3.0f, 0.5f, -122.5f));

	game_object[64] = new GameObject();
	game_object[64]->setPosition(vec3(-3.0f, 0.5f, -122.5f));

	game_object[65] = new GameObject();
	game_object[65]->setPosition(vec3(5.0f, 0.5f, -126.5f));

	game_object[66] = new GameObject();
	game_object[66]->setPosition(vec3(-5.0f, 0.5f, -126.5f));

	game_object[67] = new GameObject();
	game_object[67]->setPosition(vec3(1.0f, 0.5f, -126.5f));

	game_object[68] = new GameObject();
	game_object[68]->setPosition(vec3(-1.0f, 0.5f, -126.5f));

	game_object[69] = new GameObject();
	game_object[69]->setPosition(vec3(3.0f, 0.5f, -131.5f));

	game_object[70] = new GameObject();
	game_object[70]->setPosition(vec3(-3.0f, 0.5f, -131.5f));

	game_object[71] = new GameObject();
	game_object[71]->setPosition(vec3(8.0f, 0.5f, -151.5f));

	game_object[72] = new GameObject();
	game_object[72]->setPosition(vec3(-8.0f, 0.5f, -151.5f));

	game_object[73] = new GameObject();
	game_object[73]->setPosition(vec3(6.0f, 0.5f, -151.5f));

	game_object[74] = new GameObject();
	game_object[74]->setPosition(vec3(-6.0f, 0.5f, -151.5f));

	game_object[75] = new GameObject();
	game_object[75]->setPosition(vec3(3.0f, 0.5f, -161.5f));

	game_object[76] = new GameObject();
	game_object[76]->setPosition(vec3(-3.0f, 0.5f, -161.5f));

	game_object[77] = new GameObject();
	game_object[77]->setPosition(vec3(3.0f, 0.5f, -171.5f));

	game_object[78] = new GameObject();
	game_object[78]->setPosition(vec3(-3.0f, 0.5f, -171.5f));

	game_object[79] = new GameObject();
	game_object[79]->setPosition(vec3(1.0f, 0.5f, -191.5f));

	game_object[80] = new GameObject();
	game_object[80]->setPosition(vec3(-1.0f, 0.5f, -191.5f));

	game_object[81] = new GameObject();
	game_object[81]->setPosition(vec3(0.0f, 0.5f, -61.5f));

	game_object[82] = new GameObject();
	game_object[82]->setPosition(vec3(7.0f, 0.5f, -148.5f));

	game_object[83] = new GameObject();
	game_object[83]->setPosition(vec3(-7.0f, 0.5f, -148.5f));

	game_object[84] = new GameObject();
	game_object[84]->setPosition(vec3(3.0f, 0.5f, -191.5f));

	game_object[85] = new GameObject();
	game_object[85]->setPosition(vec3(-3.0f, 0.5f, -191.5f));

	//Side walls
	for (int i = 86; i < 188; i++)
	{
		game_object[i] = new GameObject();
		game_object[i]->setPosition(vec3(-11.1f, 0.5f, pos));
		pos -= 2;
	}
	pos = -0.5f;
	for (int i = 188; i < sizeOfArray; i++)
	{
		game_object[i] = new GameObject();
		game_object[i]->setPosition(vec3(11.1f, 0.5f, pos));
		pos -= 2;
	}


}

Game::~Game()
{
}


void Game::run()
{

	initialize();

	Event event;

	float rotation = 0.01f;
	float start_value = 0.0f;
	float end_value = 1.0f;

	while (isRunning){

#if (DEBUG >= 2)
		DEBUG_MSG("Game running...");
#endif

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				isRunning = false;
			}

			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			{
				// Set Model Rotation
				if (!animate)
				{
					animate = true;
					if (rotation < 0)
						rotation *= 1; // Set Positive
					animation = glm::vec3(0, 1, 0); //Rotate Y
				}
			}

			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			{
				// Set Model Rotation
				if (!animate)
				{
					animate = true;
					if (rotation >= 0)
						rotation *= -1; // Set Negative
					animation = glm::vec3(0, -1, 0); //Rotate Y
				}

				// https://www.sfml-dev.org/documentation/2.0/classsf_1_1Clock.php
				// https://github.com/acron0/Easings
				// http://robotacid.com/documents/code/Easing.cs
				// http://st33d.tumblr.com/post/94243475686/easing-equations-for-unity-c
				// http://easings.net/
				// http://upshots.org/actionscript/jsas-understanding-easing
				// https://www.kirupa.com/html5/animating_with_easing_functions_in_javascript.htm
				// https://medium.com/motion-in-interaction/animation-principles-in-ui-design-understanding-easing-bea05243fe3#.svh4gczav
				// http://thednp.github.io/kute.js/easing.html
				// http://gizma.com/easing/#quad1
				// https://github.com/warrenm/AHEasing

				// VR
				// https://www.sfml-dev.org/documentation/2.4.2/classsf_1_1Sensor.php
				// http://en.sfml-dev.org/forums/index.php?topic=9412.msg65594
				// https://github.com/SFML/SFML/wiki/Tutorial:-Building-SFML-for-Android-on-Windows
				// https://github.com/SFML/SFML/wiki/Tutorial:-Building-SFML-for-Android
				// https://www.youtube.com/watch?v=n_JSi6ihDFs
				// http://en.sfml-dev.org/forums/index.php?topic=8010.0
				// 

				/*
				// Set Model Rotation
				// t = time, b = startvalue, c = change in value, d = duration:

				time = clock.getElapsedTime();
				std::cout << time.asSeconds() << std::endl;
				float original = 0.001f;
				float destination = 0.05f;

				float factor, temp;

				for (int t = 0; t < 5.0f; t++)
				{
				factor = gpp::Easing::easeIn(t, original, 0.00001f, 5.0f);
				cout << "Factor : " << factor << endl;
				}


				factor = gpp::Easing::easeIn(time.asMilliseconds(), original, 0.00001f, 5.0f);
				cout << "Factor : " << factor << endl;
				temp = original + ((destination - original) * factor);
				cout << "Temp : " << factor << endl;
				model = rotate(model, temp, glm::vec3(0, 1, 0)); // Rotate
				*/
			}

			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			{
				// Set Model Rotation
				model = rotate(model, -0.01f, glm::vec3(1, 0, 0)); // Rotate
			}

			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			{
				// Set Model Rotation
				model = rotate(model, 0.01f, glm::vec3(1, 0, 0)); // Rotate
			}

			if (animate)
			{
				rotation += (1.0f * rotation) + 0.05f;
				model = rotate(model, 0.01f, animation); // Rotate
				rotation = 0.0f;
				animate = false;
			}
		}
		update();
		render();
	}

#if (DEBUG >= 2)
	DEBUG_MSG("Calling Cleanup...");
#endif
	unload();

}

void Game::initialize()
{
	isRunning = true;
	GLint isCompiled = 0;
	GLint isLinked = 0;

	if (!(!glewInit())) { DEBUG_MSG("glewInit() failed"); }

	// Copy UV's to all faces
	for (int i = 1; i < 6; i++)
		memcpy(&uvs[i * 4 * 2], &uvs[0], 2 * 4 * sizeof(GLfloat));

	DEBUG_MSG(glGetString(GL_VENDOR));
	DEBUG_MSG(glGetString(GL_RENDERER));
	DEBUG_MSG(glGetString(GL_VERSION));

	// Vertex Array Buffer
	glGenBuffers(1, &vbo);		// Generate Vertex Buffer
	glBindBuffer(GL_ARRAY_BUFFER, vbo);

	// Vertices (3) x,y,z , Colors (4) RGBA, UV/ST (2)

	int countVERTICES = game_object[0]->getVertexCount();
	int countCOLORS = game_object[0]->getColorCount();
	int countUVS = game_object[0]->getUVCount();

	glBufferData(GL_ARRAY_BUFFER, ((3 * VERTICES) + (4 * COLORS) + (2 * UVS)) * sizeof(GLfloat), NULL, GL_STATIC_DRAW);

	glGenBuffers(1, &vib); //Generate Vertex Index Buffer
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vib);


	int countINDICES = game_object[0]->getIndexCount();
	// Indices to be drawn
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, 3 * INDICES * sizeof(GLuint), indices, GL_STATIC_DRAW);

	// NOTE: uniforms values must be used within Shader so that they 
	// can be retreived
	const char* vs_src =
		"#version 400\n\r"
		""
		"in vec3 sv_position;"
		"in vec4 sv_color;"
		"in vec2 sv_uv;"
		""
		"out vec4 color;"
		"out vec2 uv;"
		""
		"uniform mat4 sv_mvp;"
		"uniform float sv_x_offset;"
		"uniform float sv_y_offset;"
		"uniform float sv_z_offset;"
		""
		"void main() {"
		"	color = sv_color;"
		"	uv = sv_uv;"
		//"	gl_Position = vec4(sv_position, 1);"
		"	gl_Position = sv_mvp * vec4(sv_position.x + sv_x_offset, sv_position.y + sv_y_offset, sv_position.z + sv_z_offset, 1 );"
		"}"; //Vertex Shader Src

	DEBUG_MSG("Setting Up Vertex Shader");

	vsid = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vsid, 1, (const GLchar**)&vs_src, NULL);
	glCompileShader(vsid);

	// Check is Shader Compiled
	glGetShaderiv(vsid, GL_COMPILE_STATUS, &isCompiled);

	if (isCompiled == GL_TRUE) {
		DEBUG_MSG("Vertex Shader Compiled");
		isCompiled = GL_FALSE;
	}
	else
	{
		DEBUG_MSG("ERROR: Vertex Shader Compilation Error");
	}

	const char* fs_src =
		"#version 400\n\r"
		""
		"uniform sampler2D f_texture;"
		""
		"in vec4 color;"
		"in vec2 uv;"
		""
		"out vec4 fColor;"
		""
		"void main() {"
		"	fColor = color - texture2D(f_texture, uv);"
		""
		"}"; //Fragment Shader Src

	DEBUG_MSG("Setting Up Fragment Shader");

	fsid = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fsid, 1, (const GLchar**)&fs_src, NULL);
	glCompileShader(fsid);

	// Check is Shader Compiled
	glGetShaderiv(fsid, GL_COMPILE_STATUS, &isCompiled);

	if (isCompiled == GL_TRUE) {
		DEBUG_MSG("Fragment Shader Compiled");
		isCompiled = GL_FALSE;
	}
	else
	{
		DEBUG_MSG("ERROR: Fragment Shader Compilation Error");
	}

	DEBUG_MSG("Setting Up and Linking Shader");
	progID = glCreateProgram();
	glAttachShader(progID, vsid);
	glAttachShader(progID, fsid);
	glLinkProgram(progID);

	// Check is Shader Linked
	glGetProgramiv(progID, GL_LINK_STATUS, &isLinked);

	if (isLinked == 1) {
		DEBUG_MSG("Shader Linked");
	}
	else
	{
		DEBUG_MSG("ERROR: Shader Link Error");
	}

	// Set image data
	// https://github.com/nothings/stb/blob/master/stb_image.h
	img_data = stbi_load(filename.c_str(), &width, &height, &comp_count, 4);

	if (img_data == NULL)
	{
		DEBUG_MSG("ERROR: Texture not loaded");
	}

	glEnable(GL_TEXTURE_2D);
	glGenTextures(1, &to[0]);
	glBindTexture(GL_TEXTURE_2D, to[0]);

	// Wrap around
	// https://www.khronos.org/opengles/sdk/docs/man/xhtml/glTexParameter.xml
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);

	// Filtering
	// https://www.khronos.org/opengles/sdk/docs/man/xhtml/glTexParameter.xml
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); 
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	// Bind to OpenGL
	// https://www.khronos.org/opengles/sdk/docs/man/xhtml/glTexImage2D.xml
	glTexImage2D(
		GL_TEXTURE_2D,			// 2D Texture Image
		0,						// Mipmapping Level 
		GL_RGBA,				// GL_RED, GL_GREEN, GL_BLUE, GL_ALPHA, GL_RGB, GL_BGR, GL_RGBA 
		width,					// Width
		height,					// Height
		0,						// Border
		GL_RGBA,				// Bitmap
		GL_UNSIGNED_BYTE,		// Specifies Data type of image data
		img_data				// Image Data
		);

	// Projection Matrix 
	projection = perspective(
		45.0f,					// Field of View 45 degrees
		4.0f / 3.0f,			// Aspect ratio
		5.0f,					// Display Range Min : 0.1f unit
		100.0f					// Display Range Max : 100.0f unit
		);

	// Camera Matrix
	view = lookAt(
		vec3(0.0f, 4.0f, 10.0f),	// Camera (x,y,z), in World Space
		vec3(0.0f, 0.0f, 0.0f),		// Camera looking at origin
		vec3(0.0f, 1.0f, 0.0f)		// 0.0f, 1.0f, 0.0f Look Down and 0.0f, -1.0f, 0.0f Look Up
		);

	// Model matrix
	model = mat4(
		1.0f					// Identity Matrix
		);

	// Enable Depth Test
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	glEnable(GL_CULL_FACE);

	// Load Font
	font.loadFromFile(".//Assets//Fonts//BBrick.ttf");
}

void Game::update()
{
#if (DEBUG >= 2)
	DEBUG_MSG("Updating...");
#endif
	// Update Model View Projection
	// For mutiple objects (cubes) create multiple models
	// To alter Camera modify view & projection
	mvp = projection * view * model;

	DEBUG_MSG(model[0].x);
	DEBUG_MSG(model[0].y);
	DEBUG_MSG(model[0].z);
	if (endGame == false && goalSuccess == false )
	{
		for (int i = 1; i < sizeOfArray; i++)
		{
			float movement = game_object[i]->getPosition().z + speed;
			float currentX = game_object[i]->getPosition().x;
			game_object[i]->setPosition((vec3(currentX, 0.5f, movement)));

			if (game_object[i]->getPosition().z > 4.5f)
			{
				game_object[i]->setPosition(vec3(game_object[i]->getPosition().x, 0.5f, -199.5f));
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			float currentZ = game_object[0]->getPosition().z;
			float moveX = game_object[0]->getPosition().x - playerSpeed;
			game_object[0]->setPosition((vec3(moveX, 0.5f, currentZ)));

			if (game_object[0]->getPosition().x < -9.0f)
			{
				game_object[0]->setPosition((vec3(-9.0f, 0.5f, game_object[0]->getPosition().z)));
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			float currentZ = game_object[0]->getPosition().z;
			float moveX = game_object[0]->getPosition().x + playerSpeed;
			game_object[0]->setPosition((vec3(moveX, 0.5f, currentZ)));

			if (game_object[0]->getPosition().x > 9.0f)
			{
				game_object[0]->setPosition((vec3(9.0f, 0.5f, game_object[0]->getPosition().z)));
			}

		}

		checkCollision();
		goalSuccess = targetGoal.goalReached(score);

		score++;
		speed += 0.0000001f;
		playerSpeed += 0.000000005f;
	}
}

void Game::checkCollision()
{
	for (int i = 1; i < sizeOfArray; i++)
	{
		if ((game_object[i]->getPosition().x - 1.0f < game_object[0]->getPosition().x - 1.0f && game_object[i]->getPosition().x + 1.0f > game_object[0]->getPosition().x - 1.0f) || (game_object[i]->getPosition().x - 1.0f < game_object[0]->getPosition().x + 1.0f && game_object[i]->getPosition().x + 1.0f > game_object[0]->getPosition().x + 1.0f))
		{
			if (game_object[i]->getPosition().z - 1.0f < game_object[0]->getPosition().z - 1.0f && game_object[i]->getPosition().z - 1.0f > game_object[0]->getPosition().z - 2 -1.0f) // Use Z instead of Y
			{
				std::cout << "COLLISION DETECTED" << std::endl;
				endGame = true;
			}
		}
	}
}

void Game::render()
{

#if (DEBUG >= 2)
	DEBUG_MSG("Render Loop...");
#endif

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Save current OpenGL render states
	// https://www.sfml-dev.org/documentation/2.0/classsf_1_1RenderTarget.php#a8d1998464ccc54e789aaf990242b47f7
	window.pushGLStates();

	// Find mouse position using sf::Mouse
	int x = Mouse::getPosition(window).x;
	int y = Mouse::getPosition(window).y;

	string hud = "Mission Complete you reached 200,000 points ";


	string scoreString = "Score:"
		+ string(toString(score));

	string loseString = "You Crashed :(";

	Text text(hud, font);
	Text scoreText(scoreString, font);
	Text loss(loseString, font);

	text.setFillColor(sf::Color(255, 255, 255, 170));
	text.setPosition(0.f, 550.f);

	scoreText.setFillColor(sf::Color(255, 255, 255, 170));
	scoreText.setPosition(10.f, 40.f);

	loss.setFillColor(sf::Color(255, 255, 255, 170));
	loss.setPosition(300.f, 550.f);

	if (goalSuccess == true)
	{
		window.draw(text);
	}
	if (goalSuccess == false)
	{
		window.draw(scoreText);
	}
	if (endGame == true)
	{
		window.draw(loss);
	}
	// Restore OpenGL render states
	// https://www.sfml-dev.org/documentation/2.0/classsf_1_1RenderTarget.php#a8d1998464ccc54e789aaf990242b47f7

	window.popGLStates();

	// Rebind Buffers and then set SubData
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vib);

	// Use Progam on GPU
	glUseProgram(progID);

	// Find variables within the shader
	// https://www.khronos.org/opengles/sdk/docs/man/xhtml/glGetAttribLocation.xml
	positionID = glGetAttribLocation(progID, "sv_position");
	if (positionID < 0) { DEBUG_MSG("positionID not found"); }

	colorID = glGetAttribLocation(progID, "sv_color");
	if (colorID < 0) { DEBUG_MSG("colorID not found"); }

	uvID = glGetAttribLocation(progID, "sv_uv");
	if (uvID < 0) { DEBUG_MSG("uvID not found"); }

	textureID = glGetUniformLocation(progID, "f_texture");
	if (textureID < 0) { DEBUG_MSG("textureID not found"); }

	mvpID = glGetUniformLocation(progID, "sv_mvp");
	if (mvpID < 0) { DEBUG_MSG("mvpID not found"); }

	x_offsetID = glGetUniformLocation(progID, "sv_x_offset");
	if (x_offsetID < 0) { DEBUG_MSG("x_offsetID not found"); }

	y_offsetID = glGetUniformLocation(progID, "sv_y_offset");
	if (y_offsetID < 0) { DEBUG_MSG("y_offsetID not found"); }

	z_offsetID = glGetUniformLocation(progID, "sv_z_offset");
	if (z_offsetID < 0) { DEBUG_MSG("z_offsetID not found"); };

	// VBO Data....vertices, colors and UV's appended
	// Add the Vertices for all your GameOjects, Colors and UVS
	
	glBufferSubData(GL_ARRAY_BUFFER, 0 * VERTICES * sizeof(GLfloat), 3 * VERTICES * sizeof(GLfloat), game_object[0]->getVertex());
	//glBufferSubData(GL_ARRAY_BUFFER, 0 * VERTICES * sizeof(GLfloat), 3 * VERTICES * sizeof(GLfloat), vertices);
	glBufferSubData(GL_ARRAY_BUFFER, 3 * VERTICES * sizeof(GLfloat), 4 * COLORS * sizeof(GLfloat), colors);
	glBufferSubData(GL_ARRAY_BUFFER, ((3 * VERTICES) + (4 * COLORS)) * sizeof(GLfloat), 2 * UVS * sizeof(GLfloat), uvs);

	// Send transformation to shader mvp uniform [0][0] is start of array
	glUniformMatrix4fv(mvpID, 1, GL_FALSE, &mvp[0][0]);

	// Set Active Texture .... 32 GL_TEXTURE0 .... GL_TEXTURE31
	glActiveTexture(GL_TEXTURE0);
	glUniform1i(textureID, 0); // 0 .... 31

	// Set the X, Y and Z offset (this allows for multiple cubes via different shaders)
	// Experiment with these values to change screen positions

	;
	//glUniform1f(x_offsetID, 0.00f);
	//glUniform1f(y_offsetID, 0.00f);
	//glUniform1f(z_offsetID, 0.00f);

	// Set pointers for each parameter (with appropriate starting positions)
	// https://www.khronos.org/opengles/sdk/docs/man/xhtml/glVertexAttribPointer.xml
	glVertexAttribPointer(positionID, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glVertexAttribPointer(colorID, 4, GL_FLOAT, GL_FALSE, 0, (VOID*)(3 * VERTICES * sizeof(GLfloat)));
	glVertexAttribPointer(uvID, 2, GL_FLOAT, GL_FALSE, 0, (VOID*)(((3 * VERTICES) + (4 * COLORS)) * sizeof(GLfloat)));
	
	// Enable Arrays
	glEnableVertexAttribArray(positionID);
	glEnableVertexAttribArray(colorID);
	glEnableVertexAttribArray(uvID);

	for (int i = 0; i < sizeOfArray; i++)
	{
		glUniform1f(x_offsetID, game_object[i]->getPosition().x);
		glUniform1f(y_offsetID, game_object[i]->getPosition().y);
		glUniform1f(z_offsetID, game_object[i]->getPosition().z);

		// Draw Element Arrays
		glDrawElements(GL_TRIANGLES, 3 * INDICES, GL_UNSIGNED_INT, NULL);
	}

	window.display();

	// Disable Arrays
	glDisableVertexAttribArray(positionID);
	glDisableVertexAttribArray(colorID);
	glDisableVertexAttribArray(uvID);

	// Unbind Buffers with 0 (Resets OpenGL States...important step)
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	// Reset the Shader Program to Use
	glUseProgram(0);

	// Check for OpenGL Error code
	error = glGetError();
	if (error != GL_NO_ERROR) {
		DEBUG_MSG(error);
	}
}

void Game::unload()
{
#if (DEBUG >= 2)
	DEBUG_MSG("Cleaning up...");
#endif
	glDetachShader(progID, vsid);	// Shader could be used with more than one progID
	glDetachShader(progID, fsid);	// ..
	glDeleteShader(vsid);			// Delete Vertex Shader
	glDeleteShader(fsid);			// Delete Fragment Shader
	glDeleteProgram(progID);		// Delete Shader
	glDeleteBuffers(1, &vbo);		// Delete Vertex Buffer
	glDeleteBuffers(1, &vib);		// Delete Vertex Index Buffer
	stbi_image_free(img_data);		// Free image stbi_image_free(..)
}

