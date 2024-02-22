#include <stdio.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main(void){
	char buffer[BUFFER_SIZE];
	// create a socket
	int sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd == -1){
		perror("webserver (socket)");
		return 1;
	}
	printf("socket created successfully\n");
	//create address for socket to bind to
	struct sockaddr_in host_addr;
	int host_addrlen = sizeof(host_addr);

	host_addr.sin_family = AF_INET;
	host_addr.sin_port = htons(PORT);
	host_addr.sin_addr.s_addr = htonl(INADDR_ANY);


	//Bind the socket to the address
	if(bind(sockfd, (struct sockaddr *)&host_addr, host_addrlen) != 0){
		perror("webserver (bind)");
		return 1;
	}
	printf("socket bound to address\n");
	

	//Listen for incoming connections
	if(listen(sockfd, SOMAXCONN) != 0) {
		perror("webserver (listen)");
		return 1;
	}
	printf("server listening for connections");


	for(;;){
		//accept incoming connection
		int newsockfd = accept(sockfd, (struct sockaddr *)&host_addr, (socklen_t *)&host_addrlen);

		if(newsockfd < 0) {
			perror("webserver (accept)");
			continue;
		}
		printf("connection accepted\n");
		
		//read from socket
		int valread = read(newsockfd, buffer, BUFFER_SIZE);
		if(valread < 0) {
			perror("webserver (read)");
			continue;
		}
		close(newsockfd);


	}
	return 0;
}



//stopped at step 5ish
//https://bruinsslot.jp/post/simple-http-webserver-in-c/
