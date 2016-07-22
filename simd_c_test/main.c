//
//  main.c
//  simd_c_test
//
//  Created by PARK JAICHANG on 7/13/16.
//  Copyright © 2016 JAICHANGPARK. All rights reserved.
//

#include <stdio.h>
#include <emmintrin.h> //import sse2

int main(int argc, const char * argv[]) {
    // insert code here...
    // printf("Hello, World!\n");
    
    short A[8] = {2,3,4,5,6,7,5,3};
    short B[8] = {1,2,3,4,5,6,7,8};
    short R[8] = {0};
   
    
    __m128i xmmA = _mm_load_si128((__m128i*)A);
    __m128i xmmB = _mm_load_si128((__m128i*)B);
    
    __m128i xmmR = _mm_add_epi16(xmmA, xmmB);   // xmmA + xmmB
    _mm_store_si128((__m128i*)R, xmmR);
    printf("ADD: %d,%d,%d,%d,%d,%d,%d,%d\n",R[7],R[6],R[5],R[4],R[3],R[2],R[1],R[0]);
    
    xmmR = _mm_sub_epi16(xmmA, xmmB);   // xmmA - xmmB
    _mm_store_si128((__m128i*)R, xmmR); //
    printf("sub: %d,%d,%d,%d,%d,%d,%d,%d\n",R[7],R[6],R[5],R[4],R[3],R[2],R[1],R[0]);
    
    
    xmmR = _mm_mullo_epi16(xmmA, xmmB);   // xmmA  * xmmB
    _mm_store_si128((__m128i*)R, xmmR); //
    printf("mul: %d,%d,%d,%d,%d,%d,%d,%d\n",R[7],R[6],R[5],R[4],R[3],R[2],R[1],R[0]);
    
    
    xmmR = _mm_max_epi16(xmmA, xmmB);   // xmmA 과 xmmB와의 레지스터 팩에서 최대값 출력
    _mm_store_si128((__m128i*)R, xmmR); //
    printf("Max Value : %d,%d,%d,%d,%d,%d,%d,%d\n",R[7],R[6],R[5],R[4],R[3],R[2],R[1],R[0]);
    
    xmmR = _mm_min_epi16(xmmA, xmmB);   // xmmA 과 xmmB와의 레지스터 팩에서 최소값 출력
    _mm_store_si128((__m128i*)R, xmmR); //
    printf("Min Value : %d,%d,%d,%d,%d,%d,%d,%d\n",R[7],R[6],R[5],R[4],R[3],R[2],R[1],R[0]);
    
    
    xmmR = _mm_avg_epu16(xmmA, xmmB);   // (xmmA + xmmB) / 2  = (xmmA+....+xmmN)/Xmm레시스터 개수
    _mm_store_si128((__m128i*)R, xmmR); // 값 저장
    printf("average : %d,%d,%d,%d,%d,%d,%d,%d\n",R[7],R[6],R[5],R[4],R[3],R[2],R[1],R[0]);

}
