
#include<bits/stdc++.h>
using namespace std;

int main(){

    string plaintext,PlainText="", newPlaintext="", ciphertext="";
    char p[]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    char c[]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
// input plaintext
    cout<<"Give a plaintext : ";
    getline(cin, plaintext);
// input keys
    int block;
    cout<<"Enter block size : ";
    cin>>block;

    int keys[block];
    cout<<"Enter keys : ";
    for(int i=0; i<block; i++){
        int tmp;
        cin>>tmp;
        keys[i]=tmp-1;
    }

    int len = plaintext.length();
//remove space
    for(int i=0; i<len; i++){
        if(plaintext[i]!=' '){
            PlainText+=plaintext[i];
        }
    }
    int length = PlainText.length();

// finding how many blocks are needed
    int rows;
    if(length%block==0){
        rows=length/block;
    }
    else{
        rows=(length/block)+1;
        for(int i=1; i<block; i++){
            PlainText+='z';
        }
    }




//encryption :
    for(int i=0; i<rows; i++){
        for(int j=0; j<block; j++){
            int t=j;
            j=keys[t];
            ciphertext+= c[PlainText[(i*block)+j]-'A'-32];
            j=t;
        }
    }

    cout<<endl<<"Ciphertext : "<<ciphertext<< endl;





// decryption

    for(int i=0; i<rows; i++){
        for(int j=0; j<block; j++){
            int t;
            for(int l=0;l<block; l++){
                if(j==keys[l]){
                    t=l;
                }
            }
            newPlaintext+= p[32-('a'-ciphertext[(i*block)+t])];
        }
    }

    cout<<"Plaintext : ";
    for(int i=0; i<length; i++){
        cout<<newPlaintext[i];
    }



    return 0;
}
