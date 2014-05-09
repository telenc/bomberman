//
// Ncurses.hpp for nibbler in /home/martre_s/Epitech/Cpp/cpp_nibbler/src
//
// Made by Steven Martreux
// Login   <martre_s@epitech.net>
//
// Started on  Mon Mar 31 12:47:25 2014 Steven Martreux
// Last update Sun Apr  6 15:43:22 2014 Steven Martreux
//

#ifndef		_NCURSES_HPP_
# define	_NCURSES_HPP_

# include	<map>
# include	"ALibGraphic.hpp"
# include	<curses.h>

class		Ncurses : public ALibGraphic
{
public:
  Ncurses(Game *);
  void	refresh();
  virtual ~Ncurses();
private:
  Game	*_game;
  std::map<char, int> _colorFruit;
  WINDOW *win;
  int	w;
  int	h;
  void	createPlan() const;
  void	createSnake() const;
  void	keyPress() const;
  void	putFruit();
  int	Scroll(char, int) const;
  void	printScore() const;
  void	printMenu();
  void	createFruitColor();
  void	printDied() const;
  void	printButtonMenu() const;
  void	printBackgroundMenu() const;
  void	printFruitMenu();
  void	printNameFruit() const;
  void	printScoreMenu() const;
};

#endif		/* _NCURSES_HPP_ */
