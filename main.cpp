#include <bits/stdc++.h>

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

}
