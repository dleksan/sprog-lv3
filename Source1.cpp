//#include <iostream>
//#include <windows.h>
//#include <tchar.h>
//#include <strsafe.h>
//#include <chrono>
//
//#define THREAD_COUNT 4
//
//
//
//#pragma pack(push, 1)
//typedef struct MyData {
//    float* matrix;
//    int64_t width;
//    int ID;
//};
//#pragma pack(pop)
//
//
//
//DWORD WINAPI MyThreadFunction(LPVOID lpParam) {
//    
//    MyData* myData = (MyData*)lpParam;
//
//    int count = myData->width * myData->width / THREAD_COUNT;
//
//    int start = count * myData->ID;
//    int end = start + count;
//
//    if (myData->ID + 1 == THREAD_COUNT) {
//        end = myData->width * myData->width;
//    }
//
//    for (int index = start; index < end; index++) {
//
//        int i = index / myData->width;
//        int j = index % myData->width;
//
//        float sum = 0;
//        for (int k = 0; k < i; k++) {
//            sum += k * sin(j) - j * cos(k);
//        }
//
//        myData->matrix[index] = sum;
//    }
//
//    return 0;
//}
//
//
//
//int _tmain() {
//
//    int64_t width = 1024;
//
//    float* matrix = (float*)malloc(width * width * sizeof(float));
//
//    auto t1 = std::chrono::steady_clock::now();
//
//    MyData* pDataArray[THREAD_COUNT];
//    DWORD   dwThreadIdArray[THREAD_COUNT];
//    HANDLE  hThreadArray[THREAD_COUNT];
//
//    for (int i = 0; i < THREAD_COUNT; i++) {
//
//        pDataArray[i] = (MyData*)HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, sizeof(MyData));
//
//        pDataArray[i]->matrix = matrix;
//        pDataArray[i]->width = width;
//        pDataArray[i]->ID = i;
//
//        hThreadArray[i] = CreateThread(NULL, 0, MyThreadFunction, pDataArray[i], 0, &dwThreadIdArray[i]); 
//    }
//
//    WaitForMultipleObjects(THREAD_COUNT, hThreadArray, TRUE, INFINITE);
//
//    for (int i = 0; i < THREAD_COUNT; i++) {
//
//        CloseHandle(hThreadArray[i]);
//
//        HeapFree(GetProcessHeap(), 0, pDataArray[i]);
//        pDataArray[i] = NULL;
//    }
//
//    float prevSum = 0;
//    float currentSum = 0;
//    for (int j = 0; j < width; j++) {
//        
//        float currentSum = 0;
//        for (int i = 0; i < width; i++) {
//            currentSum += matrix[i * width + j];
//            matrix[i * width + j] += prevSum;
//        }   
//
//        prevSum += currentSum / width;
//    }
//
//    auto t2 = std::chrono::steady_clock::now();
//
//    float sum = 0;
//    for (int i = 0; i < width * width; i++) {
//        sum += matrix[i];
//    }
//
//    printf("%f\n", sum);
//    printf("%f ms\n", (t2 - t1).count() / 1000000.0f);
//
//    free(matrix);
//
//    return 0;
//}
//
//
//
