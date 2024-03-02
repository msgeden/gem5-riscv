#include <stdio.h>
#include <string.h>
int Authenticate(char* packet){
  return (strstr(packet,"secret")!=NULL);
}
void PacketRead(char* packet){
  scanf("%s", packet);
}
void ProcessPacket(char* packet){
  printf("Processed packet:%s\n", packet);
}
int main() {
  int authenticated=0;
  int *p;
  p=&authenticated;
  char packet[7];
  while (!authenticated)
  {
    PacketRead(packet);
    if (Authenticate(packet))
      authenticated=1;
  }
  if (authenticated)
    ProcessPacket(packet);
  return 0;
}
