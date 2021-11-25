//Z Algorithm

#include<bits/stdc++.h>
using namespace std;

vector<int> calculateZ(string input){
    vector<int> Z;
    for(int i=0;i<input.length();i++){
        Z.push_back(0);
    }
    int left = 0;
    int right = 0;
    for(int k = 1;k<input.length();k++){
        if(k > right){
            left = k;
            right = k;
            while(right < input.length() && input[right] == input[right - left]){
                right++;
            }
            Z[k] = right - left;
            right--;
        }
        else{
            int k1 = k - left;
            if(Z[k1] < right - k + 1){
                Z[k] = Z[k1];
            }
            else{
                left = k;
                while(right < input.length() && input[right] == input[right-left]){
                    right++;
                }
                Z[k] = right - left;
                right--;
            }
        }
    }

    return Z;
}

vector<int> Zalgorithm(string text, string pattern){

    string newString = "";
    int i = 0;
    while(pattern[i]){
        newString += pattern[i];
        i++;
    }
    newString += "$";
    i = 0;
    while(text[i]){
        newString += text[i];
        i++;
    }

    vector<int> result;
    vector<int> z = calculateZ(newString);
    for(int i = 0; i<z.size(); i++){
        if(z[i] == pattern.length()){
            result.push_back(i-pattern.length()-1);
        }
    }

    return result;
}

void Print(string text, string pattern, vector<int> result){
    cout<<"Text   :\t"<<text<<endl;
    cout<<"Pattern:\t"<<pattern<<endl;
    cout<<"Matches Found : "<<result.size()<<endl;
    cout<<"Matches found at index :   ";
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<"\t";
    }
    cout<<"\n\n\t"<<text<<endl;
    cout<<"\t";
    int counter = 0;
    for(int i=0;i<text.length();i++){
        if(i==result[counter]){
            cout<<"^";
            counter++;
        }
        else{
            cout<<" ";
        }
    }

    cout<<"\n\n";
}

int main(void){
    string text = "CATGATCATG";
    string pattern = "ATG";
    vector<int> result = Zalgorithm(text, pattern);
    Print(text,pattern,result);
}
