#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

unsigned short get_chr(const char * s) {
	if (s[3]=='x' || s[3]=='X') {
		return 23;
	}
	if (s[3]=='y' || s[3]=='Y') {
		return 24;
	}
	if (s[3]=='m' || s[3]=='M') {
		return 25;
	}
	return atoi(s+3);
}

int main (int argc, char ** argv) {
	if (argc!=2) {
		cerr<<argv[0]<<" out_file";
		return 0;
	}

	char * filename=argv[1];

	FILE * fp =  fopen(filename,"wb");
	if (fp==NULL) {
		cerr<<"something terrible";
		return 0;
	}	

	string chr,nucleo;
	unsigned int pos;
	unsigned short dp;
	string line;
	while(getline(cin, line)) {
		cin>>chr>>pos>>nucleo>>dp;
		//cout<<pos<<" "<<dp<<endl;
		unsigned short ichr=get_chr(chr.c_str());
		fwrite(&ichr,sizeof(unsigned short),1,fp);
		fwrite(&pos,sizeof(unsigned int),1,fp);
		fwrite(&dp,sizeof(unsigned short),1,fp);
	}


}

//chr1    10000   N       3       AA^:A   D@+
