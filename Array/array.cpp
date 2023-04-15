#include <iostream>
using namespace std;

struct Array{
    int A[20];
    int size;
    int length;
};

void Display(struct Array arr){
    for(int i = 0; i < arr.length; i++){
        cout << arr.A[i] << " ";
    }
    cout << endl;
}
void Append(struct Array *arr,int x ){
    if(arr->length <= arr->size){
    arr->A[arr->length++] = x;
    }
}
void Insert(struct Array *arr, int index, int x){
    if(arr->length < arr->size && index <= arr->size && index >= 0){
        for(int i = arr->length; i > index; i--){
            arr->A[i] = arr->A[i-1];
            arr->A[index++] = x;
        }
    }
}

void Delete(struct Array *arr, int index){
    if(arr->length > 0 && index <= arr->length && index >= 0){

        for(int i = index; i < arr->size; i++){
            arr->A[i] = arr->A[i+1];
        }
        arr->length--;
    }
}

int main(){

    struct Array arr={{2,3,4,5,6}, 20, 5};

    Display(arr);

    Append(&arr, 10);

    Display(arr);

    Insert(&arr, 4, 15);

    Display(arr);

    Delete(&arr, 0);

    Display(arr);

    return 0;
}
