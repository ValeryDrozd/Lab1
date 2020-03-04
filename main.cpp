#include <bits/stdc++.h>
#include <dirent.h>
#include <sys/types.h>

using namespace std;
struct country{
    string name;
    int votes[20];
};

vector <country> v;
void readCsvFile(char filepath[],char filename[])
{
    string s1 = filepath,s2 = filename;
    string fin = s1+"\\"+s2;
     ifstream file;
    file.close();
}
void getFiles(char folderpath[]){
    DIR *dir;
    struct dirent * dp;
    dir = opendir(folderpath);
    if(!dir){
        cout<<"Error during opening folder\n";
        exit(1);
    }
    string s;
    while((dp = readdir(dir))!=NULL){
        s = dp->d_name;

    }
}

bool cmp(country a,country b){
    int sa = 0,sb = 0;
    for(int i=0;i<20;i++){
        sa+=a.votes[i];
        sb+=b.votes[i];
    }
    return sa>sb;
}
int main()
{
    char folderpath[256];
    gets(folderpath);
    getFiles(folderpath);
}
