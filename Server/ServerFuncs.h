extern void SendMovePlayer(int idPlayer, Event ev);
extern void SendBombPlanted (int id, int coord);
extern void SendBombExplode (int id, int radius);
extern void SendPlayerDead (int idPlayer);
extern void SendPlusHP(int idPlayer);
extern void SendMinusHP(int idPlayer);
extern void SendBoxExplode(int id, int newType);
extern void SendEndGame(int idPlayer);