#include "IPClassification.h"

#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h> 
#include <errno.h> 
#include <netdb.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <netinet/in.h> 
#include <arpa/inet.h> 


int main() 
{ 
	char hostbuffer[256]; 
	char *IPbuffer; 
	struct hostent *host_entry; 
	int hostname; 

	hostname = gethostname(hostbuffer, sizeof(hostbuffer)); 
	checkHostName(hostname); 

	host_entry = gethostbyname(hostbuffer); 
	checkHostEntry(host_entry); 

	IPbuffer = inet_ntoa(*((struct in_addr*) host_entry->h_addr_list[0])); 

	printf("Hostname: %s\n", hostbuffer); 
	printf("Host IP: %s\n", IPbuffer);
	
	char ipClass = findClass(IPbuffer);
	printf("IP Class: %c\n", ipClass);
	
	separate(IPbuffer, ipClass);

	return 0;
} 
