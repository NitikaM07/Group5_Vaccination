/************************************************************************************
 *   FILENAME    :   Password.c
 *
 *   DESCRIPTION :   This file is used for masking and checking the password when and 
 *                   customer/user logging in
 *
 *   REVISION HISTORY
 *
 *   DATE            NAME             REASON
 *
 *  -------------------------------------------
 *   
 *   22/09/2022    Group-5           Validate password
 *
 * ***********************************************************************************/
#include<stdio.h>  //Include all header files
#include<stdlib.h>
#include<string.h>
#include<termios.h>
#include<ctype.h>
#define MAXPW 32
ssize_t password(char **pw,size_t sz,int mask,FILE *fp)

{     
	if(!pw || !sz||!fp)return -1;   // validate input
#ifdef MAXPW
	if(sz> MAXPW) sz=MAXPW;
#endif

	if(*pw==NULL)                // reallocate if no address 
	{

		void *tmp = realloc(*pw,sz * sizeof **pw);
		if(!tmp)
			return -1;
		memset (tmp,0,sz);  // initialize memory to 0
		*pw = (char*)tmp;
	}
	size_t idx = 0;         // index number of chars in read
	int c = 0;
	struct termios old_kbd_mode; // orig keyboard settings
	struct termios new_kbd_mode;
	if(tcgetattr (0,&old_kbd_mode)) // save orignal settings
	{
		fprintf(stderr, "%s() error: tcgetattr failed.\n",__func__);
		return -1;
	}   // copy old to new
	memcpy(&new_kbd_mode, &old_kbd_mode,sizeof(struct termios));
	new_kbd_mode.c_lflag &= ~(ICANON | ECHO); //new kbd flags
	new_kbd_mode.c_cc[VTIME] = 0;
	new_kbd_mode.c_cc[VMIN] = 1;
	if(tcsetattr (0, TCSANOW, &new_kbd_mode)){
		fprintf(stderr, "%s() error: tcsetattr failed.\n",__func__);
		return -1;
	}
	// read chars from fp , mask if valid char specified
	while(((c=fgetc(fp)) != '\n' && c != EOF && idx <sz - 1)||(idx ==sz - 1 && c==127))
	{
		if(c != 127){
			if(31 < mask && mask <127)//valid ascii char
				fputc(mask,stdout);
			(*pw)[idx++] = c;
		}
		else if(idx > 0)  //handle backspace (del)
		{
			if (31 < mask && mask < 127){
				fputc(0x8,stdout);
				fputc(' ',stdout);
				fputc(0x8,stdout);
			}
			(*pw)[--idx] = 0;
		}
	}
	(*pw)[idx] = 0; // null-terminate
	// reset original keyboard
	if(tcsetattr(0,TCSANOW,&old_kbd_mode)){
		fprintf(stderr,"%s() error: tcsetattr failed.\n",__func__);
		return 1;
	}
	if(idx == sz-1 && c!='\n')  // warn if pw truncate
		fprintf(stderr,"(%s() warning: truncated at %zu chars.)\n",__func__,sz -1);
	return idx;  // number of chars in password
}
int checkpassword() //Validating passwords for banker corner
{
	char pw[MAXPW]={0};
	char *p=pw;

	FILE *fp=stdin;
	ssize_t nchr=0;
	nchr=password(&p,MAXPW,'*',fp);

	//Taking input for password
	printf("\nEnter password:\n");
	nchr=password(&p,MAXPW,'*',fp);
	if(strcmp(p,"abc@123")==0 || strcmp(p,"xyz@345")==0) //checking the fixed password
	{
		return 0;
	}
	else
	{
		return 1;
	}


}

