//
//  main.cpp
//  CRC-16
//
//  Created by Aahan Singh on 17/08/15.
//  Copyright (c) 2015 Aahan Singh. All rights reserved.
//

#include <iostream>
using namespace std;

string XOR(string x,string y){
    
    int l=x.length();
    string temp;
    for(int i=0;i<l;i++){
        if(x[i]==y[i])
            temp.append("0");
        else
            temp.append("1");
    }
    return temp;
}

string calc(string crc, string dw,int l){
    //appending 16 0s
    dw.append("0000000000000000");
    string temp=dw.substr(0,17);
    for(int i=0;i<l ;i++){
        char x=temp[0];
        if(x=='1')
            temp=XOR(crc,temp);
        temp=temp.substr(1,16);
        temp.append(dw.substr(i+17,1));
    }
    cout<<"CRC VALUE: "<<temp;
    return temp;
}
bool check(string crcN,string crc,string dw){
    
    int l=dw.length();
    dw.append(crcN);
    string temp=dw.substr(0,17);
    for(int i=0;i<l ;i++){
        char x=temp[0];
        if(x=='1')
            temp=XOR(crc,temp);
        temp=temp.substr(1,16);
        temp.append(dw.substr(i+17,1));
    }
    if(temp.compare("0000000000000000")==0)
        return true;
    else
        return false;

}

int main(int argc, const char * argv[]) {

    string crc="10001000000100001";
    string dw;
    cout<<"ENTER DATA WORD";
    cin>>dw;
    int l=dw.length();
    string crcN=calc(crc,dw,l);
    cout<<"\nENTER THE RECEIVED WORD\n";
    cin>>dw;
    if(check(crcN,crc,dw))
        cout<<"\nRECEIVED CORRECT DATA";
    else
        cout<<"\nRECEIVED WRONG DATA";
}
