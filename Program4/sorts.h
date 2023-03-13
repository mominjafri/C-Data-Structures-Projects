#include <iostream>
#include <string>
#include <vector>
using namespace std;

void BubbleSort(vector<int> &vec, int first, int last){
    for(int i = first; i < last; i++){
        for(int j = 0; j < last; j++){
            if(vec[j] > vec[j + 1])
            swap(vec[j], vec[j + 1]);
        }
    }
}

void InsertionSort(vector<int> &vec, int first, int last){
    for(int i = first +  1; i <= last; i++){
        int last = vec[i];
        int j = i - 1;
        while(j >= first && vec[j] > last){
            vec[j + 1] = vec[j];
            j = j -1;
        }

        vec[j + 1] = last;
    }
}

void Merge(vector<int> &vec, int first, int middle, int last){
    int *tempVec;
    int size = last - first + 1;
    tempVec = new int[size];
    int first_1 = first;
    int last_1 = middle;
    int first_2 = middle + 1;
    int last_2 = last;
    int i = 0;
    while((first_1 <= last_1) && (first_2 < last_2)){
        if(vec[first_1] < vec[first_2]){
            tempVec[i] = vec[first_1];
            first_1++;
        } else {
            tempVec[i] = vec[first_2];
            first_2++;
        }
        i++;
    }

    while(first_1 <= last_1){
        tempVec[i] = vec[first_1];
        first_1++;
        i++;
    }

    while(first_2 <= last_2){
        tempVec[i] = vec[first_1];
        first_2++;
        i++;
    }

    for(i = 0; i < size; i++){
        vec[first] = tempVec[i];
        first++;
    }

    delete[] tempVec;

}

void MergeSort(vector<int> &vec, int first, int last){
    if(first < last){
        int middle = (first + last) / 2;
        MergeSort(vec, first, middle);
        MergeSort(vec, middle + 1, last);
        Merge(vec, first, middle , last);
    }
}

void QuickSort(vector<int>& vec, int first, int last){
    if(last - first < 4){
        InsertionSort(vec, first, last);
        return;
    }

    int mid = (first + last) / 2;
    //sort first, mid, last values

    if(vec[first] > vec[last]){
        swap(vec[first], vec[last]);
    }
    
    if(vec[first] > vec[mid]){
        swap(vec[first], vec[mid]);
    }

    if(vec[mid] > vec[last]){
        swap(vec[mid], vec[last]);
    }

    int pivot = vec[mid];
    swap(vec[mid], vec[last - 1]);
    int left = first + 1;
    int right = last - 2;
    bool done = false;
    while(!done){
        while(vec[left] < pivot){
            left++;
        }
        while(vec[right] > pivot){
            right--;
        }
        if(right > left){
            swap(vec[left], vec[right]);
            right--;
            left++;

        } else {
            done = true;
        }

        swap(vec[left], vec[last - 1]);
        QuickSort(vec, first, left - 1);
        QuickSort(vec, left + 1, last);

    }
}

void ShellSort(vector<int> &vec, int num){
    for(int gap = num / 2; gap > 0; gap =(gap == 2) ? 1 : int(gap / 2.2)){
        for(int i = gap; i < num; i++){
            int tmp = vec[i];
            int j;
            for(j = i; (j >= gap) && (tmp < vec[j - gap]); j -= gap){
                vec[j] = vec[j - gap];
            }
            vec[j] = tmp;
        }

    }
}

void ShellSort(vector<int> &vec, int first, int last){
    if((first == 0) && (last == vec.size() - 1)){
        ShellSort(vec, vec.size());
        return;
    }

    vector<int> temp;
    for(int i = first; i <= last; i++){
        temp.push_back(vec[i]);
    }

    ShellSort(vec, vec.size());
    int count = first;
    for(int sorted: temp){
        vec[count] = sorted;
        count++;
    }
}

void IterativeMergeSort(vector<int> &vec, int first, int last){
    if(first < last){
        int *temp = new int[last + 1];
        int vec_length = (last - first) + 1;
        int vec_end = last + 1;
        int subSize = 1;
        int first1, first2, last1, last2, index1, index2, temp_index;
        
        for(temp_index = 0; temp_index < first; temp_index++){
            temp[temp_index] = vec[temp_index];
        }

        while(subSize < vec_length){
            first1 = first;
            temp_index = first;
            while((first1 + subSize) < vec_end){
                first2 = first1 + subSize;
                last1 = first2 - 1;
                last2 = ((first2 + subSize - 1) < vec_end) ? (first2 + subSize - 1) : (vec_end - 1);

                for(index1 = first1, index2 = first2; index1 <= last1 && index2 <= last2; temp_index++){
                    if(vec[index1] <= vec[index2]){
                        temp[temp_index] = vec[index1++];
                    } else {
                        temp[temp_index] = vec[index2++];
                    }

                }

                while(index1 <= last1){
                    temp[temp_index++] = vec[index1++];
                }

                while(index2 <= last2){
                    temp[temp_index++] = vec[index2++];
                }

                first1 = last2 + 1;
                
            }

            for(index1 = first1; temp_index < vec_end; index1++){
                temp[temp_index++] = vec[index1];
            }

            for(int i = first; i < vec_end; i++){
                vec[i] = temp[i];
            }

            subSize *= 2;
        }
    }

}
