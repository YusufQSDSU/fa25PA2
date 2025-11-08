//
// Created by Manju Muralidharan on 10/19/25.
//

#ifndef HEAP_H
#define HEAP_H

#include <iostream>
using namespace std;

struct MinHeap {
    int data[64];
    int size;

    MinHeap() { size = 0; }

    void push(int idx, int weightArr[]) {
        // TODO: insert index at end of heap, restore order using upheap()
        data[size] = idx;
        upheap(size, weightArr);
        size++;
    }

    int pop(int weightArr[]) {
        // TODO: remove and return smallest index
        // Replace root with last element, then call downheap()
        if (size == 0) return -1; // Empty heap
        int root = data[0];
        data[0] = data[size - 1];
        size--;
        downheap(0, weightArr);
        return root;
    }

    void upheap(int pos, int weightArr[]) {
        // TODO: swap child upward while smaller than parent
        // Move an element up to restore heap property
        int child = pos;
        while (child > 0) {
            int parent = (child - 1) / 2;
            if (weightArr[data[child]] < weightArr[data[parent]]) {
                swap(data[child], data[parent]);
                child = parent;
            } else {
                break; // already in correct order
            }
        }
    }
    // Move an element down to restore heap property
    void downheap(int pos, int weightArr[]) {
        // TODO: swap parent downward while larger than any child
        int parent = pos;
        while (true) {
            int left = 2 * parent + 1;
            int right = 2 * parent + 2;
            int smallest = parent;
            if (left < size && weightArr[data[left]] < weightArr[data[smallest]]) {
                smallest = left;
            }
            if (right < size && weightArr[data[right]] < weightArr[data[smallest]]) {
                smallest = right;
            }
            if (smallest == parent) break;
            swap(data[parent], data[smallest]);
            parent = smallest;
        }
    }
};

#endif