/**
* @file ip-classification.h
*
*/
#ifndef __IPCLASSIFICATION_H__
#define __IPCLASSIFICATION_H__

void checkHostName(int hostname);

void checkHostEntry(struct hostent * hostentry);

void checkIPbuffer(char *IPbuffer);

char findClass(char str[]);

void separate(char str[], char ipClass);

#endif /* #ifndef __IPCLASSIFICATION_H__ */