#include<iostream>
#include<fstream>
#include<string.h>

using namespace std;
int main() {
    ifstream fin("input.txt");
    int count=0;
    char file_word[20], word[20];

    cout<<"Enter a word to count: ";
    cin >> word;
    int word_len = strlen(word);
    int positions[128] = {-1};
    int pos = 0, ptr_in_file = 0;
    while(fin)
    {
        fin >> file_word;
        cout << file_word << "-" << strlen(file_word) << endl;
        if(strncmp(file_word, word, strlen(file_word)) == 0) {
            count++;
            positions[pos++] = ptr_in_file;
        }
        ptr_in_file += strlen(file_word) + 1;
    }

    cout << "Number of occurrences = "<< count << endl;
    cout << "Positions at: ";
    for(int i = 0; i < pos; i++) {
         cout << positions[i] << " ";
    }
    cout << endl;
    fin.close(); //closing file

    return 0;
}
