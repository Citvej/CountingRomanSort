#include <iostream>
#include <vector>
#include <fstream>

using namespace std;


void countingSort(vector<int> A, vector<int> C, int min){
    for(int i = 1; i <= C.size(); i++) C[i] += C[i-1];  //prefix-sum
    vector<int> B(A.size());
    ofstream inputFile("sorted_output.txt");

    if(!inputFile){
        cout<<"Failed to create output file!";
    }

    for(int i = A.size()-1; i >= 0; i--){   
        B[C[A[i]]-1] = A[i] + min;
        C[A[i]]--;
        
    }
    for(int i=0; i<B.size();i++){
        inputFile << B[i] << " ";
    }
    inputFile.close();

}

void romanSort(vector<int> A, vector<int> C, int min){
    ofstream inputFile("sorted_output.txt");

    if(!inputFile){
        cout<<"Failed to create output file!";
    }

    for(int i = 0; i < C.size(); i++){
        if (C[i] > 0){
            for(int j = 0; j < C[i]; j++){
                inputFile << i+min << " ";
            }
        }
    }

    inputFile.close();
}

int main(int argc, char *argv[]){
    char izbira = *argv[1];                                                                          
    string pot = argv[2];                                                                           

    vector<int> A;                                                                                  
    int min = 0, max = 0, n;                                                                        
    
    ifstream inputFile;
    int currentNumberBeingRead;                                                                     
    inputFile.open(pot);

    if(!inputFile)                                                                                  
	{
		cout<<"Napaka pri odpiranju datoteke! \n";
		exit(1);
	}

    while(inputFile.eof() == 0)
	{
		inputFile >> currentNumberBeingRead;
        if(currentNumberBeingRead < min) min = currentNumberBeingRead;
        if(currentNumberBeingRead > max) max = currentNumberBeingRead; 
        A.push_back(currentNumberBeingRead);
	}

    for(vector<int>::iterator it = A.begin(); it != A.end(); ++it){
        *it -= min;
    }
    max -= min;                                                             
    vector<int> C (max+1, 0);
    for(int i = 0; i < A.size(); i++){
        C[A[i]]++;
    }
    if(izbira == '0'){
        countingSort(A, C, min);
    }
    if(izbira == '1'){
        romanSort(A, C, min);
    }


    return 0;
}