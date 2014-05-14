#include <cstdlib>
#include "GameEngine.hpp"
#include <Game.hh>
#include <Clock.hh>
#include <Input.hh>
#include <SdlContext.hh>
#include <Geometry.hh>
#include <Texture.hh>
#include <BasicShader.hh>
#include <Model.hh>
#include <OpenGL.hh>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

int main()
{
  // On cree son engine
  GameEngine engine;
  //  gdl::Model::load("./assets/marvin.fbx")
  if (engine.initialize() == false)
    return (EXIT_FAILURE);
  while (engine.update() == true)
    {
      std::cout << SDL_NumJoysticks() << std::endl;
      engine.draw();
    }
  return EXIT_SUCCESS;
}
