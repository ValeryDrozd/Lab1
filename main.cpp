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
    cout<<"Reading file\n";
    string s1 = filepath,s2 = filename;
    string fin = s1+"\\"+s2;
    ifstream file;
    cout<<fin;
    file.open(fin.c_str());
    if(!file){
        cout<<"Error during reading the file\n";
        exit(2);
        }
    int n;
    string s,data;
    country to_push;
    file>>n;
    file.ignore(256,'\n');
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
}

void getFiles(char folderpath[]){
    cout<<"Reading folder\n";
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
        cout<<s<<endl;
        if(s[0]!='.')readCsvFile(folderpath,dp->d_name);
    }
    closedir(dir);
}

void outCsvFile(char filepath[]){
    ofstream file;
    file.open(filepath);
    if(!file){
        cout<<"Error during writing data in the file\n";
        exit(3);
    }

    file.close();
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
    cout<<"Read!\n";
    getFiles(folderpath);
    sort(v.begin(),v.end(),cmp);
    outCsvFile("rezult.csv");
}
