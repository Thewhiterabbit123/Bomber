#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
/* hton, ntoh и проч. */
#include <arpa/inet.h>
#include <memory.h>
#include <stdio.h>

int main(int argc, char * argv[])
{

      /*объявляем сокет*/
      int s = socket( AF_INET, SOCK_STREAM, 0 );
      if(s < 0)
      {
              perror( "Error calling socket" );
              return 0;
      }

      /*соединяемся по определённому порту с хостом*/
      struct sockaddr_in peer;
      peer.sin_family = AF_INET;
      peer.sin_port = htons( 18666 );
      peer.sin_addr.s_addr = inet_addr( "127.0.0.1" );
      int result = connect( s, ( struct sockaddr * )&peer, sizeof( peer ) );
      if( result )
      {
              perror( "Error calling connect" );
              return 0;
      }

      /*посылаем данные
       *
       * Если быть точным, данные не посланы, а записаны где-то в стеке, когда и как они будут
       * отправлены реализации стека TCP/IP виднее. Зато мы сразу получаем управление, не
       * дожидаясь у моря погоды.*/
      char buf[] = "Hello, world!";
      result = send( s, "Hello, world!", 13, 0);
      if( result <= 0 )
      {
              perror( "Error calling send" );
              return 0;
      }
      /* закрываем соединения для посылки данных */
      if( shutdown(s, 1) < 0)
      {
              perror("Error calling shutdown");
              return 0;
      }

      /* читаем ответ сервера */
      fd_set readmask;
      fd_set allreads;
      FD_ZERO( &allreads );
      FD_SET( 0, &allreads );
      FD_SET( s, &allreads );
      for(;;)
      {
              readmask = allreads;
              if( select(s + 1, &readmask, NULL, NULL, NULL ) <= 0 )
              {
                      perror("Error calling select");
                      return 0;
              }
              if( FD_ISSET( s, &readmask ) )
              {
                      char buffer[20];
                      memset(buffer, 0, 20*sizeof(char));
                      int result = recv( s, buffer, sizeof(buffer) - 1, 0 );
                      if( result < 0 )
                      {
                              perror("Error calling recv");
                              return 0;
                      }
                      if( result == 0 )
                      {
                              perror("Server disconnected");
                              return 0;
                      }
                      if(strncmp(buffer, "Hi, dear!", 9) == 0)
                              printf("Got answer. Success.\n");
                      else
                              perror("Wrong answer!");
              }
              if( FD_ISSET( 0, &readmask ) )
              {
                      printf( "No server response" );
                      return 0;
              }
      }
      return 0;
}
