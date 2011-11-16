//starting NFS file used the README stuff

#include <iostream>

#include <cstdlib>

#include "fs_client.h"

//test 

using namespace std;

 

main(int argc, char *argv[])

{

  char *server;

  int server_port;

  int session, seq=0;

  char buf[10];

 

  if (argc != 3)

    {

      cout << "error: usage: " << argv[0] << "\n"; exit(1);

    }

 

  server = argv[1];

  server_port = atoi(argv[2]);

  fs_session("user1", "password1", server, server_port, &session);

  fs_create("user1", "password1", session, seq++, "tmp");

  fs_append("user1", "password1", session, seq++, "tmp", "abc", 3);

  fs_read("user1", "password1", session, seq++, "tmp", 1, buf, 2);

  fs_delete("user1", "password1", session, seq++, "tmp");

}



