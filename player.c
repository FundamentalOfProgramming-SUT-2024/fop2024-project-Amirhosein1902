#include <rogue.h>


Entity* createPlayer(Position start_pos)
{
  Entity* newPlayer = calloc(1, sizeof(Entity));

  newPlayer->pos.y = start_pos.y;
  newPlayer->pos.x = start_pos.x;
  newPlayer->ch = '@' ;

  return newPlayer;
}

void handleInput(int input)
{

  Position newPos = { player->pos.y, player->pos.x };	
  switch(input)
  {
    //move up
    case '8':
      newPos.y--;
      break;
    //move down
    case '5':
      newPos.y++;
      break;
    //move left
    case '4':
      newPos.x--;
      break;
    //move right
    case '6':
      newPos.x++;
      break;
    case '9':
      newPos.x++;
      newPos.y--;
      break;
    case '7':
      newPos.x--;
      newPos.y--;
      break;
    case '3':
      newPos.x++;
      newPos.y++;
      break;
    case '1':
      newPos.x--;
      newPos.y++;
      break;
    default:
      break;
  }

  movePlayer(newPos);
}

void movePlayer(Position newPos)
{
  if (map[newPos.y][newPos.x].walkable)
  {
    player->pos.y = newPos.y;
    player->pos.x = newPos.x;
  }
}
