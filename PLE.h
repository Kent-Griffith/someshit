#ifndef PEL
#define PEL

string GetStr(){
string s;
cin>>s;
return s;
}

int len(string s){
int l = 0;
for(int i = 0;s[i]!='\0';i++){
    l++;
}
return l;
}

string ToValid(string s,int l){
    string m;
    for(int i = 0;i<l;i++){
        if(isupper(s[i])){
            m+=tolower(s[i]);
        }else{m+=s[i];}
    }
    for(int i = 0;i<l;i++){
        if(m[i]>=97&&m[i]<=122){
        }else{cout<<"\r\nWRONG TRY AGAIN!\r\n";break;}
    }
    return m;
}


#endif