extern void SendMovePlayer(int idPlayer, int coord);
extern void SendBombPlanted (int coord);
extern void SendBombExplode (int coord, int radius);
extern void SendPlayerDead (int idPlayer);
extern void SendPlusHP(int idPlayer);
extern void SendMinusHP(int idPlayer);
extern void SendBoxExplode(int coord, int newType);