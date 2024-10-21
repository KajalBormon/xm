#include<bits/stdc++.h>
using namespace std;
int main(){
    int key,ciphercode;
    string plaintext,ciphertext, mainCipher, newPlaintext;

    char p[]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    char c[]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

//    cout<<"Enter the plaintext : ";

 //   getline(cin, plaintext);

    // read plaintext from file
    ifstream MyReadFile("input.txt");
    string myText;
    while (getline (MyReadFile, myText)) {
       plaintext = myText;
    }
    MyReadFile.close();


    cout<<"Enter the initial key value : ";
    cin>>key;
    int len = plaintext.length();


    int pre=0;

    // Encryption
    for(int i=0;i<len;i++){
        for(int j=0;j<26;j++){
            if(plaintext[i]==p[j]){
                if(i==0)
                {
                    ciphercode = (j+key)%26;
                    pre = j;
                }
                else{
                    ciphercode = (j+pre)%26;
                    pre=j;
                }
                break;
            }
        }
        if(plaintext[i]!=' '){
            ciphertext+=c[ciphercode];
            mainCipher+=c[ciphercode];
        }

        else
            ciphertext+=' ';
    }

    cout<<endl<<"Ciphertext : "<<mainCipher<<endl;


    // decryption
    int pree, plaincode;;
    for(int i=0;i<len;i++){
        for(int j=0;j<26;j++){
            if(ciphertext[i]==c[j]){
                for(int k=0; k<26; k++){
                    if(i>0 && plaintext[i-1]!=' ' && plaintext[i-1]==p[k]){
                        pree= k;
                    }
                    else if(i>0 && plaintext[i-1]==' ' && plaintext[i-2]==p[k]){
                        pree= k;
                    }
                }
                if(i==0)
                {
                    if(j-key<0)
                        plaincode = (j-key+26)%26;
                    else
                        plaincode = (j-key)%26;
                }
                else{
                    if(j-pree<0)
                        plaincode = (j-pree+26)%26;
                    else
                        plaincode = (j-pree)%26;
                }
                break;
            }
        }
        if(plaintext[i]!=' '){
            newPlaintext+=p[plaincode];
        }

        else
            newPlaintext+=' ';
    }

    cout<<endl<<"Plaintext : "<<newPlaintext<<endl;

    return 0;
}
