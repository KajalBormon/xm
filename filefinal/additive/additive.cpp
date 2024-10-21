#include<bits/stdc++.h>
using namespace std;

int main()
{
    int ciphercode;
    int key;
    char cipherarr[100];
    char p[]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    char c[]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    string plaintext,ciphertext,mainCipher;
 //   cout<<"Enter the plaintext : ";
   // cin>>plaintext;
// getline(cin, plaintext);

//     cout<<"Enter the key : ";
//     cin>>key;



int inCount = 0;
// Read from the text file
ifstream MyReadFile("input.txt");
string myText;
// Use a while loop together with the getline() function to read the file line by line
while (getline (MyReadFile, myText)) {
  // Output the text from the file
  inCount+=1;
    if(inCount==1)
       plaintext = myText;
    else if(inCount==2)
        key = stoi(myText);
}

// Close the file
MyReadFile.close();





    int len = plaintext.length();

    // Encryption
    for(int i=0;i<len;i++){
        for(int j=0;j<26;j++){
            if(plaintext[i]==p[j]){
                 ciphercode = (j+key)%26;
                break;
            }
        }
        if(plaintext[i]!=' '){
            mainCipher+=c[ciphercode];
            ciphertext+=c[ciphercode];
        }
        else
            ciphertext+=' ';
    }

    cout<<endl<<"Cipher : "<<mainCipher<<endl;


    // Decryption
    int plaincode;
    string newPlaintext;
    for(int i=0;i<ciphertext.length();i++){
        for(int j=0;j<26;j++){
            if(ciphertext[i]==c[j]){
                if(j-key<0)
                    plaincode = (j-key+26)%26;
                else
                    plaincode = (j-key)%26;
                break;
            }
        }
        if(ciphertext[i]!=' ')
            newPlaintext+=p[plaincode];
        else
            newPlaintext+=' ';
    }

    cout<<endl<<"Decrypted Plaintext : "<<newPlaintext<<endl;

return 0;
}
