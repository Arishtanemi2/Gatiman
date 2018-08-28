//This_is_only_necessary_if_intergration_with_a_cloud-server_is_difficult_or_unwanted.Then_this_program_will_recieve_the_data_and_put_it_in_a_corresponding_file_format.
#include<ctype.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<fcntl.h>
#include<netdb.h>
#include<unistd.h>
#include<pthread.h>

char 	id[32];
char *file="login";
char	data[100];
void main()
{
	
	int sock = socket(AF_INET,SOCK_STREAM,0);
	struct sockaddr_in client,server;
	//client = (sockaddr_in *) malloc(10*sizeof(sockaddr_in));
	server.sin_addr.s_addr = INADDR_ANY;
	puts("Enter the port : ");
	int port;
	scanf("%d",&port);
	server.sin_port = htons(port);
	server.sin_family = AF_INET;
	if(bind(sock,(struct sockaddr*)&server,sizeof(struct sockaddr_in))==0)
		puts("binded");
	else
	{
		puts("bind failed");
		exit(0);
	}

	int list = 0;
	char a;
	socklen_t len = (socklen_t) sizeof(struct sockaddr_in);
	 if(listen(sock,1000)==0)
		 puts("listening");

	 
	 

	               



int cli;
int	check;
	int count=0;
	

xya:
   cli = accept(sock,(struct sockaddr*)&client,&len);
  if(cli)
  {
   printf("connected on socket %d \n",cli);
  }
  char	buf[200];
  check=fork();
  int count1=0;
  if(check==0)
  {
	int	fd=open(file,O_RDONLY);
	int	count=0;
	char	temp[32];
	close(sock);
	puts("communicating.......");
	recv(cli,&buf,200,0);
	printf("%s",buf);
	char	login_name[20];
	int	i=0;
char	temp1[20];
	while(read(fd,login_name,20))
	{
	if(buf[i]=='$')
	break;
       for(i=1;buf[i]!='$';temp1[i-1]=buf[i],i++)
	if(buf[i]!=login_name[i-1])
	{
	break;	
	}
	}
	temp1[i]='\0';
	puts(temp1);
	close(fd);
	if(buf[i+1]=='1')
	{
	int	ld=open(temp1,O_RDWR);
	i+=3;
	for(int	j=0;buf[i]!='$';i++,j++)
	data[j]=buf[i];
	write(ld,data,200);
	close(ld);
}	
	
	



	printf("connected#at:%s..ip=%s...mac_adress=%s",__TIME__,inet_ntoa(client.sin_addr));

  }
  else
  {
	goto	xya;
  }
		
	

}
