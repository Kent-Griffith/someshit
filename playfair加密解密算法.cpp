#include <iostream>
#include <string>
using namespace std;
#include "PLE.h"

char alp[26]={0};
char M[5][5]={0};
int main(){
cout<<"请输入你的密钥\r\n>";
string key = GetStr();
int k_len = len(key);
cout<<"请输入要加密的信息\r\n>";
string mess = GetStr();
int m_len = len(mess);
key = ToValid(key,k_len);
k_len = len(key);
for(int i = 0;i<k_len;i++){
    char ch = key[i];
    alp[ch-97]=1;
}
string s;
for(int i = 0;i<26;i++){
    if(alp[i]==1){
        s+=(char)i+97;
    }
}
key = s;
k_len = len(key);

mess = ToValid(mess,m_len);
m_len = len(mess);
string d;
for(int i = 0;i<m_len;i++){
    if(mess[i]!='j'){
        d+=mess[i];
    }else{d+='i';}
}
mess = d;
m_len = len(mess);
string ss;
for(int i = 0;i<m_len;i++){
    if(i>0){
        if(mess[i-1]==mess[i]){
            ss+='x';
            ss+=mess[i];
        }else{
        ss+=mess[i];
        }
    }else{ss+=mess[i];}
}
mess = ss;
m_len = len(mess);
if(m_len%2!=0){
    mess+='x';
    m_len++;
}
int n=0;
for(int i = 0;i<5;i++){
    for(int j = 0;j<5;j++){
       if(n<k_len){
            M[i][j]=key[n];
            n++;
       }
    }
}
char ch = 97;
string filtred;
while(len(filtred)<25-k_len){
for(int i = 0;i<k_len;i++){
    if(key[i]==ch){
        ch++;
        i = 0;
    }
}
if(ch!='j'){
filtred+=ch;
ch++;
}else{ch++;}
}
int c = 0;
for(int i = 0;i<5;i++){
    for(int j = 0;j<5;j++){
        if(i*5+j+1>k_len){
        M[i][j]=filtred[c];
        c++;
        }
    }
}
string encrypted;
for(int i = 0;i<m_len;i+=2){
    char ch1 = mess[i];
    char ch2 = mess[i+1];
    int ch1_i = 0;
    int ch1_j = 0;
    int ch2_i = 0;
    int ch2_j = 0;
    for(int o = 0;o<5;o++){
        for(int t = 0;t<5;t++){
            if(M[o][t]==ch1){
                ch1_i=o;
                ch1_j=t;
            }
            if(M[o][t]==ch2){
                ch2_i=o;
                ch2_j=t;
            }
        }
    }
    if(ch1_i==ch2_i){
        ch1_j++;
        ch1_j%=5;
        ch2_j++;
        ch2_j%=5;
        encrypted+=M[ch1_i][ch1_j];
        encrypted+=M[ch1_i][ch2_j];
    }
    if(ch1_j==ch2_j){
        ch1_i++;
        ch1_i%=5;
        ch2_i++;
        ch2_i%=5;
        encrypted+=M[ch1_i][ch1_j];
        encrypted+=M[ch2_i][ch1_j];
    }
    if(ch1_i!=ch2_i&&ch1_j!=ch2_j){
        int temp = ch1_i;
        ch1_i=ch2_i;
        ch2_i=temp;
        encrypted+=M[ch1_i][ch1_j];
        encrypted+=M[ch2_i][ch2_j];
    }

}
cout<<"你加密的信息是： ";
cout<<encrypted;
//Decryption
cout<<"\r\n请输入要解密的信息\n";
string str;
cin>>str;
encrypted=str;
string decrypted;
for(int i = 0;i<len(encrypted);i+=2){
    char ch1 = encrypted[i];
    char ch2 = encrypted[i+1];
    int ch1_i = 0;
    int ch1_j = 0;
    int ch2_i = 0;
    int ch2_j = 0;
    for(int o = 0;o<5;o++){
        for(int t = 0;t<5;t++){
            if(M[o][t]==ch1){
                ch1_i=o;
                ch1_j=t;
            }
            if(M[o][t]==ch2){
                ch2_i=o;
                ch2_j=t;
            }
        }
    }
    if(ch1_i==ch2_i){
        ch1_j-=1;
        if(ch1_j<0){
            ch1_j=5-ch1_j;
        }
        ch2_j-=1;
        if(ch2_j<0){
            ch2_j=5-ch2_j;
        }
        decrypted+=M[ch1_i][ch1_j];
        decrypted+=M[ch1_i][ch2_j];
    }
    if(ch1_j==ch2_j){
        ch1_i-=1;
        if(ch1_i<0){
            ch1_i=5-ch1_i;
        }
        ch2_i-=1;
        if(ch2_i<0){
            ch2_i=5-ch2_i;
        }
        decrypted+=M[ch1_i][ch1_j];
        decrypted+=M[ch2_i][ch1_j];
    }
    if(ch1_i!=ch2_i&&ch1_j!=ch2_j){
        int temp = ch1_i;
        ch1_i=ch2_i;
        ch2_i=temp;
        decrypted+=M[ch1_i][ch1_j];
        decrypted+=M[ch2_i][ch2_j];
    }

}
cout<<decrypted;
return 0;
}
