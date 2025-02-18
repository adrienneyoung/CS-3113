#include "Entity.h"
#include <vector>
#include <SDL_mixer.h>

// 60 FPS (1.0f/60.0f)
#define FIXED_TIMESTEP 0.0166666f
#define MAX_TIMESTEPS 6
#define TILE_SIZE .70f
#define SPRITE_COUNT_X 14
#define SPRITE_COUNT_Y 7

class Platformer {
public:
	Platformer();
	~Platformer();

	void scrollScreen();
	void handleCollisions();

	void Setup();
	void Render();
	void Update(float elapsed);
	bool Run();

	void buildLevel();
	bool readHeader(std::ifstream &stream);
	bool readLayerData(std::ifstream &stream);
	//bool readEntityData(std::ifstream &stream);
	void RenderLevel();
	

private:
	SDL_Window* displayWindow;

	ShaderProgram* program;

	Mix_Music* music;

	//Matrices
	Matrix projectionMatrix;
	Matrix viewMatrix;
	Matrix modelMatrixText;
	Matrix modelMatrix;
	Matrix backgroundMatrix;

	GLuint font;
	GLuint spritesheet;
	GLuint background;

	vector<float> vertices;
	vector<float> texCoords;

	//Entities
	Entity* player;
	vector<Entity*> staticEntities;

	//Map stuff
	int mapWidth;
	int mapHeight;
	unsigned char** levelData;

	bool done = false;
	float lastFrameTicks = 0.0f;

	Matrix modelMatrixText2;
	Matrix modelMatrixText3;
	Matrix modelMatrixText4;
	//Entity* block;
	vector<Entity*> blocks; //this is for testing purposes
	vector<Entity*> blocks2; //this is for testing purposes
};