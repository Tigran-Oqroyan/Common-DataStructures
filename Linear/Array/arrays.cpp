#include <iostream>
using namespace std;

int main(){
    int array[10] = {10,20,30,40,50};

    cout << "Bounds Access" << endl;
    cout << array[0] << " ";
    cout << array[1] << " ";
    cout << array[2] << " ";
    cout << array[3] << " ";
    cout << array[4] << " ";
    cout << endl;
    cout << endl;
    
    cout << "Loop" << endl;
    for(int i = 0; i < 5;i++){
        cout << array[i] << " ";
    }
    cout << endl;
    cout << endl;

    cout << "Array - " << array << endl;
    cout << endl;
    
    cout << "Pointer Arithmetic" << endl;

    cout << *array << " ";
    cout << *(array + 1) << " ";
    cout << *(array + 2) << " ";
    cout << *(array + 3) << " ";
    cout << *(array + 4) << " ";
}

// array y elementneri havaqacu e voronq dasavorvac en hishoxutyunum akoxq koxqi yev bolor elementnery nuyn tipi en

