#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>

void	main()
{
char	buf[20];
int	n=open("login",O_RDWR||O_APPEND);
while(1)
{
puts("Enter..the..name");
scanf("%s",buf);
lseek(n,0,SEEK_END);
write(n,buf,20);
}
}
