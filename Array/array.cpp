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

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

int LinearSearch(struct Array *arr, int x){
    for(int i = 0; i < arr->length; i++){
        if(arr->A[i] == x){
            swap(arr->A[i], arr->A[i-1]);
            return i;
        }
    }
    return -1;
}

int binarySearch(struct Array arr, int x){
    int high = arr.length -1;
    int low = 0;

    while(low <= high){
        int mid = high + low / 2;

        if(arr.A[mid] == x){
            return mid;
        }else if(arr.A[mid] > x){
            high = mid -1;
        }else{
            low = mid + 1;
        }
    }
    return -1;
}


int main(){

    struct Array arr={{2,3,4,5,6}, 20, 5};

    Display(arr);

    Append(&arr, 10);

    Display(arr);

    Insert(&arr, 5, 15);

    Display(arr);

    // Delete(&arr, 0);

    Display(arr);

    cout << LinearSearch(&arr, 4) << endl;

    Display(arr);

    cout << binarySearch(arr, 4) << endl;;

    cout << binarySearch(arr, 10) << endl;

    cout << binarySearch(arr, 20) << endl;

    Display(arr);

    return 0;
}
