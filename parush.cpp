
//author-Parush gupta>>parush.32-cse-16@mietjammu.in
//roll no.-32-cse-16
//A1 miet jammu
#include<dirent.h>
#include<string.h>
#include<string>
#include<iostream>
#include<sys/stat.h>
using namespace std;
class mp3{//class
public://access
void find( string Desktop){//member
	DIR *dir;
	struct dirent *entry;
	struct stat info;
	dir = opendir(Desktop.c_str());
	if(!dir)
	{ cout<<"not found";
	}
	while(      (entry = readdir(dir))  != NULL){
		if(entry->d_name[0] != '.'){
			string path = string(Desktop) + "/" + string(entry->d_name);
			cout<<"Entry= " << path <<endl;
			stat(path.c_str(),&info);   //
			if(S_ISDIR(info.st_mode)){
				find(path) ;
			}
                  if(entry->d_type==DT_REG){
			  if(entry->d_name[strlen(entry->d_name)-1]=='3')
			  cout<<entry->d_name<<" "<<endl;
		  }
		}
       closedir(dir);

	}


}




};


int main(){ mp3 m;
      string s;
      cout<<"Enter the path..."<<endl;
      cin>>s;
       m.find(s);



	return 0;
}
