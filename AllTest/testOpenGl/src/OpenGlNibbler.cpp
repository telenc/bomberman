//
// OpenGlNibbler.cpp for opengl in /home/remi/Epitech/Teck2/rendu/nibler/cpp_nibbler/src
//
// Made by telenc_r
// Login   <remi@epitech.net>
//
// Started on  Sat Mar 15 09:45:31 2014 telenc_r
// Last update Tue May  6 07:13:50 2014 Remi telenczak
//

#include	"OpenGlNibbler.hpp"
#include	<math.h>
#include	<list>
#include	"myException.hpp"
#include	"Game.hpp"
#include	"Snake.hpp"

ALibGraphic	*self;

extern "C" ALibGraphic *constructor_graphic(Game *game)
{
  self = new OpenGlNibbler(game);
  return self;
}

void	OpenGlNibbler::createSphere(double x, double y, double size = 1) const
{
  float coul[4] = {0, 0, 0, 1};
  glColor3ub(rgb[0], rgb[1], rgb[2]);
  glMaterialfv(GL_FRONT,GL_SPECULAR,coul);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, coul);
  glPushMatrix();
  glTranslatef(x, 1, y);
  glutSolidSphere(size, 36, 36);
  glPopMatrix();
}

void	OpenGlNibbler::createCube(double x, double y, double size = 1) const
{
  float coul[4] = {0, 0, 0, 1};
  glColor3ub(rgb[0], rgb[1], rgb[2]);
  glMaterialfv(GL_FRONT,GL_SPECULAR,coul);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, coul);
  glPushMatrix();
  glTranslatef(x, 0, y);
  glutSolidCube(size * 2);
  glPopMatrix();
  return;
}

void	OpenGlNibbler::createCylinder(double x, double y, double size = 1, double height = 1) const
{
  float coul[4] = {0, 0, 0, 1};
  glColor3ub(rgb[0], rgb[1], rgb[2]);
  glMaterialfv(GL_FRONT,GL_SPECULAR,coul);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, coul);
  glPushMatrix();
  glTranslatef(x, 0.7, y);
  glRotatef(-100, 1, 0, 0);
  glRotatef(45, 0, 1, 0);
  glutSolidCylinder(size, height, 32, 32);
  glPopMatrix();
}

void	OpenGlNibbler::createPlan() const
{
  int	w;
  int	h;

  float coul[4] = {0, 0, 0, 1};
  w = this->game()->getMap()->getWidth();
  h = this->game()->getMap()->getHeight();
  glColor3ub(217, 217, 217);
  glMaterialfv(GL_FRONT,GL_SPECULAR,coul);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, coul);
  glPushMatrix();
  glTranslatef(w, -1, h);
  glScalef(w*2, 1, h*2);
  glutSolidCube(1);
  glPopMatrix();
}

void		OpenGlNibbler::createEyes(int x, int y)
{
  int		direction;

  setRgb(242, 227, 14);
  direction = this->game()->getMap()->getSnake()->getDirection();
  if (direction == 1 || direction == 2)
    this->createSphere(x * 2 + 1, y * 2 + 1, 0.4);
  if (direction == 1 || direction == 4)
    this->createSphere(x * 2 + 1, y * 2 - 1, 0.4);
  if (direction == 2 || direction == 3)
    this->createSphere(x * 2 - 1, y * 2 + 1, 0.4);
  if (direction == 3 || direction == 4)
    this->createSphere(x * 2 - 1, y * 2 - 1, 0.4);

}

void			OpenGlNibbler::createFruit()
{
  std::list<Fruit *> fruit;
  std::list<Fruit *>::iterator i;
  std::map<char, t_color>::iterator j;

  fruit = this->game()->getMap()->getFruit();
  i = fruit.begin();
  while (i != fruit.end())
    {
      j = this->_colorFruit.find((*i)->getType());
      if (j != _colorFruit.end())
	this->setRgb((*j).second.r,(*j).second.g,(*j).second.b);
      else
	this->setRgb(0,255, 0);
      this->createSphere((*i)->getX() * 2, (*i)->getY() * 2, 1);
      this->setRgb(0, 255, 0);
      this->createCylinder((*i)->getX() * 2, (*i)->getY() * 2, 0.2, 2);
      i++;
    }
}

void				OpenGlNibbler::createSnake()
{
  std::list<Tile *>		vect;
  std::list<Tile *>::iterator	i;
  double		size;

  size = 1;
  vect = this->game()->getMap()->getSnake()->getSnake();
  for (i = vect.begin(); i != vect.end(); ++i)
    {
      this->setRgb(102, 204, 0);
      if (i == vect.begin())
	{
	  this->setRgb(37, 147, 37);
	  this->createSphere((*i)->getX() * 2, (*i)->getY() * 2, size);
	  createEyes((*i)->getX(), (*i)->getY());
	}
      else
	this->createSphere((*i)->getX() * 2, (*i)->getY() * 2, size);
      size -= 0.05;
      if (size < 0.3)
	size = 0.3;
    }
}

OpenGlNibbler::~OpenGlNibbler()
{
  glutLeaveMainLoop();
}

void			OpenGlNibbler::view()
{
  std::list<Tile *>	vect;
  int			x;
  int			y;
  int			hauteur_cam;
  int			direct;

  hauteur_cam = 1;
  direct = this->game()->getMap()->getSnake()->getDirection();
  vect = this->game()->getMap()->getSnake()->getSnake();
  x = vect.front()->getX();
  y = vect.front()->getY();
  if (this->_display == 1)
    gluLookAt((x * 2) - 10, this->_zoom, (y * 2), x * 2, 0.5, y * 2, 1 ,1 ,0);
  else
    {
      if (direct == 1)
	gluLookAt((x * 2) - 2, hauteur_cam+2, (2 * y),
		  (x * 2) + 2, 2, (2 * y),
		  0, 1, 0);
      if (direct == 2)
	gluLookAt((x * 2) , hauteur_cam+2, (2 * y) - 2,
		  (x * 2) , 2, (2 * y) + 2,
		  0, 1, 0);
      if (direct == 3)
	gluLookAt((x * 2) + 2, hauteur_cam+2, (2 * y),
		  (x * 2) - 2, 2, (2 * y),
		  0, 1, 0);
      if (direct == 4)
	gluLookAt((x * 2), hauteur_cam+2, (2 * y) + 2,
		  (x * 2), 2, (2 * y) - 2,
		  0, 1, 0);
    }
  this->settingColor(this->game()->getMap()->getWidth(), this->game()->getMap()->getHeight());
}

void	OpenGlNibbler::setRgb(int r, int g, int b)
{
  this->rgb[0] = r;
  this->rgb[1] = g;
  this->rgb[2] = b;
}

void	OpenGlNibbler::writeText(int x, int y, const char *p) const
{
  glDisable(GL_LIGHTING);
  glMatrixMode(GL_PROJECTION);
  glPushMatrix();
  glLoadIdentity();
  gluOrtho2D(0, 1000, 0, 1000);
  glScalef(1, -1, 1);
  glTranslatef(0, -1000, 0);
  glMatrixMode(GL_MODELVIEW);
  glPushMatrix();
  glLoadIdentity();
  glRasterPos2f(x, y );
  while (*(p))
    {
      glutBitmapCharacter( GLUT_BITMAP_HELVETICA_18, *p );
      p++;
    }
  glPopMatrix();
  glMatrixMode(GL_PROJECTION);
  glPopMatrix();
  glMatrixMode(GL_MODELVIEW);
  glEnable(GL_LIGHTING);
}

void	OpenGlNibbler::createScore() const
{
  std::string score;
  std::ostringstream ss;

  ss << this->game()->getScore();
  score = ss.str();
  score = "Score : " + score;
  writeText(20, 50, score.c_str());
}

void	OpenGlNibbler::refreshGame()
{
  //std::list<Tile *>	vect;
  //int			x;
  //int			y;

  //glClear(GL_DEPTH_BUFFER_BIT);
  glScissor(0, 40, 720, 720);
  glViewport(0, 40, 720, 720);
  //Vector3f eye = Quaternion.right(rift);

  this->view();

  this->refreshGame2();

  glClear(GL_DEPTH_BUFFER_BIT);

  glScissor(640, 40, 720, 720);
  glViewport(560, 40,720, 720);

  glTranslatef(0, 0, -1);

  //vect = this->game()->getMap()->getSnake()->getSnake();
  //x = vect.front()->getX();
  //y = vect.front()->getY();
  ///if (this->_display == 1)
  //gluLookAt((x * 2) - 10, this->_zoom, (y * 2), x * 2, 0.5, y * 2, 1 ,1 ,0);


  this->refreshGame2();
}
void	OpenGlNibbler::refreshGame2()
{
  int		w;
  int		h;
  double	x;
  double	y;
  Tile		*tile;


  w = this->game()->getMap()->getWidth();
  h = this->game()->getMap()->getHeight();
  for (y = 0; y < h * 2 ; y += 2)
    {
      for (x = 0; x < w * 2; x += 2)
	{
	  tile = this->game()->getMap()->getTile(y/2, x/2);
	  if (tile && tile->getType() == 'w')
	    {
	      this->setRgb(154, 103, 13);
	      this->createCube(x, y);
	    }
	}
    }
  this->createPlan();
  this->createSnake();
  this->createFruit();
  //this->createScore();
}

void	OpenGlNibbler::refreshDied()
{
  std::string score;
  std::ostringstream ss;

  glClearColor(0.0f, 0.2f, 0.2f, 0.0f);
  writeText(500, 300, "You died");
  ss << this->game()->getScore();
  score = ss.str();
  writeText(500, 450, "Votre score : ");
  writeText(500, 500, score.c_str());
}

void	OpenGlNibbler::menuSnakeLeft()
{
  int			i;
  int			x;
  int			nbr;

  i = 0;
  x = this->_xMenu;
  while (i < 4)
    {
      this->setRgb(102, 204, 0);
      if (i == 0)
	{
	  this->setRgb(37, 147, 37);
	  this->createSphere(this->_yMenu, x, 1);
	  setRgb(242, 227, 14);
	  this->createSphere(this->_yMenu + 1, x - 1, 0.4);
	  this->createSphere(this->_yMenu - 1, x - 1, 0.4);
	}
      else
	this->createSphere(this->_yMenu, x, 1);
      x += 2;
      i++;
    }
  this->_xMenu -= 1;
  if (this->_xMenu < -40)
    {
      std::srand(std::time(0));
      nbr = std::rand() % 40 - 20;
      this->_directionMenu = 1;
      this->_yMenu = nbr;
    }
  usleep(10000);
}

void	OpenGlNibbler::menuSnakeRight()
{
  int			i;
  int			x;
  int			nbr;

  i = 0;
  x = this->_xMenu;
  while (i < 4)
    {
      this->setRgb(102, 204, 0);
      if (i == 0)
	{
	  this->setRgb(37, 147, 37);
	  this->createSphere(this->_yMenu, x, 1);
	  setRgb(242, 227, 14);
	  this->createSphere(this->_yMenu + 1, x + 1, 0.4);
	  this->createSphere(this->_yMenu - 1, x + 1, 0.4);
	}
      else
	this->createSphere(this->_yMenu, x, 1);
      x -= 2;
      i++;

    }
  this->_xMenu += 1;
  if (this->_xMenu > 40)
    {
      std::srand(std::time(0));
      nbr = std::rand() % 40 - 20;
      this->_directionMenu = -1;
      this->_yMenu = nbr;
    }
  usleep(10000);
}

void	OpenGlNibbler::menuFruit()
{
  std::map<char, t_color >::iterator	i;
  int					x;

  gluLookAt(10, 30, 0, 0, 0, 0, 1 ,1 ,0);
  i = this->_colorFruit.begin();
  x = -17;
  while (i != this->_colorFruit.end())
    {
      this->setRgb(i->second.r, i->second.g, i->second.b);
      createSphere(-10, x);
      this->setRgb(0, 255, 0);
      this->createCylinder(-10, x, 0.2, 2);      i++;
      x += 6;
    }
  writeText(110, 630, "Normal");
  writeText(250, 630, "Rm");
  writeText(350, 630, "SpeedHack");
  writeText(500, 630, "Slow");
  writeText(610, 630, "Hangover");
  writeText(730, 630, "Give me more");
  writeText(860, 630, "Random");
}

void	OpenGlNibbler::refreshMenu()
{
  std::list<int>::iterator		j;
  std::string				score;
  std::ostringstream			ss;
  int					x;
  std::list<int>			listt;

  glClearColor(0.0f, 0.2f, 0.2f, 0.0f);
  writeText(100, 100, "--> Jouer <--");
  writeText(100, 150, "Mode Facile");
  writeText(100, 200, "Mode Difficile");
  writeText(100, 250, "--> Quitter");
  x = 120;
  writeText(700, 100, "High scores : ");
  this->menuFruit();
  if (this->_directionMenu == -1)
    this->menuSnakeLeft();
  else
    this->menuSnakeRight();
  listt = this->game()->getScores();
  j = listt.begin();
  while (j != listt.end())
    {
      ss << (*j);
      score = ss.str();
      writeText(740, x, score.c_str());
      ss.str("");
      x+=20;
      j++;
    }
}

void OpenGlNibbler::refresh()
{
  glutMainLoopEvent();
  glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  if (this->game()->getMenu())
    {
      this->refreshMenu();
    }
  else
    {
      if (this->game()->getMap()->isAlive())
	this->refreshGame();
      else
	this->refreshDied();
    }
  glFlush ();
  glutSwapBuffers();
  glutPostRedisplay();
}

void	OpenGlNibbler::zoomCam()
{
  this->_zoom -= 1;
}

void	OpenGlNibbler::dezoomCam()
{
  this->_zoom += 1;
}

void	keyPress(unsigned char key, int x, int y)
{
  if (!self->game()->getMenu())
    {
      if (key == 'a')
	((OpenGlNibbler*)self)->changeDisplay();
      if (key == '+')
	((OpenGlNibbler*)self)->zoomCam();
      if (key == '-')
	((OpenGlNibbler*)self)->dezoomCam();
    }
  else if (key == 27)
    self->game()->setEnd(0);
  (void)x;
  (void)y;
}

void	mouseFunc(int key, int state, int x, int y)
{
  if (key == 0 && state == 1 && self->game()->getMenu() == 1)
    {
      if (x > 97 && x < 200 && y > 136 && y < 157)
	self->game()->launchGame();
      else if (x > 101 && x < 208 && y > 183 && y < 207)
	self->game()->launchHardGame();
      else if (x > 101 && x < 213 && y > 232 && y < 259)
	self->game()->setEnd(0);
    }
  else if (key == 0 && state == 1)
    {
      if (!self->game()->getMap()->isAlive())
	self->game()->launchMenu();
    }
}

void	keyPressSpecial(int key, int x, int y)
{
  if (!self->game()->getMenu())
    {
      if (key == 100)
	self->game()->getMap()->getSnake()->changeDirectionLeft();
      else if (key == 102)
	self->game()->getMap()->getSnake()->changeDirectionRight();
    }
  (void)x;
  (void)y;
}

void idle(void)
{
  glutPostRedisplay();
}


void render(void)
{
  glutSwapBuffers();
}

void		OpenGlNibbler::changeDisplay()
{
  if (this->_display == 1)
    this->_display = 0;
  else
    this->_display = 1;
}

void		OpenGlNibbler::settingColor(int w, int h)
{
  GLfloat ambient[] = {0.15f,0.15f,0.15f,0.0f};
  GLfloat diffuse[] = {1.5f,1.5f,1.5f,1.5f};
  GLint light0_position [] = {w * 2, 5, h * 2, 1};
  GLfloat specular_reflexion[] = {0.1,0.1,0.1,1};
  GLubyte shiny_obj = 100;

  glShadeModel(GL_SMOOTH);
  glEnable(GL_COLOR_MATERIAL);
  glColorMaterial(GL_FRONT,GL_AMBIENT_AND_DIFFUSE);
  glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,ambient);
  glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,diffuse);
  glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,specular_reflexion);
  glMateriali(GL_FRONT_AND_BACK,GL_SHININESS,shiny_obj);
  glLightfv(GL_LIGHT1,GL_AMBIENT,ambient);
  glLightfv(GL_LIGHT1,GL_DIFFUSE,diffuse);
  glLightiv(GL_LIGHT1,GL_POSITION,light0_position);
  glEnable(GL_AUTO_NORMAL);
  glEnable(GL_NORMALIZE);
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT1);
}

t_color		OpenGlNibbler::createTColor(int r, int g, int b)
{
  t_color	res;

  res.r = r;
  res.g = g;
  res.b = b;
  return res;
}


void		OpenGlNibbler::createMapColor()
{
  this->_colorFruit.insert(std::pair<char, t_color>('a', createTColor(255, 119, 119)));
  this->_colorFruit.insert(std::pair<char, t_color>('r', createTColor(255, 255, 0)));
  this->_colorFruit.insert(std::pair<char, t_color>('s', createTColor(255, 255, 255)));
  this->_colorFruit.insert(std::pair<char, t_color>('d', createTColor(151, 151, 151)));
  this->_colorFruit.insert(std::pair<char, t_color>('t', createTColor(120, 215, 105)));
  this->_colorFruit.insert(std::pair<char, t_color>('m', createTColor(206, 75, 213)));
  this->_colorFruit.insert(std::pair<char, t_color>('p', createTColor(199, 3, 3)));

}

OpenGlNibbler::OpenGlNibbler(Game *game) : ALibGraphic(game)
{
  int	c;
  int res;

  c = 0;
  this->_xMenu = 40;
  this->_yMenu = 10;
  this->_directionMenu = -1;
  this->_zoom = 50;
  this->_display = 1;
  this->createMapColor();
  glutInit(&c, NULL);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
  glutInitWindowSize(1280, 800);
  glutInitWindowPosition(100, 0);
  res = glutCreateWindow("Nibbler - Telenc_r - Dedick_r - Martre_s");
  if (res < 1)
    throw new myException(" OpenGl\nFail Function create Window");
  glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glEnable(GL_SCISSOR_TEST);
  gluPerspective(70, (double)1, 1, 1000);
  this->settingColor(0, 0);
  glutKeyboardFunc(keyPress);
  glutSpecialFunc(keyPressSpecial);
  glutMouseFunc(mouseFunc);
  glutIdleFunc(idle);
  glutDisplayFunc(render);
}
