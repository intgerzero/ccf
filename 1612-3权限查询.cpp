#include<iostream>
#include<vector> 
#include<string>
#include<cstdlib>
using namespace std;

const int NOVALUE = -1;  
const int TRUE = -2;  
const int FALSE = -3;  

//权限 
struct _privige{
	string name;
	int level;
}; 
vector<_privige>privige;

//角色
struct _role{
	string name;
	int num;
	vector<_privige>privige; 
}; 
vector<_role>role; 

//用户
struct _user{
	string name;
	int num;
	vector<string>role;
}; 
vector<_user>user;

//获取字符串
string getname(string &s){
	int pos=s.find(":");
	if(pos==string::npos)
		return s;
	else
		return s.substr(0,pos);
} 

//获取等级
int getlevel(string &s){
	int pos=s.find(":");
	if(pos==string::npos)
		return NOVALUE;
	else
		return atoi(s.substr(pos+1,s.length()-1).c_str());//将字符串转换成int 
} 


int privilegematch(_privige& p1, _privige& p2)  
{  
    if(p1.name != p2.name)  
        return FALSE;  
    else if(p2.level == NOVALUE) {  
        // 不分等级查询  
        if(p1.level == NOVALUE)  
            return TRUE;  
        else  
            return p1.level;  
    } else {    // p2.level >= 0  
        // 分等级查询  
        if(p1.level == NOVALUE)  
            return TRUE;  
        else {  
            if(p1.level >= p2.level)  
                return TRUE;  
            else  
                return FALSE;  
        }  
    }  
}  
  
int rolematch(string& rl, _privige& prvl)  
{  
    int ans = FALSE;  
  
    for(int i=0; i<(int)role.size(); i++) {  
        if(role[i].name == rl) {  
            for(int j=0; j<role[i].num; j++) {  
                int rt = privilegematch(role[i].privige[j], prvl);  
                if(rt > ans)  
                    ans = rt;  
            }  
        }  
    }  
  
    return ans;  
}  
  
int query(string& usr, _privige& prvl)  
{  
    for(int i=0; i<(int)user.size(); i++) {  
        if(user[i].name == usr) {  
            int ans = FALSE;  
            for(int j=0; j<user[i].num;j++) {  
                int rt = rolematch(user[i].role[j], prvl);  
                if(rt > ans)
                    ans = rt;  
            }  
            return ans;  
        }  
    }  
  
    return FALSE;  
}  

int main(){
	
	int n;
	string s;
	_privige pri; 
	//读取权限 
	cin>>n; 
	for(int i=0;i<n;i++){
		cin>>s;
		pri.name=getname(s);
		pri.level=getlevel(s);
		privige.push_back(pri);
	}
	cin>>n;
	for(int i=0;i<n;i++){
		_role r1;
		int t;
		cin>>s>>t;
		r1.name=s;
		r1.num=t;
		for(int j=0;j<t;j++){
			cin>>s;
			pri.name=getname(s);
			pri.level=getlevel(s);
			r1.privige.push_back(pri);
		}
		role.push_back(r1);
	}
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s;
		int t;
		cin>>t;
		_user u1;
		u1.name=s;
		u1.num=t;
		for(int j=0;j<t;j++){
			cin>>s;
			u1.role.push_back(s);
		}
		user.push_back(u1);	
	} 
	cin>>n;
	string use_name;
	for(int i=0;i<n;i++){
		cin>>use_name;
		cin>>s;
		pri.name=getname(s);
		pri.level=getlevel(s);
		int ans=query(use_name,pri);
		
		if(ans == TRUE)  
            cout << "true" << endl;  
        else if(ans == FALSE)  
            cout << "false" << endl;  
        else  
            cout << ans << endl;  
	}
}
