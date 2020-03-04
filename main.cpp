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
     if(!file){
        cout<<"Error during reading the file\n";
        exit();
    }
    int n;
    string s,data;
    file>>n;
    country to_push;
    for(int i=1;i<=n;i++){
    getline(file,s);
    stringstream line(s);
    vector <string> words;
    words.clear();
    while(getline(line,data,',')){
        words.push_back(data);
    }
    to_push.name = words[0];
    for(int i=1;i<=20;i++){
        to_push.votes[i-1] = stoi(words[i]);
    }
    v.push_back(to_push);
}
    file.close();

}
void getFiles(char folderpath[]){
    DIR *dir;
    struct dirent * dp;
    dir = opendir(folderpath);
    if(!dir){
        cout<<"Error during opening folder\n";
        exit();
    }
    string s;
    while((dp = readdir(dir))!=NULL){
        s = dp->d_name;
         if(s[0]!='.')readCsvFile(folderpath,dp->d_name);
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
void outCsvFile(char filepath[]){
}
int main()
{
    char folderpath[256];
    gets(folderpath);
    getFiles(folderpath);
    sort(v.begin(),v.end(),cmp)
    outCsvFile("rezult.csv");
}
