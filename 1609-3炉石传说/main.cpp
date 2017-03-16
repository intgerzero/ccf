#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct _role{
    int a;
    int h;
};
vector<_role>play1;

vector<_role>play2;

void f_summon(vector<_role>& play){
    int a,b,c;
    _role r;
    cin>>a>>b>>c;
    r.a=b;
    r.h=c;
    if(a==play.size())
        play.push_back(r);
    else
        play.insert(play.begin()+a,r);
}
void f_attack(vector<_role>& play_1,vector<_role>& play_2){
    int i,j;
    cin>>i>>j;
    int a1,a2;
    a1=play_1[i].a;
    a2=play_2[j].a;
    play_1[i].h=play_1[i].h-a2;
    play_2[j].h=play_2[j].h-a1;
    if(play_1[i].h<=0&&i!=0)
        play_1.erase(play_1.begin()+i);
    if(play_2[j].h<=0&&j!=0)
        play_2.erase(play_2.begin()+j);
}
int main()
{
    int status=0;
    int n;
    string s;

    _role r;
    r.a=0;
    r.h=30;
    play1.push_back(r);
    play2.push_back(r);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s;
        if(s=="end")
            status++;
        else if(status%2==0){
            if(s=="summon"){
                f_summon(play1);
            }
            if(s=="attack"){
                f_attack(play1,play2);
            }
        }
        else{
            if(s=="summon"){
                f_summon(play2);
            }
            if(s=="attack"){
                f_attack(play2,play1);
            }
        }
    }

    if(play1[0].h<=0)
        cout<<-1<<endl;
    else if(play2[0].h<=0)
        cout<<1<<endl;
    else
        cout<<0<<endl;

    cout<<play1[0].h<<endl;

    if(play1.size()-1==0)
        cout<<play1.size()-1<<endl;
    else
        cout<<play1.size()-1<<' ';
    for(int i=0;i<play1.size()-1;i++){
        if(i!=play1.size()-2)
            cout<<play1[i+1].h<<' ';
        else
            cout<<play1[i+1].h<<endl;
    }

    cout<<play2[0].h<<endl;
    if(play2.size()-1==0)
        cout<<play2.size()-1<<endl;
    else
        cout<<play2.size()-1<<' ';
    for(int i=0;i<play2.size()-1;i++){
        if(i!=play2.size()-2)
            cout<<play2[i+1].h<<' ';
        else
            cout<<play2[i+1].h<<endl;
    }
    return 0;
}
